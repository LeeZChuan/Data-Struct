let arr = [1, [2, [3, 4]],[6,7,8]];
let arr1 = [1, [2, [3, 4]],[6,7,8]];
let arr2 = [1, [2, [3, 4]],[6,7,8]];
let obj=[{name:"Lee",age:17,class:7},{name:"ZZ",age:18,class:3}]
//console.log(flatten(arr)) // [1, 2, 3, 4]
// console.log(arr.concat(arr1,arr2));
// console.log(Object.keys(arr));
console.log(obj.map((item,index,array)=>{
    return item
}))

console.log(Object.prototype.toString.call(function(){}));//[object Function]
console.log(Object.prototype.toString.call([]));//[object Array]
console.log(Object.prototype.toString.call(new Date));//[object Date]

console.log(obj.filter(item=>{
    return item;
}))

//1.常规方式 递归处理
//Array.isArray() 用于确定传递的值是否是一个 Array
var result=[];
const flattern_recursion=(arr)=>{
    for(let i=0;i<arr.length;i++)
    {
        if(Array.isArray(arr[i]))
        {
            //如果是一个数组那么递归
            flattern_recursion(arr[i])
        }else{
            result.push(arr[i])
        }
    }
    return result;
}
console.log("递归调用")
console.log(flattern_recursion(arr));

//2.toString() 与 & split方法返回一个表示该对象的字符串
//toString() 返回一个字符串，表示指定的数组及其元素
//这是mdn官方文档对这个方法的解释，讲到这里就不得不提到拆箱操作，在 JavaScript 标准中，规定了 ToPrimitive 函数，它是对象类型到基本类型的转换(即， 拆箱转换)。
const flattern_toString=(arr)=>{
    return arr.toString().split(',').map((item)=>{
       return Number(item)
    })
}

console.log("toString & split");
console.log(flattern_toString(arr));

//3. 使用es6扩展运算符
//some() 方法测试数组中是不是至少有1个元素通过了被提供的函数测试。它返回的是一个Boolean类型的值。
const flattern_es6=(arr)=>{
    while(arr.some(item => Array.isArray(item))){
        arr=[].concat(...arr);
    }
    return arr;
}

console.log("es6...运算符");
console.log(flattern_es6(arr));

//4. 使用join()方法
//join() 方法将一个数组（或一个类数组对象）的所有元素连接成一个字符串并返回这个字符串。如果数组只有一个项目，那么将返回该项目而不使用分隔符。

const flattern_join=(arr)=>{
    return arr.join().map((item)=>{
        return Number(item);
    })
}

console.log("join");
console.log(flattern_toString(arr));

//5. 使用 reduce()方法
//reduce() 方法对数组中的每个元素执行一个由您提供的reducer函数(升序执行)，将其结果汇总为单个返回值。

const flattern_reduce=(arr)=>{
    return arr.reduce((result, item)=> {
        return result.concat(Array.isArray(item) ? flattern_reduce(item) : item);
    }, []);
}

console.log("reduce");
console.log(flattern_reduce(arr));