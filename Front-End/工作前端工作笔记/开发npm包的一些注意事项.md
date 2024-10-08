在前端开发中，经常会`npm install`社区的包，有时候也会想要自己编写一些包，提供给别人使用。

本文整理了开发一个npm包的大概流程，以及其中的一些注意事项，包括环境搭建、构建目标、调试、构建和发布等流程。

## 项目及开发环境[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E9%A1%B9%E7%9B%AE%E5%8F%8A%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83)

先创建一个目录，以及初始的`package.json`文件

```
mkdir tools
cd tools
npm init -y
```

然后你就会得到一个最基础的项目

json

```
{
  "name": "tools",
  "version": "1.0.0",
  "description": "",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [],
  "author": "",
  "license": "ISC"
}
```

记得选一个好名字，npm使用字符串作为包的名字，因此确保你选择的包名是唯一的，不会与现有的包发生冲突。

你可以在npm官方网站上搜索你打算使用的包名，以确保它还没有被使用。最简单的方式是使用命名空间，即`@xxx/packagename`形式的包。

这个包作为一个完整的项目工程，并且会托管在开源仓库中，因此也需要具备基础的代码质量和检测工具，方便使用者可以直接阅读项目源码。

相关的`ESLint`、`prettier`、`husky`、`git commitizen`与个人编程习惯、代码质量相关工具的使用，读者可以自行查阅相关文档。

## 开发模块[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%BC%80%E5%8F%91%E6%A8%A1%E5%9D%97)

一个npm包往往实现了某个特定的功能，使用者安装包并进行一系列开发之后，最终代码会运行在NodeJS或者浏览器上。

不同的使用者可能使用了不同的模块系统，这决定了我们编写的包如何被开发使用。

因此作为包的作者，我们需要理解JavaScript常用的几种模块规范。

### ESM还是CJS[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#esm%E8%BF%98%E6%98%AFcjs)

参考：

