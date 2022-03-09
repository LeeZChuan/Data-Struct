# 接口
## 只读属性
一些对象属性只能在对象刚刚创建的时候修改其值。 你可以在属性名前用 readonly来指定只读属性；
```ts
let a: number[] = [1, 2, 3, 4];
let ro: ReadonlyArray<number> = a;
ro[0] = 12; // error!
ro.push(5); // error!
ro.length = 100; // error!
a = ro; // error!
```

上面代码的最后一行，可以看到就算把整个ReadonlyArray赋值到一个普通数组也是不可以的。 但是你可以用类型断言重写：
```ts
a = ro as number[];
```

# 类型断言

有时候你会遇到这样的情况，你会比TypeScript更了解某个值的详细信息。 通常这会发生在你清楚地知道一个实体具有比它现有类型更确切的类型。

通过*类型断言*这种方式可以告诉编译器，“相信我，我知道自己在干什么”。 类型断言好比其它语言里的类型转换，但是不进行特殊的数据检查和解构。 它没有运行时的影响，只是在编译阶段起作用。 TypeScript会假设你，程序员，已经进行了必须的检查。

* 类型断言有两种形式。 其一是“尖括号”语法：

```ts
let someValue: any = "this is a string"; 

let strLength: number = (<string>someValue).length;
```

* 另一个为`as`语法：

```ts
let someValue: any = "this is a string";

let strLength: number = (someValue as string).length;
```

两种形式是等价的。 至于使用哪个大多数情况下是凭个人喜好；然而，当你在TypeScript里使用JSX时，只有 `as`语法断言是被允许的。



## 全新函数类型

为了使用接口表示函数类型，我们需要给接口定义一个调用签名。 
它就像是一个只有参数列表和返回值类型的函数定义。参数列表里的每个参数都需要名字和类型。

```ts
interface SearchFunc {
  (source: string, subString: string): boolean;
}

这样定义后，我们可以像使用其它接口一样使用这个函数类型的接口。 
下例展示了如何创建一个函数类型的变量，并将一个同类型的函数赋值给这个变量。
let mySearch: SearchFunc;
mySearch = function(source: string, subString: string) {
  let result = source.search(subString);
  return result > -1;
}
```

## 可索引的类型
与使用接口描述函数类型差不多，我们也可以描述那些能够“通过索引得到”的类型，
比如a[10]或ageMap["daniel"]。 可索引类型具有一个 索引签名，它描述了对象索引的类型，
还有相应的索引返回值类型。 让我们看一个例子：

```ts
interface StringArray {
  [index: number]: string;
}

let myArray: StringArray;
myArray = ["Bob", "Fred"];

let myStr: string = myArray[0];

//TypeScript支持两种索引签名：字符串和数字
```

## 类-类型
### 实现接口
### 继承接口
和类一样，接口也可以相互继承。 这让我们能够从一个接口里复制成员到另一个接口里，可以更灵活地将接口分割到可重用的模块里。
```ts
interface Shape {
    color: string;
}

interface Square extends Shape {
    sideLength: number;
}

let square = <Square>{};
square.color = "blue";
square.sideLength = 10;
```

接口继承类
当接口继承了一个类类型时，它会继承类的成员但不包括其实现。 就好像接口声明了所有类中存在的成员，但并没有提供具体实现一样。 接口同样会继承到类的private和protected成员。 这意味着当你创建了一个接口继承了一个拥有私有或受保护的成员的类时，这个接口类型只能被这个类或其子类所实现（implement）。

当你有一个庞大的继承结构时这很有用，但要指出的是你的代码只在子类拥有特定属性时起作用。 这个子类除了继承至基类外与基类没有任何关系。

```ts
class Control {
    private state: any;
}

interface SelectableControl extends Control {
    select(): void;
}

class Button extends Control implements SelectableControl {
    select() { }
}

class TextBox extends Control {
    select() { }
}

// 错误：“Image”类型缺少“state”属性。
class Image implements SelectableControl {
    select() { }
}

class Location {

}
```

## 公共，私有与受保护的修饰符
###### 默认为 public
###### private:当成员被标记成 private时，它就不能在声明它的类的外部访问。
###### protected:protected修饰符与 private修饰符的行为很相似，但有一点不同， protected成员在派生类中仍然可以访问。



```ts
class Person {
    protected name: string;
    constructor(name: string) { this.name = name; }
}

class Employee extends Person {
    private department: string;

    constructor(name: string, department: string) {
        super(name)
        this.department = department;
    }

    public getElevatorPitch() {
        return `Hello, my name is ${this.name} and I work in ${this.department}.`;
    }
}

let howard = new Employee("Howard", "Sales");
console.log(howard.getElevatorPitch());
console.log(howard.name); // 错误
```
注意，我们不能在 Person类外使用 name，但是我们仍然可以通过 Employee类的实例方法访问，因为 Employee是由 Person派生而来的。

