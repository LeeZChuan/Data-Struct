//对象枚举
/* 
### 如何知道一个对象上的属性是否可以枚举

1. object.hasOwnProperty()方法进行判断对象上属性是否可以枚举
2. Object.getOwnPropertyNames() 返回一个数组
 */

var obj={
    name:"lee",
    age:23,
    sex:"nan",
    job:"it"
}

//for in 方法遍历所有属性
console.log("==========for in========")
for (let p in obj) {
    
    console.info(p)
}
//使用hasOwnProperty
console.log("==========hasOwnProperty()========")
console.log("==========用于单一判断obj对象上是否有该属性========")
console.log("name:"+obj.hasOwnProperty("name"));
console.log("xxx:"+obj.hasOwnProperty("xxx"));

//Object.keys,只能枚举非原型链上得属性
console.log("==========Object.keys========")
console.log(Object.keys(obj));

//使用in来判断属性是否在该对象上
console.log("===========in方法========")
console.log('name' in obj);