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

### DOM

    文档对象模型（DOM，Document Object Model）是一个应用编程接口（API），用于在HTML中使用扩展的XML。DOM将整个页面抽象为一组分层节点。HTML或XML页面的每个组成部分都是一种节点，包含不同的数据。比如下面的HTML页面：




 

