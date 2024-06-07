### 问题1: h5与ios调整时遇到的问题，h5滑动的时候app底部会有一小块留白：

h5与ios调整时遇到的问题，h5滑动的时候app底部会有一小块留白：

1.  解决方案1: 原生ios开发可以使用:

```ts
 const webview= new WKWebView();
webview.scrollView.contentInsetAdjustmentBehavior=UIScrollViewContentInsetAdjustmentNever

// contentInsetAdjustmentBehavior这是iosapp中内嵌的浏览器的属性，如果设置成了UIScrollViewContentInsetAdjustmentNever，那么ios就不会给底部一个默认的安全边距；
//但如果设置的是UIScrollViewContentInsetAdjustmentAuto，这时候就会给其设置一个安全边距，这样用户在滑动过程中就会出现底部的白块的问题
```
2. 解决方案2:
`app这边环境需要head里的meta标签添加一个配置viewport-fit=cover；同时要注意每个页面div元素需要充满当前页面，也就是height:100vh`


### 问题2:  ios16.3/4以下的版本无法自动唤起input标签的小键盘
16.4/3以下的版本，直接不支持通过函数调用focus方法；往上就支持了函数调用focus方法；我们可以通过h5页面与app协议调用方法
如果是16.3/4以下app需要修改底层逻辑：hook里，通过方法交换将系统默认的逻辑进行替代，ios机制load生命周期我可以交换页面中的方法，这样我就可以实现我的业务逻辑，实现，AOP面向切片式编程
 
