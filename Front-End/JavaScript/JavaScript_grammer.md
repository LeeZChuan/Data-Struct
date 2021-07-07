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

数据类型 | 转换为true的值 | 转换为false的值
--- | --- | ---
**Boolean** | true | false
**String** | 非空字符串 | ""(空字符串)
**Number** | 非零数值 | 0、NaN
**Object** | 任意对象 | null
**Undefinead** | 未声明 | undefined

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















