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

*  边框宽度


  使用方法：border-width:xxxxx;

```css

常见的属性：可以将宽度设置为特定大小（以 px、pt、cm、em 计），也可以使用以下三个预定义值之一：thin、medium 或 thick

当然border-width 属性可以设置一到四个值（用于上边框、右边框、下边框和左边框）：
 border-width: 5px 20px; /* 上边框和下边框为 5px，其他边为 20px */
 border-width: 20px 5px; /* 上边框和下边框为 20px，其他边为 5px */
 border-width: 25px 10px 4px 35px; /* 上边框 25px，右边框 10px，下边框 4px，左边框 35px */



```