## 介绍
Webpack 是一个用于现代 JavaScript 应用程序的 静态模块打包工具。当 webpack 处理应用程序时，它会在内部从一个或多个入口点构建一个 依赖图(dependency graph)，然后将你项目中所需的每一个模块组合成一个或多个 bundles，它们均为静态资源，用于展示你的内容。


![在线链接](https://juejin.cn/post/7067051380803895310)

## webpack的作用

1. 代码分割
2. 文件压缩和合并
3. 编译兼容
4. 模块合并
5. 高级语法翻译（babel）
6. 按需加载
7. 代码验证
8. 自动刷新（热更新）
   
> 我们可以使用loader和plugin机制去进一步扩展能力


### loader介绍

> loader 本质上是一个函数，output=loader(input) // input可为工程源文件的字符串，也可是上一个loader转化后的结果；
> 第一个 loader 的传入参数只有一个：资源文件(resource file)的内容；

>loader支持链式调用，webpack打包时是按照数组从后往前的顺序将资源交给loader处理的。

>支持同步或异步函数。

```js
// source：资源输入，对于第一个执行的 loader 为资源文件的内容；后续执行的 loader 则为前一个 loader 的执行结果
// sourceMap: 可选参数，代码的 sourcemap 结构
// data: 可选参数，其它需要在 Loader 链中传递的信息，比如 posthtml/posthtml-loader 就会通过这个参数传递参数的 AST 对象
const loaderUtils = require('loader-utils');

module.exports = function(source, sourceMap?, data?) {
  // 获取到用户给当前 Loader 传入的 options
  const options = loaderUtils.getOptions(this);
  // TODO： 此处为转换source的逻辑
  return source;
};
```

### 常用的Loader

1. babel-loader
babel-loader基于babel，用于解析JavaScript文件。babel有丰富的预设和插件，babel的配置可以直接写到options里或者单独写道配置文件里。

Babel是一个Javscript编译器，可以将高级语法(主要是ECMAScript 2015+ )编译成浏览器支持的低版本语法，它可以帮助你用最新版本的Javascript写代码，提高开发效率。


插件和预设的执行顺序：

插件比预设先执行
插件执行顺序是插件数组从前向后执行
预设执行顺序是预设数组从后向前执行

webpack配置项代码：
```js
// webpack.config.js
module: {
  rules: [
    {
      test: /\.m?js$/,
      exclude: /node_modules/,
      use: {
        loader: 'babel-loader',
        options: {
          presets: [
            ['@babel/preset-env', { targets: "defaults" }]
          ],
          plugins: ['@babel/plugin-proposal-class-properties'],
          // 缓存 loader 的执行结果到指定目录，默认为node_modules/.cache/babel-loader，之后的 webpack 构建，将会尝试读取缓存
          cacheDirectory: true,
        }
      }
    }
  ]
}
```

2. ts-loader
为webpack提供的 TypeScript loader，打包编译Typescript

webpack配置项如下：
```js

// webpack.config.json
module.exports = {
  mode: "development",
  devtool: "inline-source-map",
  entry: "./app.ts",
  output: {
    filename: "bundle.js"
  },
  resolve: {
    // Add `.ts` and `.tsx` as a resolvable extension.
    extensions: [".ts", ".tsx", ".js"]
  },
  module: {
    rules: [
      // all files with a `.ts` or `.tsx` extension will be handled by `ts-loader`
      { test: /\.tsx?$/, loader: "ts-loader" }
    ]
  }
};

```

还需要typescript编译器的配置文件tsconfig.json：
```json
{
  "compilerOptions": {
    // 目标语言的版本
    "target": "esnext",
    // 生成代码的模板标准
    "module": "esnext",
    "moduleResolution": "node",
    // 允许编译器编译JS，JSX文件
    "allowJS": true,
    // 允许在JS文件中报错，通常与allowJS一起使用
    "checkJs": true,
    "noEmit": true,
    // 是否生成source map文件
    "sourceMap": true,
    // 指定jsx模式
    "jsx": "react"
  },
  // 编译需要编译的文件或目录
  "include": [
    "src",
    "test"
  ],
  // 编译器需要排除的文件或文件夹
  "exclude": [
    "node_modules",
    "**/*.spec.ts"
  ]
}

```

3. raw-loader:可将文件作为字符串导入
4. file-loader:用于处理文件类型资源，如jpg，png等图片。返回值为publicPath为准

```js
// file.js
import img from './webpack.png';
console.log(img); // 编译后：https://www.tencent.com/webpack_605dc7bf.png
// webpack.config.js
module.exports = {
  module: {
    rules: [
      {
        test: /\.(png|jpe?g|gif)$/i,
        loader: 'file-loader',
        options: {
          name: '[name]_[hash:8].[ext]',
          publicPath: "https://www.tencent.com",
        },
      },
    ],
  },
};

```

5. url-loader: 它与file-loader作用相似，也是处理图片的，只不过url-loader可以设置一个根据图片大小进行不同的操作，如果该图片大小大于指定的大小，则将图片进行打包资源，否则将图片转换为base64字符串合并到js文件里。
6.  svg-sprite-loader
会把引用的 svg文件 塞到一个个 symbol 中，合并成一个大的SVG sprite，使用时则通过 SVG 的 <use> 传入图标 id 后渲染出图标。最后将这个大的 svg 放入 body 中。symbol的id如果不特别指定，就是你的文件名。
该loader可以搭配svgo-loader 一起使用，svgo-loader是svg的优化器，它可以删除和修改SVG元素，折叠内容，移动属性等，具体不展开描述。感兴趣的可以移步 官方介绍。
**用途：可以用来开发统一的图标管理库。 **

8. style-loader
通过注入<style>标签将CSS插入到DOM中
注意：


如果因为某些原因你需要将CSS提取为一个文件(即不要将CSS存储在JS模块中)，此时你需要使用插件 mini-css-extract-plugin(后面的Pugin部分会介绍)；


对于development模式(包括 webpack-dev-server)你可以使用style-loader，因为它是通过<style></style>标签的方式引入CSS的，加载会更快；


不要将 style-loader 和 mini-css-extract-plugin 针对同一个CSS模块一起使用！


代码示例见下文 postcss-loader
9. css-loader
仅处理css的各种加载语法(@import和url()函数等),就像 js 解析 import/require() 一样
代码示例见下文 postcss-loader
10. postcss-loader
PostCSS 是一个允许使用 JS 插件转换样式的工具。 这些插件可以检查（lint）你的 CSS，支持 CSS Variables 和 Mixins， 编译尚未被浏览器广泛支持的先进的 CSS 语法，内联图片，以及其它很多优秀的功能。
PostCSS 在业界被广泛地应用。PostCSS 的 autoprefixer 插件是最流行的 CSS 处理工具之一。
autoprefixer 添加了浏览器前缀，它使用 Can I Use 上面的数据。

11. less-loader
解析less，转换为css

### Plugin简介

>Webpack 就像一条生产线，要经过一系列处理流程后才能将源文件转换成输出结果。 这条生产线上的每个处理流程的职责都是单一的，多个流程之间有存在依赖关系，只有完成当前处理后才能交给下一个流程去处理。 插件就像是一个插入到生产线中的一个功能，在特定的时机对生产线上的资源做处理。




> Webpack 通过 Tapable 来组织这条复杂的生产线。 Webpack 在运行过程中会广播事件，插件只需要监听它所关心的事件，就能加入到这条生产线中，去改变生产线的运作。 Webpack 的事件流机制保证了插件的有序性，使得整个系统扩展性很好。

1. copy-webpack-plugin
将已经存在的单个文件或整个目录复制到构建目录。

2. html-webpack-plugin
基本作用是生成html文件


单页应用可以生成一个html入口，多页应用可以配置多个html-webpack-plugin实例来生成多个页面入口


为html引入外部资源如script、link，将entry配置的相关入口chunk以及mini-css-extract-plugin抽取的css文件插入到基于该插件设置的template文件生成的html文件里面，具体的方式是link插入到head中，script插入到head或body中。

3.  webpack.HotModuleReplacementPlugin
模块热替换插件，除此之外还被称为 HMR。
该功能会在应用程序运行过程中，替换、添加或删除 模块，而无需重新加载整个页面。主要是通过以下几种方式，来显著加快开发速度:


保留在完全重新加载页面期间丢失的应用程序状态。


只更新变更内容，以节省宝贵的开发时间。


在源代码中 CSS/JS 产生修改时，会立刻在浏览器中进行更新，这几乎相当于在浏览器 devtools 直接更改样式。


启动方式有2种：


引入插件webpack.HotModuleReplacementPlugin 并且设置devServer.hot: true


命令行加 --hot参数
