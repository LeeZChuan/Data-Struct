六 React 和 Vue 比对
6.1 相同之处
虚拟 DOM。映射真实 DOM，通过新旧 DOM 的 diff 对比，更好的跟踪渲染页面。

组件化。将应用拆分成一个个功能明确的模块，每个模块之间可以通过合适的方式互相联系。

构建工具。都有自己的构建工具，通过 Webpack + Babel 去搭建脚手架。

Chrome 开发工具。两者都有很好的 Chrome 扩展去帮助查找 Bug。

配套框架。Vue 有 Vue-router 和 Vuex，而 React 有 React-router 和 React-Redux。

6.2 不同之处
模板 VS JSX。Vue 推荐编写近似常规 HTML 的模板进行渲染，而 React 推荐 JSX 的书写方式。
监听数据变化的不同。Vue 使用的是可变数据，而 React 更强调数据的不可变。在 Vue 中通过 v-model 绑定的数据，用户改变输入值后对应的值也相应改变。而 React 需要通过 setState 进行设置变化。
Diff 不同。Vue 通过双向链表实现边对比边更新 DOM，而 React 通过 Diff 队列保存需要更新的 DOM，得到 patch 树，再统一批量更新 DOM。
开发团队。Vue 一开始核心就是 Evan You，后面再招了其他人组成团队；React 的话是一开始就是 Facebook 团队搞的。所以网上的人比对源码情况的话，Vue 的比 React 的简单易懂点。


一、监听数据变化的实现原理不同

为什么 React 不精确监听数据变化呢 ？这是因为 Vue 和 React 设计理念上的区别， Vue 使用的是可变数据，而React更强调数据的不可变。所以应该说没有好坏之分，Vue更加简单，而React构建大型应用的时候更加鲁棒。

二、数据流的不同

大家都知道Vue中默认是支持双向绑定的。在Vue1.0中我们可以实现两种双向绑定：

props 
v-model 
在 Vue2.x 中去掉了第一种， 也就是父子组件之间不能双向绑定了（但是提供了一个语法糖自动帮你通过事件的方式修改），并且 Vue2.x 已经不鼓励组件对自己的 props 进行任何修改了 。
然而 React从诞生之初就不支持双向绑定，React一直提倡的是单向数据流，他称之为 onChange/setState() 模式 。不过由于我们一般都会用 Vuex 以及 Redux 等单向数据流的状态管理框架，因此很多时候我们感受不到这一点的区别了。

三、HOC和mixins


在Vue中我们组合不同功能的方式是通过mixin，而在React中我们通过HOC（高阶组件）。React 最早也是使用 mixins 的，不过后来他们觉得这种方式对组件侵入太强会导致很多问题，就弃用了 mixinx 转而使用 HoC，关于mixin究竟哪里不好，可以参考React官方的这篇文章 Mixins Considered Harmful。而 Vue 一直是使用 mixin 来实现的。

但是为什么Vue不采用HOC的方式来实现呢？

因为 高阶组件本质就是高阶函数，React的组件是一个纯粹的函数，所以高阶函数对React来说非常简单 。但是Vue就不行了， Vue中组件是一个被包装的函数，并不简单的就是我们定义组件的时候传入的对象或者函数 。比如我们定义的模板怎么被编译的？比如声明的props怎么接收到的？这些都是vue创建组件实例的时候隐式干的事。由于vue默默帮我们做了这么多事，所以我们自己如果直接把组件的声明包装一下，返回一个高阶组件，那么这个被包装的组件就无法正常工作了。

四、组件通信的区别

在Vue 中有三种方式可以实现组件通信：

父组件通过 props 向子组件传递数据或者回调，虽然可以传递回调，但是我们一般只传数据，而通过 事件的机制来处理子组件向父组件的通信
子组件通过 事件 向父组件发送消息
通过 V2.2.0 中新增的 provide/inject 来实现父组件向子组件注入数据，可以跨越多个层级。
在React中，也有对应的三种方式：
父组件通过 props 可以向子组件传递数据或者回调
可以通过 context 进行跨层级的通信 ，这其实和 provide/inject 起到的作用差不多。
可以看到， React 本身并不支持自定义事件 ，Vue中子组件向父组件传递消息有两种方式：事件和回调函数，而且Vue更倾向于使用事件 。但是 在 React 中我们都是使用回调函数的 ，这可能是他们二者最大的区别。

五、渲染模版的不同

在表层上， 模板的语法不同

React是通过JSX渲染模版
而Vue是通过一种拓展的HTML语法进行渲染
但其实这只是表面现象，毕竟 React并不必须依赖JSX 。在深层上，模板的原理不同，这才是他们的本质区别：

React是在组件JS代码中，通过 原生JS实现 模板中的常见语法，比如插值，条件，循环等，都是通过JS语法实现的
Vue是在和组件JS代码分离的单独的模板中， 通过指令来实现的 ，比如 条件语句就需要 v-if 来实现
react中 render函数是支持闭包特性的，所以我们import的组件在render中可以直接调用 。但是在Vue中， 由于模板中使用的数据都必须挂在 this 上进行一次中转，所以我们import 一个组件完了之后，还需要在 components 中再声明下，这样显然是很奇怪但又不得不这样的做法


六、Vuex和Redux的区别

从表面上来说， store 注入和使用方式有一些区别 。在 Vuex 中， $store 被直接注入到了组件实例中 ，因此可以比较灵活的使用：

使用dispatch和commit提交更新
通过mapState或者直接通过this.$store来读取数据
在 Redux 中， 我们每一个组件都需要显示的用 connect 把需要的 props 和 dispatch 连接起来。

另外 Vuex 更加灵活一些， 组件中既可以 dispatch action 也可以 commit updates ，而 Redux 中只能进行 dispatch，并不能直接调用 reducer 进行修改。

从实现原理上来说，最大的区别是两点：

Redux 使用的是不可变数据，而Vuex的数据是可变的。Redux每次都是用新的state替换旧的state，而Vuex是直接修改
Redux 在检测数据变化的时候，是通过 diff 的方式比较差异的，而Vuex其实和Vue的原理一样，是通过 getter/setter来比较的（如果看Vuex源码会知道，其实他内部直接创建一个Vue实例用来跟踪数据变化）

七、diff算法不同

两者流程思维上是类似的，都是基于两个假设（使得算法复杂度降为O(n)）：

不同的组件产生不同的 DOM 结构。当type不相同时，对应DOM操作就是直接销毁老的DOM，创建新的DOM。
同一层次的一组子节点，可以通过唯一的 key 区分。
但两者源码实现上有区别：

Vue基于snabbdom库，它有较好的速度以及模块机制。Vue Diff使用双向链表，边对比，边更新DOM 。
React主要使用 diff队列保存需要更新哪些DOM，得到patch树，再统一操作批量更新DOM。

八、事件机制不同

Vue
Vue原生事件使用 标准Web事件
Vue组件 自定义事件机制，是父子组件通信基础
Vue合理利用了snabbdom库的模块插件
React
React原生事件被包装，所有事件都冒泡到顶层document监听，然后在这里合成事件下发 。基于这套，可以跨端使用事件机制，而不是和Web DOM强绑定。
React组件上无事件，父子组件通信使用props



综合：
component层面，web component和virtual dom
数据绑定（vue双向，react的单向）等好多
计算属性 vue 有，提供方便；而 react 不行
vue 可以 watch 一个数据项；而 react 不行
vue 由于提供的 direct 特别是预置的 directive 因为场景场景开发更容易；react 没有
生命周期函数名太长 directive
