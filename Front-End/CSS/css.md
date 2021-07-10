# css
*  background背景简写属性：

```css
body{
    background-color:#fffff;
    background-image:url();
    background-repeat:no-repeat;
    background-position:right top;
    等等
}

body{
    background:#fffff url() no-repeat right top;
}
```
   顺序应该是：颜色，是否有图片 是否重复 背景位置

*  css边框


  使用方法：border-style:xxxx;


```css
dotted - 定义点线边框
dashed - 定义虚线边框
solid - 定义实线边框
double - 定义双边框
groove - 定义 3D 坡口边框。效果取决于 border-color 值
ridge - 定义 3D 脊线边框。效果取决于 border-color 值
inset - 定义 3D inset 边框。效果取决于 border-color 值
outset - 定义 3D outset 边框。效果取决于 border-color 值
none - 定义无边框
hidden - 定义隐藏边框
border-style 属性可以设置一到四个值（用于上边框、右边框、下边框和左边框）。

```

  使用方法：border-radius 属性用于向元素添加圆角边框：

```css

p {
  border: 2px solid red;
  border-radius: 5px;
}

```

*  边框宽度 


  使用方法：border-width:xxxxx;

```css

常见的属性：可以将宽度设置为特定大小（以 px、pt、cm、em 计），也可以使用以下三个预定义值之一：thin、medium 或 thick

当然border-width 属性可以设置一到四个值（用于上边框、右边框、下边框和左边框）：
 border-width: 5px 20px; /* 上边框和下边框为 5px，其他边为 20px */
 border-width: 20px 5px; /* 上边框和下边框为 20px，其他边为 5px */
 border-width: 25px 10px 4px 35px; /* 上边框 25px，右边框 10px，下边框 4px，左边框 35px */

 边框颜色也有一样的属性，设置不同边框颜色使用颜色分布就可以

```

*  边框border简写

```css
border 属性是以下各个边框属性的简写属性：

border-width
border-style（必需）
border-color
``

* css外边距（margin）

  CSS margin 属性用于在任何定义的边框之外，为元素周围创建空间。
  CSS 拥有用于为元素的每一侧指定外边距的属性：
  margin-top
  margin-right
  margin-bottom
  margin-left

  所有外边距属性都可以设置以下值：
  auto - 浏览器来计算外边距
  length - 以 px、pt、cm 等单位指定外边距
  % - 指定以包含元素宽度的百分比计的外边距
  inherit - 指定应从父元素继承外边距

同样margin简写也是可以的：

```css

p {
  margin: 25px 50px 75px 100px;上外边距是 25px 右外边距是 50px 下外边距是 75px 左外边距是 100px
}

p {
  margin: 25px 50px 75px; 上外边距是 25px 右和左外边距是 50px 下外边距是 75px
}

p {
  margin: 25px 50px; 上和下外边距是 25px 右和左外边距是 50px
}
```
**外边距合并：这个需要注意**


* css内边距（padding）

还是按照上、右、下、左来进行设计
padding 属性是以下各内边距属性的简写属性：

padding-top
padding-right
padding-bottom
padding-left

其中简写与上面的形式一致，padding:xxxx xxxx xxxx;

* css高度和宽度



* css的position定位：分别由有absolute relative
* 其中position有absolute relative
* absolute : 　将对象从文档流中拖出，使用left，right，top，bottom等属性进行绝对定位。而其层叠通过css z-index属性定义。此时对象不具有边距，但仍有补白和边框
* relative : 　对象不可层叠，但将依据left，right，top，bottom等属性在正常文档流中偏移位置


使用原因：有时一个布局中几个小对象，不易用css padding、css margin进行相对定位
