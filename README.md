# 代码碎片 code-piece

汇总在学习编程语言时候需要测试的一些代码碎片。很杂很乱。

## 网站浏览

本仓库附带一个静态网站（`site/`），以代码卡片的形式浏览所有碎片：

- 网页端与手机端自适应
- Shiki 构建时语法高亮，支持亮/暗主题切换
- 支持按标题、语言、代码内容全文搜索
- 按目录自动分类（`cpp/` `python/` `md/`），URL 形如 `/?cat=python`

本地运行：

```bash
cd site
npm install
npm run dev      # 开发预览 http://localhost:4321/pieces/
npm run build    # 构建产物输出到 site/dist/
npm run preview  # 本地预览构建产物
```

新增碎片：直接在 `cpp/`、`python/`、`md/` 目录下添加源码文件即可，
站点构建时自动扫描收录（开发模式下新增文件需重启 dev server）。
建议在文件首行写一句注释，会作为卡片的简介展示。

部署：push 到 GitHub 后由 `.github/workflows/deploy.yml` 自动构建并发布到
GitHub Pages（`site/astro.config.mjs` 中的 `site` / `base` 按实际仓库地址调整）。


