// 实现对象深拷贝 & key下划线转驼峰 
// ( a_bbb => aBbb、a_d_s => aDS ) 
// const testData = {     
//   a_bbb: 123,     
//   a_g: [1, 2, 3, 4],    
//   a_d: {         
//     s: 2,         
//     s_d: 3     },     
//     a_f: [1, 2, 3, 
//     {         
//       a_g: 5     }],     
//     a_d_s: 1 
// }  


const testData = {
    a_bbb: 123,
    a_g: [1, 2, 3, 4],
    a_d: {
        s: 2,
        s_d: 3
    },
    a_f: [1, 2, 3,
        {
            a_g: 5
        }],
    a_d_s: 1
}


/*下划线转驼峰*/
function toHump(name) {
    return name.replace(/\_(\w)/g, function (all, letter) {
        console.log(all);
        console.log(letter);
        //这里正则表达式最后加一个g表达的是匹配所有可能的字串，不加g那么只匹配第一个就结束了
        //然而如何使用的是split方法，加上g与不加g是一样的
        //replace() 方法返回一个由替换值（replacement）替换部分或所有的模式（pattern）匹配项后的新字符串。模式可以是一个字符串或者一个正则表达式，替换值可以是一个字符串或者一个每次匹配都要调用的回调函数。如果pattern是字符串，则仅替换第一个匹配项。
        return letter.toUpperCase();
        //toUpperCase() 方法将调用该方法的字符串转为大写形式并返回（如果调用该方法的值不是字符串类型会被强制转换）。
    });
}


/* 驼峰转换下划线*/
function toLine(name) {
    return name.replace(/([A-Z])/g, "_$1").toLowerCase();
}


const deepClone = (obj) => {
    let result;
    if (obj instanceof Date) return Date(obj);
    if (obj instanceof RegExp) return RegExp(obj);
    if (typeof obj !== "object" || obj == null) {
        return obj;
    }
    if (obj instanceof Array) {
        result = [];
    } else {
        result = {};
    }
    for (let key in obj) {
        // result[key]=obj[key];
        if (obj.hasOwnProperty(key)) {
            let newkey = toHump(key);
            result[newkey] = deepClone(obj[key]);

        }
    }

    return result;

}


let a = deepClone(testData);
console.log("==========展示效果==============")
console.log(a);