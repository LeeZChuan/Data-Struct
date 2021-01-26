# HTML中的JavaScript

将JavaScript引入网页，首先要解决它与网页的主导语言HTML的关系问题。在JavaScript早期，网景公司的工作人员希望在将JavaScript
引入HTML页面的同时，不会导致页面在其他浏览器中渲染出问题。通过反复试错和讨论，他们最终做出了一些决定，并达成了向网页中
引入通用脚本能力的共识。当初他们的很多工作得到了保留，并且最终形成了HTML规范。

## 1.1 <script> 元素

    <script> 元素有下列8个属性。

*  async ：可选。表示应该立即开始下载脚本，但不能阻止其他页面动作，比如下载资源或等待其他脚本加载。只对外部脚本文件有效。
*  charset ：可选。使用 src 属性指定的代码字符集。这个属性很少使用，因为大多数浏览器不在乎它的值。
*  crossorigin ：可选。配置相关请求的CORS（跨源资源共享）设置。默认不使用CORS。
*  crossorigin="anonymous" 配置文件请求不必设置凭据标志。 crossorigin="use-credentials" 设置凭据标志，意味着出站请求会包含凭据。
*  defer ：可选。表示在文档解析和显示完成后再执行脚本是没有问题的。只对外部脚本文件有效。在IE7及更早的版本中，对行内脚本也可以指定这个属性。
*  integrity ：可选。允许比对接收到的资源和指定的加密签名以验证子资源完整性（SRI，Subresource Intergrity）。如果接收到的资源的签名与这个属性指定的签名不匹配，则页面会报错，脚本不会执行。这个属性可以用于确保内容分发网络（CDN，Content Delivery Network）不会提供恶意内容。
*  src ：可选。表示包含要执行的代码的外部文件。
*  type ：可选。代替 language ，表示代码块中脚本语言的内
容类型（也称MIME类型）。按照惯例，这个值始终都
是 "text/javascript" ，尽管 "text/javascript" 和 "text/ecmascript" 都已经废弃了。JavaScript文件的MIME类型通常是 "application/xjavascript" ，不过给type属性这个值有可能导致脚本被忽略。在非IE的浏览器中有效的其他值还有 "application/javascript" 和 "application/ecmascript" 。如果这个值是 module ，则代码会被当成ES6模块，而且只有这时候代码中才能出现 import 和 export 关键字。

使用 <script> 的方式有两种：通过它直接在网页中嵌入JavaScript代码，以及通过它在网页中包含外部JavaScript文件。

要嵌入行内JavaScript代码，直接把代码放在 <script> 元素中就行：

```javascript
<script>
function sayHi() {
console.log("Hi!");
}
</script>
```







