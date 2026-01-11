# 全国交通查询系统 (Traffic Inquiry Frontend)

一个基于 Vue 3 + TypeScript 的全国交通路线查询系统前端应用，支持路线查询、可视化展示和管理功能。

## 📋 项目简介

本项目是一个交通路线查询系统，提供以下核心功能：

- **路线查询**：支持最快路径、最便宜路径、最少中转路径三种查询策略
- **可视化展示**：使用 ECharts 展示交通网络图和查询结果
- **数据管理**：管理员可对城市和路线进行增删改查操作
- **用户系统**：支持普通用户和管理员两种角色

## 🛠️ 技术栈

- **框架**：Vue 3.5.24
- **语言**：TypeScript 5.9.3
- **构建工具**：Vite 7.2.4
- **UI 组件库**：Element Plus 2.13.0
- **路由**：Vue Router 4.6.4
- **HTTP 客户端**：Axios 1.13.2
- **数据可视化**：ECharts 6.0.0
- **样式预处理**：Less 4.5.1
- **自动导入**：unplugin-auto-import、unplugin-vue-components

## 📁 项目结构

```
traffic-inquiry-fe/
├── src/
│   ├── api/              # API 接口封装
│   ├── assets/           # 静态资源
│   ├── components/        # 组件
│   ├── router/           # 路由配置
│   │   ├── index.ts      # 路由入口
│   │   └── modules/      # 路由模块
│   ├── utils/            # 工具函数
│   ├── views/            # 页面视图
│   ├── App.vue           # 根组件
│   ├── main.ts           # 入口文件
│   └── style.less        # 全局样式
├── public/               # 公共资源
├── index.html            # HTML 模板
├── package.json          # 项目配置
├── tsconfig.json         # TypeScript 配置
└── vite.config.ts        # Vite 配置
```

## 🚀 快速开始

### 环境要求

- Node.js >= 16.0.0
- npm >= 7.0.0 或 yarn >= 1.22.0

### 安装依赖

```bash
npm install
```

### 开发运行

```bash
npm run dev
```

项目将在 `http://localhost:5173` 启动（具体端口以终端输出为准）

### 构建生产版本

```bash
npm run build
```

构建产物将输出到 `dist` 目录

### 预览生产构建

```bash
npm run preview
```

## 🔐 登录账号

系统提供两种角色：

- **普通用户**
  - 用户名：`user`
  - 密码：`123456`
  - 功能：路线查询、结果查看

- **管理员**
  - 用户名：`admin`
  - 密码：`123456`
  - 功能：路线查询、数据管理（城市和路线的增删改查）

## ✨ 主要功能

### 1. 路线查询（Home 页面）

- **最快路径查询**：查找从起点到终点的最快路线
- **最便宜路径查询**：查找从起点到终点的最经济路线
- **最少中转路径查询**：查找需要最少中转次数的路线

查询结果会以表格形式展示，并在右侧的交通网络图中高亮显示。

### 2. 可视化展示

- 使用 ECharts 力导向图展示全国交通网络
- 支持缩放、拖拽等交互操作
- 查询结果路径会高亮显示
- 支持深色/浅色主题切换

### 3. 数据管理（Admin 页面）

管理员可以对以下数据进行管理：

- **城市管理**
  - 添加新城市（城市名称、城市代码）
  - 修改城市信息
  - 删除城市

- **路线管理**
  - 添加新路线（起点、终点、出发时间、到达时间、车次、价格、类型）
  - 修改路线信息
  - 删除路线



## 📦 主要依赖

### 生产依赖

- `vue` - Vue 框架
- `vue-router` - 路由管理
- `element-plus` - UI 组件库
- `@element-plus/icons-vue` - Element Plus 图标
- `axios` - HTTP 请求库
- `echarts` - 数据可视化库

### 开发依赖

- `vite` - 构建工具
- `typescript` - TypeScript 支持
- `vue-tsc` - Vue TypeScript 类型检查
- `@vitejs/plugin-vue` - Vite Vue 插件
- `less` - Less 预处理器
- `unplugin-auto-import` - 自动导入插件
- `unplugin-vue-components` - 组件自动导入插件
