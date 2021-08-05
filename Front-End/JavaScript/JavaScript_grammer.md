
- [JavaScript的语法](#javascript的语法)
  - [1.1 区分大小写](#11-区分大小写)
  - [1.2 标识符](#12-标识符)
  - [1.3 注释](#13-注释)
  - [1.4关键字与保留字](#14关键字与保留字)
  - [1.5 var 关键字](#15-var-关键字)
  - [1.6 let 声明](#16-let-声明)
    - [1.7 const 声明](#17-const-声明)
    - [1.8 Undefined 类型](#18-undefined-类型)
    - [1.9 Null 类型](#19-null-类型)
    - [1.10 Boolean 类型](#110-boolean-类型)
    - [1.11 Number 类型](#111-number-类型)
  - [2 箭头函数](#2-箭头函数)
  - [3 关系操作符](#3-关系操作符)
    - [3.1相等操作符](#31相等操作符)
    - [3.2 全等和不全等](#32-全等和不全等)
    - [3.3 总结](#33-总结)
  - [4 变量、作用域与内存](#4-变量作用域与内存)
    - [4.1 动态属性](#41-动态属性)
    - [4.2 赋值](#42-赋值)
  - [5.基本引用类型](#5基本引用类型)
    - [5.1 RegExp类型支持正则表达式](#51-regexp类型支持正则表达式)
    - [5.2原始值包装类型](#52原始值包装类型)
  - [6.Promise、async与await](#6promiseasync与await)
    - [6.1 Promise](#61-promise)
    - [6.2 Promise的then，catch如何改变promise状态](#62-promise的thencatch如何改变promise状态)
  - [7.深拷贝与浅拷贝](#7深拷贝与浅拷贝)
  - [8.Math](#8math)

# JavaScript的语法

## 1.1 区分大小写

## 1.2 标识符

* 第一个字符必须是一个字母、下划线（ _ ）或美元符号（ $ ）；
* 剩下的其他字符可以是字母、下划线、美元符号或数字。

## 1.3 注释

采用C语言风格的注释
// 单行注释
块注释以一个斜杠和一个星号（ /* ）开头，以它们的反向组合（ */ ）结尾

## 1.4关键字与保留字

ECMA-262描述了一组保留的关键字，这些关键字有特殊用途，比如表示控制语句的开始和结束，或者执行特定的操作。按照规定，
保留的关键字不能用作标识符或属性名。ECMA-262第6版规定的所有关键字如下：

## 1.5 var 关键字

1. var 声明作用域

关键的问题在于，使用 var 操作符定义的变量会成为包含它的
函数的局部变量。比如，使用 var 在一个函数内部定义一个变
量，就意味着该变量将在函数退出时被销毁：

```javascript
function test() {
var message = "hi"; // 局部变量
}
test();
console.log(message); // 出错！
```
2. var 声明提升

      使用 var 时，下面的代码不会报错。这是因为使用这个关键字声明的变量会自动提升到函数作用域顶部：

```javascript
function foo() {
console.log(age);
var age = 26;
}
foo(); // undefined
```

     这就是所谓的“提升”（hoist），也就是把所有变量声明都拉到函数作用域的顶部。此外，反复多次使用 var 声明同一个变量也没有问题：

## 1.6 let 声明

let 跟 var 的作用差不多，但有着非常重要的区别。最明显的区别是， **let 声明的范围是块作用域，而 var 声明的范围是函数作用域。**

1. 暂时性死区

let 与 var 的另一个重要的区别，就是 let 声明的变量不会在作用域中被提升。

```javascript
// name会被提升
console.log(name); // undefined
var name = 'Matt';
// age不会被提升
console.log(age); // ReferenceError：age没有定
义
let age = 26;
```
     let 声明之前的执行瞬间被称为“暂时性死区”（temporal deadzone），在此阶段引用任何后面才声明的变量都会抛出ReferenceError


2. 全局声明

与 var 关键字不同，使用 let 在全局作用域中声明的变量不会成为 window 对象的属性（ var 声明的变量则会）。

```javascript
// name会被提升
var name = 'Matt';
console.log(window.name); // 'Matt'
let age = 26;
console.log(window.age); // undefined
```
不过， let 声明仍然是在全局作用域中发生的，相应变量会在页面的生命周期内存续。因此，为了避免 SyntaxError ，必须确保页面不会重复声明同一个变量。


3. 条件声明


4. for 循环中的 let 声明

在 let 出现之前， for 循环定义的迭代变量会渗透到循环体外部
改成使用 let 之后，这个问题就消失了，因为迭代变量的作用域仅限于 for 循环块内部
在使用 var 的时候，最常见的问题就是对迭代变量的奇特声明和修改:

```javascript
for (var i = 0; i < 5; ++i) {
setTimeout(() => console.log(i), 0)
}
// 你可能以为会输出0、1、2、3、4
// 实际上会输出5、5、5、5、5
```

之所以会这样，是因为在退出循环时，迭代变量保存的是导致循
环退出的值：5。在之后执行超时逻辑时，所有的 i 都是同一个
变量，因而输出的都是同一个最终值。

### 1.7 const 声明

const 的行为与 let 基本相同，唯一一个重要的区别是用它声明变量时必须同时初始化变量，且尝试修改 const 声明的变量会导致运行时错误。

      不过，如果你只想用 const 声明一个不会被修改的 for 循环变量，那也是可以的。也就是说，每次迭代只是创建一个新变量。这对for-of 和 for-in 循环特别有意义：

```javascript
let i = 0;
for (const j = 7; i < 5; ++i) {
console.log(j);
}
// 7, 7, 7, 7, 7
for (const key in {a: 1, b: 2}) {
console.log(key);
}
// a, b
for (const value of [1,2,3,4,5]) {
console.log(value);
}
// 1, 2, 3, 4, 5

```

### 1.8 Undefined 类型

Undefined 类型只有一个值，就是特殊值 undefined 。当使用 var 或 let 声明了变量但没有初始化时，就相当于给变量赋予了 undefined 值：

### 1.9 Null 类型

Null 类型同样只有一个值，即特殊值 null 。逻辑上讲，null 值表示一个空对象指针，这也是给 typeof 传一个 null 会返回 "object" 的原因.

在定义将来要保存对象值的变量时，建议使用 null 来初始化，不要使用其他值。这样，只要检查这个变量的值是不是 null 就可以知道这个变量是否在后来被重新赋予了一个对象的引用，比如：

```javascript
if (car != null) {
// car是一个对象的引用
}
```

### 1.10 Boolean 类型

| 数据类型       | 转换为true的值 | 转换为false的值 |
| -------------- | -------------- | --------------- |
| **Boolean**    | true           | false           |
| **String**     | 非空字符串     | ""(空字符串)    |
| **Number**     | 非零数值       | 0、NaN          |
| **Object**     | 任意对象       | null            |
| **Undefinead** | 未声明         | undefined       |

### 1.11 Number 类型

八进制的第一个数字必须是零（0），然后是相应的八进制数字（数值0~7）.如果字面量
中包含的数字超出应有的范围，就会忽略前缀的零，后面的数字序列会被当成十进制数，


而在ES6的八进制通过前缀**0o**来表示，同样的真正的十六进制字面量，必须使用数值前缀**0x**

## 2 箭头函数


   箭头函数不会创建自己this，他只会从自己的作用域链上一层继承this

   不绑定arguments对象

   箭头函数不能用作构造器，和new一起用会出错

   箭头函数没有prototype属性

   返回对象字面量：需要用圆括号把对象字面量包起来：var func=()=>({foo:1});

   箭头函数在参数和箭头之间不能换行


箭头函数也可以使用闭包：

```javascript
//标准的闭包
function A(){
      var i=0;
      return function b(){
            return(++i);
      }
}

var V=A();

V();

//箭头函数的闭包
var A=(i=0)=>{
      return(()=>(++i))
}
var v=A();

v();
v();

```
## 3 关系操作符

### 3.1相等操作符

1. 等于和不等于：等于号用（==）表示，不等于使用（!=）表示，在使用两个操作符都会先进行类型转换（通常称为强制类型转换）
2. 如果在进行相等或者不等操作，一般**false**与**true**分别转化为0与1
3. 如果一个操作数是字符串，另一个操作数是数，则将字符串转化城数值再进行比较
4. 如果一个操作数是对象，另一个操作数不是，则调用对象的valueOf()方法取得其原始值，再根据前面的规则进行比较

常见样式
表达式 结果

    null == undefined true
    "NaN" == NaN false
    5 == NaN false
    NaN == NaN false
    NaN != NaN true
    false == 0 true
    true == 1 true
    true == 2 false
    undefined == 0 false
    null == 0 false
    "5" == 5 true     

### 3.2 全等和不全等

全等操作符由三个等于号表示，只有两个操作数在不转换得前提下相等才返回true


### 3.3 总结

ES6得基本数据类型包括Undefined、Null、Boolean、Number、String和Symbol

ES6不区分整数和浮点数，只有Number一种数值数据类型


## 4 变量、作用域与内存

### 4.1 动态属性

```javascript
let name1 = "Nicholas";
let name2 = new String("Matt");
name1.age = 27;
name2.age = 26;
console.log(name1.age); // undefined
console.log(name2.age); // 26
console.log(typeof name1); // string
console.log(typeof name2); // object
```

### 4.2 赋值

>  原始值与引用值通过变量赋值时，再通过变量吧一个原始值赋值到另一个变量时，原始值会被复制到新变量得位置；这里复制得值实际上一个指针，他指向存储在堆内存中得对象。完成赋值操作后，两个变量实际上指向同一个对象，因此一个对象上面得变化会在另一个对象上反应出来
>  对于var声明变量时，变量会被自动添加到最接近得上下文（如果var变量声明得在函数的局部上下文，那么函数外侧也无法获取到该变量）
> 如果变量没有声明就被初始化了，那么他会自动被添加到全局上下文(这个就是内存泄漏)
> 在ES6所提到的let不会像var对象那样导致变量提升，



```javascript
let name1 = "Nicholas";
let name2 = new String("Matt");
name1.age = 27;
name2.age = 26;
console.log(name1.age); // undefined
console.log(name2.age); // 26
console.log(typeof name1); // string
console.log(typeof name2); // object
```

## 5.基本引用类型

### 5.1 RegExp类型支持正则表达式



### 5.2原始值包装类型


## 6.Promise、async与await

### 6.1 Promise

   解决的是将程序异步执行变成同步执行

- 执行async函数，返回的都是Promise对象

```javascript
async function test1()
{
      return 1;
}

async funcation test2(){
      return Promise.resolve(2);
}

//以上两个输出都是Promise对象

//Promise.then成功的情况对应await

async function test3(){
      const p3=Promise.resolve(3);
      p3.then(data=>{
            console.log('data',data);
      })

      const data=await p3;
}

async function test4() {
	const data = await 4;//await Promise.resolve(4);
	console.log('data', data);

}

test4();

```
[Promise例子](./原理实现/Promise/Promise.html)

### 6.2 Promise的then，catch如何改变promise状态

- then正常返回的时候，Promise的状态是fulfilled
- 报错的时候Promise的状态是rejected
- catch正常返回的时候Promise的状态是fulfilled，
- 报错返回的状态是rejected



- fulfilled状态的Promise会执行then里面的回调函数
- rejected状态的Promise会执行catch里面的回调函数



* 如果回调函数throw了一个Error的话，那么这个Promise的状态就回变成rejected


## 7.深拷贝与浅拷贝

- 浅拷贝由于引用是指针上的引用，没有改变对象的储存地址，当在引用对象进行了修改，原始数据上也会进行修改
- 而深拷贝，当拷贝完成，那么你在修改新的对象的时候，并不会出现原始对象也被修改的情况
- 内存中有栈区和堆区，基本类型数据直接存在栈中，而引用类型（new出来的）是在堆中存储，在栈中保存堆中的地址。
- 也就是说引用类型中在栈中存的不是数据，而是地址。赋值其实就是拷贝。在基本类型数据赋值的时候，没有深浅拷贝的区别，因为直接赋予的是数据。
- 但在引用类型数据赋值的时候，实际上是把原来的地址复制给了新的，并没有实际复制其中的数据，所以这是一个浅拷贝（拷贝的深度不够），
- 当使用新的变量操作地址中的值的时候，旧变量对应的值也会发生改变。Java中Object的clone方法默认是浅拷贝。
- 深拷贝会创造另外一个一模一样的对象，新对象和原来的对象不共享内存，修改新对象不会影响旧对象。


```javascript
function deepCopy(obj) {
    if (typeof obj !== 'object' || obj == null) {
        return obj;
    }
    let result;
    if (obj instanceof Array) {
        result = [];
    } else {
        result = {};
    }
    //开始拷贝
    for (let key in obj) {
        // result[key] = obj[key];//深拷贝核心--一层克隆
        if(obj.hasOwnProperty(key)){
              //hasOwnProperty() 方法会返回一个布尔值，指示对象自身属性中是否具有指定的属性（也就是，是否有指定的键）。
            result[key]=deepCopy(obj[key]);//递归调用嵌套对象就不会被影响到
        }
    }
    return result;
}

//对于数组对象的深拷贝则有两个方法

//（1）for循环实现数组的深拷贝
//（2）concat 方法实现数组的深拷贝

concat() 方法用于连接两个或多个数组。

//(3)slice 方法实现数组的深拷贝

arrayObject.slice(start,end)

//（4）ES6扩展运算符实现数组的深拷贝
// ...扩展运算符是ES6的语法，使用起来非常的方便简洁，相信在写ES6的时候也是备受欢迎的。但是需要注意的是：用扩展运算符对数组或者对象进行拷贝时，只能扩展和深拷贝第一层的值，对于第二层极其以后的值，扩展运算符将不能对其进行打散扩展，也不能对其进行深拷贝，即拷贝后和拷贝前第二层中的对象或者数组仍然引用的是同一个地址，其中一方改变，另一方也跟着改变。

1 var arr1 = [1, 2, 3];
2 var [...arr2] = arr1;
3 arr1[0] = 4;
4 console.log(arr1); //4, 2, 3
5 console.log(arr2); //1, 2, 3
```

## 8.Math

  Math()方法一般常有random()方法返回一个0-1范围内的随机数，其中包含0不包含1，
  ceil()方法始终向上舍入为最接近的整数。
  floor()方法始终向下舍入为最接近的整数。
  注意：如果是想要为了加密而需要生成随机数，建议使用window.crpto.getRandomValues()

