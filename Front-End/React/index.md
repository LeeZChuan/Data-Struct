# React组件实例的三大核心属性

这里排除了使用function定义组件，因为他不是实例

函数式也可以使用三大核心属性，使用16.8版本提出的hooks

## 1. 组件的3大属性:state

	1. 组件被称为"状态机", 页面的显示是根据组件的state属性的数据来显示
	2. 初始化指定:
        constructor() {
          super()
          this.state = {
            stateName1 : stateValue1,
            stateName2 : stateValue2
          }
        }
	3. 读取显示: 
	    this.state.stateName1
	4. 更新状态-->更新界面 (状态不可直接更改，需要使用API去进行更改): 
	    this.setState({stateName1 : newValue})//API更改

> 如果在实例对象上的方法需要修改你想要的实例对象，那么你就需要使用bind()方法；
Function.prototype.bind()
bind() 方法创建一个新的函数，在 bind() 被调用时，这个新函数的 this 被指定为 bind() 的第一个参数，而其余参数将作为新函数的参数，供调用时使用。
```javascript
//1.创建组件
		class Weather extends React.Component{
			
			//构造器调用几次？ ———— 1次
			constructor(props){
				console.log('constructor');
				super(props)
				//初始化状态
				this.state = {isHot:false,wind:'微风'}
				//解决changeWeather中this指向问题
				this.changeWeather = this.changeWeather.bind(this)
			}

			//render调用几次？ ———— 1+n次 1是初始化的那次 n是状态更新的次数
			render(){
				console.log('render');
				//读取状态
				const {isHot,wind} = this.state
				return <h1 onClick={this.changeWeather}>今天天气很{isHot ? '炎热' : '凉爽'}，{wind}</h1>
			}

			//changeWeather调用几次？ ———— 点几次调几次
			changeWeather(){
				//changeWeather放在哪里？ ———— Weather的原型对象上，供实例使用
				//由于changeWeather是作为onClick的回调，所以不是通过实例调用的，是直接调用
				//类中的方法默认开启了局部的严格模式，所以changeWeather中的this为undefined
				
				console.log('changeWeather');
				//获取原来的isHot值
				const isHot = this.state.isHot
				//严重注意：状态必须通过setState进行更新,且更新是一种合并，不是替换。
				this.setState({isHot:!isHot})
				console.log(this);

				//严重注意：状态(state)不可直接更改，下面这行就是直接更改！！！
				//this.state.isHot = !isHot //这是错误的写法
			}
		}
```
> 类中可以直接书写赋值语句

```javascript
//1.创建组件
		class Weather extends React.Component{
			//初始化状态,这里与上面的constructor构造器所产生的state状态效果一致，简写方式
			state = {isHot:false,wind:'微风'}

			render(){
				const {isHot,wind} = this.state
				return <h1 onClick={this.changeWeather}>今天天气很{isHot ? '炎热' : '凉爽'}，{wind}</h1>
			}

            //
			//自定义方法————要用赋值语句的形式+箭头函数
            //箭头函数内部的this，寻找其外部组件的this作为箭头函数的this，也就是weather的实例
			changeWeather = ()=>{
				const isHot = this.state.isHot
				this.setState({isHot:!isHot})
			}
		}
//2.渲染组件到页面

```


## 2. 组件的3大属性: props
所有组件标签的属性的集合对象，给标签指定属性, 保存外部数据(可能是一个function)
	
	在组件内部读取属性: this.props.propertyName
	作用: 从目标组件外部向组件内部传递数据
	对props中的属性值进行类型限制和必要性限制
		Person.propTypes = {	
			name: React.PropTypes.string.isRequired,
			age: React.PropTypes.number.isRequired
		}
	扩展属性: 将对象的所有属性通过props传递
	    <Person {...person}/>

## 3. 组件的3大属性: ref

用处：组件内的标签可以定义ref属性来标识自己，但是在最新的文档更新了，弃用了ref标签的使用方式，字符串类型的ref不建议使用


    建议使用回调函数形式的ref

	执行回调函数的ref：<input ref={(c)=>{this.input=c}}>

	失焦函数：onBulr

```javascript
//创建组件
		class Demo extends React.Component{
			//展示左侧输入框的数据
			showData = ()=>{
				const {input1} = this
				alert(input1.value)
			}
			//展示右侧输入框的数据
			showData2 = ()=>{
				const {input2} = this
				alert(input2.value)
			}
			render(){
				return(
					<div>
						<input ref={c => this.input1 = c } type="text" placeholder="点击按钮提示数据"/>&nbsp;
						<button onClick={this.showData}>点我提示左侧的数据</button>&nbsp;
						<input onBlur={this.showData2} ref={c => this.input2 = c } type="text" placeholder="失去焦点提示数据"/>&nbsp;
					</div>
				)
			}
		}
```

## 4. 组件属性,生命周期函数

1. 组件挂完毕调用componentDidMount()，这个方法只调用一次
2. 组件将要卸载调用componentWillUnmount()，用于清除你在前面开启的定时器方法

![旧版生命周期](../React/2_react生命周期(旧).png)

旧版本的生命周期函数：
* 初始化阶段: 由ReactDOM.render()触发---初次渲染
1.	constructor()
2.	componentWillMount()
3.	render()
4.	componentDidMount() =====> 常用
一般在这个钩子中做一些初始化的事，例如：开启定时器、发送网络请求、订阅消息
* 更新阶段: 由组件内部this.setSate()或父组件render触发
1.	shouldComponentUpdate()==>在组件状态更新的时候进行调用更新页面
2.	componentWillUpdate()
3.	render() =====> 必须使用的一个
4.	componentDidUpdate()
* 卸载组件: 由ReactDOM.unmountComponentAtNode()触发
1.	componentWillUnmount()  =====> 常用
		一般在这个钩子中做一些收尾的事，例如：关闭定时器、取消订阅消息




