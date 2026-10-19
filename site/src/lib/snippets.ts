import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { execFileSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';

export interface Author {
  name: string;
  email: string;
  avatar: string;
}

export interface Snippet {
  slug: string;
  name: string;
  ext: string;
  desc: string | null;
  dir: string;
  category: string;
  lang: string;
  code: string;
  lines: number;
  mtime: Date;
  date: string;
  authors: Author[];
}

export const EXT_LANGS: Record<string, string> = {
  '.cpp': 'cpp',
  '.cc': 'cpp',
  '.cxx': 'cpp',
  '.hpp': 'cpp',
  '.h': 'cpp',
  '.c': 'c',
  '.py': 'python',
  '.md': 'markdown',
  '.ts': 'typescript',
  '.tsx': 'tsx',
  '.js': 'javascript',
  '.jsx': 'jsx',
  '.json': 'json',
  '.go': 'go',
  '.rs': 'rust',
  '.java': 'java',
  '.sh': 'bash',
  '.bash': 'bash',
  '.zsh': 'bash',
  '.html': 'html',
  '.htm': 'html',
  '.css': 'css',
  '.sql': 'sql',
  '.yaml': 'yaml',
  '.yml': 'yaml',
  '.toml': 'toml',
};

const IGNORED_DIRS = new Set(['site', 'assets', 'node_modules', 'dist']);

const LABEL_OVERRIDES: Record<string, string> = {
  cpp: 'C++',
  md: 'Markdown',
};

const HASH_COMMENT_LANGS = new Set(['python', 'bash', 'yaml', 'toml']);

const REPO_ROOT = fileURLToPath(new URL('../../..', import.meta.url));

interface GitInfo {
  date: string | null;
  authors: Author[];
}

function gravatarUrl(email: string): string {
  const hash = createHash('md5').update(email.trim().toLowerCase()).digest('hex');
  return `https://www.gravatar.com/avatar/${hash}?d=mp&s=64`;
}

function withSize(url: string, size = 64): string {
  return url + (url.includes('?') ? '&' : '?') + `s=${size}`;
}

function noreplyAvatar(email: string): string | null {
  const m = email.match(/^(?:\d+\+)?([^@]+)@users\.noreply\.github\.com$/i);
  return m ? withSize(`https://github.com/${m[1]}.png`) : null;
}

function remoteUrls(): string[] {
  try {
    return execFileSync('git', ['-C', REPO_ROOT, 'remote', '-v'], { encoding: 'utf8' })
      .split('\n')
      .map((l) => l.trim())
      .filter((l) => l.endsWith('(fetch)') || l.endsWith('(push)'))
      .map((l) => l.split(/\s+/)[1])
      .filter(Boolean);
  } catch {
    return [];
  }
}

function siteOwner(): string | null {
  try {
    const src = fs.readFileSync(new URL('../../astro.config.mjs', import.meta.url), 'utf8');
    const m = src.match(/site:\s*['"]https?:\/\/([^.']+)\.github\.io/i);
    return m ? m[1] : null;
  } catch {
    return null;
  }
}

