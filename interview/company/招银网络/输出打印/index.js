//因为是setTimeout是异步的。正确的理解setTimeout的方式(注册事件)：
//有两个参数，第一个参数是函数，第二参数是时间值。调用setTimeout时，把函数参数，放到事件队列中。等主程序运行完，再调用。
function test() {
	for (var i = 0; i < 4; i++) {
		setTimeout(function () {
			console.log(i);
		}, 1000);
	}
}

test();

//如果要输出0,1,2,3要怎么改

function test1() {
	for (let i = 0; i < 4; i++) {
		setTimeout(function () {
			console.log(i);
		}, 1000);
	}
}

test1();

//思路是使用递归函数，不断地去执行setTimeout从而达到setInterval的效果，看代码

function mySetInterval(fn, millisec){
	function interval(){
	  setTimeout(interval, millisec);
	  fn();
	}
	setTimeout(interval, millisec)
  }