### readonly修饰符
你可以使用 readonly关键字将属性设置为只读的。 只读属性必须在声明时或构造函数里被初始化。

## 存取器
TypeScript支持通过getters/setters来截取对对象成员的访问。 它能帮助你有效的控制对对象成员的访问。

下面来看如何把一个简单的类改写成使用 get和 set。 首先，我们从一个没有使用存取器的例子开始。
```ts
class Employee {
    fullName: string;
}

let employee = new Employee();
employee.fullName = "Bob Smith";
if (employee.fullName) {
    console.log(employee.fullName);
}
```
我们可以随意的设置 fullName，这是非常方便的，但是这也可能会带来麻烦。

下面这个版本里，我们先检查用户密码是否正确，然后再允许其修改员工信息。 我们把对 fullName的直接访问改成了可以检查密码的 set方法。 我们也加了一个 get方法，让上面的例子仍然可以工作。
```ts
let passcode = "secret passcode";

class Employee {
    private _fullName: string;

    get fullName(): string {
        return this._fullName;
    }

    set fullName(newName: string) {
        if (passcode && passcode == "secret passcode") {
            this._fullName = newName;
        }
        else {
            console.log("Error: Unauthorized update of employee!");
        }
    }
}

let employee = new Employee();
employee.fullName = "Bob Smith";
if (employee.fullName) {
    alert(employee.fullName);
}
```

## this和箭头函数


## 泛型
我们需要一种方法使返回值的类型与传入参数的类型是相同的。 这里，我们使用了 类型变量，它是一种特殊的变量，只用于表示类型而不是值。
```ts
function identity<T>(arg: T): T {
    return arg;
}
```
使用泛型变量
使用泛型创建像identity这样的泛型函数时，编译器要求你在函数体必须正确的使用这个通用的类型。
换句话说，你必须把这些参数当做是任意或所有类型。
### 泛型多多理解

## 枚举

使用枚举我们可以定义一些带名字的常量。 使用枚举可以清晰地表达意图或创建一组有区别的用例。 TypeScript支持数字的和基于字符串的枚举。

## 高级类型需要再学习一下

##### 联合类型（Union Types）

联合类型表示一个值可以是几种类型之一。 我们用竖线（ `|`）分隔每个类型，所以 `number | string | boolean`表示一个值可以是 `number`， `string`，或 `boolean`。

如果一个值是联合类型，我们只能访问此联合类型的所有类型里共有的成员。

```ts
interface Bird {
    fly();
    layEggs();
}

interface Fish {
    swim();
    layEggs();
}

function getSmallPet(): Fish | Bird {
    // ...
}

let pet = getSmallPet();
pet.layEggs(); // okay
pet.swim();    // errors
```

### Symbols

Symbols是不可改变且唯一的。

```ts
let sym2 = Symbol("key");
let sym3 = Symbol("key");

sym2 === sym3; // false, symbols是唯一的
```
像字符串一样，symbols也可以被用做对象属性的键。
```ts
let sym = Symbol();

let obj = {
    [sym]: "value"
};

console.log(obj[sym]); // "value"
```
Symbols也可以与计算出的属性名声明相结合来声明对象的属性和类成员。
```ts
const getClassNameSymbol = Symbol();

class C {
    [getClassNameSymbol](){
       return "C";
    }
}

let c = new C();
let className = c[getClassNameSymbol](); // "C"
```
## 迭代器和生成器
### 可迭代性
#### for..of 语句
for..of会遍历可迭代的对象，调用对象上的Symbol.iterator方法。 下面是在数组上使用 for..of的简单例子：
```ts
let someArray = [1, "string", false];

for (let entry of someArray) {
    console.log(entry); // 1, "string", false
}
```
#### for..of vs. for..in 语句
for..of和for..in均可迭代一个列表；但是用于迭代的值却不同，for..in迭代的是对象的 键 的列表，而for..of则迭代对象的键对应的值。

下面的例子展示了两者之间的区别：
```ts
let list = [4, 5, 6];

for (let i in list) {
    console.log(i); // "0", "1", "2",
}

for (let i of list) {
    console.log(i); // "4", "5", "6"
}
```
另一个区别是for..in可以操作任何对象；它提供了查看对象属性的一种方法。 但是 for..of关注于迭代对象的值。内置对象Map和Set已经实现了Symbol.iterator方法，让我们可以访问它们保存的值。

