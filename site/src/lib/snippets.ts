import fs from 'node:fs';
import path from 'node:path';
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
}

interface CategoryDef {
  label: string;
  langs: Record<string, string>;
}

const CATEGORIES: Record<string, CategoryDef> = {
  cpp: {
    label: 'C++',
    langs: { '.cpp': 'cpp', '.cc': 'cpp', '.cxx': 'cpp', '.h': 'cpp', '.hpp': 'cpp' },
  },
  python: { label: 'Python', langs: { '.py': 'python' } },
  md: { label: 'Markdown', langs: { '.md': 'markdown' } },
};

const REPO_ROOT = fileURLToPath(new URL('../../..', import.meta.url));

function extractDesc(code: string, lang: string): string | null {
  for (const raw of code.split('\n')) {
    const line = raw.trim();
    if (!line) continue;
    if (lang === 'markdown') {
      const heading = line.match(/^#{1,6}\s+(.+)/);
      return heading ? heading[1] : line;
    }
    if (lang === 'python' && line.startsWith('#')) {
      return line.replace(/^#+\s*/, '');
    }
    if (lang === 'cpp' && (line.startsWith('//') || line.startsWith('/*'))) {
      return line.replace(/^[/]+\s*/, '').replace(/\s*\*\/$/, '');
    }
    return null;
  }
  return null;
}

export function getSnippets(): Snippet[] {
  const snippets: Snippet[] = [];
  for (const [dir, def] of Object.entries(CATEGORIES)) {
    const dirPath = path.join(REPO_ROOT, dir);
    if (!fs.existsSync(dirPath)) continue;
    for (const entry of fs.readdirSync(dirPath, { withFileTypes: true })) {
      if (!entry.isFile()) continue;
      const ext = path.extname(entry.name).toLowerCase();
      const lang = def.langs[ext];
      if (!lang) continue;
      const filePath = path.join(dirPath, entry.name);
      const code = fs.readFileSync(filePath, 'utf8');
      const name = path.basename(entry.name, ext);
      snippets.push({
        slug: `${dir}/${name}`,
        name,
        ext,
        desc: extractDesc(code, lang),
        dir,
        category: def.label,
        lang,
        code,
        lines: code.replace(/\n$/, '').split('\n').length,
        mtime: fs.statSync(filePath).mtime,
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
