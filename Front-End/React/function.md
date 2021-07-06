# React中使用Antd组件

## React控制元素显示隐藏的三种方法

第一种是通过state变量来控制是否渲染元素，类似vue中的v-if。
第二种是通过style控制display属性，类似vue 中的v-show。
第三种是通过动态切换className，也就是把你想要展示的图表的classname修改上去。

   例子，在Dashborad的页面中引入两个组件，然后使用state状态组件切换true、false然后达到切换对应组件,使用三元组件：
   {showChart?(<char1/>):(<chart2/>)}
