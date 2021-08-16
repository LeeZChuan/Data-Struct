// 相对于 Promise.all 需要所有 promise都成功时才 resolve或者有一个失败时即reject，Promise.allSettled 只关心所有 promise 是不是都被 settle 了，不管其是 rejected状态的 promise，还是非 rejected状态(即fulfilled)的 promise, 我都可以拿到它的最终状态并对其进行处理

// Promise.allSettled 的结果数组中可能包含以下两种格式的数据

// {status:"fulfilled", value:result} 对于成功的响应
// {status:"rejected", reason:error} 对于 error

// var a=Object.prototype.toString("a");
var a=Object.prototype.toString.call("a");
var b={
    name:"li",
    age:15
}

var array=[3,55,22,123,6,7,9,233,2,15]
console.log(a);
console.log(b);
console.log(array.sort(array,0,5));