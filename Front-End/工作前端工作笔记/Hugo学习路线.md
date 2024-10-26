# Hugo API 学习路线

## 1. 入门基础
### 1.1 安装 Hugo
- [官方安装文档](https://gohugo.io/getting-started/installing)
- 使用 Homebrew（macOS）或通过二进制文件安装
- 使用 `hugo version` 确认安装成功

### 1.2 Hugo 基础概念
- **站点结构**：了解 Hugo 项目结构（content、layouts、themes 等）
- **Markdown 文件**：所有内容页面使用 Markdown 编写
- **配置文件**：`config.toml`、`config.yaml` 或 `config.json`

## 2. 站点内容和组织
### 2.1 内容组织
- **Content 文件夹**：如何使用 `content/` 组织站点的内容
- **Front Matter**：在 Markdown 文件中添加元数据（如标题、日期、标签）
- **Page Bundles**：`leaf` 和 `branch` page bundle 的区别

### 2.2 多语言支持
- 配置多语言站点的最佳实践
- `i18n` 文件的使用方法

## 3. 模板系统
### 3.1 基础模板语法
- [Hugo 模板基础](https://gohugo.io/templates/introduction/)
- **Go 模板引擎**：学习 Go 模板的基本语法
- `baseof.html`：基础布局模板
- `partial` 模板：代码复用

### 3.2 常用模板函数
- 使用 `{{ .Title }}`、`{{ .Content }}` 访问页面数据
- **变量和函数**：使用 `range` 遍历内容、使用 `where` 过滤内容
- **内置函数**：`len`、`slice`、`default` 等常见函数

### 3.3 数据与内容关系
- **数据文件**：使用 `data/` 目录加载 YAML、JSON 或 TOML 文件
- **短代码（Shortcodes）**：创建可重用的内容片段
  - 内置短代码：`figure`、`highlight` 等
  - 自定义短代码

## 4. 静态资源和 Hugo Pipes
### 4.1 Hugo Pipes 概述
- [Hugo Pipes 文档](https://gohugo.io/hugo-pipes/introduction/)
- **CSS/JS 处理**：使用 Hugo Pipes 管理和优化 CSS/JS 文件
- **图像处理**：压缩、调整大小和裁剪图像

### 4.2 静态文件管理
- `static/` 文件夹：处理不会被 Hugo 处理的静态文件
- 引用静态文件的方法：`/static/images/logo.png`

## 5. 高级主题和布局
### 5.1 创建和使用主题
- **主题结构**：如何创建和使用 Hugo 主题
- 使用 `themes/` 文件夹管理主题

### 5.2 自定义布局和模板继承
- 覆盖主题的模板文件
- 通过 `block` 和 `define` 实现模板继承

## 6. 数据接口与扩展 API
### 6.1 使用外部数据源
- 如何通过 API 调用外部数据源（如 JSON、CSV）
- 处理数据并将其呈现在页面中

### 6.2 Hugo 的 CLI 工具
- 使用 `hugo server` 本地运行 Hugo 开发服务器
- 使用 `hugo` 构建站点，生成静态文件
- 常见 CLI 参数：`--minify`、`--gc`

## 7. 部署和优化
### 7.1 部署 Hugo 站点
- 将 Hugo 部署到 GitHub Pages、Netlify 或 Vercel
- CI/CD 集成：自动化部署流程

### 7.2 性能优化
- **缓存**：使用 Hugo 缓存机制优化构建时间
- **SEO**：优化站点的 SEO 标签
- **Page Speed**：优化图片、CSS 和 JS 以提高页面加载速度

## 8. 参考资源
- [Hugo 官方文档](https://gohugo.io/documentation/)
- [Hugo API 文档](https://gohugo.io/functions/)