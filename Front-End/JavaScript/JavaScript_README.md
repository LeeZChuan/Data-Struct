# JavaScript
## 《JavaScript 高级程序设计（第4版）》



### JavaScript与ECMAScript的关系

        完整的JavaScript实现包含以下几个部分
        1. 核心（ECMAScript）
        2. 文档对象模型（DOM）
        3. 浏览器对象模型（BOM）


### ECMAScript(ECMA-262)

* 对于ECMAScript面试常常叫做ES他有很多版本（ES5/ES6/ES7/ES8/ES9/ES10）


![ES6](/Picture/JavaScript/ES6.jpeg)


* 在书中曾这样写道“。Web浏览器只是ECMAScript实现可能存在的一种宿主环境（host environment）。宿主环境提供ECMAScript的基准实现和与环境自身交
互必需的扩展。”
*  ECMA-262到底定义了什么？在基本的层面，它描述这门语言的如下部分：
    1. 语法
    2. 类型
    3. 语句
    4. 关键字
    5. 保留字
    6. 操作符
    7. 全局对象

###  🗒️面试里面常考的问题：

>  ECMA-262第6版，俗称ES6、ES2015或ES Harmony（和谐版），于2015年6月发布。这一版包含了大概这个规范有史以来最重要的一批增强特性。ES6正式支持了类、模块、迭代器、生成器、箭头函数、期约、反射、代理和众多新的数据类型（后面会讲到这些更新的有何作用有何需要学习的地方）。

> ECMA-262第7版，也称为ES7或ES2016，于2016年6月发布。这次修订只包含少量语法层面的增强，如Array.prototype.includes 和指数操作符。

> ECMA-262第8版，也称为ES8、ES2017，完成于2017年6月。这一版主要增加了异步函数（async/await）、SharedArrayBuffer 及Atomics API，以及Object.values() / Object.entries() / Object.getOwnPropertyDescriptors() 和字符串填充方法，另外明确支持对象字面量最后的逗号。

> ECMA-262第9版，也称为ES9、ES2018，发布于2018年6月。这次修订包括异步迭代、剩余和扩展属性、一组新的正则表达式特性、 Promise finally() ，以及模板字面量修订。

> ECMA-262第10版，也称为ES10、ES2019，发布于2019年6月。这次修订增加了
Array.prototype.flat() / flatMap() 、String.prototype.trimStart() / trimEnd() 、Object.fromEntries() 方法，以及Symbol.prototype.description 属性，明确定义了Function.prototype.toString() 的返回值并固定了Array.prototype.sort() 的顺序。另外，这次修订解决了与JSON字符串兼容的问题，并定义了 catch 子句的可选绑定。

![ES6](/Picture/JavaScript/ES6Deleopment.png)

### DOM

    文档对象模型（DOM，Document Object Model）是一个应用编程接口（API），用于在HTML中使用扩展的XML。DOM将整个页面抽象为一组分层节点。HTML或XML页面的每个组成部分都是一种节点，包含不同的数据。比如下面的HTML页面：

####  其他DOM

* 除了DOM Core和DOM HTML接口，有些其他语言也发布了自己
的DOM标准。下面列出的语言是基于XML的，每一种都增加了
该语言独有的DOM方法和接口：
可伸缩矢量图（SVG，Scalable Vector Graphics）
数学标记语言（MathML，Mathematical Markup Language）
同步多媒体集成语言（SMIL，Synchronized Multimedia
Integration Language）


### BOM
使用BOM，开发者可以操控浏览
器显示页面之外的部分。而BOM真正独一无二的地方，当然也是问题
最多的地方，就是它是唯一一个没有相关标准的JavaScript实现。
HTML5改变了这个局面，这个版本的HTML以正式规范的形式涵盖了
尽可能多的BOM特性。由于HTML5的出现，之前很多与BOM有关的
问题都迎刃而解了。
总体来说，BOM主要针对浏览器窗口和子窗口（frame），不过
人们通常会把任何特定于浏览器的扩展都归在BOM的范畴内。比如，
下面就是这样一些扩展：

* 弹出新浏览器窗口的能力；
* 移动、缩放和关闭浏览器窗口的能力；
* navigator 对象，提供关于浏览器的详尽信息；
* location 对象，提供浏览器加载页面的详尽信息；
* screen 对象，提供关于用户屏幕分辨率的详尽信息；
* performance 对象，提供浏览器内存占用、导航行为和时间统
计的详尽信息；
* 对cookie的支持；
* 其他自定义对象，如 XMLHttpRequest 和IE的
ActiveXObject 。

[详细介绍]()

## 总结：

JavaScript是一门用来与网页交互的脚本语言，包含以下三个组成
部分。
ECMAScript：由ECMA-262定义并提供核心功能。
文档对象模型（DOM）：提供与网页内容交互的方法和接口。
浏览器对象模型（BOM）：提供与浏览器交互的方法和接口。









 

