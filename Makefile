SITE_DIR := site

.PHONY: help install dev build preview clean

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
