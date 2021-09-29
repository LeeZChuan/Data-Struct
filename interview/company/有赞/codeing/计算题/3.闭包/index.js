function fn() {
    for (var i = 0; i < 2; i++) {
        console.log(this);
        (function() {
            var variate = i;
            setTimeout(function() {
                console.log("setTimeout执行后:" + variate);
            }, 1000);
        })(); //闭包,立即执行函数,匿名函数
    }
    console.log(i); //2
    console.log(variate); //variate is not defined
}
fn();