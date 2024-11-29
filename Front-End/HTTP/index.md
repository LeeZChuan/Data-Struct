# HTTP

## 网络请求

* 选择1 Fetch API,
* 选择2 axios请求

### 方案1: axios

- [axios](https://github.com/axios/axios)

基于Vue3框架，一般官方配置就是axios

具体封装可以参考：[axios封装](axios封装.md)



> 核心就是引入axios后：import axios from 'axios';
> 创建axiosInstance实例，配置baseURL, timeout等
> 基于axiosInstance实例，封装请求方法，如get, post, put, delete等



### 方案2: Fetch API

* [Fetch API](https://developer.mozilla.org/zh-CN/docs/Web/API/Fetch_API)
* [Fetch API 教程](https://www.ruanyifeng.com/blog/2020/12/fetch-tutorial.html)


在现如今开源的react框架下，大多数使用fetch作为网络请求

具体封装可以参考：[fetch封装](fetch封装.md)(原生封装)

* 目前有很多网络请求框架:

- [cross-fetch](https://github.com/lquixada/cross-fetch) 1.7k star
- [unfetch](https://github.com/developit/unfetch) 5.7k star
- [whatwg-fetch](https://github.com/JakeChampion/fetch) 25.8k star
- [fetch-event-source](https://github.com/Azure/fetch-event-source) 1.8k star
