import json
import os
import re
import sys

DIR_RE = re.compile(r"^[a-z0-9_-]{1,20}$")
NAME_RE = re.compile(r"^[A-Za-z0-9][A-Za-z0-9._-]*$")
EXT_LANGS = {
    ".cpp": "cpp", ".cc": "cpp", ".cxx": "cpp", ".hpp": "cpp", ".h": "cpp",
    ".c": "c", ".py": "python", ".md": "markdown", ".ts": "typescript",
    ".tsx": "tsx", ".js": "javascript", ".jsx": "jsx", ".json": "json",
    ".go": "go", ".rs": "rust", ".java": "java", ".sh": "bash",
    ".bash": "bash", ".zsh": "bash", ".html": "html", ".htm": "html",
    ".css": "css", ".sql": "sql", ".yaml": "yaml", ".yml": "yaml", ".toml": "toml",
}
HASH_COMMENT_LANGS = {"python", "bash", "yaml", "toml"}
MAX_CODE = 50000
MAX_DESC = 80
MAX_NAME = 60
PREFIX = "[碎片] "


CODE_RE = re.compile(r"### 代码\s*\n+````[^\n]*\n(.*?)\n````\s*$", re.S)


def parse_sections(body: str) -> dict[str, str]:
    result: dict[str, str] = {}
    parts = re.split(r"\n### ", "\n" + body)
    for part in parts[1:]:
        name, _, rest = part.partition("\n")
        result[name.strip()] = rest.strip()
    return result


def main() -> None:
    title = os.environ.get("ISSUE_TITLE", "")
    body = os.environ.get("ISSUE_BODY", "")

    if not title.startswith(PREFIX):
        print(json.dumps({"action": "skip"}))
        return

    code = ""
    m = CODE_RE.search(body)
    if m:
        code = m.group(1)
        body = body[: m.start()]
    sec = parse_sections(body)
    cat = sec.get("分类", "")
    name = sec.get("文件名", "")
    desc = sec.get("简介", "")

    errors = []
    if not DIR_RE.fullmatch(cat):
        errors.append("分类名不合法（仅小写字母、数字、-、_，长度 1-20）")
    if not NAME_RE.fullmatch(name) or len(name) > MAX_NAME:
        errors.append("文件名不合法（仅字母、数字、点、下划线、连字符，且不以点开头）")
    ext = os.path.splitext(name)[1].lower()
    if ext not in EXT_LANGS:
        errors.append(f"不支持的扩展名「{ext}」")
    if not code.strip():
        errors.append("代码为空或无法解析（请通过网站提交页生成 Issue）")
    elif len(code) > MAX_CODE:
        errors.append(f"代码超过 {MAX_CODE} 字符上限")
    if len(desc) > MAX_DESC:
        errors.append(f"简介超过 {MAX_DESC} 字上限")

    if errors:
        print(json.dumps({"action": "reject", "errors": errors}, ensure_ascii=False))
        return

    lang = EXT_LANGS[ext]
    content = code.rstrip("\n") + "\n"
    if desc:
        if lang == "markdown":
            content = f"# {desc}\n\n{content}"
        elif lang in HASH_COMMENT_LANGS:
            content = f"# {desc}\n{content}"
        else:
            content = f"// {desc}\n{content}"

    print(json.dumps(
        {"action": "pr", "path": f"{cat}/{name}", "content": content},
        ensure_ascii=False,
    ))


if __name__ == "__main__":
    sys.exit(main())
