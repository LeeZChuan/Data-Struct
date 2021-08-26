- [一、JavaScript](#一javascript)
  - [1. 原始值和引用值类型及区别](#1-原始值和引用值类型及区别)
  - [2. 判断数据类型typeof、instanceof、Object.prototype.toString.call()、constructor](#2-判断数据类型typeofinstanceofobjectprototypetostringcallconstructor)
  - [3. 类数组与数组的区别与转换](#3-类数组与数组的区别与转换)
  - [1. 数组的常见API](#1-数组的常见api)
  - [5. bind、call、apply的区别](#5-bindcallapply的区别)
  - [6. new的原理](#6-new的原理)
  - [7. 如何正确判断this？](#7-如何正确判断this)
  - [8. 闭包及其作用](#8-闭包及其作用)
  - [9.  原型和原型链](#9--原型和原型链)
  - [10. prototype与__proto__的关系与区别](#10-prototype与__proto__的关系与区别)
  - [11. 继承的实现方式及比较](#11-继承的实现方式及比较)
  - [12. 深拷贝与浅拷贝](#12-深拷贝与浅拷贝)
  - [13. 防抖和节流](#13-防抖和节流)
  - [14. 作用域和作用域链、执行期上下文](#14-作用域和作用域链执行期上下文)
  - [15. DOM常见的操作方式](#15-dom常见的操作方式)
  - [16. Array.sort()方法与实现机制](#16-arraysort方法与实现机制)
  - [17. Ajax的请求过程](#17-ajax的请求过程)
  - [18. JS的垃圾回收机制](#18-js的垃圾回收机制)
  - [19. JS中的String、Array和Math方法](#19-js中的stringarray和math方法)
  - [20. addEventListener和onClick()的区别](#20-addeventlistener和onclick的区别)
  - [21. new和Object.create的区别](#21-new和objectcreate的区别)
  - [22. DOM的location对象](#22-dom的location对象)
  - [23. 浏览器从输入URL到页面渲染的整个流程（涉及到计算机网络数据传输过程、浏览器解析渲染过程）](#23-浏览器从输入url到页面渲染的整个流程涉及到计算机网络数据传输过程浏览器解析渲染过程)
  - [24.  跨域、同源策略及跨域实现方式和原理](#24--跨域同源策略及跨域实现方式和原理)
  - [25. 浏览器的回流（Reflow）和重绘（Repaints）](#25-浏览器的回流reflow和重绘repaints)
  - [26. JavaScript中的arguments](#26-javascript中的arguments)
  - [27. EventLoop事件循环](#27-eventloop事件循环)
  - [28. 宏任务与微任务](#28-宏任务与微任务)
  - [29. BOM属性对象方法](#29-bom属性对象方法)
  - [30. 函数柯里化及其通用封装](#30-函数柯里化及其通用封装)
  - [31. JS的map()和reduce()方法](#31-js的map和reduce方法)
  - [32. “==”和“===”的区别](#32-和的区别)
  - [33. setTimeout用作倒计时为何会产生误差？](#33-settimeout用作倒计时为何会产生误差)
- [二、ES6](#二es6)
  - [1. let、const和var的概念与区别](#1-letconst和var的概念与区别)
  - [2. 变量提升与暂时性死区](#2-变量提升与暂时性死区)
  - [3. 变量的解构赋值](#3-变量的解构赋值)
  - [4. 箭头函数及其this问题](#4-箭头函数及其this问题)
  - [5. Symbol概念及其作用](#5-symbol概念及其作用)
  - [6. Set、Map、weakset和weakmap数据结构](#6-setmapweakset和weakmap数据结构)
  - [7. Proxy](#7-proxy)
  - [8. Reflect对象](#8-reflect对象)
  - [9.  Promise（手撕Promise A+规范、Promise.all、Promise相关API和方法）](#9--promise手撕promise-a规范promiseallpromise相关api和方法)
  - [10. Iterator和for...of（Iterator遍历器的实现）](#10-iterator和forofiterator遍历器的实现)
  - [11. 循环语法比较及使用场景（for、forEach、for...in、for...of）](#11-循环语法比较及使用场景forforeachforinforof)
  - [12. Generator及其异步方面的应用](#12-generator及其异步方面的应用)
  - [13. async函数](#13-async函数)
  - [14. 几种异步方式的比较（回调、setTimeout、Promise、Generator、async）](#14-几种异步方式的比较回调settimeoutpromisegeneratorasync)
    - [why](#why)
  - [15.   class基本语法及继承](#15---class基本语法及继承)
  - [16.  模块加载方案比较（CommonJS和ES6的Module）](#16--模块加载方案比较commonjs和es6的module)
  - [17.  ES6模块加载与CommonJS加载的原理](#17--es6模块加载与commonjs加载的原理)
- [三、HTML/CSS](#三htmlcss)
  - [1. CSS权重及其引入方式](#1-css权重及其引入方式)
  - [2. <a></a>标签全部作用](#2-标签全部作用)
  - [3. 用CSS画三角形](#3-用css画三角形)
  - [4. 未知宽高元素水平垂直居中（方案及比较）](#4-未知宽高元素水平垂直居中方案及比较)
  - [5. 元素种类的划分](#5-元素种类的划分)
  - [6. 盒子模型及其理解](#6-盒子模型及其理解)
  - [7. 定位方式及其区别（文档流）](#7-定位方式及其区别文档流)
  - [8. margin塌陷及合并问题](#8-margin塌陷及合并问题)
  - [9.  浮动模型及清除浮动的方法](#9--浮动模型及清除浮动的方法)
  - [10. CSS定位属性](#10-css定位属性)
  - [11. display及相关属性](#11-display及相关属性)
  - [12. IFC与BFC](#12-ifc与bfc)
  - [13. 圣杯布局和双飞翼布局的实现](#13-圣杯布局和双飞翼布局的实现)
  - [14. Flex布局](#14-flex布局)
  - [15. px、em、rem的区别](#15-pxemrem的区别)
  - [16. Less预处理语言](#16-less预处理语言)
  - [17. 媒体查询](#17-媒体查询)
  - [18. vh与vw](#18-vh与vw)
  - [19. H5的语义化作用及语义化标签](#19-h5的语义化作用及语义化标签)
  - [20. Web Worker和Web Socket](#20-web-worker和web-socket)
  - [21. CSS3及相关动画](#21-css3及相关动画)
  - [22. 如何实现响应式布局](#22-如何实现响应式布局)
  - [23. SEO的概念及实现](#23-seo的概念及实现)
  - [24. HTML5的新特性](#24-html5的新特性)
  - [25. Less和Sass使用](#25-less和sass使用)
- [四、HTTP与计算机网络](#四http与计算机网络)
  - [1. TCP/IP协议分层管理](#1-tcpip协议分层管理)
  - [2. 三次握手四次挥手机制及原因](#2-三次握手四次挥手机制及原因)
  - [3. HTTP方法](#3-http方法)
  - [4. GET和POST的区别](#4-get和post的区别)
  - [5. HTTP建立持久连接的意义](#5-http建立持久连接的意义)
  - [6. HTTP报文的结构](#6-http报文的结构)
  - [7. HTTP状态码](#7-http状态码)
  - [8. Web服务器及其组成](#8-web服务器及其组成)
  - [9.  HTTP报文首部](#9--http报文首部)
  - [10.  HTTP通用首部字段](#10--http通用首部字段)
  - [11. HTTP请求首部字段、响应首部字段、实体首部字段](#11-http请求首部字段响应首部字段实体首部字段)
  - [12. Cookie相关首部字段](#12-cookie相关首部字段)
  - [13. HTTPS与HTTP区别及实现方式](#13-https与http区别及实现方式)
  - [14. Cookie与Session](#14-cookie与session)
  - [15. 基于HTTP的功能追加协议（SPY、WebSocket、HTTP）](#15-基于http的功能追加协议spywebsockethttp)
  - [16. 常见的Web攻击分类](#16-常见的web攻击分类)
  - [17. TCP与UDP区别](#17-tcp与udp区别)
  - [18.http2.0有了解吗和http1.x进行对比一下](#18http20有了解吗和http1x进行对比一下)
- [五、前端工程化](#五前端工程化)
  - [1. 前端工程化的流程（架构选型、业务开发、测试、打包构建、部署上线、项目监控）](#1-前端工程化的流程架构选型业务开发测试打包构建部署上线项目监控)
  - [2. Webpack基本概念与配置](#2-webpack基本概念与配置)
  - [3. loader与plugin原理与实现](#3-loader与plugin原理与实现)
  - [4. Webpack的模块热替换及实现](#4-webpack的模块热替换及实现)
  - [5. Webpack的优化问题](#5-webpack的优化问题)
  - [6. SPA及其优缺点](#6-spa及其优缺点)
  - [7. SSR实现及优缺点](#7-ssr实现及优缺点)
  - [8. 设计模式（工厂模式、单例模式、原型模式、***模式、适配器模式、观察者模式等...）](#8-设计模式工厂模式单例模式原型模式模式适配器模式观察者模式等)
- [六、React](#六react)
  - [1. React自身特点及选型时考虑](#1-react自身特点及选型时考虑)
  - [2. React与VUE的异同](#2-react与vue的异同)
  - [3. Virtual DOM](#3-virtual-dom)
- [八、需要会手撕的代码部分](#八需要会手撕的代码部分)
  - [6. 防抖和节流](#6-防抖和节流)
  - [11. 三栏布局的实现](#11-三栏布局的实现)
  - [12. 两栏布局的实现](#12-两栏布局的实现)


# 一、JavaScript
## 1. 原始值和引用值类型及区别

在 JavaScript 中数据类型分两种，一类是基本类型的值，另一类是复杂数据类型，基本数据类型包括 7 种：undefined，null，boolean，string,number,bigInt,Symbol,复杂数据类型在 JavaScript 中主要是对象类型，在这之中又包含许多子类型，比如普通对象，数组，函数，Math，正则等等

然后就是存储方式，基本类型一般存的原始值，复杂数据类型一般是引用值，具体的含义就是，原始值的话，当你引用它是值拷贝的方式，一般存储在栈中，引用类型的值引用它时只是引用了一个指向它的内存地址的指针，这个指针存在栈中，这就会导致一个共享内存的问题，当把一个复杂数据类型赋值给另一个变量，由于是将其指针进行了拷贝，所以当修改其中一个对象的，所有值为这个指针的对象都会发生相应的改变

::: tip 关于数据类型这一块，还可以讲讲关于数据类型的判断，类型转换 :::

## 2. 判断数据类型typeof、instanceof、Object.prototype.toString.call()、constructor

typeof 适合用来判断基本数据类型，对于基本类型一般会返回对应的数据类型的字符换，而对于复杂数类型除 function 外一般会返回 Object，用 typeof 判断 function 会返回字符串 function，基本数据类型中 null 是个例外，typeof 判断 null 会返回 object，这是因为 JavaScript 中不同的对象在底层都表示为二进制，当二进制前三位全为 0 时会被判断为 object，null 的二进制表示全 0，自然前三位也是 0，typeof 就会将其判断位 Object，但这不影响 null 是基本数据类型，这只是语言本身的 bug

instanceof 用于检测构造函数的 prototype 属性是否出现在某个实例对象的原型链上，所以这这个操作符的本质就是基于原型链查找，会沿着 left 得原型链查找，若找到了 right 就返回 true，所以 instance 实现的话大致就是在一个循环中不断获取 left 得原型，并检查是否与 right 相等，left 为对象，right 为函数，我们还可以在一个类上自定义 instanceof ，Symbol.hasInstance 用于判断某对象是否为构造器的实例,所以这样就可以在内部使用 typeof 来判断基本数据类型了
```javascript
class Array1 {
  static [Symbol.hasInstance](instance) {
    return typeof instance === "number";
  }
}
console.log(111 instanceof Array1);
```


Object.toString.call(),是调用了 Object 上的 toString 方法，之所以任何数据类型都可以调用该方法是因为，JavaScript 中基本数据类型会先转为包装对象，然后所有对象最终的原型指向都是 Object，所以可以调用 toString 方法，调用该方法后会返回一个[object 数据类型]的字符串，这个方法对基本数据类型和复杂数据类型都有效，这种方法的一个缺点是对于自定义对象总是返回[object Object],所以该方法常用来判断内置对象

constructor 也可以用来判断数据类型，constructor 属性返回创建此对象的数组函数的引用，不能对 null 和 undefined 使用


## 3. 类数组与数组的区别与转换

类数组是指写法上跟数组一样，但不是数组，她的原型是 Object，而数组的原型是 Array

类数组一般有 arguments , HTMLCollection, NodeList

关于 arguments 对象，他是函数的参数对象，通过 Object.prototype.toString.call()返回的结果是[object arguments],这个对象里面有一个 calle 属性可以返回函数本身，该属性从 es5 严格模式删除了

HTMLCollection 是 html dom 对象的一个接口，这个接口包含了获取到的 DOM 元素集合，返回的类型也是类数组对象，随文档中的 dom 变化而变化

NodeList 对象是节点的集合，通常由 querySelect 返回也是一种类数组，虽然不是一个数组但可以用 for of 迭代，也是一个实时集合

关于转换类数组，因为类数组并没有自带一些数组的方法，一般可以使用 call 来借用 Array 原型链上的方法来操作，比如 slice，concat，也可以使用扩展运算符来装换



## 1. 数组的常见API
   
数组常见的 API 大致可以分为三种一种是改变数组自身的方法，然后是不改变数组自身即返回一个新数组的方法，还有就是遍历的方法

改变数组自身的方法有：push,pop,shift,unshift,reverse,splice,fill,copyWithin

不改变数组自身的方法有：slice,concat,join,toString,toLocalString(根据本地时间把 Date 对象转换为字符串),indexof,lastIndexof,includes

遍历方法有：forEach,map,some,eveny,filter,reduce,find,findIndex 还有对象原型上的一些方法 keys,values,entries

::: tip 这一块还有一些 API 的实现：map，splice,pop,push,reduce,filter :::


## 5. bind、call、apply的区别

这三个方法都是在 Function 的原型上的，都用来显示的绑定 this，call 和 reply 可以由函数调用，然后第一个参数传入要绑定的上下文，后面的参数为要传给函数参数，
apply 是将后续的这些参数写入到一个数组然后作为第二个参数，
call 是将这些参数一个一个的作为 call 的后续参数，所以他们两个的区别就是对传入给函数的参数的传入形式不一样，最终的效果是一样的，
而 bind 并不是想刚才哪两个一样直接执行函数，他先进行显示绑定 this，然后返回一个函数，然后可以自由的去调用这个函数，传入给函数参数的形式和 call 一样

## 6. new的原理

当我们执行了一个 new 操作，它内部会执行四个步骤，
一是先创建一个空对象，
第二是将构造函数的作用域赋值给新对象，也就是将 this 指向新对象，通过 Object 的原型上的 create 方法，
第三个是执行构造函数，
第四个是返回这个对象，其中若构造函数又返回一个对象那么就返回这个对象，否则返回前面创建的那个对象

四大步骤：

1、创建一个空对象，并且 this 变量引用该对象，// let target = {};
2、继承了函数的原型。// target.proto = func.prototype;
3、属性和方法被加入到 this 引用的对象中。并执行了该函数func// func.call(target);
4、新创建的对象由 this 所引用，并且最后隐式的返回 this ，如果func.call(target)返回的res是个对象或者function 就返回它

function new(func) {
	let target = {};
	target.__proto__ = func.prototype;
	let res = func.call(target);
	if (typeof(res) == "object" || typeof(res) == "function") {
		return res;
	}
	return target;
}

## 7. 如何正确判断this？

关于 this 有显示绑定和隐式绑定，显示得很好判断，因为自己使用 call,apply,bind 来绑定，隐式的话若不考虑箭头函数那么 this 指向哪是由他在哪运行决定的，也就是 this 指向当前调用它的上下文，如果找不到就指向全局，而箭头函数和他很不一样的一点就是它内部 this 的执行是由他在哪里定义决定的，而不有运行时决定，也可以说她的 this 指向当前离他最近的非箭头函数的 this

举个例子，比如说，在函数里面有一个函数函数内获取 this，如果通过这个对象直接调用这个函数那么这是 this 指向这个对象，而如果把这个对象单独赋值给一个全局变量，这时 this 就指向全局，浏览器里是 window，nodejs 环境下为 global，严格模式选为 undefined

上面说了两种关于运行时决定 this 的指向，还有就是比如全局定义一个函数的，这是函数的 this 指向全局，通过构造函数 new 了一个实例，此时构造函数的 this 指向这个实例，还有比如浏览器中的监听事件 onclick，addEventListen，默认指向绑定的元素，IE 的话比较奇怪，使用 attachEvent 里面的 this 指向 undefined

还有一些比较特殊的情况，就是数组的遍历 API，第一个参数通常为回调函数，第二个参数可以显示绑定 this；还有就是函数中的 this 是不会传递的，比如函数里嵌套函数，外层函数的 this 有运行时所在的上下文决定，这个上下文不会传递给嵌套的函数，最后就是类中的 this 指向，类中的 this 指向类本身，但还是 this 有运行时的上下文决定，若将类中的方法赋值给全局变量，然后在全局进行调用，由于 class 内部默认采用严格模式，所以 this 并不会指向全局而是指向 undefined


## 8. 闭包及其作用

闭包是基于作用域链的，是当前作用域可以访问到父级作用域，针对的是函数，一个嵌套另一个函数，当里面的函数引用了外层函数的变量就形成了当前作用域访问到了父级作用域，此时就形成了闭包，这是嵌套的函数同时保存了当前作用域和父级作用域

产生闭包一般有函数内返回返回另一个函数，函数作为参数进行传递，立即执行函数，比如 js 中经常会在 setTimeout，事件监听中中使用回调函数，这也是闭包，还有 webpack 打包后的结果是一个立即执行函数，这也是闭包

闭包的优点就是可以访问并保存父级作用域，这样就可以形成私有变量，同时由于保存了父级作用域，自然父级作用域就不会被垃圾回收，这样也会产生一个缺点就是，当这种操作很多的话，由于许多父级作用域被引用，并不会被垃圾回收，就会导致内存泄漏

闭包的另一个优点是他可以用来实现模块化，从而避免全局变量的一个污染，因为立即执行函数就为模块提供了私有空间，具体做法就是将每个模块成员都放到一个立即执行函数所形成的私有作用域中，而对于需要暴露给外部的成员，可以挂载到全局对象上，因为立即执行函数保存当前父级也就是全局作用域

还有一种模块的方式就是函数返回一个有许多函数组成的对象，这个模块其实是暴露给了全局

闭包的用途除了刚刚说的私有作用域模块化之外还有，可以实现单例模式，还有比较经典的循环里打印下标

## 9.  原型和原型链

javaScript 是一门基于原型的语言，原型可以分为隐式原型和显式原型，比如我声明一个空对象，这是通过 Object.getPrototypeOf()就可以获取到这个对象的隐式原型，当然也可以直接访问这个对象的proto,但这个不在规范中，官方也不推荐使用，显式原型的就是比如我声明一个构造函数，那么这个构造函数就有 prototype 属性指向这个构造函数的显式原型，我们是可以往这个显示原型的挂在一些方法和属性，这样通过这个构造函数 new 的实例就可以访问到这个原型上的属性，做实例的隐式原型也指向构造函数的显式原型

原型链的话就是，构造函数的原型也拥有自己的原型，同时这个原型也肯有自己的原型，这样当我们在这个构造函数的一个实例上访问一个属性，会先在自身查找，找不到去原型上查找，还找不到去原型的原型上查找，知道找到为止，所有对象的原型都会指向 Object，找到最后没找到就会报找不到的错误，这样就形成了一条原型链，属性和方法也可以基于原型链查找，这也就是为什么 Object.prototype.toString.call()，可以判断基本数据类型和复杂数据类型的原因，所有对象在其原型链上都可找到 Object，自然可以调用该方法，基本数据类型通过 Object()被转为包装对象，自然也可以调用这个方法

原型链的作用一个是属性和方法的查找，还有一个是可以用来实现基于原型链继承

## 10. prototype与__proto__的关系与区别

实例的__proto__,指向构造函数的 prototype,或者说实例的隐式原型指向构造函数的显式原型

区别就是一个针对实例的，一个是针对构造函数的，__proto__不是标准中规范的，可以使用 Object.getProtoType()代替


## 11. 继承的实现方式及比较

继承的实现方式大致有五种：

1. 第一种是通过原型链来实现继承，做法就是在子类的原型上挂载一个父类实例，这样就可以访问到父类的属性和方法，这种继承的问题在于对于引用数据类型内存空间是共享的，一个实例发送改变会引起其他实力也发生改变

2. 第二种是通过构造函数来实现继承，具体做法就是在子类面通过 call，在在子类的上下文中执行父类，这样可以解决内存空间共享的问题，因为每个子类实例都是一个新的内存空间，但这样这样做的缺点是如果父类在原型上有方法，那么子类会继承不了

3. 将上面两种方式结合形成第三种继承方式，组合式集成，但这样带来的问题是父类的的构造函数执行了两次，一次在子类的构造函数中，另一次是在网子类原型上挂在时，造成了一次不必要的开销，一个优化是直接将父类的原型挂载到子类原型上，这样少了一次开销，但同时引入了新的问题，子类的构造函数变成了父类，正常来说应该是子类

4. 第四种是通过对象关联这样一种形式，通过 Object.create()来基于父类的原型创建子类，这叫做原型式继承，这样做的的缺点是内存空间共享问题

使用原型式继承可以获得一份目标对象的浅拷贝，然后利用这个浅拷贝的能力在进行增强就形成了寄生式继承，但依然存在内存空间共享的问题

5. 第五种就是寄生式组合继承，在构函数里调用父类来解决内存空间共享，通过 Objec.create()来会的目标对象的一份浅拷贝，这就是最优的一种继承实现方式，既没有内存空间共享问题，也没有两次调用父类造成不必要开销的问题，并且 es6 中的 class 的 extend 也是基于这种方式实现的继承

关于继承的这几种实现代表了两种设计思想，一种通过继承的设计思想即父类子类这样，另一种是通过行为委托，并没有父子类之说，而是兄弟关系，JavaScript 的原型机制本身也就是行为委托，对象关联可以通过行为委托来实现

## 12. 深拷贝与浅拷贝

看面试记录文档

## 13. 防抖和节流

看面试记录文档

## 14. 作用域和作用域链、执行期上下文

作用域就是可以访问的代码中的变量和函数的范围

作用域链的作用是保证变量和函数的一个有序访问，通过作用域链，我们可以访问到外层的变量和函数，她的本质是一个指向变量对象的变量指针，变量对象包含了执行环境中的所有变量和函数，作用域链的始端指向当前作用域，终端指向全局作用域，当查找一个变量时，会现在当前作用域查找，找不到就沿着作用域链向上查找，作用域链的创建过程和执行上下文有关

执行上下文可以理解成一个对象，这个对象分三部分：变量对象，作用域链，this 指向，类型包含全局上下文，函数上下文和 eval 上下文

执行上下文其实是代码的一个执行环境，一段代码执行过程中，遇到了函数，会将函数上下文依次压入到执行占中，当函数执行完便会将这个函数上线文从执行栈中弹出，

## 15. DOM常见的操作方式

dom 中的操作主要分为添加，删除，移动，复制，创建和查找

创建节点的方式主要有:createDocumentFragMent()创建一个 Dom 片段，createElement()创建一个具体的元素，createTextNode()创建一个文本节点

appendChild()添加操作，removeChild()删除操作,replaceChild()替换操作,insertBefore()插入

查找方法有:getElementById(),getElementByName(),getElementByTagName(),getElemenetByClassName(),querySeletor(),querySleectorAll()

属性操作：getAttribute(key),setAttribute(key, value),hasAttribute(key),removeAttribute()

## 16. Array.sort()方法与实现机制

Array,sort()，在不同的浏览器里底层是用的排序方法是不一样的，以 V8 为例，根据排序的元素个数会采用不同的排序方法：

当n <= 10时，采用差如排序，当 n > 10采用快速排序，当10<n<=1000,使用中位数作为哨兵元素，当n>1000每隔 200-215 个元素，放入到一个新数组中，对他排序，找到中间位置的数，以此作为中位数

元素少是使用插入排序因为插入排序在最好的情况下时间复杂度为 o(n),尽管平均复杂度为 o(n^2),快速排序平均复杂度为 o(nlogn),实际情况下两者的前面都一个系数，对于插入排序，若 n 足够小，速度会超过快排，插入排序在经过优化以后，对于小数据集会有非常优越的性能，所以这是选择插入排序是个不错的选择

快速排序的性能瓶颈在与递归的深度，最坏的情况是每次的哨兵都是最小的元素会最大的元素，在进行 partiton（一边是小于哨兵的元素，一边是大于哨兵的元素）那么就会有一边是空的，这么排下去递归层数就为元素的个数 n，时间复杂度会退化为 o(n^2),通过让哨兵元素尽肯能处于中间位置，减少最大或最小的情况，这就是 v8 对快速排序的一种优化

## 17. Ajax的请求过程

使用 ajax 步骤大概是:

* 创建 XMLHttpRequest 对象，这是一个异步调用对象
* 然后创建一个新的 http 请求的方法，并指定该 HTTP 请求的方法，URL 及验证信息
* 设置响应 http 请求状态变化的函数
* 发送 http 请求
* 获取异步返回的数据
* 使用 JavaScript 和 Dom 实现局部刷新
* 如果是 post 可以通过xhr.setRequestHeader("Content-type","application/x-www-from-urlencoded")设置请求头

关于上面第三部的 http 的请求状态 readState，0 表示未初始化，1 表示服务器已建立连接，2 表示请求已收到，3 表示请求处理中，4 表示请求以完成，且响应已就绪

## 18. JS的垃圾回收机制

js 中数据存储的位置有两种，一种是在栈中，另一种是在堆中，由于栈中的数据量都比较小，所以栈中的垃圾回收由操作系统来完成，js 中的垃圾回收机制只要针对的是堆内存

js 中有两个垃圾回收器，一个是副垃圾回收器，一个是主垃圾回收器，前者负责新生代中的垃圾回收，后者负责老生代中的垃圾回收

新生代中的垃圾回收机制是这样的，他主要回收哪些生命周期比较短的内存对象，所以需要一个效率非常高的算法，这个算法是一个牺牲空间来换取时间的算法，在占用空间不大的场景下非常适用，这个算法将内存分为两部分，一个 from space 一个是 to space，对 from space 中的活动对象进行标记，然后移动到 to space，并将这些对象有序的排列起来，然后将 from space 中的非活动对象进行释放，完成之后交换这两块，使得新生代中的这两块区域可以重复利用

新生代中的对象会通过晋升然后移动到老生代，在新生代中进一步划分了两个子区域，当我们第一次对内存进行分配时会被分配到其中一个子区域中，如果下一次垃圾回收这个对象还在新生代中，则会被移动到另一个子区域中，如果下一次垃圾回收这个对象还在新生代中，则这个对象会被移动到老生代

老生代中不能使用新生代中的垃圾回收算法，因为新生代中的算法为复制算法，重复复制活动对象效率低下，且是牺牲空间换时间的算法，老生带中的支持很大的容量，会出现资源浪费，所以老生代中主要使用标记清除和标记整理的算法

标记清除算法中先对老生代进行一次扫描，标记活动对象，然=然后进行第二次扫描，清理掉这些未被标记的对象，及非活动对象，这样会造成一个问题，被清除的对象遍布于各内存地址，产生了很多碎片，当需要分配一个很大的对象时，这些碎片空间无法完成分配，就会提前触发垃圾回收，而这次垃圾回收是不必要的，因此就有了标记整理的算法，他会将所有活动对象移项一端，然后直接清理掉边界外的内存

上面的垃圾回收当中当标记整理算法在移动活对象时可能对象比较多，她的执行速度不是很快，为了避免 js 的应用逻辑和垃圾回收器的资源竞争导致不一致的问题，这时垃圾回收器会将整个 JavaScript 应用暂停，这个过程叫做全停顿，而在新生代中由于空间小，存活对象较少，新生代的算法效率较快，所以全停顿并不影响，而老生带中活动对象较多，垃圾回收器全停顿的时间较长就会导致页面卡顿

为了解决上面那种卡顿 v8 通过增量标记和惰性清除，以及并发并行来降低主线程的挂在时间

增量标记就是将标记的过程穿插在 JavaScript 应用逻辑之间，允许标记的时间为 5~10ms，增量标记达到一定的阈值时才会启动，启动之后每当一定量的内存分配之后脚本的执行就会停顿进行一次增量标记

惰性清除用来真正释放内存，当增量标记完之后，加入当前的可用内存足以让我们的代码快速执行，其实我们是没有必要进行立即的清理内存的，可以将这个清理的过程延迟一下，让 js 代码先执行，也无需进行一次性的清理完所有非活动对象，垃圾回收器会逐一进行清理，直到所有都清理完毕

虽然增量标记和惰性清除是的主线程的最大停顿时间大大减少，也让用户与浏览器的交互过程流畅许多，但是每个小的标记之间执行了 js 代码堆中的变量的指针的可能发生了变化需要使用写屏障技术来保证这些引用关系的一致性，这就是增量标记的缺点：并没有减少主线程的总暂停时间甚至略微增加，由于写屏障技术机制的成本，增量标记可能会降低应用程序的吞吐量

并行式的 gc 可以使得辅助线程同时执行同样的 gc 工作，让辅助现成来分担主线程 gc 的工作，使得垃圾回收的耗时等于总时间除以参与线程的数量

目前 v8 的垃圾回收机制就是，副垃圾回收器使用并行机制，讲 from space 移动到 to space 时开启多个辅助线程，并行的进行整理，这会导致资源竞争，所以需要在每个对象复制完成后都去维护这个复制这个活动对象后的指针转发地址，以便于其他辅助线程可以找到该活动对象后判断该活动对象是否已被复制；对于主垃圾回收器，当堆中的内存大小超过阈值后，会并发的进行标记任务，每个辅助线程都会去追踪每个标记到的对象以及这个对象的引用，js 代码执行时，并发标记也会在后台的辅助线程中执行，当对象被修改时写入屏障技术会在辅助线程进行并发标记时进行追踪，当标记或动态分配的内存达到极限的时候，主线程会进行最终的快速标记步骤，这个时候主线程会挂起，主线程会再一次进行扫描确保所有对象都完成了标记，由于辅助线程已经标记过了活动对象，这次的扫描只是进行一次 check 操作，确认完成之后，有辅助线程进行内存的整理和清除，由于都是并行的，所以并不会影响主线程的执行

## 19. JS中的String、Array和Math方法

String : split,slice,substr,trim,concat,indexOf ,lastIndexOf

Array:····

Math：有一些常量和一些方法，都是与数学运算有关的

## 20. addEventListener和onClick()的区别

onclick 是 Dom0 的绑定事件的方式，而 addEventLister 是 Dom2 绑定事件的方式，使用 onclick 绑定的事件解绑需要将 onclick 设为 null，而 addEventListener 绑定的事件解绑需要 removeEventListerk 来解绑

onclick 绑定事件有点有：简洁，处理事件 this 指向当前元素，缺点是不能对事件进行捕获和冒泡进行控制，只能使用事件冒泡而不能使用事件捕获，并且一次只能对一个元素绑定一个事件处理程序，当使用 window.onload 时，会覆盖采用相同方法所绑定的事件

addEventListener 的优点就是支持捕获与冒泡，通过最后一个参数来设置，默认值为 false 表示事件冒泡，设置为 true 表示事件捕获，她的 this 和 onclick 一样，事件处理函数中，event 对象总是作为第一个可用参数，可以绑定多个事件而不会发生覆盖，缺点是 ie8 不支持

## 21. new和Object.create的区别

new 操作所做的工作有：

创建一个对象
对新对象进行原型操作，指向构造函数的原型
将 this 绑定到新对象上
如果构造函数返回了一个对象，就返回这个对象，否则返回新对象
object.create 所做的工作有：

该方法有两个参数，第一个参数作为新建对象的原型，第二个参数是一个对象，该对象的属性名称是新创建的对象的属性名称

创建一个新对象
将新对象的__proto__指向传入的参数
将传入的对象属性复制到新对象并返回新对象
从他们的内部所做的工作可以看出 new 是保留了构造函数，而 object.create()没有，原型链方面，new 保留了原构造函数的 prototype 属性，而 object.create 就是原构造函数或对象本身，new 作用的对象只能是函数，而 object.create 可以是函数也可以是对象

## 22. DOM的location对象

window.location 是一个只读属性，返回一个 location 对象，其中包含有文档当前的位置信息，包括 hash，search,host,hostname,href,origin 等等,还有一些方法比如 reload，replace，assign

尽管他是一个只读对象，仍然可以赋值给他一个 DOMString，这意味着可以再大多数情况下处理 location，就像它是一个字符串一样：

window.location = 'http://www.example.com'，是 window.location.href = 'http://www.example.com'的同义词

reload 强制从服务器从新加载当前页面，replace 重新加载页面，assign 使用新的 url 加载页面

## 23. 浏览器从输入URL到页面渲染的整个流程（涉及到计算机网络数据传输过程、浏览器解析渲染过程）


首先，我们假设输入的url的请求为最简单的Http请求，以GET请求为例，大致分以下几个步骤：

1. 用户在浏览器的地址栏输入访问的URL地址。浏览器会先根据这个URL查看浏览器缓存-系统缓存-路由器缓存，若缓存中有，直接跳到第6步操作，若没有，则按照下面的步骤进行操作。

2. 浏览器根据输入的URL地址解析出主机名。

3. 浏览器将主机名转换成服务器ip地址。浏览器先查找本地DNS缓存列表，看缓存里面是否存在这个ip,如果有则进入第4步，如果缓存中不存在这个ip地址，就再向浏览器默认的DNS服务器发送查询请求，同时缓存当前这个ip到DNS缓存列表中。更详细步骤参考DNS查找域名的过程。

4. 拿到ip地址后，浏览器再从URL中解析出端口号。

5. 拿到ip和端口后，浏览器会建立一条与目标Web服务器的TCP连接，也就是三次握手。传送门：[完整的tcp链接](https://www.cnblogs.com/xsilence/p/6034361.html)。

6. 浏览器向服务器发送一条HTTP请求报文。

7. 服务器向浏览器返回一条HTTP响应报文。

8. 关闭连接（四次挥手） 浏览器解析文档。

如果文档中有资源则重复6、7、8动作，直至资源全部加载完毕。

以上步骤简述了浏览器从输入url到最后页面呈现的大致过程，但这并不很具体，比如浏览器请求报文类型是什么，会遇到哪些错误场景、浏览器又是如何解析响应报文等等都没具体描述。

> 网络层面，
1. 首先，域名是对 ip 地址的映射，所以这里也有一个 DNS 解析的过程，DNS 也会存在缓存，
2. 首先是浏览器缓存，然后是系统缓存，然后是路由器缓存，然后是运营商缓存，根域名服务器，再到顶级域名服务器，主域名服务器逐一读取，DNS 的查询方式有两种一种是递归查询，从客户端到 DNS 服务器是属于递归查询的，而 DNS 服务器之间的交互查询是迭代查询，然后会建立 tcp 链接经历三次握手，
3. 然后进行 http 链接，构建请求构建请求行，GET / HTTP/1.1,查找强缓存，强缓存失效，使用协商缓存，得到服务端的响应，到这网络层面结束

> 解析层面，
1. 浏览器收到服务端传过来的 html 文件的字节流，先进行字节流的一个解码，这样才能看到字符串，然后进行输入流预处理，主要是生成规范化的字符流数据，
2. 然后是令牌化，将字符流解析成标签和文本节点，然后根据上一步的操作进行 Dom 树的构建，在这当中若遇到 script 标签会根据 script 加载的方式进行不同的处理，当 script 标签中改变了 DOM 的结构，则会将这些改变的代码加入到字符流重新进行解析，dom 树构建完会进行 CSSOM 树的构建

> 渲染方面，
1. 有了 cssom 树和 dom 树会计算布局，并生成布局树，然后对于一些复杂的场景比如动画，会有层叠上下文，这是会进行图层树得构建，接下来渲染引擎会将图层拆分成一个一个绘制指令，生成绘制列表，然后由合成线程进行绘制，考虑到视口很大不可能一下子绘制完，所以会对图层进行分块，渲染进程还会专门维护一个栅格化线程池专门负责把图块转换成位图数据，这个过程要进入到 GPU 当中进行加速并生成位图然后返回给合成线程，由于上传 GPU 会比较慢，chrom 采取了一个优化首屏加载速度操作，回先展示一个分辨率比较低的图片，最后显示器显示内容，合成线程生成绘制指令，发送给浏览器进程，浏览器受到这个命令把页面内容绘制到内存，也就是生成了页面，再把这部分内存发送给显卡，显卡接收到后会合成相应的图像，并将图像保存到缓冲区

所以当动画过多占用大量内存，浏览器生成图像变慢，传递给显卡不及时，显示器以不变的频率刷新，就会出现掉帧现象

## 24.  跨域、同源策略及跨域实现方式和原理

跨域之所以出现是因为浏览器为了保证安全而制定的一个同源策略，浏览器之外是不存在跨域的，同源策略是一个域去访问另一个域中的资源是会被禁止，同源要求 ur 协议，主机名，端口都相同

浏览器遵循同源政策(scheme(协议)、host(主机)和 port(端口)都相同则为同源)。
非同源站点有这样一些限制: 不能读取和修改对方的 DOM 不读访问对方的 Cookie、IndexDB 和 LocalStorage 限制 XMLHttpRequest 请求。(后面的话题着重围绕这个) 当浏览器向目标 URI 发 Ajax 请求时，只要当前 URL 和目标 URL 不同源，则产生跨域，被称为跨域请求。 跨域请求的响应一般会被浏览器所拦截，注意，是被浏览器拦截，响应其实是成功到达客户端了。那这个拦截是如何发生呢？ 首先要知道的是，浏览器是多进程的，以 Chrome 为例，进程组成如下：

广义上：
1.  资源跳转： A链接、重定向、表单提交
2.  资源嵌入： **link、script、img、frame**等dom标签，还有样式中background:url()、@font-face()等文件外链
3.  脚本请求： js发起的ajax请求、dom和js对象的跨域操作等

跨域解决方案
1. 通过jsonp跨域

JSONP 是服务器与客户端跨源通信的常用方法。最大特点就是简单适用，兼容性好（兼容低版本IE），缺点是只支持get请求，不支持post请求。

核心思想：网页通过添加一个<script>元素，向服务器请求 JSON 数据，服务器收到请求后，将数据放在一个指定名字的回调函数的参数位置传回来。


2. document.domain + iframe跨域
3. location.hash + iframe
4. window.name + iframe跨域
5. postMessage跨域
6. 跨域资源共享（CORS）

ORS 是跨域资源分享（Cross-Origin Resource Sharing）的缩写。它是 W3C 标准，属于跨源 AJAX 请求的根本解决方法。

1、普通跨域请求：只需服务器端设置Access-Control-Allow-Origin

2、带cookie跨域请求：前后端都需要进行设置

【前端设置】根据xhr.withCredentials字段判断是否带有cookie
【服务端设置】服务器端对于CORS的支持，主要是通过设置Access-Control-Allow-Origin来进行的。如果浏览器检测到相应的设置，就可以允许Ajax进行跨域的访问。

7、 nginx代理跨域

在webpack.config.js中利用 WebpackDevServer 配置本地代理，详情配置查看devServer

如下简单配置案例，这样 `http://localhost:8080/api/getUser.php` 的请求就是后端的接口 `http://192.168.25.20:8088/getUser.php`


8、 nodejs中间件代理跨域
9、 WebSocket协议跨域

Websocket 是 HTML5 的一个持久化的协议，它实现了浏览器与服务器的全双工通信，同时也是跨域的一种解决方案。WebSocket 和 HTTP 都是应用层协议，都基于 TCP 协议。但是 WebSocket 是一种双向通信协议，在建立连接之后，WebSocket 的 服务器与 客户端都能主动向对方发送或接收数据。同时，WebSocket 在建立连接时需要借助 HTTP 协议，连接建立好了之后 client 与 server 之间的双向通信就与 HTTP 无关了。

## 25. 浏览器的回流（Reflow）和重绘（Repaints）

> 重绘
重绘：当页面中元素样式的改变不影响它在文档流中的位置，浏览器会将新样式赋予给元素，这个过程叫做重绘

> 回流（重排）
回流：由于浏览器是流式布局：当render tree中的一部分或全部因为元素的规模尺寸、布局、隐藏等改变时，浏览器重新渲染部分DOM或全部DOM的过程。回流也被称为重排，其实从字面上来看，重排更容易让人形象易懂（即重新排版整个页面）

* 总结：回流（重排）一定会引起重绘，而重绘不一定会引起回流

> 会导致回流的操作
   添加或删除可见的DOM元素
   元素位置改变
   元素本身的尺寸发生改变
   内容改变
   页面渲染器初始化
   浏览器窗口大小发生改变
   激活css伪类（这个不是太清楚）


* 避免性能影响

> css:
* 避免使用table布局
* 避免设计多层内敛样式

> js
* 避免频繁操作dom
* 对于大量插入dom操作，建议使用文档片段，也就是documentFragment

>那么避免回流可以这样组：

使用 transfrom 代替 top
进行防抖节流处理
DOM 离线修改，使用 documentFragment 对象在内存中操作 Dom
避免频繁使用 style，而是使用 class
添加 will-change:transform,让渲染进程单独实现一个图层，仅仅利用合成线程去处理，不牵涉到主线程，大大提高渲染效率

## 26. JavaScript中的arguments

他是一个类数组，使用 typeof 返回 [object argumengt],他作为函数的参数对象，内部有 callee 返回函数本身，可以使用显示绑定 this 的方式借用数组上的方法，也可以将它转换成数组

## 27. EventLoop事件循环


浏览器中的事件循环 
JS 本身是单线程的，它依靠事件循环机制完成的异步操作和多线程

大体有三个部分组成：

1. 调用栈call stack
2. 消息队列message queque
3. 微任务队列microtask queque

* 对于所有执行属性，当前执行流程结束他就会弹出调用栈，

* 但对于fetch，事件回调，settimeout，setinterval会入队到消息队列中，消息会在调用栈清空的情况下执行，这也就是为什么settimeout中的时间是延迟的最小参数的原因

* 使用promise、async、await的异步操作都会加入到微任务队列中，他会在调用栈情况的情况下立即执行，
* 所以在这里如果出现消息队列与微任务队列同时出现的情况下，先是微任务队列先执行完毕后，再执行消息队列的任务



## 28. 宏任务与微任务

宏任务常见的有 setTimeout，setInterval，setImmediate，requestAnimationFrame，这些事件会在开启新的一轮事件循环时去执行

微任务常见的有 Promise，MutiationObserver，process.nextTick,微任务的引入是为了解决异步回调的问题，对于异步回调 js 采取的是将异步回调放到当前宏任务的末尾，这样可以保证回调函数及时得到执行，不会造成卡顿，如果把回调函数进行宏任务的入队操作，当宏任务队列非常长的时候回调函数会迟迟得不到执行

微任务中的 Process.nextTick 是一个独立于事件循环的任务队列，每一个轮事件循环结束后回去检查这个队列，如果有，会让其优于微任务执行

## 29. BOM属性对象方法

对象：Window，document，location，screen，history，navigator。

方法：Alert()，confirm()，prompt()，open()，close()

## 30. 函数柯里化及其通用封装

函数柯里化是指将多个参数的函数装化成一系列使用一个参数的函数，一个简单的函数柯里化实现：

```javascript
function curry(fn, args) {
  let length = fn.length;
  args = args || [];
  return function() {
    let subArgs = args.slice(0);
    for (let i = 0; i < arguments.length; i++) {
      subArgs.push(arguments[i]);
    }
    if (subArgs.length >= length) {
      return fn.apply(this, subArgs);
    } else {
      return curry.call(this, fn, subArgs);
    }
  };
}
```
使用函数柯里化可以实现参数复用，提前返回，延迟计算或执行，js 中的 bind 是延迟函数的执行


## 31. JS的map()和reduce()方法

map 方法主要来遍数组，返回一个新数组不会对原数组产生影响，第一个参数为回调函数，用来对数组的元素进行处理，其中回调函数的参数第一个为当前数组元素，第二个为当前下标，第三个为遍历的数组，第二参数 this 的显示绑定

reduce 方法也用来遍历数组，第一个参数为回调函数，第二个参数为初始值，回调函数的第一个参数为累机器，第二个为当前元素，第三个为当前索引，第四个为遍历的数组

## 32. “==”和“===”的区别

==在进行判断时会进行隐式的数据类型转换，而===在进行比较是不会进行数据类型转换

==的转换规则为：

字符串与数字比较，将字符串转为数字在比较
其他类型与 boolen 进行比较，先将布尔转换为数字，在应用其他规则进行比较
null 和 undefined 比较，结果为真，他们和其他值比较均为假
对象和非对象进行比较，对象会进行转换的操作，然后在进行比较
如果有一个为 NaN,返回 false
若两个都是对象，判断他们是否指向同一个对象，是的话为 true，否为为 false
Object.is(),也可以用来进行比较，他主要是修复了一些特殊情况下的 bug，比如正 0 等于负零，NaN 不等于 NaN

## 33. setTimeout用作倒计时为何会产生误差？

setTimeout 属于宏任务，如果当前执行栈的执行时间很长大于定于定时器的时间，那定时器的回调在宏任务里来不及去调用，这个时候就会产生误差，另外一种，是在上一轮事件循环中将 setTimeout 推入到宏任务队列中，若上一轮事件循环也需要很长的时间执行，也会造成误差，所以 setTimeout 的倒计时只是保证在这个倒计时之前不会被执行，但不能保证倒计时结束之后一定被执行

# 二、ES6
## 1. let、const和var的概念与区别

let 声明的块级作用域，而 var 声明的词法作用域，这两者都声明可变的变量，前者不可重复声明，后者可重复声明，会进行覆盖

const 也是声明的块级作用域，声明不可变得变量，不可重复声明，这里的不可变是指变量在栈中的位置不可变，对于复杂数据类型，存储在堆当中，堆中的数据是可以改变的，如果想让复杂数据类型彻底的不可变可以对对象进行冻结操作

let 和 const 会有暂时性死区，而 var 会有变量提升

## 2. 变量提升与暂时性死区

暂时性死区是指变量只能在声明后在使用，在一个作用域中开始到声明变量，这之间的区域成为暂时性死区

变量提升是指当全局声明了一个变量会先将变量的声明提升到作用域的顶端，然后再原来的位置进行赋值，如果有的话，函数会将整个函数体放到作用域的顶端，造成变量提升的本质是 js 引擎在执行代码前有一个解析的过程，创建了执行上下文，初始化了一些执行代码需要用到的变量

## 3. 变量的解构赋值

解构赋值分为两个步骤：变量的声明，和变量的赋值，解构赋值的本质就是模式匹配，只要等号两边模式相同，左边的变量就会被赋予右边的值，如果匹配不成功，就会被赋值为 undefined

解构分为数组的解构赋值，对象的解构赋值，对象的结构也包括比如说基本数类型的解构赋值，因为基本数据也是可以转为对象的

对于数组的解构赋值，只要某种数据具备 Ierator 接口既可以结构维数组，如果不使用默认值，不会执行默认的函数

对于对象的解构赋值，只要右边不是对象或数组，就会先转为对象，由于 undefined 和 null 都不是对象，所以对他们进行解构赋值会报错

只有变量严格等于 undefined 是才会使用默认值，null 不会使用默认值

## 4. 箭头函数及其this问题

关于箭头函数，
1. 内部的 this 指向定义是所在的上下文，而不是使用时所在的上下文，
2. 他不可以当做构造函数使用，不可以使用 new 命令，使用会报错，
3. 也没有原型对象，
4. 也没有参数对象 arguments，不过可以使用 rest 代替，也不可以使用 yield，
5. 箭头函数不能用作 generator

## 5. Symbol概念及其作用

symbol 不能使用 new 命令，接受一个字符串作为参数，表示对 symbol 实例的描述，可在控制台显示转为字符串，symbol 作为属性名，不会被 forin，forof，Objet.keys(),Object.getOwnPropertyNames()，遍历到，也不能被 JSON.stringfy 返回，但可以使用 Object.getOwnPropertySymbols 方法返回一个数组，成员是对象所有用作属性名的 Symbol 值

Symbol.for(),接受一个字符串做为参数，然后搜索有没有以该参数作为名称的 Symbol 的值，若有就返回这个 Symbol 值，没有就创建一个，相应的也有 Symbol.keyFor(),参数为一个变量，返回一个已登记的 symbol 类型的 key 值

## 6. Set、Map、weakset和weakmap数据结构

es6 提供的新的数据结构，set 和 map，同时还有 weakSet，weakMap

set 类似数组，但他里面存的都是唯一的值，没有重复值，weakSet 的成员只能是对象，不能是其他类型的值，weakSet 中的对象都是弱引用，即垃圾回收机制不考虑 weakSet 对该对象的引用

map 里存的都是键值对的集合，类似于对象，但是他的键不限于字符串也可以是其他类型的值，比如对象，weakMap 只接受对象组为健名，该对象也是弱引用，不计入垃圾回收机制

## 7. Proxy

proxy 是代理的意思，用于修改某些操作的默认行为，等同于在语言层面作出修改，所以属于一种元编程，也就是对编程语言尽行编程，proxy 就是在目标对象之前做一层拦截，外界访问该对象都必须经过这层拦截，因此它提供了一种机制，可以对外界的访问进行过滤和改写

## 8. Reflect对象

Reflect 的目的是为了让一些明显属于语言内部的方法放到 Reflect 上，比如 Object.defineProperty,修改某些方法的返回结果，让其更合理,让 Object 的操作都变成函数行为

Reflect 与 Proxy 的方法一一对应，也就是说，不管 proxy 怎么修改默认行为，只要是 Proxy 对象的方法，就能在 Reflect 对象上找到对应的方法，总可以在 Reflect 上获取默认行为

## 9.  Promise（手撕Promise A+规范、Promise.all、Promise相关API和方法）



## 10. Iterator和for...of（Iterator遍历器的实现）

Iterator 是一种接口，为各种不同的数据类型提供统一的访问机制，任何数据类型只要部署 Iterator 接口，就可以完成便利操作，作用主要有三个，一是提供统一的简便的访问接口，二是使得数据结构的成员能够按照某种次序排序，三是 es6 提供了针对 Iterator 消费的 for of 遍历，js 有许多数据类型都默认部署了 Iterator 接口，比如 Array，map，set,String,arguments,nodelist

for of 可以再可迭代对象上创建一个迭代循环，调用自身的迭代钩子，为每个不同的属性的值执行语句

Iterator 遍历器的简单实现：

const makeIterator = (array) => {
  var nextIndex = 0;
  return {
    next: function() {
      return nextIndex < array.length
        ? { value: array[nextIndex++], done: false }
        : { value: undefined, done: true };
    },
  };
};

## 11. 循环语法比较及使用场景（for、forEach、for...in、for...of）

for 循环 缺点是很麻烦。

forEach 回调函数参数分别是 value,index,array

缺点在于无法中途跳出 forEach 循环，break 和 return 命令都不行。

for…in 用于遍历所有的可枚举属性，功能类似于 Object.keys()，但是遍历不到 constructor、length 这样的不可枚举属性。

缺点：

数组的键名为数字，但是 for…in 循环是以字符串作为键名"0",“1”,“2”

for…in 循环主要是为遍历对象而设计的，不适用于遍历数组。

for…of for…of 是 ES6 新增的遍历方式，它提供了统一的遍历机制。所有实现了[Symbol.iterator]接口的对象都可以被遍历。for…of 循环可以使用的范围包括数组、Set 和 Map 结构、某些类似数组的对象（比如 arguments 对象、DOM NodeList 对象）、Generator 对象，以及字符串

优点：1、用法简洁 2、可以和 break,continue,return 配合使用 3、提供了遍历所有数据结构的统一操作接口。

三个遍历器对象：

entries() 返回一个遍历器对象，一个给定对象自身可枚举属性的键值对数组,其排列与使用 for...in 循环遍历该对象时返回的顺序一致（区别在于 for-in 循环还会枚举原型链中的属性）,对于数组，键名就是索引值；对于 Set，键名与键值相同。Map 结构的 Iterator 接口，默认就是调用 entries 方法。
keys() 返回一个遍历器对象，一个由一个给定对象的自身可枚举属性组成的数组。
values() 返回一个遍历器对象，一个给定对象自身的所有可枚举属性值的数组。

## 12. Generator及其异步方面的应用

Generator 是一种异步编程解决方案，最大的特点就是可以交出函数的执行权，和 yield 配合返回的是一个迭代器

Generator 是 es6 的一个新关键词，是一个带星号的函数，但他不是一个函数，可以配合 yield 关键字来暂停或执行函数执行，当声明了一个 Generator 变量后，程序会阻塞住，不会执行任何语句，这个变量是 object 而不是 function，调用 gen.next()，程序会继续执行到 yield 关键词处停止，next 方法会返回一个对象，对象有两个属性，value 和 done，value 表示 yield 返回的值，done 表示 Generator 是否执行完毕

Generator 在异步方面的应用，可以通过 Generator 与 thunk 函数结合来实现异步的控制，thunk 函数的基本思路是接受一定的参数，会产出定制化的函数，最后使用定制化的函数去实现想要实现的功能比如一个读取文件的例子

```javascript
const readFileThunk = (filename) => {
  return (callback) => {
    fs.readFile(filename, callback);
  };
};

const gen = function*() {
  const data1 = yield readFileThunk("./1.txt");
  console.log(data1.toString());
  const data2 = yield readFileThunk("./2.txt");
  console.log(data2.toString());
};

let g = gen();
g.next().value((err, data1) => {
  g.next(data1).value((err, data2) => {
    g.next(data2);
  });
});

//将执行的代码进行封装

function run(gen) {
  const next = (err, data) => {
    let res = gen.next(data);
    if (res.done) return;
    res.value(next);
  };
  next();
}


//Generator 也可以与 Promise 结合

const readFilePromise = function(filename) {
  return new Promise((resolve, reject) => {
    fs.readFile(filename, (err, data) => {
      if (err) {
        reject(err);
      } else {
        resolve(data);
      }
    });
  }).then((res) => res);
};

const gen = function*() {
  const data1 = yield readFilePromise("./1.txt");
  console.log(data1.toString());
  const data2 = yield readFilePromise("./2.txt");
  console.log(data2.toString());
};

function run(gen) {
  const next = (err, data) => {
    let res = gen.next(data);
    if (res.done) return;
    res.value.then(next);
  };
  next();
}
run(g);
```
有一个 co 函数库可以处理 Generator 的自动执行，核心就是通过 thunk 函数以及 Promise 对象进行配合来实现

Generator 就是一个异步操作的容器，它需要一种自动执行机制，co 函数库接受一个 Generator 函数作为参数然后返回一个 Promise，在返回的 Promise 函数里检查 gen 是否为 Generator 函数，如果是，就执行该函数，否则将 Promise 对象的状态改为 resolved，co 将 Generator 函数的内部指针对象的 next 方法包装成 onFulfilled 函数，这样做的是为了能够捕获抛出的错误，关键是配合 next 函数，反复调用自身


## 13. async函数

async/await 可以让我们用同步的方式来书写异步的代码，又得到底层语法的支持，无需借助任何第三方库，async 相对于 Generator 的改进体现在内置执行器，适应性更好，可读性更好，它其实是 Generator 与 Promise 的语法糖

一个带有 async 的函数返回的必定是一个 Promise 对象，如果函数没有返回一个 Promise，他会自动用 Promise.resolve()包装，如果显式的返回了 Promise，那就以返回的 Promise 为准

await 右侧如果是函数，那么返回函数的返回值就是表达式结果，右侧如果是'123'，或者什么值，拿表达式的结果就是 123

async/awiat 还可以使用 try/catch 来同时处理同步和异步的错误

## 14. 几种异步方式的比较（回调、setTimeout、Promise、Generator、async）

所谓的同步就是在执行某段代码时，在该代码没有得到返回结果之前，其他代码暂时是无法执行的，但是一旦执行完成拿到返回值之后，就可以执行其他代码了。换句话说，在此段代码执行完未返回结果之前，会阻塞之后的代码执行，这样的情况称为同步 所谓异步就是当某一代码执行异步过程调用发出后，这段代码不会立刻得到返回结果。而是在异步调用发出之后，一般通过回调函数处理这个调用之后拿到结果。异步调用发出后，不会影响阻塞后面的代码执行，这样的情形称为异步。 
### why 

JavaScript 是单线程的，如果 JS 都是同步代码执行意味着什么呢？这样可能会造成阻塞，如果当前我们有一段代码需要执行时，如果使用同步的方式，那么就会阻塞后面的代码执行；而如果使用异步则不会阻塞，我们不需要等待异步代码执行的返回结果，可以继续执行该异步任务之后的代码逻辑。因此在 JS 编程中，会大量使用异步来进行编程

> 异步的发展 回调函数--> Promise--> Generator-->async/await


1.   回调函数 早些年为了实现 JS 的异步编程，一般都采用回调函数的方式，比如比较典型的事件的回调，或者用 setTimeout/ setInterval 来实现一些异步编程的操作，但是使用回调函数来实现存在一个很常见的问题，那就是回调地狱 
```javascript   
fs.readFile(A, "utf-8", function(err, data) {
  fs.readFile(B, "utf-8", function(err, data) {
    fs.readFile(C, "utf-8", function(err, data) {
      fs.readFile(D, "utf-8", function(err, data) {
        //....
      });
    });
  });
});
```

回调实现异步编程的场景也有很多，比如： 
ajax 请求的回调； 定时器中的回调； 
事件回调； Nodejs 中的一些方法回调。 
异步回调如果层级很少，可读性和代码的维护性暂时还是可以接受，一旦层级变多就会陷入回调地狱，上面这些异步编程的场景都会涉及回调地狱的问题 # Promise 为了解决回调地狱的问题，之后社区提出了 Promise 的解决方案，
ES6 又将其写进了语言标准，采用 Promise 的实现方式在一定程度上解决了回调地狱的问题 
```javascript
function read(url) {
  return new Promise((resolve, reject) => {
    fs.readFile(url, "utf8", (err, data) => {
      if (err) reject(err);

      resolve(data);
    });
  });
}

read(A)
  .then((data) => {
    return read(B);
  })
  .then((data) => {
    return read(C);
  })
  .then((data) => {
    return read(D);
  })
  .catch((reason) => {
    console.log(reason);
  });
  ```
针对回调地狱进行这样的改进，可读性的确有一定的提升，优点是可以将异步操作以同步操作的流程表达出来，避免了层层嵌套的回调函数，但是 Promise 也存在一些问题，即便是使用 Promise 的链式调用，如果操作过多，其实并没有从根本上解决回调地狱的问题，只是换了一种写法，可读性虽然有所提升，但是依旧很难维护。不过 Promise 又提供了一个 all 方法，对于这个业务场景的代码，用 all 来实现可能效果会更好

```javascript
function read(url) {
  return new Promise((resolve, reject) => {
    fs.readFile(url, "utf8", (err, data) => {
      if (err) reject(err);

      resolve(data);
    });
  });
}

// 通过 Promise.all 可以实现多个异步并行执行，同一时刻获取最终结果的问题

Promise.all([read(A), read(B), read(C)])
  .then((data) => {
    console.log(data);
  })
  .catch((err) => console.log(err));

```
async/await
ES6 之后 ES7 中又提出了新的异步解决方案：async/await，async 是 Generator 函数的语法糖，async/await 的优点是代码清晰（不像使用 Promise 的时候需要写很多 then 的方法链），可以处理回调地狱的问题。async/await 写起来使得 JS 的异步代码看起来像同步代码，其实异步编程发展的目标就是让异步逻辑的代码看起来像同步一样容易理解
```javascript
 function testWait() {
  return new Promise((resolve, reject) => {
    setTimeout(function() {
      console.log("testWait");

      resolve();
    }, 1000);
  });
}

async function testAwaitUse() {
  await testWait();

  console.log("hello");

  return 123; // 输出顺序：testWait，hello // 第十行如果不使用await输出顺序：hello , testWait
}

console.log(testAwaitUse());
```

## 15.   class基本语法及继承   
    class 的出现是为了不出 js 缺少一些面向对象语言的特性，但本质上来说是一种构造函数的语法糖，背后依然是原型继承的思想，采用的是寄生组合式继承，通过 class 可以更好地组织代码，在 class 上添加方法其实是在类的原型上添加方法,class 内部默认采用的是严格模式，class 中的静态方法不可以被继承，可以通过类名来调用，也可以在子类中通过 super 来调用，类中的 construct 默认返回实例对象，但也可以返回另一个对象，类必须使用 new 来调用，类不存在变量提升因为有继承，所以必须保证子类在父类后面，私有方法 es6 不提供，只能通过变通的方法来模拟私有变量，比如 symbol，类的内部 this 默认指向类的实例

类的继承可以通过 extend 来实现这比通过修改原型链继承更加清晰方便，子类必须在 construct 中调用 super 否则得不到 this 对象，super 要放到使用 this 前面，否则创建实例时会报错


## 16.  模块加载方案比较（CommonJS和ES6的Module）
   
es6 模块输出的是值的引用，commonjs 输出的是值的拷贝
值的拷贝意味着一旦输出一个值，模块内部的变化就影响不到这个值，es6 模块的运行机制和 common 不一样，js 在对脚本静态分析的时候，遇到模块加载命令 import，会生成一个只读的引用，等到脚本真正执行的时候再根据这个只读的引用，到被加载的那个模块里去取值
commonjs 是运行时加载，es6 模块是编译时加载输出接口
运行时加载就是先加载整个模块，生成一个对象，然后从这个对象上读取方法
编译时加载：e6 模块 s 不是对象，而是通过 export 命令显示指定输出代码，import 时采用静态命令的形式，在 import 时指定加载某个输出值，而不是加载整个模块，它的对外接口只是一种静态定义，在代码静态解析阶段就会生成
commonjs 模块加载方式并不是语言层面的标准，只能在运行时确定模块的依赖关系以及输入输出变量，而 es6 模块在语言规格层面支持模块功能，支持编译时静态分析，便于 js 引入宏和类型检查，动态绑定
commonjs 导入模块是只能是的路劲可以是一个表达式，因为使用的 require()方法，而 es6 模块只能是字符串
commonjs 模块的 this 指向当前模块，而 es6 模块的 this 指向 undefined


## 17.  ES6模块加载与CommonJS加载的原理


# 三、HTML/CSS
## 1. CSS权重及其引入方式

判断优先级时，首先我们会判断一条属性声明是否有权重，也就是是否在声明后面加上了!important。一条声明如果加上了权重，那么它的优先级就是最高的，前提是它之后不再出现相同权重的声明。如果权重相同，我们则需要去比较匹配规则的特殊性。

一条匹配规则一般由多个选择器组成，一条规则的特殊性由组成它的选择器的特殊性累加而成。选择器的特殊性可以分为四个等级，第一个等级是行内样式，为 1000，第二个等级是 id 选择器，为 0100，第三个等级是类选择器、伪类选择器和属性选择器，为 0010，第四个等级是元素选择器和伪元素选择器，为 0001。规则中每出现一个选择器，就将它的特殊性进行叠加，这个叠加只限于对应的等级的叠加，不会产生进位。选择器特殊性值的比较是从左向右排序的，也就是说以 1 开头的特殊性值比所有以 0 开头的特殊性值要大。比如说特殊性值为 1000 的的规则优先级就要比特殊性值为 0999 的规则高。如果两个规则的特殊性值相等的时候，那么就会根据它们引入的顺序，后出现的规则的优先级最高

## 2. <a></a>标签全部作用

a 标签有四个作用：

* 使用 target 规定在何处打开文档，也就是超连接作用
* 设置锚点
* 打电话或发邮件
* 协议限定符
* target 属性有：_blank,_self,_parent,_top

锚点通过#配合 id 来设置

打电话发邮件时需要将href设置为tel:xxx,mailto:xxx

最后一种协议限定符这样使用:<a href="javascript:alert('alert')">点击a标签时执行里面的代码</a>

## 3. 用CSS画三角形

```css
.demo {
  weight: 0;
  height: 0;
  border-top: 40px solid transparent;
  border-bottom: 40px solid transparent;
  border-left: 40px solid transparent;
  border-right: 40px solid red;
}
```

## 4. 未知宽高元素水平垂直居中（方案及比较）


* 方法一 
思路：显示设置父元素为：table，子元素为：cell-table，这样就可以使用vertical-align: center，实现水平居中
优点：父元素（parent）可以动态的改变高度（table元素的特性）
缺点：IE8以下不支持


* 方法二：

思路：使用一个空标签span设置他的vertical-align基准线为中间，并且让他为inline-block，宽度为0
缺点：多了一个没用的空标签，display:inline-blockIE 6 7是不支持的(添加上：_zoom1;*display:inline)。
当然也可以使用伪元素来代替span标签，不过IE支持也不好，但这是后话了

* 方法三

思路：子元素绝对定位，距离顶部 50%，左边50%，然后使用css3 transform:translate(-50%; -50%)
优点：高大上,可以在webkit内核的浏览器中使用
缺点：不支持IE9以下不支持transform属性

* 方法四：
思路：使用css3 flex布局
优点：简单 快捷
缺点：兼容不好吧，详情见：http://caniuse.com/#search=flex

## 5. 元素种类的划分

块状元素、内联元素(又叫行内元素)和内联块状元素

块级元素总是独占一行，另起一行开始，后面的元素也得另起一行，宽度，高度，内边距，外边距都可以控制

内联元素和相邻的内联元素在同一行，只要 padding 和 margin 的 left 和 right 可以设置，其他宽度高度等等都不可设置

inline-block 可以这这是宽高，不会自动换行，一般有，input，button，img，label，texterea

## 6. 盒子模型及其理解

css 盒模型描述了以文档树中的元素而生成的矩阵框，并根据排版模式进行布局，每个盒子都有一个内容区域以及周围可选的 padding，border，margin,css 盒模型负责计算块级元素占用多少空间，边框是否重叠，边距是否合并，盒子的尺寸

盒模型有以下规则：

块级元素大小由 width，height，padding，margin,border 共同决定
如果没有指定 height，块级元素的高度等于其包含的子元素的告诉加上 padding(在没有浮动的情况下)
如果没有指定 width，非浮动元素的宽度等于其父元素的宽度减去父元素的 padding
元素的 height 是由内容的 height 来计算的。
元素的 width 是由内容的 width 来计算的。
默认情况下，padding 和 border 不是元素 width 和 height 的组成部分
盒模型又分为标准盒模型和 ie 盒模型

盒模型都是由四个部分组成的，分别是 margin、border、padding 和 content。

标准盒模型和 IE 盒模型的区别在于设置 width 和 height 时，所对应的范围不同。标准盒模型的 width 和 height 属性的范围只包含了 content，而 IE 盒模型的 width 和 height 属性的范围包含了 border、padding 和 content。

一般来说，我们可以通过修改元素的 box-sizing 属性来改变元素的盒模型

::: tip 在 ie8+浏览器中使用哪个盒模型可以由 box-sizing（CSS 新增的属性）控制，默认值为 content-box，即标准盒模型；

如果将 box-sizing 设为 border-box 则用的是 IE 盒模型。如果在 ie6，7，8 中 DOCTYPE 缺失会将盒子模型解释为 IE 盒子模型。若在页面中声明了 DOCTYPE 类型，所有的浏览器都会把盒模型解释为 W3C 盒模型 :::

## 7. 定位方式及其区别（文档流）

absolute 生成绝对定位的元素，相对于值不为 static 的第一个父元素的 paddingbox 进行定位，也可以理解为离自己这一级元素最近的一级 position 设置为 absolute 或者 relative 的父元素的 paddingbox 的左上角为原点的。不为元素预留空间，绝对定位的元素可以设置外边距（margins），且不会与其他边距合并

fixed 不为元素预留空间，而是通过指定元素相对于屏幕视口（viewport）的位置来指定元素位置。元素的位置在屏幕滚动时不会改变。打印时，元素会出现在的每页的固定位置。fixed 属性会创建新的层叠上下文。当元素祖先的 transform 属性非 none 时，容器由视口改为该祖先

relative 生成相对定位的元素，相对于其在普通流中的位置进行定位。该关键字下，元素先放置在未添加定位时的位置，再在不改变页面布局的前提下调整元素位置（因此会在此元素未添加定位时所在位置留下空白）

static 默认值。该关键字指定元素使用正常的布局行为，即元素在文档常规流中当前的布局位置。此时 top, right, bottom, left 和 z-index 属性无效

sticky 是 2017 年浏览器才开始支持，会产生动态效果，类似 relative 和 fixed 的结合，一个实例是"动态固定"，生效前提是必须搭配 top,left,bottom,right 一起使用，不能省略，否则等同于 relative 定位，不产生"动态固定"的效果

::: tip 谈到 float 还有 position 中的 absolute 和 fixed 脱离文本流的时候，问到底是脱离文档流还是文本流

文档流是相对于盒子模型讲的

文本流是相对于文子段落讲的

元素浮动之后，会让它跳出文档流，也就是说当它后面还有元素时，其他元素会无视它所占据了的区域，直接在它身下布局。但是文字却会认同浮动元素所占据的区域，围绕它布局，也就是没有拖出文本流。

但是绝对定位后，不仅元素盒子会拖出文档流，文字也会出文本流。那么后面元素的文本就不会在认同它的区域位置，会直接在它后面布局，不会在环绕。当然你可以使用 index-z 来让底部的元素到上面来，类似于一个图层的概念 :::

## 8. margin塌陷及合并问题

margin 重叠指的是在垂直方向上，两个相邻元素的 margin 发生重叠的情况。

一般来说可以分为四种情形：

第一种是相邻兄弟元素的 marin-bottom 和 margin-top 的值发生重叠。这种情况下我们可以通过设置其中一个元素为 BFC 来解决。

第二种是父元素的 margin-top 和子元素的 margin-top 发生重叠。它们发生重叠是因为它们是相邻的，所以我们可以通过这一点来解决这个问题。我们可以为父元素设置 border-top、padding-top 值来分隔它们，当然我们也可以将父元素设置为 BFC 来解决。

第三种是高度为 auto 的父元素的 margin-bottom 和子元素的 margin-bottom 发生重叠。它们发生重叠一个是因为它们相邻，一个是因为父元素的高度不固定。因此我们可以为父元素设置 border-bottom、padding-bottom 来分隔它们，也可以为父元素设置一个高度，max-height 和 min-height 也能解决这个问题。当然将父元素设置为 BFC 是最简单的方法。

第四种情况，是没有内容的元素，自身的 margin-top 和 margin-bottom 发生的重叠。我们可以通过为其设置 border、padding 或者高度来解决这个问题。

## 9.  浮动模型及清除浮动的方法

浮动（float）是 CSS 定位属性。浮动元素从网页的正常流动中移出，但是保持了部分的流动性，会影响其他元素的定位（比如文字会围绕着浮动元素）。这一点与绝对定位不同，绝对定位的元素完全从文档流中脱离。

CSS 的 clear 属性通过使用 left、right、both，让该元素向下移动（清除浮动）到浮动元素下面

如果父元素只包含浮动元素，那么该父元素的高度将塌缩为 0。我们可以通过清除（clear）从浮动元素后到父元素关闭前之间的浮动来修复这个问题

清除浮动是为了清除使用浮动元素产生的影响。浮动的元素，高度会塌陷，而高度的塌陷使我们页面后面的布局不能正常显示

清除浮动的方法有：

额外标签，即在最后一个浮动标签后加一个空 div，给其设置 clear:both ，缺点是增加无意义标签，语义化差
a 内部标签：会将父盒子的高度重新撑开
b 外部标签：只能将浮动盒子的影响清除，但是不会撑开盒子
给父级元素添加 overflow:不为 visible 通过触发 BFC 的方式清除浮动，先找到浮动盒子的父元素，给父元素添加一个属性：overflow:hidden;就会清除子元素对页面的影响（不推荐使用）
使用 after 伪元素，缺点是 IE6-7 不支持伪元素，zoom:1 触发 hasLayout,zoom 属性是 IE 浏览器的专有属性
::: tip clear 属性清除浮动的原理 如果单看字面意思，clear:left 应该是“清除左浮动”，clear:right 应该是“清除右浮动”的意思，实际上，这种解释是有问题的，因为浮动一直还在，并没有清除。

官方对 clear 属性的解释是：“元素盒子的边不能和前面的浮动元素相邻。”，我们对元素设置 clear 属性是为了避免浮动元素对该元素的影响，而不是清除掉浮动还需要注意的一点是 clear 属性指的是元素盒子的边不能和前面的浮动元素相邻，注意这里“前面的”3 个字，也就是 clear 属性对“后面的”浮动元素是不闻不问的。考虑到 float 属性要么是 left，要么是 right，不可能同时存在，同时由于 clear 属性对“后面的”浮动元素不闻不问，因此，当 clear:left 有效的时候，clear:right 必定无效，也就是此时 clear:left 等同于设置 clear:both；同样地，clear:right 如果有效也是等同于设置 clear:both。由此可见，clear:left 和 clear:right 这两个声明就没有任何使用的价值，至少在 CSS 世界中是如此，直接使用 clear:both 吧。

clear 属性只有块级元素才有效的，而::after 等伪元素默认都是内联水平，这就是借助伪元素清除浮动影响时需要设置 display 属性值的原因 :::

## 10. CSS定位属性



## 11. display及相关属性

这个属性用于定义建立布局时元素生成的显示框类型

block 块类型。默认宽度为父元素宽度，可设置宽高，换行显示。

none 元素不显示，并从文档流中移除。

inline 行内元素类型。默认宽度为内容宽度，不可设置宽高，同行显示。

inline-block 默认宽度为内容宽度，可以设置宽高，同行显示。

list-item 像块类型元素一样显示，并添加样式列表标记。

table 此元素会作为块级表格来显示。

inherit 规定应该从父元素继承 display 属性的值

::: tip display 、position 和 float 的相互关系 （1）首先我们判断 display 属性是否为 none，如果为 none，则 position 和 float 属性的值不影响元素最后的表现。

（2）然后判断 position 的值是否为 absolute 或者 fixed，如果是，则 float 属性失效，并且 display 的值应该被设置为 table 或者 block，具体转换需要看初始转换值。

（3）如果 position 的值不为 absolute 或者 fixed，则判断 float 属性的值是否为 none，如果不是，则 display 的值则按上面的规则转换。注意，如果 position 的值为 relative 并且 float 属性的值存在，则 relative 相对于浮动后的最终位置定位。

（4）如果 float 的值为 none，则判断元素是否为根元素，如果是根元素则 display 属性按照上面的规则转换，如果不是，则保持指定的 display 属性值不变。

总的来说，可以把它看作是一个类似优先级的机制，"position:absolute"和"position:fixed"优先级最高，有它存在的时候，浮动不起作用，'display'的值也需要调整；其次，元素的'float'特性的值不是"none"的时候或者它是根元素的时候，调整'display'的值；最后，非根元素，并且非浮动元素，并且非绝对定位的元素，'display'特性值同设置值。 :::

::: tip 使用 display:inline-block 会产生什么问题


产生空白的原因

元素被当成行内元素排版的时候，元素之间的空白符（空格、回车换行等）都会被浏览器处理，根据 CSS 中 white-space 属性的处理方式（默认是 normal，合并多余空白），原来 HTML 代码中的回车换行被转成一个空白符，在字体不为 0 的情况下，空白符占据一定宽度，所以 inline-block 的元素之间就出现了空隙

解决办法:

将子元素标签的结束符和下一个标签的开始符写在同一行或把所有子标签写在同一行
父元素中设置 font-size: 0，在子元素上重置正确的 font-size
为子元素设置 float:left :::

## 12. IFC与BFC

BFC （Block formatting contexts ）：

块级格式上下文页面上的一个隔离的渲染区域，那么他是如何产生的呢？可以触发 BFC 的元素有 float、position、overflow、display：table-cell/inline-block/table-caption ；BFC 有什么作用呢？比如说实现多栏布局’

IFC （Inline formatting contexts ）：

内联格式上下文 IFC 的 line box（线框）高度由其包含行内元素中最高的实际高度计算而来（不受到竖直方向的 padding/margin 影响)IFC 中的 line box 一般左右都贴紧整个 IFC，但是会因为 float 元素而扰乱。float 元素会位于 IFC 与与 line box 之间，使得 line box 宽度缩短。 同个 ifc 下的多个 line box 高度会不同 IFC 中时不可能有块级元素的，当插入块级元素时（如 p 中插入 div）会产生两个匿名块与 div 分隔开，即产生两个 IFC，每个 IFC 对外表现为块级元素，与 div 垂直排列。那么 IFC 一般有什么用呢？水平居中：当一个块要在环境中水平居中时，设置其为 inline-block 则会在外层产生 IFC，通过 text-align 则可以使其水平居中。垂直居中：创建一个 IFC，用其中一个元素撑开父元素的高度，然后设置其 vertical-align:middle，其他行内元素则可以在此父元素下垂直居中。

GFC （GrideLayout formatting contexts ）：

网格布局格式化上下文当为一个元素设置 display 值为 grid 的时候，此元素将会获得一个独立的渲染区域，我们可以通过在网格容器（grid container）上定义网格定义行（grid definition rows）和网格定义列（grid definition columns）属性各在网格项目（grid item）上定义网格行（grid row）和网格列（grid columns）为每一个网格项目（grid item）定义位置和空间。那么 GFC 有什么用呢，和 table 又有什么区别呢？首先同样是一个二维的表格，但 GridLayout 会有更加丰富的属性来控制行列，控制对齐以及更为精细的渲染语义和控制。

FFC （Flex formatting contexts ）:

自适应格式上下文 display 值为 flex 或者 inline-flex 的元素将会生成自适应容器（flex container），可惜这个牛逼的属性只有谷歌和火狐支持，不过在移动端也足够了，至少 safari 和 chrome 还是 OK 的，毕竟这俩在移动端才是王道。FlexBox 由伸缩容器和伸缩项目组成。通过设置元素的 display 属性为 flex 或 inline-flex 可以得到一个伸缩容器。设置为 flex 的容器被渲染为一个块级元素，而设置为 inline-flex 的容器则渲染为一个行内元素。伸缩容器中的每一个子元素都是一个伸缩项目。伸缩项目可以是任意数量的。伸缩容器外和伸缩项目内的一切元素都不受影响。简单地说，Flexbox 定义了伸缩容器内伸缩项目该如何布局。

## 13. 圣杯布局和双飞翼布局的实现

使用双飞翼布局，它最先渲染的是中间元素，然后才渲染两边元素（注意，这一点与float布局方式正好相反哟），先将三个元素都设置为向左浮动，然后使用负边距将左右两个元素覆盖到中间元素的左右两边，形成羽翼。

## 14. Flex布局

lex 布局是 CSS3 新增的一种布局方式，我们可以通过将一个元素的 display 属性值设置为 flex 从而使它成为一个 flex 容器，它的所有子元素都会成为它的项目。

一个容器默认有两条轴，一个是水平的主轴，一个是与主轴垂直的交叉轴。我们可以使用 flex-direction 来指定主轴的方向。

我们可以使用 justify-content 来指定元素在主轴上的排列方式，使用 align-items 来指定元素在交叉轴上的排列方式。还可以使用 flex-wrap 来规定当一行排列不下时的换行方式。

对于容器中的项目，我们可以使用 order 属性来指定项目的排列顺序，还可以使用 flex-grow 来指定当排列空间有剩余的时候，项目的放大比例。还可以使用 flex-shrink 来指定当排列空间不足时，项目的缩小比例

::: tip flex 属性 以下 6 个属性设置在容器上。

flex-direction 属性决定主轴的方向（即项目的排列方向）。

flex-wrap 属性定义，如果一条轴线排不下，如何换行。

flex-flow 属性是 flex-direction 属性和 flex-wrap 属性的简写形式，默认值为 rownowrap。

justify-content 属性定义了项目在主轴上的对齐方式。

align-items 属性定义项目在交叉轴上如何对齐。

align-content 属性定义了多根轴线的对齐方式。如果项目只有一根轴线，该属性不起作用。

以下 6 个属性设置在项目上。

order 属性定义项目的排列顺序。数值越小，排列越靠前，默认为 0。

flex-grow 属性定义项目的放大比例，默认为 0，即如果存在剩余空间，也不放大。

flex-shrink 属性定义了项目的缩小比例，默认为 1，即如果空间不足，该项目将缩小。

flex-basis 属性定义了在分配多余空间之前，项目占据的主轴空间。浏览器根据这个属性，计算主轴是否有多余空间。它的默认值为 auto，即项目的本来大小。

flex 属性是 flex-grow，flex-shrink 和 flex-basis 的简写，默认值为 01auto。

align-self 属性允许单个项目有与其他项目不一样的对齐方式，可覆盖 align-items 属性。默认值为 auto，表示继承父元素的 align-items 属性，如果没有父元素，则等同于 stretch。 :::

## 15. px、em、rem的区别

px 像素（Pixel）。相对长度单位。像素 px 是相对于显示器屏幕分辨率而言的

IE 无法调整那些使用 px 作为单位的字体大小；
国外的大部分网站能够调整的原因在于其使用了 em 或 rem 作为字体单位；
Firefox 能够调整 px 和 em，rem，但是 96%以上的中国网民使用 IE 浏览器(或内核)。
em 是相对长度单位。相对于当前对象内文本的字体尺寸。如当前对行内文本的字体尺寸未被人为设置，则相对于浏览器的默认字体尺寸

em 的值并不是固定的；
em 会继承父级元素的字体大小。
::: tip 任意浏览器的默认字体高都是 16px。所有未经调整的浏览器都符合: 1em=16px。那么 12px=0.75em,10px=0.625em。为了简化 font-size 的换算，需要在 css 中的 body 选择器中声明 Font-size=62.5%，这就使 em 值变为 16px*62.5%=10px, 这样 12px=1.2em, 10px=1em, 也就是说只需要将你的原来的 px 数值除以 10，然后换上 em 作为单位就行了 :::

rem 是 CSS3 新增的一个相对单位（root em，根 em），这个单位与 em 有什么区别呢？区别在于使用 rem 为元素设定字体大小时，仍然是相对大小，但相对的只是 HTML 根元素。这个单位可谓集相对大小和绝对大小的优点于一身，通过它既可以做到只修改根元素就成比例地调整所有字体大小，又可以避免字体大小逐层复合的连锁反应，目前，除了 IE8 及更早版本外，所有浏览器均已支持 rem

优点：

在屏幕分辨率千差万别的时代，只要将 rem 与屏幕分辨率关联起来就可以实现页面的整体缩放，使得在设备上的展现都统一起来了。而且现在浏览器基本都已经支持 rem 了，兼容性也非常的好。

缺点：

在奇葩的 dpr 设备上表现效果不太好，比如一些华为的高端机型用 rem 布局会出现错乱。

使用 iframe 引用也会出现问题。

rem 在多屏幕尺寸适配上与当前两大平台的设计哲学不一致。即大屏的出现到底是为了看得又大又清楚，还是为了看的更多的问题。

::: tip 对于只需要适配少部分手机设备，且分辨率对页面影响不大的，使用 px 即可。

对于需要适配各种移动设备，使用 rem，例如只需要适配 iPhone 和 iPad 等分辨率差别比较挺大的设备 :::

## 16. Less预处理语言



## 17. 媒体查询

假设你现在正用一台显示设备来阅读这篇文章，同时你也想把它投影到屏幕上，或者打印出来，而显示设备、屏幕投影和打印等这些媒介都有自己的特点，CSS 就是为文档提供在不同媒介上展示的适配方法当媒体查询为真时，相关的样式表或样式规则会按照正常的级联规被应用。当媒体查询返回假，标签上带有媒体查询的样式表仍将被下载（只不过不会被应用）。包含了一个媒体类型和至少一个使用宽度、高度和颜色等媒体属性来限制样式表范围的表达式。CSS3 加入的媒体查询使得无需修改内容便可以使样式应用于某些特定的设备范围

## 18. vh与vw

vw : 1vw 等于视口宽度的 1%
vh : 1vh 等于视口高度的 1%
vmin : 选取 vw 和 vh 中最小的那个
vmax : 选取 vw 和 vh 中最大的那个

## 19. H5的语义化作用及语义化标签

html 语义化主要指的是我们应该使用合适的标签来划分网页内容的结构。html 的本质作用其实就是定义网页文档的结构，一个语义化的文档，能够使页面的结构更加清晰，易于理解。这样不仅有利于开发者的维护和理解，同时也能够使机器对文档内容进行正确的解读

比如说我们常用的 b 标签和 strong 标签，它们在样式上都是文字的加粗，但是 strong 标签拥有强调的语义。对于一般显示来说，可能我们看上去没有差异，但是对于机器来说，就会有很大的不同。如果用户使用的是屏幕阅读器来访问网页的话，使用 strong 标签就会有明显的语调上的变化，而 b 标签则没有。如果是搜索引擎的爬虫对我们网页进行分析的话，那么它会依赖于 html 标签来确定上下文和各个关键字的权重，一个语义化的文档对爬虫来说是友好的，是有利于爬虫对文档内容解读的，从而有利于我们网站的 SEO

从 html5 我们可以看出，标准是倾向于以语义化的方式来构建网页的，比如新增了 header 、footer 这些语义标签，删除了 big 、font 这些没有语义的标签

## 20. Web Worker和Web Socket

web worker 就是在 web 应用程序中使用的 worker。这个 worker 是独立于 web 主线程的，在后台运行的线程,web worker 的优点就是可以将工作交给独立的其他线程去做，这样就不会阻塞主线程

基本使用：

通过 worker = new Worker( url ) 加载一个 JS 文件来创建一个 worker，同时返回一个 worker 实例。

通过worker.postMessage( data ) 方法来向 worker 发送数据。

绑定worker.onmessage方法来接收 worker 发送过来的数据。

可以使用 worker.terminate() 来终止一个 worker 的执行。

WebSocket 是 Web 应用程序的传输协议，它提供了双向的，按序到达的数据流。他是一个 Html5 协议，WebSocket 的连接是持久的，他通过在客户端和服务器之间保持双工连接，服务器的更新可以被及时推送给客户端，而不需要客户端以一定时间间隔去轮询

## 21. CSS3及相关动画



## 22. 如何实现响应式布局

响应式网站设计是一个网站能够兼容多个终端，而不是为每一个终端做一个特定的版本。基本原理是通过媒体查询检测不同的设备屏幕尺寸做处理。页面头部必须有 meta 声明的 viewport

::: tip 响应式设计与自适应设计有何不同 响应式设计和自适应设计都以提高不同设备间的用户体验为目标，根据视窗大小、分辨率、使用环境和控制方式等参数进行优化调整。

响应式设计的适应性原则：网站应该凭借一份代码，在各种设备上都有良好的显示和使用效果。响应式网站通过使用媒体查询，自适应栅格和响应式图片，基于多种因素进行变化，创造出优良的用户体验。就像一个球通过膨胀和收缩，来适应不同大小的篮圈。

自适应设计更像是渐进式增强的现代解释。与响应式设计单一地去适配不同，自适应设计通过检测设备和其他特征，从早已定义好的一系列视窗大小和其他特性中，选出最恰当的功能和布局。与使用一个球去穿过各种的篮筐不同，自适应设计允许使用多个球，然后根据不同的篮筐大小，去选择最合适的一个 :::

## 23. SEO的概念及实现

前端需要注意哪些 SEO

（1）合理的 title、description、keywords：搜索对着三项的权重逐个减小，title 值强调重点即可，重要关键词出现不要超过 2 次，而且要靠前，不同页面 title 要有所不同；description 把页面内容高度概括，长度合适，不可过分堆砌关键词，不同页面 description 有所不同；keywords 列举出重要关键词即可。

（2）语义化的 HTML 代码，符合 W3C 规范：语义化代码让搜索引擎容易理解网页。

（3）重要内容 HTML 代码放在最前：搜索引擎抓取 HTML 顺序是从上到下，有的搜索引擎对抓取长度有限制，保证重要内容肯定被抓取。

（4）重要内容不要用 js 输出：爬虫不会执行 js 获取内容

（5）少用 iframe：搜索引擎不会抓取 iframe 中的内容

（6）非装饰性图片必须加 alt

（7）提高网站速度：网站速度是搜索引擎排序的一个重要指标

在 SEO 中，所谓的 TDK 其实就是 title、description、keywords 这三个标签，title 标题标签，description 描述标签，keywords 关键词标签

## 24. HTML5的新特性

HTML5 现在已经不是 SGML 的子集，主要是关于图像，位置，存储，多任务等功能的增加。

新增的有：

绘画 canvas;
用于媒介回放的 video 和 audio 元素;
本地离线存储 localStorage 长期存储数据，浏览器关闭后数据不丢失;
sessionStorage 的数据在浏览器关闭后自动删除;
语意化更好的内容元素，比如 article、footer、header、nav、section;
表单控件，calendar、date、time、email、url、search;
新的技术 webworker, websocket;
新的文档属性 document.visibilityState
移除的元素有：

纯表现的元素：basefont，big，center，font, s，strike，tt，u;
对可用性产生负面影响的元素：frame，frameset，noframes；

## 25. Less和Sass使用



# 四、HTTP与计算机网络


## 1. TCP/IP协议分层管理


## 2. 三次握手四次挥手机制及原因

* 三次握手 

第一次握手是让服务端知道客户端具有发送能力，
第二次握手是让客户端知道服务端具有接受和发送的能力，但此时服务端并不知道客户端是否收到了自己发送的消息，
所以第三次握手起到了这个作用，经过了三次握手后服务端和客户端都确认了双方的接收和发送能力 

不是两次是因为无法确认客户端的接受能力，大于等于三次都可以，只是再多用处不大，第三次握手是可以携带数据的，前两次不可以，因为有人想攻击服务器，在第一次握手中放了大量数据，那么服务端必定会消耗更多的时间和内存去处理这些数据，大大增加了服务端被攻击的风险 第一次握手，客户端处于 close 状态，服务端处理 listening 状态，客户端给服务端发送了一个 SYN 报文并指明了客户端的初始化序列号 ISN，此时客户端处于 SYN_SEND 状态 第二次握手，服务端接收到 SYN 报文后，会以自己的 SYN 报文作为应答，并且也指定了自己的初始化序列号 ISN，同时会把客户端的 ISN + 1 作为 ACK 的值，表示自己已经收到了客户端的 SYN，此时服务端处于 SYN_REVD 状态 第三次握手，当客户端接收到 SYN 报文后，会发送一个 ACK 报文，也把 ISN + 1 作为 ACK 的值，表示客户端接收到了服务端的 SYN 报文，此时客户端处于 establish 的状态，服务端接收到 ACK 报文后也处于 established 状态，此时双方成功建立起链接 

* 四次挥手 

为什么链接需要三次而断开需要四次：当服务端接收到客户端的 FIN 报文后，发送的 ACK 报文还是用来应答，并不表示服务端也希望立即关闭连接，只有当服务端把所有的报文都发送完了，才会发送 FIN 报文，告诉客户端可以断开连接了，因此这就是需要四次挥手的原因 
1. 第一次挥手，在挥手之前，两端都处于 established 的状态，客户端发送一个 FiN 报文，用来关闭客户端到服务端的数据传输，此时客户端处于 FIN_WAIT_1 状态。 
2. 第二次挥手，当服务端收到 FIN 报文后，会发送 ACK 报文，并把客户端的序列号值加 1 作为 ACK 报文的序列号，表明已经收到客户端的报文了，此时服务端处于 close_wait 状态 
3. 第三次挥手，如果服务端同意关闭连接，则会向客户端发送一个 FIN 报文，并指定一个序列号，此时服务端处于 LAST_ACK 的状态 
4. 第四次挥手，当客户端收到 ACK 后，处于 FIN_WAIT_2 状态，待收到 FIN 报文时发送一个 ACK 报文作为应答，并且把服务端的序列号值+1 作为自己的 ACK 报文的序列号值，是客户端处于 TIME_WAIT 状态，等待一段时间后会进入 closed 状态，当服务端接收到 ACK 值后，也会变为 closed 状态，此时连接正式关闭


## 3. HTTP方法
   GET:通常用来获取资源 
   HEAD：获取资源的元信息
   POST：提交数据，即上传数据 
   PUT：修改数据 
   DELETE：删除数据 
   CONNECT：建立连接隧道，用于代理服务器 
   OPTIONS:列出可对资源实行的请求方法，用来跨域请求 
   TRACE：追踪请求-响应的传输路径

## 4. GET和POST的区别

最直观的是语义上的区别，往细了说： 
从缓存角度，GET 请求会被浏览器主动缓存下来，留下历史记录，而 post 请求不会 从编码角度，get 请求只能进行 URL 编码，只能收到 ASCII 字符，而 POST 没有限制。 
从参数角度，get 请求一般会放到 URL 中，因此不安全，post 请求放在请求体中，更适合传输敏感信息 从幂等性角度，get 是幂等性的，而 post 不是（幂等性是指执行相同的操作，结果也是相同的） 
从 TCP 的角度，get 请求会吧请求报文一次性的发出去，而 Post 会分为两个 TCP 数据包，首先发送 header 部分，如果服务器响应 100，然后发 boy（火狐浏览器除外，她的 post 请求只发一个 TCP 包）

## 5. HTTP建立持久连接的意义

HTTP 建立持久连接是在 HTTP1.1 版本中才有的，HTTP1.0 通过设立头部字段来进行不同类型文件的传输，随着互联网的发展，HTTP1.0 已经无法满都需求，最核心的问题就是连接问题，具体来说就是每进行一次通信都要进行建立连接，传输数据，断开连接的过程三个阶段，当一个页面引用了较多的外部文件时，这个建立连接和断开连接的过程就会增加大量的网阔开销 为了解决这个问题，http1.1 版本增加了一个创建之持久连接的方法，实现了每当一个连接传输完成时，并不是马上进行关闭，而是继续复用他传输其他请求，这个链接直到浏览器或者服务器要求断开为止


## 6. HTTP报文的结构

http 报文结构是 header+body 的结构，大致为起始行+头部+空行+实体 起始行对于请求报文来说是请求方法 路径 http版本，对于响应报文是http版本 状态码 原因，起始行中每两个部分之间用空格隔开，最后一个部分后面接一个换行符 不管是请求头韩式响应头，其中的字段是相当多的，牵扯到 http 非常多的特性，格式方面： 字段名不区分大小写 字段名不允许出现空格，不可以出现下划线 字段名后面必须紧跟着: 空行很重要，用来区分头部和实体，如果故意在头部中间加一个空行，那么空行后面的内容会全部被视为实体 最后实体就是 body 部分了，请求报文对应请求体，响应报文对应响应体

## 7. HTTP状态码

http 状态码为三位数，被分为 5 类： 
1xx 表示目前是协议的中间状态，还需要后续操作 
2xxx 表示成功状态 
3xx 是重定向状态，资源位置发生变动，需要重新请求 
4xx 是请求报文有误 
5xx 是服务端发生错误 
常见的状态码有这些： 
200 表示成功的状态码 
204 表示请求成功但响应头后没有 body 数据 
206 表示部分内容，使用场景为 http 分块下载和断点续传，当然也会带上相应的响应头部字段 Content-Range 
301 永久重定向，
302 临时重定向 
304 表示命中协商缓存 
400 笼统的提示一下，并不知道哪里出错了 
403 表示服务器禁止访问 
404 表示未在服务器上找到资源 
405 表示请求方法不被允许 
406 表示资源无法满足客户端的条件 
408 表示服务器等待时间过长 
409 表示多个请求发生了冲突
413 表示请求体数据过大
414 表示请求行里的 URL 太大 
429 表示客户端发送的请求过多
431 表示请求字段内容太大 
500 表示服务器出错了，但不知道出了什么错 
501 表示客户端请求的功能还不支持 
502 表示服务器本身正常，但访问时出错了，具体什么错误不知道 
503 表示服务器当前很忙，暂时无法响应服务


## 8. Web服务器及其组成

Web 服务器一般指网站服务器，是指驻留于因特网上某种类型计算机的程序，可以处理浏览器等 Web 客户端的请求并返回相应响应，也可以放置网站文件，让全世界浏览；可以放置数据文件，让全世界下载，目前最主流的三个 Web 服务器是 Apache、 Nginx 、IIS Web 服务器有以下几个部分组成： 服务器初始化部分，这部分主要完成初始化的工作，比如建立守护进程，创建 TCP 套接字，绑定端口，等待接收客户端的连接 接收客户端请求，http1.x 中以文本行的形式接收，因为请求头是以文本行的方式实现的 解析客户端请求，解析出请求方法，url 目标，可选的查询信息以及表单信息，如果请求方法为 HEAD，则简单的返回响应首部即可；如果方法是 GET，则首先返回响应首部，然后将客户端请求的 URL 目标文件从服务器磁盘上读取，再发送给客户端；如果是 POST，则比较麻烦，首先要调用相应的 CGI 程序，然后将用户表单信息传给 CGI 程序，CGI 程序根据表单内容完成相应的工作，并将结果数据返回 发送响应信息后，关闭与客户端的链接 # HTTP 的特点

## 9.  HTTP报文首部

灵活扩展，语义上很自由，没有严格的语法限制，传输形式多样 可靠传输，将 TCP 的这一特性继承了下来 请求-应答，一收一发，有来有回 无状态，指的是通信过程中的上下文信息，每次 http 请求都是独立，无关的，默认不需要保留状态信息 缺点： 无状态，在长链接中，需要保存大量的上下文信息，一面传输大量的重复信息，这时无状态就成了缺点，而少量的数据传输不需要保存上下文信息，无状态减少了网络开销，就是无状态的优点 明文传输，报文都是文本形式，而不是使用的二进制形式，报文信息暴露给外界，方便调试的同时也给了攻击者方便，比如 wifi 陷阱 队头阻塞问题，当开启长连接，多个请求共用一个 TCP，同一时刻只能处理一个请求，那么如果当前请求耗时过长，其它请求就只能处于阻塞状态

## 10.  HTTP通用首部字段

## 11. HTTP请求首部字段、响应首部字段、实体首部字段
## 12. Cookie相关首部字段
## 13. HTTPS与HTTP区别及实现方式
http
## 14. Cookie与Session
## 15. 基于HTTP的功能追加协议（SPY、WebSocket、HTTP）
## 16. 常见的Web攻击分类

1. XSS(Cross Site Scripting)跨站JS脚本攻击：针对接口进行 XSS攻击，即把js脚本或者带恶意js脚本的html标签，作为GET或者POST参数提交到服务器，然后服务器解释并响应
2. CSRF(Cross-site request forgery)跨站请求(GET和POST)伪造攻击：则可以通过在恶意网站B上静态或者动态创建img,script等标签发起GET或者POST请求，发出的恶意请求是身份认证后的，这就构成CSRF攻击了。将其src属性指向发起对A网站的接口请求（如一个GET请求：api.a.com/blog/del?id=1）。通过标签的方式发起的请求不受同源策略的限制。
3. SQL注入：
4. 接口访刷问题：


## 17. TCP与UDP区别

>TCP 是一个面向连接的、可靠的、基于字节流的传输层协议。
>而 UDP 是一个面向无连接的传输层协 

具体来分析，和 UDP 相比，TCP 有三大核心特性: 
面向连接。所谓的连接，指的是客户端和服务器的连接，在双方互相通信之前，
TCP 需要三次握手建立连接，而 UDP 没有相应建立连接的过程。 
可靠性。TCP 花了非常多的功夫保证连接的可靠，这个可靠性体现在哪些方面呢？一个是有状态，另一个是可控制。TCP 会精准记录哪些数据发送了，哪些数据被对方接收了，哪些没有被接收到，而且保证数据包按序到达，不允许半点差错。这是有状态,当意识到丢包了或者网络环境不佳，TCP 会根据具体情况调整自己的行为，控制自己的发送速度或者重发。这是可控制,相应的，UDP 就是无状态, 不可控的 面向字节流。UDP 的数据传输是基于数据报的，这是因为仅仅只是继承了 IP 层的特性，而 TCP 为了维护状态，将一个个 IP 包变成了字节流


1.  存储机制localStorage、sessionStorage与Cookie存储技术
2.  XSS攻击及防御
3.  CSRF攻击及防御

## 18.http2.0有了解吗和http1.x进行对比一下

> http2特点
1. 多路复用：相同域名多个请求，共享同一个TCP连接，降低了延迟

2. 请求优先级：给每个request设置优先级

3. 二进制传输；之前是用纯文本传输

4. 数据流：数据包不是按顺序发送，对数据包做标记。每个请求或回应的所有数据包成为一个数据流，

5. 服务端推送：可以主动向客户端发送消息。

6. 头部压缩：减少包的大小跟数量

7. HTTP/1.1 中的管道（ pipeline）传输中如果有一个请求阻塞了，那么队列后请求也统统被阻塞住了 HTTP/2 多请求复用一个TCP连接，一旦发生丢包，就会阻塞住所有的 HTTP 请求。HTTP/3 把 HTTP 下层的 TCP 协议改成了 UDP！http1 keep alive 串行传输
  
```javascript
// 面试官: http2实现了多路复用,http1.x为什么不能多路复用?
// 我: 我说因为http1.x要按照顺序来.
// 面试官: 没错,但是为什么http1.x要按照顺序来?
// 我: 唔...这个不知道..
// 面试官: HTTP/1.1是基于文本分割解析的协议,也没有序号,如果多路复用会导致顺序错乱,http2则用帧的方式,等于切成一块块,每一块都有对应的序号,所以可以实现多路复用.
```

# 五、前端工程化
## 1. 前端工程化的流程（架构选型、业务开发、测试、打包构建、部署上线、项目监控）

前端工程化的话，首先是工具的选择，比如是用什么框架，是用什么脚手架等等，然后是一个好的代码编辑器和一个好的开发环境，比如使用 vscode 插件来提升编码速度，使用 webpak 的 devserver 来提高开发环境下的构建速度，也可以使用一些 nobundle 类的打包工具，比如 vite，使用 HMR 来进一步提高开发中的效率，前后端交互中，数据往往有后端提供，为了提高开发的整体速度，前端可以显示 mock 的形式自己 mock 一份数据，这样前后端同时开发，等后端的接口开发完毕，就可以将 mock 数据提换成真实的数据，但我们开发完了一个项目，需要对现目进行打包，这时，可以通过 webpack 的一系列的优化打包的方案来对代码进行更好地打包，比如代码压缩，tree sharking 等等，最后是项目部书，可以引入自动化部署方案，比如 Jenkins

对于一些重复性比较高的，实现起来比较通用的页面可以使用低代码开发或无代码开发

开发效率方面除了传统的的前后端分离的开发方式，也可以会用前后端一体化的云开发

## 2. Webpack基本概念与配置

webpack 是一个打包工具，它借助 babel 具备编译代码的能力，比如将一些包含新特性的代码编译成浏览器所兼容的代码，能够将项目中一些散落的模块打包到一块，因为只有开发阶段才需要模块文件的划分，来帮我们更好地组织代码，借助 loader 机制可以支持各种类型的文件，比如图片，字体文件，样式文件都可以将其看作为一个模块，这样一来就有了一个统一的模块化方案

webpack4 的话又是那种打包模式，开发模式，生产模式，和 none 模式，none 模式进行最原始的打包，不做任何处理，前两种打包模式都会在一定程度上进行优化，production 模式下，启动内置优化插件，自动优化打包结果，打包速度偏慢，development 模式下，自动优化打包速度，添加一些调试过程中的辅助插件

## 3. loader与plugin原理与实现

每个 Webpack 的 Loader 都需要导出一个函数，这个函数就是我们这个 Loader 对资源的处理过程，它的输入就是加载到的资源文件内容，输出就是我们加工后的结果

Webpack 加载资源文件的过程类似于一个工作管道，你可以在这个过程中依次使用多个 Loader，但是最终这个管道结束过后的结果必须是一段标准的 JS 代码字符串

相比于 Loader，插件的能力范围更宽，因为 Loader 只是在模块的加载环节工作，而插件的作用范围几乎可以触及 Webpack 工作的每一个环节 webpack 的插件机制就是我们在软件开发中最常见的钩子机制,钩子机制也特别容易理解，它有点类似于 Web 中的事件。在 Webpack 整个工作过程会有很多环节，为了便于插件的扩展，Webpack 几乎在每一个环节都埋下了一个钩子。这样我们在开发插件的时候，通过往这些不同节点上挂载不同的任务，就可以轻松扩展 Webpack 的能力

Webpack 要求我们的插件必须是一个函数或者是一个包含 apply 方法的对象，一般我们都会定义一个对象，在这个对象中定义 apply 方法。然后在使用时，再通过这个对象来创建一个实例对象去使用这个插件

这个方法会在 Webpack 启动时被调用，它接收一个 compiler 对象参数，这个对象是 Webpack 工作过程中最核心的对象，里面包含了我们此次构建的所有配置信息，我们就是通过这个对象去注册钩子函数

## 4. Webpack的模块热替换及实现



## 5. Webpack的优化问题

分为两点：构建优化，打包优化

## 6. SPA及其优缺点

优点：

良好的交互体验,用户不需要重新刷新页面，获取数据也是通过 Ajax 异步获取，页面显示流畅。
良好的前后端工作分离模式,单页 Web 应用可以和 RESTful 规约一起使用，通过 REST API 提供接口数据，并使用 Ajax 异步获取，这样有助于分离客户端和服务器端工作。更进一步，可以在客户端也可以分解为静态页面和页面交互两个部分。
减轻服务器压力,服务器只用出数据就可以，不用管展示逻辑和页面合成，吞吐能力会提高几倍；
共用一套后端程序代码,不用修改后端程序代码就可以同时用于 Web 界面、手机、平板等多种客户端；
缺点：

SEO 难度较高,由于所有的内容都在一个页面中动态替换显示，所以在 SEO 上其有着天然的弱势，所以如果你的站点对 SEO 很看重，且要用单页应用，那么就做些静态页面给搜索引擎用吧。
页面复杂都提高，复杂逻辑程度成倍,由于后端只提供数据而不再管前端的展示逻辑和页面合成，所以这些展示逻辑和页面合成都需要在前端进行编写（前进、后退等），所以会大大提高页面的复杂性和逻辑的难度
初次加载耗时多,为实现单页 Web 应用功能及显示效果，需要在加载页面的时候将 JavaScript、CSS 统一加载，部分页面可以在需要的时候加载。所以必须对 JavaScript 及 CSS 代码进行合并压缩处理，如果使用第三方库，建议使用一些大公司的 CDN，因此带宽的消耗是必然的

## 7. SSR实现及优缺点

优点

更利于 SEO，服务端渲染返回给客户端的是已经获取了异步数据并执行 JavaScript 脚本的最终 HTML，网络爬中就可以抓取到完整页面的信息
更利于首屏渲染，首屏的渲染是 node 发送过来的 html 字符串，并不依赖于 js 文件了，这就会使用户更快的看到页面的内容。尤其是针对大型单页应用，打包后文件体积比较大，普通客户端渲染加载所有所需文件时间较长，首页就会有一个很长的白屏等待时间

缺点

服务端压力较大，本来是通过客户端完成渲染，现在统一到服务端 node 服务去做。尤其是高并发访问的情况，会大量占用服务端 CPU 资源
开发条件受限，在服务端渲染中，只会执行到 componentDidMount 之前的生命周期钩子，因此项目引用的第三方的库也不可用其它生命周期钩子，这对引用库的选择产生了很大的限制；
学习成本相对较高，除了对 webpack、React 要熟悉，还需要掌握 node、Koa2 等相关技术。相对于客户端渲染，项目构建、部署过程更加复杂。

## 8. 设计模式（工厂模式、单例模式、原型模式、***模式、适配器模式、观察者模式等...）
# 六、React
## 1. React自身特点及选型时考虑
## 2. React与VUE的异同
## 3. Virtual DOM

Virtual DOM(VDOM) 是Real DOM的内存表示形式。UI 的展示形式被保存在内存中并与真实的 DOM 同步。这是在调用的渲染函数和在屏幕上显示元素之间发生的一个步骤。整个过程被称为reconciliation。

Real DOM vs Virtual DOM



* Virtual DOM分为三个简单的步骤。

每当任何底层数据发生更改时，整个 UI 都将以 Virtual DOM 的形式重新渲染。
然后计算先前 Virtual DOM 对象和新的 Virtual DOM 对象之间的差异。
一旦计算完成，真实的 DOM 将只更新实际更改的内容。


4. React生命周期
5. Diff算法
6. 受控组件与非受控组件
7. 高阶组件
8. Flux架构模式（涉及MVC/MVVM、Flux）
9.  Redux设计概念、设计原则、方法、redux实现异步流的库
10. 纯组件（Pure Component）与shouldComponentUpdate关系
11. Redux中的<Provider/>组件与connect函数
12. React Fiber架构
13. React Hooks的作用及原理
七、NodeJS
1. NodeJS基本概念与特点
2. CommonJS规范、核心模块
3. Node的异步I/O
4. Node的内存控制
5. Node构建网络服务（TCP、HTTP、Web Socket服务等）
6. Node的进程


# 八、需要会手撕的代码部分
1. Promise（A+规范）、then、all方法
2. Iterator遍历器实现
3. Thunk函数实现（结合Generator实现异步）
4. async实现原理（spawn函数）
5. class的继承
## 6. 防抖和节流

* 防抖函数

> 当持续触发事件，一定时间内没有再触发事件，事件处理函数才会执行一次，如果设定的时间到来之前，又一次触发了事件，就重新开始延时
> 触发事件 一段时间内 没有触发 事件执行 肯定是定时器
> (在设定的时间内 没有触发 事件执行 肯定事定时器)
> (那么意味着上一次还没有结束的定时器要清除掉 重新开始)

```js
function debounce(delay,value){
   let timer
 clearInterval(timer)
//我们想清楚的是setTimeout 我们应该储存这个timer的变量
//timer变量需要一直保存在内存当中
  timer=setTimeout(function(){
    console.log(value)
},delay)
}

//我需要做的是，首先，输入框的结果只出现一次，是在我键盘抬起不在输入的1秒之后打印
input.addEventListener('keyup',function(e){
  debounce(1000,e.target.value)
})  

//这里需要用到闭包 
function debounce(delay){
  let timer
  return function(value){
    clearTimeout(timer)
    timer=setTimeout(function(){
    // console.log(value)
    //使用回调函数将数值进行输出
    callback(value)
    },delay)
  }
}
//需要在这里进行位置输出，应该需要回调函数
function callback(value){
  console.log(value);
}

var debounceFunc=debounce(1000)
input.addEventListener('keyup',function(e){
  debounceFunc (e.target.value)
}) 
```

节流函数

* 一段时间内只做一件事情，实际应用，表单的提交：典型的案例就是鼠标不断点击的触发，规定在n秒多次点击只有一次生效

```javascript
//节流函数实现
function thro(func,waittime){
  let timerOut//判断
  return function(){
    if(!timerOut){
      timerOut=setTimeout(function(){
        func();
        timerOut=null
      },waittime)
    }
  }
}

function handle(){
  console.log(Math.random())
}

document.getElementById('button').onclick=thro(handle,2000)

```

* 实际应用

> 使用echarts时，改变浏览器宽度的时候，希望重新渲染echarts的图像，可以使用该函数，提升性能。（虽然echarts里面有自带的resize函数）
> 典型案例就是输入搜索：输入结束n秒后才进行搜索请求，n秒内又输入内容，就重新计时。解决搜索的bug

7. Ajax原生实现
8. 深拷贝的几种方法与比较
9. 继承的几种实现与比较
10. 未知宽高的元素水平垂直居中
## 11. 三栏布局的实现

 float布局、Position定位、table布局、弹性(flex)布局、网格(grid)布局

 这里我们给左右两栏设置float属性使其脱离文档流左边栏设置 float:left, 右边栏设置float: right ,由于宽度高度已知所以我们可以给其设置指定的宽高 width:300px, height:100px，然后最中间的模块要设置margin-left、和margin-right
## 12. 两栏布局的实现

两栏布局（左侧宽度固定，右侧自适应）

* 方法一：float+margin-left：左侧宽度固定，然后使用float:left,右侧盒子使用margin-left：为宽度大小

* 方法二：absolute+margin-left：左侧使用绝对定位，设置宽度大小，然后右侧盒子使用margin-left:宽度大小
* 缺点:1、使用了绝对定位，若是用在某个div中，需要更改父容器的position。2、没有清除浮动的方法，若左侧盒子高于右侧盒子，就会超出父容器的高度。因此只能通过设置父容器的min-height来放置这种情况。


* 方法三：float+BFC：为左侧元素设置浮动后，左侧元素会因为浮动盖在右侧元素上，因此要将右侧元素变成BFC，BFC是一个独立的区域，不会让BFC外的元素对其内部造成干扰。当右侧元素变成一个BFC时它的元素边界会发生变化，会紧紧贴合左侧的元素。
常见的右侧元素设置—-overflow：hidden；

* 方法四：flex布局：
* 方法五：使用display: table;优点，高度不受限制，随内容多少变化，设定的高度会作为最小高度；内容增多，高度随之增高


13.   React高阶组件 
14. 数组去重
15. 几种排序算法的实现及其复杂度比较
16. 前序后序遍历二叉树（非递归）
17. 二叉树深度遍历（分析时间复杂度）
18. 跨域的实现（JSONP、CORS）

浏览器遵循同源政策(scheme(协议)、host(主机)和 port(端口)都相同则为同源)。
非同源站点有这样一些限制: 不能读取和修改对方的 DOM 不读访问对方的 Cookie、IndexDB 和 LocalStorage 限制 XMLHttpRequest 请求。(后面的话题着重围绕这个) 当浏览器向目标 URI 发 Ajax 请求时，只要当前 URL 和目标 URL 不同源，则产生跨域，被称为跨域请求。 跨域请求的响应一般会被浏览器所拦截，注意，是被浏览器拦截，响应其实是成功到达客户端了。那这个拦截是如何发生呢？ 首先要知道的是，浏览器是多进程的，以 Chrome 为例，进程组成如下：

广义上：
1.  资源跳转： A链接、重定向、表单提交
2.  资源嵌入： **link、script、img、frame**等dom标签，还有样式中background:url()、@font-face()等文件外链
3.  脚本请求： js发起的ajax请求、dom和js对象的跨域操作等

跨域解决方案
1. 通过jsonp跨域

JSONP 是服务器与客户端跨源通信的常用方法。最大特点就是简单适用，兼容性好（兼容低版本IE），缺点是只支持get请求，不支持post请求。

核心思想：网页通过添加一个<script>元素，向服务器请求 JSON 数据，服务器收到请求后，将数据放在一个指定名字的回调函数的参数位置传回来。


2. document.domain + iframe跨域
3. location.hash + iframe
4. window.name + iframe跨域
5. postMessage跨域
6. 跨域资源共享（CORS）

ORS 是跨域资源分享（Cross-Origin Resource Sharing）的缩写。它是 W3C 标准，属于跨源 AJAX 请求的根本解决方法。

1、普通跨域请求：只需服务器端设置Access-Control-Allow-Origin

2、带cookie跨域请求：前后端都需要进行设置

【前端设置】根据xhr.withCredentials字段判断是否带有cookie
【服务端设置】服务器端对于CORS的支持，主要是通过设置Access-Control-Allow-Origin来进行的。如果浏览器检测到相应的设置，就可以允许Ajax进行跨域的访问。

7、 nginx代理跨域

在webpack.config.js中利用 WebpackDevServer 配置本地代理，详情配置查看devServer

如下简单配置案例，这样 `http://localhost:8080/api/getUser.php` 的请求就是后端的接口 `http://192.168.25.20:8088/getUser.php`


8、 nodejs中间件代理跨域
9、 WebSocket协议跨域

Websocket 是 HTML5 的一个持久化的协议，它实现了浏览器与服务器的全双工通信，同时也是跨域的一种解决方案。WebSocket 和 HTTP 都是应用层协议，都基于 TCP 协议。但是 WebSocket 是一种双向通信协议，在建立连接之后，WebSocket 的 服务器与 客户端都能主动向对方发送或接收数据。同时，WebSocket 在建立连接时需要借助 HTTP 协议，连接建立好了之后 client 与 server 之间的双向通信就与 HTTP 无关了。

九、数据可视化
1. Canvas和SVG的区别
2. 在考虑设计可视化图表时，结合Canvas和SVG特性会怎么取舍
3. 常见的可视化组件库
4. 可视化组件库如Echarts的设计思路
5. 一些偏向底层的可视化组件库和前端框架结合方面需要考虑哪些问题
6. 可视化组件如何做到数据驱动？
十、计算机基础
1. 计算机系统
2. 线程与进程
3. 常见的git指令
4. Linux相关指令
5. 其他类型的编程语言（如Java）
6. 数据库