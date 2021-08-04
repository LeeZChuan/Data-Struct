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

作者：jsliang
链接：https://leetcode-cn.com/circle/discuss/vTbRmd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。