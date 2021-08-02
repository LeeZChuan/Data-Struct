async function test3() {
    const p3 = Promise.resolve(3);
    p3.then(data => {
        console.log('data', data);
    })

    const data = await p3;
}

test3();

async function test4() {
    const data = await 4;//await Promise.resolve(4);
    console.log('data', data);

}

test4();

//回调函数
//有时需要将现有对象转为 Promise 对象，Promise.resolve方法就起到这个作用。
const p1 = Promise.resolve();

console.log('p1', p1);
const p1Then = p1.then(() => {
    console.log('p1.then');
})

p1Then.then(() => {
    console.log('p1Then.then');
}).catch(() => {
    console.log('p1.catch');
})

//如果回调函数throw了一个Error的话，那么这个Promise的状态就回变成rejected
const p1ThenError = p1.then(() => {
    throw new Error('出错了');
})

p1ThenError.then(() => {
    console.log('p1ThenError.then');
}).catch(() => {
    console.log('p1ThenError.catch');
})
