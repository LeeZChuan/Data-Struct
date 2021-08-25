let f = function () {
    this.a = 1;
    this.b = 2;
};
let o = new f();   // {a: 1, b: 2}
f.prototype.b = 3;
f.prototype.c = 4;
console.log("for in遍历")
for (let i in o) {
    console.log(i) //a,b,c
}

console.log("只遍历不在原型链上的对象属性")

for (let i in o) {
    if (o.hasOwnProperty(i)) {
        console.log(i)  //a,b
    }

}


console.log("object.keys")

console.log(Object.keys(o));