function repoSlug(): string | null {
  const urls = remoteUrls();
  for (const url of urls) {
    const m = url.match(/github\.com[/:]([^/]+)\/([^/.#]+)/i);
    if (m) return `${m[1]}/${m[2]}`;
  }
  const owner = siteOwner();
  const repo = urls[0]?.replace(/\.git$/, '').split(/[/:]/).pop();
  if (owner && repo) return `${owner}/${repo}`;
  return null;
}

async function buildGithubAvatarMap(): Promise<Map<string, string>> {
  const map = new Map<string, string>();
  const slug = repoSlug();
  if (!slug) return map;
  const headers: Record<string, string> = { Accept: 'application/vnd.github+json' };
  if (process.env.GITHUB_TOKEN) headers.Authorization = `Bearer ${process.env.GITHUB_TOKEN}`;
  for (let page = 1; page <= 10; page++) {
    try {
      const res = await fetch(`https://api.github.com/repos/${slug}/commits?per_page=100&page=${page}`, {
        headers,
        signal: AbortSignal.timeout(5000),
      });
      if (!res.ok) break;
      const commits = (await res.json()) as unknown;
      if (!Array.isArray(commits) || commits.length === 0) break;
      type GhCommit = {
        commit?: { author?: { email?: string } };
        author?: { avatar_url?: string } | null;
      };
      for (const c of commits as GhCommit[]) {
        const email = c.commit?.author?.email?.trim().toLowerCase();
        const avatar = c.author?.avatar_url;
        if (email && avatar && !map.has(email)) map.set(email, avatar);
      }
      if (commits.length < 100) break;
    } catch {
      break;
    }
  }
  return map;
}

function avatarUrl(email: string, githubMap: Map<string, string>): string {
  const noreply = noreplyAvatar(email);
  if (noreply) return noreply;
  const gh = githubMap.get(email.trim().toLowerCase());
  if (gh) return withSize(gh);
  return gravatarUrl(email);
}

let gitInfoCache: Map<string, GitInfo> | null = null;

async function buildGitInfoMap(): Promise<Map<string, GitInfo>> {
  const map = new Map<string, GitInfo>();
  const githubAvatars = await buildGithubAvatarMap();
  try {
    const out = execFileSync(
      'git',
      ['-C', REPO_ROOT, 'log', '--reverse', '--format=\x1e%cI\x1f%an\x1f%ae', '--name-only'],
      { encoding: 'utf8', maxBuffer: 64 * 1024 * 1024 },
    );
    for (const block of out.split('\x1e')) {
      const lines = block.split('\n').filter((l) => l.trim());
      if (lines.length < 2) continue;
      const [iso, name, email] = lines[0].split('\x1f');
      if (!iso || !name || !email) continue;
      const author: Author = { name, email, avatar: avatarUrl(email, githubAvatars) };
      for (const file of lines.slice(1)) {
        const info = map.get(file) ?? { date: null, authors: [] };
        info.date = iso;
        if (!info.authors.some((a) => a.email === email)) info.authors.push(author);
        map.set(file, info);
      }
    }
  } catch {
    /* git 历史不可用时返回空映射，回退到文件系统 mtime */
  }
  return map;
}

async function gitInfoMap(): Promise<Map<string, GitInfo>> {
  gitInfoCache ??= await buildGitInfoMap();
  return gitInfoCache;
}

function extractDesc(code: string, lang: string): string | null {
  for (const raw of code.split('\n')) {
    const line = raw.trim();
    if (!line) continue;
    if (lang === 'markdown') {
      const heading = line.match(/^#{1,6}\s+(.+)/);
      return heading ? heading[1] : line;
    }
    if (line.startsWith('#') && HASH_COMMENT_LANGS.has(lang)) {
      return line.replace(/^#+\s*/, '');
    }
    if (line.startsWith('//') || line.startsWith('/*')) {
      return line.replace(/^[/]+\s*/, '').replace(/\s*\*\/$/, '');
    }
    return null;
  }
  return null;
}

function* walkFiles(root: string, rel = ''): Generator<string> {
  const abs = rel ? path.join(root, rel) : root;
  for (const entry of fs.readdirSync(abs, { withFileTypes: true })) {
    if (entry.name.startsWith('.')) continue;
    const relPath = rel ? `${rel}/${entry.name}` : entry.name;
    if (entry.isDirectory()) {
      if (IGNORED_DIRS.has(entry.name)) continue;
      yield* walkFiles(root, relPath);
    } else if (entry.isFile()) {
      yield relPath;
    }
  }
}

function dirLabel(dir: string): string {
  return LABEL_OVERRIDES[dir] ?? dir.charAt(0).toUpperCase() + dir.slice(1);
}

export async function getSnippets(): Promise<Snippet[]> {
  const snippets: Snippet[] = [];
  const gitInfo = await gitInfoMap();
  for (const entry of fs.readdirSync(REPO_ROOT, { withFileTypes: true })) {
    if (!entry.isDirectory() || entry.name.startsWith('.') || IGNORED_DIRS.has(entry.name)) continue;
    const dir = entry.name;
    const category = dirLabel(dir);
    for (const relPath of walkFiles(path.join(REPO_ROOT, dir))) {
      const ext = path.extname(relPath).toLowerCase();
      const lang = EXT_LANGS[ext];
      if (!lang) continue;
      const filePath = path.join(REPO_ROOT, dir, relPath);
      const code = fs.readFileSync(filePath, 'utf8');
      const stem = relPath.slice(0, relPath.length - ext.length);
      const name = path.basename(stem);
      const fsMtime = fs.statSync(filePath).mtime;
      const info = gitInfo.get(path.relative(REPO_ROOT, filePath));
      const iso = info?.date ?? null;
      snippets.push({
        slug: `${dir}/${stem}`,
        name,
        ext,
        desc: extractDesc(code, lang),
        dir,
        category,
        lang,
        code,
        lines: code.replace(/\n$/, '').split('\n').length,
        mtime: iso ? new Date(iso) : fsMtime,
        date: iso ? iso.slice(0, 10) : fsMtime.toLocaleDateString('en-CA'),
        authors: info?.authors ?? [],
      });
    }
  }
  return snippets.sort((a, b) => b.mtime.getTime() - a.mtime.getTime());
}

export function getCategories(snippets: Snippet[]): { dir: string; label: string; count: number }[] {
  const map = new Map<string, { dir: string; label: string; count: number }>();
  for (const s of snippets) {
    const c = map.get(s.dir) ?? { dir: s.dir, label: s.category, count: 0 };
    c.count++;
    map.set(s.dir, c);
  }
  return [...map.values()];
}
