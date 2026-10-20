SITE_DIR := site

.PHONY: help install dev build preview clean git-sync

help: ## 显示帮助
	@grep -E '^[a-zA-Z_-]+:.*?## ' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'

install: ## 安装站点依赖
	cd $(SITE_DIR) && npm install

dev: ## 开发预览（热更新）http://localhost:4321/pieces/
	cd $(SITE_DIR) && npm run dev

build: ## 构建静态站点到 site/dist/
	cd $(SITE_DIR) && npm run build

preview: ## 本地预览构建产物（先执行 make build）
	cd $(SITE_DIR) && npm run preview

clean: ## 清理构建产物与依赖
	rm -rf $(SITE_DIR)/dist $(SITE_DIR)/node_modules $(SITE_DIR)/.astro

git-sync: ## 同步 GitHub 最新到本地并推送 GitCode
	@git fetch --multiple github origin
	@echo "── 同步前 ──"
	@echo "本地    $$(git log -1 --oneline HEAD)"
	@echo "GitHub  $$(git log -1 --oneline github/main)"
	@echo "GitCode $$(git log -1 --oneline origin/main)"
	@if [ "$$(git rev-list --count HEAD..github/main)" -gt 0 ]; then \
		echo "── git merge --ff-only github/main ──"; \
		git merge --ff-only github/main; \
	else \
		echo "本地已含 GitHub 全部提交，跳过合并"; \
	fi
	@echo "── git push origin main ──"
	@git push origin main
	@echo "── 同步后 ──"
	@git log --oneline -3 HEAD
