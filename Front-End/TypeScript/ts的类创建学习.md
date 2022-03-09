### 创建模块结构指导
#### 尽可能地在顶层导出

用户应该更容易地使用你模块导出的内容。 嵌套层次过多会变得难以处理，因此仔细考虑一下如何组织你的代码。

从你的模块中导出一个命名空间就是一个增加嵌套的例子。 虽然命名空间有时候有它们的用处，在使用模块的时候它们额外地增加了一层。 这对用户来说是很不便的并且通常是多余的。

导出类的静态方法也有同样的问题 - 这个类本身就增加了一层嵌套。 除非它能方便表述或便于清晰使用，否则请考虑直接导出一个辅助方法。

如果仅导出单个 class 或 function，使用 export default
就像“在顶层上导出”帮助减少用户使用的难度，一个默认的导出也能起到这个效果。 如果一个模块就是为了导出特定的内容，那么你应该考虑使用一个默认导出。 这会令模块的导入和使用变得些许简单。 比如：
```ts
//类
export default class SomeType {
  constructor() { ... }
}
//方法
export default function getThing() { return 'thing'; }
//使用
import t from "./MyClass";
import f from "./MyFunc";
let x = new t();
console.log(f());

//对用户来说这是最理想的。他们可以随意命名导入模块的类型（本例为t）并且不需要多余的（.）来找到相关对象。
```

```ts
// 如果要导出多个对象，把它们放在顶层里导出
/**MyThings*/
export class SomeType { /* ... */ }
export function someFunc() { /* ... */ }
// 相反地，当导入的时候：

// 明确地列出导入的名字
import { SomeType, someFunc } from "./MyThings";
let x = new SomeType();
let y = someFunc();

//使用命名空间导入模式当你要导出大量内容的时候 
/**MyLargeModule.ts*/
export class Dog { ... }
export class Cat { ... }
export class Tree { ... }
export class Flower { ... }


import * as myLargeModule from "./MyLargeModule.ts";
let x = new myLargeModule.Dog();
```


##### 使用重新导出进行扩展
你可能经常需要去扩展一个模块的功能。 JS里常用的一个模式是JQuery那样去扩展原对象。 如我们之前提到的，模块不会像全局命名空间对象那样去 合并。 推荐的方案是 不要去改变原来的对象，而是导出一个新的实体来提供新的功能。

假设Calculator.ts模块里定义了一个简单的计算器实现。 这个模块同样提供了一个辅助函数来测试计算器的功能，通过传入一系列输入的字符串并在最后给出结果。