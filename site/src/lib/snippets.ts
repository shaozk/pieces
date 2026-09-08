import fs from 'node:fs';
import path from 'node:path';
import { execFileSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';

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
}

const EXT_LANGS: Record<string, string> = {
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

function gitLastModified(relPath: string): string | null {
  try {
    const out = execFileSync('git', ['-C', REPO_ROOT, 'log', '-1', '--format=%cI', '--', relPath], {
      encoding: 'utf8',
    });
    return out.trim() || null;
  } catch {
    return null;
  }
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

export function getSnippets(): Snippet[] {
  const snippets: Snippet[] = [];
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
      const iso = gitLastModified(path.relative(REPO_ROOT, filePath));
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
