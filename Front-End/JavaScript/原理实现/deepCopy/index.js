const oldObj = {
    name: '李',
    age: 20,
    friend: {
        name: '小明'
    }
}

const newObj1 = oldObj;
newObj1.name = '王';

console.log('浅拷贝，这时候虽然是newObj进行赋值但是改变的是原始对象的引用地址的数据也改变了');
console.log('oldObj', oldObj);
console.log('newObj', newObj1);


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

            result[key]=deepCopy(obj[key]);//递归调用嵌套对象就不会被影响到
        }
    }

    return result;
}


const newObj2=deepCopy(oldObj); 
newObj2.name='小叶';
console.log('oldObj', oldObj);
console.log('newObj', newObj2);

//或者使用conact方法进行深拷贝(仅限于数组对象才可以使用)
const newObj3=oldObj