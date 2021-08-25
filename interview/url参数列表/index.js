
let url = "https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=0&rsv_idx=1&tn=baidu";
let parames = url.split("?")[1].split("&");
let arr = [];
for (let i = 0; i < parames.length; i++) {
    let person = {
        key: parames[i].split("=")[0],
        value: parames[i].split("=")[1],
    }
    arr.push(person);
}
console.log(arr)
