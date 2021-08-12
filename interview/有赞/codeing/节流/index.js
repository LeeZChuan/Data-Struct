// * 一段时间内只做一件事情，实际应用，表单的提交：典型的案例就是鼠标不断点击的触发，规定在n秒多次点击只有一次生效


//节流函数实现
function thro(func,waittime){
  let timerOut//判断
  //null与undifined都是取反为真
  return function(){
    if(!timerOut){
      timerOut=setTimeout(function(){
        func();
        timerOut=null
      },waittime)
    }
  }
}



function handle(){
  console.log(Math.random())
}

document.getElementById('button').onclick=thro(handle,2000)