- [NodeJS中CommonJS和ESModule混用的问题](https://www.shymean.com/article/NodeJS%E4%B8%ADCommonJS%E5%92%8CESModule%E6%B7%B7%E7%94%A8%E7%9A%84%E9%97%AE%E9%A2%98)

**UMD**

UMD（Universal Module Definition）用于同时支持浏览器环境和Node.js环境的情况，以及在不同的模块规范之间进行兼容性处理

UMD模块规范兼容了CommonJS和AMD（异步模块定义）的语法，以及全局变量的导出方式，可以在不同的环境中使用

**IIFE**

IIFE（Immediately Invoked Function Expression）使用立即执行的函数表达式将模块代码封装在函数作用域内，防止变量冲突和全局污染。通过全局变量或参数传递来导出模块。

适用于老旧浏览器或不支持模块系统的环境，以及一些独立的库或插件。

**CJS**

CommonJS使用`require()`和`module.exports`（或`exports`）语法进行模块导入和导出。在Node.js中是同步加载模块的，适用于服务器端和命令行应用。

主要用于Node.js环境，也可在一些构建工具（如Webpack、Browserify）中使用

**ESM**

ESM（ES Modules）适用于现代浏览器和支持ES模块的环境，也可以在Node.js中使用（需要开启配置）

使用`import`和`export`语法进行模块导入和导出。支持静态分析和按需加载，可以实现更好的模块封装和代码优化。

借助静态分析的特性，esm模块还可以实现`tree shaking`的功能，将未被使用的依赖自动移除，优化构建速度和产物体积。

由于ESM是JavaScript语言实现的模块规范，**建议大家都是用ESM开发新的包**。

通过将`package.json`的`type`声明为`module`，将项目设置为ESM模块。

在构建环节会进一步讲解关于模块的知识。

### 入口文件main、module和exports[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%85%A5%E5%8F%A3%E6%96%87%E4%BB%B6main%E3%80%81module%E5%92%8Cexports)

每个模块都会有一个`入口文件`，这样才能通过`import x from 'xxx'`的方式引入模块

可以通过`main`、`module`、`exports`等`package.json`中的字段声明入口文件，他们各自有一些区别。

`main`字段指向库文件的入口，如果项目是ESM的，则main需要指向一个ESM文件；否则需要指向一个CJS文件

`module`字段就有点特殊了。参考：[package.json 中的 Module 字段是干嘛的](https://segmentfault.com/a/1190000014286439)

在早期，npm包基本是基于`CJS`规范的；在ES6中，JavaScript增加了ESM模块，一些打包器如[rollup](https://www.rollupjs.com/)开始利用ESM的特性，提高打包效率，并且可以实现`Tree shaking`优化构建。

同时为了兼容历史的生态中大量的CJS模块，按照约定，新增了一个`module`字段，打包器如`rollup`、`webpack`等会根据该字段查找ESM模块入口。

需要注意的是，NodeJS不会识别该字段，如果是一个为NodeJS提供的ESM模块，可以直接在main中指定（前提是`type`为`module`）。

如果一个npm包既支持CJS，也支持ESM，那么也被称作`Dual CommonJS/ES module packages`，参考：[Nodejs官方文档](https://nodejs.org/api/packages.html#dual-commonjses-module-packages)。

可以通过[conditional-exports](https://nodejs.org/api/packages.html#conditional-exports)显式声明ESM和CJS的入口文件，配置的字段为`exports`

json

```
{
  "type": "module",
  "exports": {
    "import": "./index.mjs",
    "require": "./index.cjs"
  }
}
```

`exports`的优先级会高于`main`和`module`字段。

### 提供按需加载[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E6%8F%90%E4%BE%9B%E6%8C%89%E9%9C%80%E5%8A%A0%E8%BD%BD)

按需加载时使用方的目标，更准确的说法应该是是“按需导出”？

比如你开发的是一个组件库，提供了很多功能齐全的组件。但用户当前可能只需要使用其中的一个或几个组件，如果将整个组件库都需要引入，显然是不太划算的。

主流的组件库`antd`、`element-ui`都提供了按需加载的`babel`插件，可以将下面形式的`import`代码

js

```
import { ElButton } from 'element-plus'
```

自动转换成

js

```
import ElButton from 'element-plus/es/components/button'
import 'element-plus/es/components/button/style/css'
```

如何编写按需加载的babel插件并不在本文讨论的范围内（实际上也比较简单，组件的目录格式是约定好的，只需要通过babel提供的AST做一下字符串拼接即可）。

这里主要探讨一下`element-plus/es/components/button`这种引入某个路径（而不是单纯的包名），也可以通过`exports`字段进行约束

json

```
"exports": {
 	"./es/*": {
    "types": [
      "./es/*.d.ts",
      "./es/*/index.d.ts"
    ],
    "import": "./es/*.mjs"
  },
}
```

如果配置了exports字段，只有在exports暴露出去的文件，才可以被显式import。

## 调试[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E8%B0%83%E8%AF%95)

在开发包时，往往需要边开发边调试。

如果是一个独立的模块，包里面一般会放一些examples之类的目录，然后通过相对路径引入包里面的模块文件进行调试。

如果这个包是从某个项目里面抽离出来的，则需要跨目录进行调试，这种场景比较常见，这里要说的调试也主要指这种场景。

### 单元测试[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%8D%95%E5%85%83%E6%B5%8B%E8%AF%95)

你编写的包可能会被很多人使用，因此需要保证包的功能是经过严格测试的，每个功能都有足够的测试覆盖率。

关于单元测试，也是一个比较大的板块，这里不单独展开。

### npm link[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#npm-link)

使用npm link命令，将npm 模块链接到对应的运行项目中去，方便地对模块进行调试和测试。

首先切换到模块目录，进行全局link，实际上会

```
cd test_mod

npm link
# 实际输出
# ~/.nvm/versions/node/v12.14.0/lib/node_modules/test_mod -> ~/test/test_mod
```

然后切换到业务项目目录，从全局模块中进行link

```
cd test
npm link test_mod

# 实际链接
# ~/test/node_modules/test_mod -> ~/.nvm/versions/node/v12.14.0/lib/node_modules/test_mod -> ~/test/test_mod
```

然后就可以在不安装`npm i test_mod`的情况下使用`test_mod`模块了，通过link可以很方便的再开发阶段进行调试。

### yalc[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#yalc)

但在实践过程中，我发现`npm link`貌似并不是一个很好的方案

- 受到不同node 版本的影响
- link的包太多容易混乱，不太容易调试link多包的场景
- 文件软链接影响node_modules依赖查询

在搜索时发现了一个新的工具[yalc](https://github.com/wclr/yalc)，yalc可以模拟npm包的发布，看了一下其原理大概是在将包发布到本地存储，然后npm、yarn等包管理工具就可以直接从本地存储中下载过来，可以达到快速调试本地包的目的

全局安装

```
npm i yalc -g
```

发布本地包mod1

```
yalc publish
```

在本地项目中使用依赖

```
yalc add mod1
```

改动mod1之后提交更新

```
yalc push
```

会触发本地项目的自动更新，甚至触发项目的HMR。

看起来就像是将包发布到了一个本地的虚拟仓库，然后在项目目录下从这个虚拟仓库安装了该文件。

与`npm link`相比，唯一的工作量是多了`yalc push`这一步，但可以把本地包当做是真实的包一样，体验还是不错的。

### monorepo[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#monorepo)

另外一种解决包在开发过程中不好调试的方案是使用monorepo，在同一个仓库中管理多个package。

目前主流的monorepo方案有`yarn workspace`、`pnpm monorepo`等，比较大型的项目如`Vue`、`vite`等都采用了`pnpm monoreo`的形式组织各个模块。

关于monorepo的架构，是另外一个比较大的话题，这里不展开具体的实现。

## 构建[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E6%9E%84%E5%BB%BA)

构建工具包和构建业务代码的最大区别是：对应构建产物的目标对象不同。

对于业务代码而言，构建产物是直接部署到服务器上并让浏览器直接访问的，资源文件会直接通过`script`引用

html

```
  <script src='https://xxx.cdn.com/fe/index-abcdef.js'></script>
```

因此打包出来的代码一般是IIFE的

js

```
(function(e){
  // ...
})({'1':xx,'2':xx,...})
```

当然，随着现代浏览器对es module规范的逐渐支持，有的打包工具也支持直接打包浏览器规范的esmodule产物

js

```
import {xxx} from './vendor-ea058dad.js'
...
```

也就是说，业务代码的构建产物是面向浏览器的；当然也有单纯在NodeJS中运行的包。

对于工具包而言，构建产物主要是发布到npm仓库，供第三方通过`npm install`的方式安装到`node_modules`中，比如

ts

```
import {ref} from 'vue'
```

也就是说，工具包的构建产物是面向开发者的。

这里有个隐含的使用顺序：先有npm包，其他开发者才能使用它。而作为包的作者，在创建这个包的时候，我们无法预知这个包会在什么环境下使用。

所以，构建工具包，就需要从第三方开发者的角度考虑以下几个问题

- 使用的模块规范是什么，esm、commonjs、umd还是iffe
- 使用的语言是什么，typescript还是javascript，是否需要类型提示
- 项目是运行在浏览器还是Node环境下的，是否需要支持同构（可以同时在NodeJS和浏览器中运行）
- 代码是否已经完全构建，这个问题在下面这个章节单独讲解。

### 是否需要构建[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E6%98%AF%E5%90%A6%E9%9C%80%E8%A6%81%E6%9E%84%E5%BB%BA)

某些构建工具（如`vue-cli`中的`babel-loader`）默认会忽略所有 `node_modules` 中的文件以加快构建速度。

如果依赖的包（在`node_modules`中）本身是ES6代码的话，就可能导致最终的构建产物包含`es6`的代码，从而出现一些不兼容的代码。

随着而来的问题就是：我们是否需要对包中的代码进行构建？

这里指的构建是：通过babel等工具将JS代码转成对应版本以及压缩代码等工作

#### 压缩代码[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%8E%8B%E7%BC%A9%E4%BB%A3%E7%A0%81)

Npm包的主要用户是开发者，在开发过程中，保持代码的可读性是很重要的，这有利于开发者通过阅读源码了解包里面的具体工作机制，并在出现问题的时候更容易调试。

另外一种观点是：压缩包可以减少整个包的体积，npm下载会更快。由于npm install是一个很低频的事件，这个下载速度相较于上面的代码可读性来说是微不足道的。

#### babel编译[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#babel%E7%BC%96%E8%AF%91)

npm包是否需要像业务代码那样进行babel编译呢？

因为运行在NodeJS端的用户代码一般是不需要打包的，如果我们提供的包也是单纯运行在NodeJS，那么一般不需要打包，只需要指定`engines`字段的node版本。

js

```
{
    "engines": { "node": ">=16.0" }
}
```

如果这个包只需要提供ESM的模块，且代码本身使用的就是ES6的版本，那么就完全不需要打包，因为ESM模块本身就需要ES6才能支持（如果使用了新的JavaScript语言特性，就需要考虑兼容和构建问题），这种情况下，只需要简单的将main字段指向入口文件即可。

如果目标代码是要运行在浏览器端的，或者要提供多种模块，那就需要提供编译后的版本。

#### 构建dev和prod两个版本[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E6%9E%84%E5%BB%BAdev%E5%92%8Cprod%E4%B8%A4%E4%B8%AA%E7%89%88%E6%9C%AC)

参考：

- [关于package.json中main字段的指向问题](https://jingsam.github.io/2018/03/12/npm-main.html)

有些库的开发者，会构建dev和prod两个不同的版本，

- 在dev版本，会包含更友好的错误提示、不压缩代码等功能，使用者在开发阶段可以轻松阅读和调试
- 在production版本，会包含完整的代码压缩、babel编译，使用者的业务代码构建效率更高

js

```
'use strict'

if (process.env.NODE_ENV === 'production') {
  module.exports = require('./dist/reactivity.cjs.prod.js')
} else {
  module.exports = require('./dist/reactivity.cjs.js')
}
```

这种显然是对使用者更友好的做法。

### 声明构建目标[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%A3%B0%E6%98%8E%E6%9E%84%E5%BB%BA%E7%9B%AE%E6%A0%87)

目前，ESM已经成为现代前端开发的主流模块规范，因此对于一个工具包而言，必须要支持esm的构建产物

此外，由于还有大量项目运行在不支持esm的Node版本（NodeJS V13以下），因此，CommonJS的构建产物也需要实现。

由于前端工程化的推荐，直接运行在浏览器端的模块加载器`requirejs`、`seajs`等已经逐步淘汰、因此已经不太需要再构建umd类型的模块了。

至于IIFE，除了需要直接提供一整个文件，然后直接通过`script`标签引入的场景（快速创建一个html文件写demo）之外，也已经不太需要了。

得到了我们的构建目标，还需要再`package.json`中进行声明

- `main`: 用于CommonJS规范的入口文件，
- `module`: 用于ESM规范的入口文件，该字段会被rollup、webpack等识别，方便借助ESM的静态分析进行tree shaking

json

```
"main": "dist/xxx.cjs.js",
"module": "dist/xxx.esm.js",
```

当第三方开发者的引用这个包的时候，就会根据工具或者环境自动加载`main`或者`module`入口文件的内容。

如果包里面提供了多个入口文件，可以配置`exports`字段，参考上面提到的[conditional-exports](https://nodejs.org/api/packages.html#conditional-exports)。

### 类型提示types[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E7%B1%BB%E5%9E%8B%E6%8F%90%E7%A4%BAtypes)

参考：[TS官方文档](https://www.typescriptlang.org/docs/handbook/declaration-files/publishing.html)

对于使用TypeScript编写的模块而言，可以通过`types`或`typings`字段指定整个模块的入口文件。

即使开发的是纯javascript项目，我们也更希望有一些智能的提示，来获得更好的代码体验。

因此，不论第三方开发者是否需要，一个工具包都应该尽量提供类型声明

typescript

```
npm i typescript -D
```

然后在项目根目录创建基础的`tsconfig.json`配置文件

json

```
{
  "compilerOptions": {
    "module": "esnext",
    "strict": true,
    "declaration": true, // 需要输出声明文件
  },
  "include": ["src"]
}
```

TypeScript本身提供了编译器（tsc）可以将TypeScript代码编译为JavaScript代码，如项目没有使用其他的本地模块文件，可以简单地使用tsc完成构建

json

```
"build:esm": "npx tsc -m es2015 --outDir dist/esm",
"build:cjs": "npx tsc -m commonjs --outDir dist/cjs",
"build:umd": "npx tsc -m umd --outDir dist/umd"
```

得到声明文件之后，也需要在`package.json`中声明`types`，该字段指定了TypeScript声明文件（.d.ts）的路径。当其他开发者使用你的模块时，TypeScript编译器将使用types字段指定的声明文件提供类型检查和自动补全的支持。

json

```
"types": "dist/xxx.d.ts"
```

但如果文件中使用了本地模块文件，如`import mod from './xxx'`这种形式，由于tsc的模块系统不会处理模块声明符，通过tsc构建出来的代码，在不同的模块系统下可能会有错误。

因此，建议ts模块包，除了非常简单的单文件模块，都建议使用其他构建工具如`rollup`或者`tsup`来将ts代码构建成目标js代码，然后声明导出文件。

### 构建工具[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E6%9E%84%E5%BB%BA%E5%B7%A5%E5%85%B7)

#### 使用rollup构建[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E4%BD%BF%E7%94%A8rollup%E6%9E%84%E5%BB%BA)

确认了构建目标之后，还需要选择合适的工具将源代码打包成符合要求的输出文件。

目前比较主流的还是`webpack`打包业务产物、`rollup`打包工具包，因此下面简单介绍一下rollup的使用

首先安装`rollup`

```
npm i rollup -D
```

编写配置文件`rollup.config.js`，类似于下面的配置

js

```
export default {
  input: 'src/index.js', // 输入文件路径
  output: [
    {
      file: 'dist/xxx.cjs.js', // 输出文件路径
      format: 'cjs', // 输出模块的格式，例如：'cjs', 'es', 'umd'
    }
     {
      file: 'dist/xxx.esm.js',
      format: 'es',
    }
  ],
  plugins: [
    // 插件配置，例如babel、commonjs等
  ]
};
```

然后就可以通过`rollup -c`命令进行构建，在实际开发中，还需要根据需求进行各种配置和插件的使用，这里不在赘述。

#### 使用tsup构建[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E4%BD%BF%E7%94%A8tsup%E6%9E%84%E5%BB%BA)

tsup基于`esbuild`进行构建，速度很快，且需要的配置和插件很少

```
npm i tsup -D
```

编写配置文件`tsup.config.js`

js

```
import { defineConfig } from 'tsup'

export default defineConfig({
  entry: ['src/index.ts'],
  format: ['cjs', 'esm'],
  splitting: false,
  sourcemap: false,
  clean: true,
  dts: true,
})
```

执行命令`tsup`，即可将构建产物输出在`dist`目录下。

由于tsup可以满足开箱即用，相较于rollup，目前我比较喜欢使用它来完成小型的npm包的构建。

rollup的配置项和可定制化程度比较高，所以被Vue等大型开源项目所采用。

### 外部依赖peerDependencies[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%A4%96%E9%83%A8%E4%BE%9D%E8%B5%96peerdependencies)

业务代码可以依赖第三方包、我们开发的工具包当然也可以依赖第三方包，这也是npm生态繁荣的一大理由。

但是在打包的时候，我们不应该将第三方包的代码一起构建，下面将阐述具体的原因

首先是版本冲突的问题，比如业务项目依赖了Vue、你的工具包也依赖了Vue版本，如果工具包打包了一份版本不同的Vue，就会导致不可预期的错误和行为，用户也很难来解决一个项目里面有多个不同版本的包的问题，最终的结果只能是将这个冲突的包移除依赖列表（然后加入黑名单

其次，包的大小也是决定用户是否愿意安装这个包的原因之一，过大的包会占据更多的下载时间和磁盘空间，以及最终打包的业务代码体积变大。

因此，在打包时不应该讲第三方包的代码一起进行构建，要达到这个目的，可以配置`rollup.config.js`中的`external`选项

js

```
export default {
  input: 'src/index.js', // 输入文件路径
  output: [],
  external: ['vue', 'vue-router'], // 外部依赖的列表
};
```

这样，在引入外部依赖的地方，还是会保留

js

```
import Vue from 'vue'
```

类似的代码，而不会替换成vue整个项目的代码。

在业务代码安装工具包时，会安装工具包`package.json`中声明的依赖列表，然后工具包就可以从node_modules自动找到对应的包，换言之，我们将工具包依赖的交给了业务方。

这会带来一个新的问题：如何保证业务方按照到工具包期望的依赖版本呢？比如业务方安装的是React14版本，而工具包只能在React16版本下工作时，强行安装就会导致node_modules里面出现两个不同大版本的Vue。

这个可以通过`package.json`中的`peerDependencies`指定包的对等依赖项来实现，即该包的用户也应该安装的其他包来声明你的包对于业务环境所需的依赖关系，帮助用户了解并安装正确的依赖版本，以确保你的包与宿主环境协同工作。

1. 首先通过在package.json中使用peerDependencies字段，你可以明确告知用户在使用你的包时需要安装的特定依赖项及其版本范围。
2. 当用户安装你的包时，npm会检查宿主环境中已安装的依赖，如果发现与你声明的peerDependencies存在版本冲突，npm会提醒用户解决这些冲突，以确保正确的依赖版本被安装。

json

```
{
  "name": "xxx",
  "version": "1.0.0",
  "peerDependencies": {
    "react": "^16.0.0",
    "react-dom": "^16.0.0"
  }
}
```

## 发布[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%8F%91%E5%B8%83)

包开发构建完毕后，还需要做一些事情

- 根据[semver](https://semver.org/lang/zh-CN/)原则，修改版本号，尽量严格遵循semver，避免用户在升级过程中出现严重的兼容问题
- 更新使用文档和说明

所有事情完成之后，就可以将包发布到npm仓库供大家使用了。

### 声明要提交的文件[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%A3%B0%E6%98%8E%E8%A6%81%E6%8F%90%E4%BA%A4%E7%9A%84%E6%96%87%E4%BB%B6)

一个npm包，实际上只需要包含必要的模块文件，像源代码、node_modules等文件都不需要提交，这样可以减少包的体积。

可以通过在`files`字段中，显式声明整个npm包要包含的文件，一般都是包含构建文件夹如`dist`即可，`package.json`和`README.md`会自动包含，不需要单独声明。

有些黑产行业，利用npm的公共存储资源来托管盗版的影视资料，这种行为非常可恨！遇见了可以举报。

在默认情况下，通过`npm publish`会将包发布到[npm](https://www.npmjs.com/)官方仓库上，如果是首次可能还需要填写账号密码登录。

如果出于某些原因，我们并不能将业务公共模块直接发布到npm官方源仓库里面（比如公司的私有模块），可以通过搭建私有npm仓库解决这个问题。

### 私有服务器[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E7%A7%81%E6%9C%89%E6%9C%8D%E5%8A%A1%E5%99%A8)

参考

- [使用verdaccio搭建npm私有仓库](https://juejin.im/entry/5c64db9851882562851b328f)
- [npm私服搭建—verdaccio方案及其最佳实践](https://www.jianshu.com/p/d32ce7e9d4d8)

下面介绍使用[verdaccio](https://www.npmjs.com/package/verdaccio)快速搭建**本地**npm私有服务器。

bash

```
# 全局安装
npm i verdaccio -g 
# 启动服务
verdaccio
# 如果希望开启守护经常，可以使用pm2 
pm2 start verdaccio
```

然后就可以输入`http://localhost:4873`访问本地的npm服务了。

如果需要在多个npm源直接切换时，建议使用[nrm](https://www.npmjs.com/package/nrm)。

bash

```
nrm add local http://localhost:4873
nrm use local
```

在发布的时候，通过`registry`命令指定要发布的仓库地址，当然也可以通过`confit set`全局设置。

bash

```
npm publish --registry http://localhost:4873
```

`verdaccio`默认配置文件位于 `~/.config/verdaccio/config.yaml`，具体的配置字段可以查阅相关文档。

如果是公司级别搭建的npm私有服务器，一般会采用`Docker`进行部署。

此外各大云服务商业提供了诸如**制品仓库**之类的系统，相当于在云服务器上面部署一个npm私有仓库，类似的还是Java的maven仓库。

如果是在云服务器上面的仓库，也可以在发包的时候指定对应的`registry`，然后进行发布。

### monorepo发布多个package[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#monorepo%E5%8F%91%E5%B8%83%E5%A4%9A%E4%B8%AApackage)

前面提到了monorepo的架构，在monorepo中，一个git仓库包含了多个package

- 在项目中按照目录设计和管理模块，所有模块公用同一个git仓库和issue列表
- 每个模块包含独立的`package.json`和`node_modules`
- 每个模块包含独立的版本号和`npm publish`操作

但是当模块逐渐增多时，就会出现下面几个问题

- 本地开发调试时，可能需要频繁的`npm link`
- 每个模块都包含一些如`babel`、`webpack`等公共的依赖，会导致同步开发环境带来的额外开销
- 某些模块从功能上来说是有一定关联的，但是从模块上来说应该是独立的，如开发一个类React库，我们可能需要配套实现`ReactRouter`、`ReactRedux`等模块

关于这个问题，社区提供了很多解决方案，之前比较主流的工具有

- [Lerna](https://lerna.js.org/docs/getting-started)，这个是一个monorepo管理工具，同时也可以管理包的发布流程

还有一些主流的项目，如Vue，是通过`pnpm publish`+ 编写的NodeJS脚本来编写的`release`脚本，满足自己高度定制化的发布流程，可以参考一下。

## 其他[​](https://www.shymean.com/article/%E5%BC%80%E5%8F%91npm%E5%8C%85%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9#%E5%85%B6%E4%BB%96)

此外还有一些需要注意的点，比如

- 不要在包中编写具有副作用的代码，
    - 一是ESM模块无法进行tree shaking、
    - 二是副作用的代码往往无法考虑全部的边界情况，如SSR需要这个包同时运行在浏览器和Node中，如果依赖了端特定的接口，就会出问题。更好的处理办法是将副作用的代码封装在初始化函数中、或者提供相关的
- 覆盖率足够的测试用例
- 及时更新的文档

实际上要学习如何编写一个npm包，最好的做法是直接参考社区各种包的工程源码，了解他们的最佳实践。
