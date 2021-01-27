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
>注意：另外，使用了 src 属性的 <script> 元素不应该再在<script> 和 </script> 标签中再包含其他JavaScript代码。如果两者都提供的话，则浏览器只会下载并执行脚本文件，从而忽略行内代码。

要包含外部文件中的JavaScript，就必须使用 src 属性。这个属性的值是一个URL，指向包含JavaScript代码的文件，比如：
```javascript
1.<script src="example.js"></script>
2.<script src="http://www.somewhere.com/afile.js"></script>

```
    💣前端安全问题：
    对于2，=>要注意来自外部域的代码会被当成加载它的页面的一部分来加载和解释。这个能力可以让我们通过不同的域分发JavaScript。不过，引用了
    放在别人服务器上的JavaScript文件时要格外小心，因为恶意的程序员随时可能替换这个文件。在包含外部域的JavaScript文件时，要确保该
    域是自己所有的，或者该域是一个可信的来源。 <script> 标签的integrity 属性是防范这种问题的一个武器，但这个属性也不是所有浏览器都支持。

## 1.2 标签占位符

过去，所有 <script> 元素都被放在页面的 <head> 标签内，

这种做法的主要目的是把外部的CSS和JavaScript文件都集中放到一起。不过，把所有JavaScript文件都放在 <head> 里，也就意味着
必须把所有JavaScript代码都下载、解析和解释完成后，才能开始渲染页面（页面在浏览器解析到 <body> 的起始标签时开始渲染）。
对于需要很多JavaScript的页面，这会导致页面渲染的明显延迟，在此期间浏览器窗口完全空白。为解决这个问题，现代Web应用程序通常将所
有JavaScript引用放在 <body> 元素中的页面内容后面，如下面的例子所示：

```javascript
<!DOCTYPE html>
<html>
<head>
<title>Example HTML Page</title>
</head>
<body>
<!-- 这里是页面内容 -->
<script src="example1.js"></script>
<script src="example2.js"></script>
</body>
</html>
```

这样一来，页面会在处理JavaScript代码之前完全渲染页面。用户会感觉页面加载更快了，因为浏览器显示空白页面的时间短了。

## 1.3 推迟执行脚本（可以加快/优化运行效率）

* HTML 4.01为 <script> 元素定义了一个叫 defer 的属性。这个属性表示脚本在执行的时候不会改变页面的结构。因此，这个脚本
完全可以在整个页面解析完之后再运行。在 <script> 元素上设置defer 属性，会告诉浏览器应该立即开始下载，但执行应该推迟：


```javascript
<!DOCTYPE html>
<html>
<head>
<title>Example HTML Page</title>
<script defer src="example1.js"></script>
<script defer src="example2.js"></script>
</head>
<body>
<!-- 这里是页面内容 -->
</body>
</html>
```

* 虽然这个例子中的 <script> 元素包含在页面的 <head> 中，但它们会在浏览器解析到结束的 </html> 标签后才会执行。HTML5
规范要求脚本应该按照它们出现的顺序执行，因此第一个推迟的脚本会在第二个推迟的脚本之前执行，而且两者都会在
DOMContentLoaded 事件之前执行（关于事件，请参考第17章）。不过在实际当中，推迟执行的脚本不一定总会按顺序执行或者在
DOMContentLoaded 事件之前执行，因此最好只包含一个这样的脚本。

* 对 defer 属性的支持是从IE4、Firefox 3.5、Safari 5和Chrome 7开始的。其他所有浏览器则会忽略这个属性，按照通常的做法来处理
脚本。考虑到这一点，还是把要推迟执行的脚本放在页面底部比较好。



      注意 对于XHTML文档，指定 defer 属性时应该写成defer="defer" 。  

## 1.4 异步执行脚本

HTML5为 <script> 元素定义了 async 属性。 async 属性与 defer 类似。当然，它们两者也都只适用于外部脚本，都会告诉浏览器立即开始下载。不过，与 defer不同的是，标记为 async 的脚本并不保证能按照它们出现的次序执行

      注意 对于XHTML文档，指定 async 属性时应该写成async="async" 。

## 1.5 动态加载脚本

除了 <script> 标签，还有其他方式可以加载脚本。因为JavaScript可以使用DOM API，所以通过向DOM中动态添加 script元素同样可以加载指定的脚本。只要创建一个 script 元素并将其添加到DOM即可。

```javascript
let script = document.createElement('script');
script.src = 'gibberish.js';
document.head.appendChild(script);
```













