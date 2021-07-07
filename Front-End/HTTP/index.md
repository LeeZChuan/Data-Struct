# HTTP

## 网络请求

* 选择1 Fetch API,
* 选择2 axios请求

### axios：ajax i/o system

可以使用httpbin.org这个网站进行网络请求设计

* 按照以往的类组件写法，一般会将网络请求放在componentDidMount()


   await async来实现axios的数据读取使用try catch方法

```javascript
try{
    const =result =await axios.get("xxx",{
        params:{
            name:xxx,
            age:xxx
        }
    })
    console.log(result);
}caatch(err){
    console.log(err);
}
```

