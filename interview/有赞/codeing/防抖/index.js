// 
// - 实现 debounce
// 

function debounce(fn, delay) {
    let setTime;
    return function () {
        if(setTime)
        {
            clearTimeout(setTime);
        }
        
        setTime = setTimeout(function () {
            fn.bind(a);
        }, delay)
    }

}

const a = {
    count: 1,
    log: debounce(function () {
        console.log('debouce count:', this.count++)
    }, 50)
}

console.log(1);
a.log() // 'debouce count: 1'
a.log()
setTimeout(() => {
    a.log() // 'debouce count: 2'
}, 150)