## 模块-重要
### 导出
#### 导出声明
任何声明（比如变量，函数，类，类型别名或接口）都能够通过添加export关键字来导出。
```ts
export interface StringValidator {
    isAcceptable(s: string): boolean;
}
//或者
export const numberRegexp = /^[0-9]+$/;

export class ZipCodeValidator implements StringValidator {
    isAcceptable(s: string) {
        return s.length === 5 && numberRegexp.test(s);
    }
}
```
导出语句很便利，因为我们可能需要对导出的部分重命名，所以上面的例子可以这样改写：
```ts
class ZipCodeValidator implements StringValidator {
    isAcceptable(s: string) {
        return s.length === 5 && numberRegexp.test(s);
    }
}
export { ZipCodeValidator };
export { ZipCodeValidator as mainValidator };
```
我们经常会去扩展其它模块，并且只导出那个模块的部分内容。 重新导出功能并不会在当前模块导入那个模块或定义一个新的局部变量。
```ts
export class ParseIntBasedZipCodeValidator {
    isAcceptable(s: string) {
        return s.length === 5 && parseInt(s).toString() === s;
    }
}

// 导出原先的验证器但做了重命名
export {ZipCodeValidator as RegExpBasedZipCodeValidator} from "./ZipCodeValidator";
```
或者一个模块可以包裹多个模块，并把他们导出的内容联合在一起通过语法：export * from "module"。

### 导入
模块的导入操作与导出一样简单。 可以使用以下 import形式之一来导入其它模块中的导出内容。

> 导入一个模块中的某个导出内容
```ts
import { ZipCodeValidator } from "./ZipCodeValidator";
let myValidator = new ZipCodeValidator();

// 可以对导入内容重命名
import { ZipCodeValidator as ZCV } from "./ZipCodeValidator";
let myValidator = new ZCV();

// 将整个模块导入到一个变量，并通过它来访问模块的导出部分
import * as validator from "./ZipCodeValidator";
let myValidator = new validator.ZipCodeValidator();

//类和函数声明可以直接被标记为默认导出。 标记为默认导出的类和函数的名字是可以省略的
/**ZipCodeValidator.ts*/
export default class ZipCodeValidator {
    static numberRegexp = /^[0-9]+$/;
    isAcceptable(s: string) {
        return s.length === 5 && ZipCodeValidator.numberRegexp.test(s);
    }
}
import validator from "./ZipCodeValidator";

let myValidator = new validator();
// 或者
/**StaticZipCodeValidator.ts*/
const numberRegexp = /^[0-9]+$/;

export default function (s: string) {
    return s.length === 5 && numberRegexp.test(s);
}

import validate from "./StaticZipCodeValidator";

let strings = ["Hello", "98052", "101"];

// Use function validate
strings.forEach(s => {
  console.log(`"${s}" ${validate(s) ? " matches" : " does not match"}`);
});


```

##### export = 和 import = require()
CommonJS和AMD的环境里都有一个exports变量，这个变量包含了一个模块的所有导出内容。

CommonJS和AMD的exports都可以被赋值为一个对象, 这种情况下其作用就类似于 es6 语法里的默认导出，即 export default语法了。虽然作用相似，但是 export default 语法并不能兼容CommonJS和AMD的exports。

为了支持CommonJS和AMD的exports, TypeScript提供了export =语法。

export =语法定义一个模块的导出对象。 这里的对象一词指的是类，接口，命名空间，函数或枚举。

若使用export =导出一个模块，则必须使用TypeScript的特定语法import module = require("module")来导入此模块。


##### 生成模块代码
根据编译时指定的模块目标参数，编译器会生成相应的供Node.js (CommonJS)，Require.js (AMD)，UMD，SystemJS或ECMAScript 2015 native modules (ES6)模块加载系统使用的代码。 想要了解生成代码中 define，require 和 register的意义，请参考相应模块加载器的文档。

下面的例子说明了导入导出语句里使用的名字是怎么转换为相应的模块加载器代码的。

##### 使用其它的JavaScript库
要想描述非TypeScript编写的类库的类型，我们需要声明类库所暴露出的API。

我们叫它声明因为它不是“外部程序”的具体实现。 它们通常是在 .d.ts文件里定义的。 如果你熟悉C/C++，你可以把它们当做 .h文件。 让我们看一些例子。

外部模块
在Node.js里大部分工作是通过加载一个或多个模块实现的。 我们可以使用顶级的 export声明来为每个模块都定义一个.d.ts文件，但最好还是写在一个大的.d.ts文件里。 我们使用与构造一个外部命名空间相似的方法，但是这里使用 module关键字并且把名字用引号括起来，方便之后import。 例如：

```ts
declare module "url" {
    export interface Url {
        protocol?: string;
        hostname?: string;
        pathname?: string;
    }

    export function parse(urlStr: string, parseQueryString?, slashesDenoteHost?): Url;
}

declare module "path" {
    export function normalize(p: string): string;
    export function join(...paths: any[]): string;
    export let sep: string;
}
```



