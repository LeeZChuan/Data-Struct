const oldObj = {
    name: '李',
    age: 20,
    friend: {
        name: '小明'
    }
}

//这种写法也可，但是不要忘记obj的类型转换
deepClone1=(obj)=>{
    let result;
    if(obj instanceof Date) return new Date(obj)
    if(obj instanceof RegExp) return new RegExp(obj)
    if(typeof obj !=="object"|| obj==null)
    {
        return obj;
        
    } 
    if(obj instanceof Array)
    {
        result=[];
    }else{
        result={};
    }
    for(let key in obj)
    {
        if(obj.hasOwnProperty(key))
        {
            result[key]=deepClone1(obj[key]);
        }
    }
    return result;
}






function deepCopy(obj) {
    let result;
    if (typeof obj !== 'object' || obj == null) {
        return obj;
    }
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


const newObj2=deepClone1(oldObj); 
newObj2.name='小叶';
console.log('oldObj', oldObj);
console.log('newObj', newObj2);

//或者使用conact方法进行深拷贝(仅限于数组对象才可以使用)
const newObj3=oldObj