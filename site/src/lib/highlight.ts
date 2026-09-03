import { codeToHtml } from 'shiki';

const themes = { light: 'github-light', dark: 'github-dark' } as const;

export function highlight(code: string, lang: string): Promise<string> {
  return codeToHtml(code, { lang, themes, defaultColor: false });
}

export function truncateLines(code: string, max = 12): { text: string; truncated: boolean } {
  const lines = code.replace(/\n$/, '').split('\n');
  if (lines.length <= max) return { text: lines.join('\n'), truncated: false };
  return { text: lines.slice(0, max).join('\n'), truncated: true };
}
