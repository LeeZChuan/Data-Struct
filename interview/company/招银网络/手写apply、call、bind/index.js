//手写apply
Function.prototype.myapply = function (context, args) {
	context = context || window;
	args = args ? args : [];
	//为了调用绑定this
	//给context新增一个属性以免覆盖原有属性
	const key = Symbol();
	context[key] = this;
	//通过隐式绑定的方法调用函数
	const result = context[key](...args);
	delete context[key];

	return result;

}



//传递参数从一个数组变成逐个传参了,不用...扩展运算符的也可以用arguments代替
Function.prototype.myCall = function (context, ...args) {
	//这里默认不传就是给window,也可以用es6给参数设置默认参数
	context = context || window
	args = args ? args : []
	//给context新增一个独一无二的属性以免覆盖原有属性
	const key = Symbol()
	context[key] = this
	//通过隐式绑定的方式调用函数
	const result = context[key](...args)
	//删除添加的属性
	delete context[key]
	//返回函数调用的返回值
	return result
}

function say() {
	console.log(this.name + this.age);
}
const obj = {
	name: 'lee',
	age: 19
}
say.myapply(obj);
say.myCall(obj);