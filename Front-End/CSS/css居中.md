# 水平居中

## 对于行内元素: 

* text-align: center;


## 对于确定宽度的块级元素：

width和margin实现。margin: 0 auto;


绝对定位和margin-left: -width/2, 前提是父元素position: relative(相对定位)


## 对于宽度未知的块级元素
    

table标签配合margin左右auto实现水平居中。使用table标签（或直接将块级元素设值为display:table），再通过给该标签添加左右margin为auto。


inline-block实现水平居中方法。display：inline-block和text-align:center实现水平居中。


绝对定位+transform，translateX可以移动本身元素的50%。


flex布局使用justify-content:center


# 垂直居中

利用line-height实现居中，这种方法适合纯文字类


通过设置父容器相对定位，子级设置绝对定位，标签通过margin实现自适应居中


弹性布局flex:父级设置display: flex; 子级设置margin为auto实现自适应居中


父级设置相对定位，子级设置绝对定位，并且通过位移transform实现


table布局，父级通过转换成表格形式，然后子级设置vertical-align实现。（需要注意的是：vertical-align: middle使用的前提条件是内联元素以及display值为table-cell的元素）。

# 浮动布局的优点？有什么缺点？清除浮动有哪些方式？

浮动布局简介:当元素浮动以后可以向左或向右移动，直到它的外边缘碰到包含它的框或者另外一个浮动元素的边框为止。元素浮动以后会脱离正常的文档流，所以文档的普通流中的框就变现的好像浮动元素不存在一样。


## 优点
这样做的优点就是在图文混排的时候可以很好的使文字环绕在图片周围。另外当元素浮动了起来之后，它有着块级元素的一些性质例如可以设置宽高等，但它与inline-block还是有一些区别的，第一个就是关于横向排序的时候，float可以设置方向而inline-block方向是固定的；还有一个就是inline-block在使用时有时会有空白间隙的问题

## 缺点
最明显的缺点就是浮动元素一旦脱离了文档流，就无法撑起父元素，会造成父级元素高度塌陷。


## 清除浮动的方式

添加额外标签
```html
<div class="parent">
    //添加额外标签并且添加clear属性
    <div style="clear:both"></div>
    //也可以加一个br标签
</div>
```


父级添加overflow属性，或者设置高度
```html
<div class="parent" style="overflow:hidden">//auto 也可以
    //将父元素的overflow设置为hidden
    <div class="f"></div>
</div>
```

建立伪类选择器清除浮动（推荐）

```css
//在css中添加:after伪元素
.parent:after{
    /* 设置添加子元素的内容是空 */
      content: '';  
      /* 设置添加子元素为块级元素 */
      display: block;
      /* 设置添加的子元素的高度0 */
      height: 0;
      /* 设置添加子元素看不见 */
      visibility: hidden;
      /* 设置clear：both */
      clear: both;
}
<div class="parent">
    <div class="f"></div>
</div>
```

