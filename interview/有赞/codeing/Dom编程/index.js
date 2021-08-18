/* 不可以改变html文档，只可以使用DOM+CSS：

（1）将最后一个 li 的文字颜色设置为 red，至少使用3种方法

（2）将 p 去除，至少使用3种方法

（3）实现三栏布局，至少使用3种方法（补充问题：flex=1 是哪些内容的缩写）

（4）点击每一个 li ，输出对应的数字，使用 */

// var content=document.getElementById("content");
var li=document.getElementsByTagName("li");
li[2].style.color = "red";

console.log(li);