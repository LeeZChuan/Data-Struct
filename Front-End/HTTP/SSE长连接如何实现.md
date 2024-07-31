### 前情提要
1. SSE是什么？能解决什么问题？；
2. 前端是如何使用的；
3. 后端是如何使用的；
### 1  SSE是什么？能解决什么问题？

SSE 全称为 Server-sent events , 是一种基于 HTTP 协议的通信技术，允许服务器主动向客户端（通常是Web浏览器）发送更新。它是 HTML5 标准的一部分，设计初衷是用来建立一个单向的服务器到客户端连接，使得服务器可以实时地向客户端发送数据。
##### 兼容性问题： 
需要注意的是，SSE只适用于高级浏览器，ie不支持，因为ie上的XMLHttpRequest对象不支持获取部分的响应内容，只有在响应完成之后才能获取其内容，需要使用 polyfilled 方案。

### 2  前端是如何使用的？

##### 1 原生使用
```ts
//**sse** 
// 原生
const source = new EventSource("http://localhost:5000/sse");

source.onopen = (data) => {

console.log("Connected", data);

}

source.onmessage = (res) => {

console.log("onmessage", res);

this.getData(JSON.parse(res.data))

}

source.onerror = (e) => {

console.log("onerror", e, EventSource.CLOSED, EventSource.CONNECTING);

if (e.target.readyState === EventSource.CLOSED) {

console.log(\'Disconnected\');

} else if (e.target.readyState === EventSource.CONNECTING) {

console.log(\'Connecting...\');

}

},

// 可自定义  服务端通知

source.addEventListener(\'close\', function(e) {
console.log(e, \'当前\');
source.close()
});
```
`

#### 3  后端是如何使用的?

```ts
// 服务端nodejs代码
 
const app = new Koa();
app.use(async (ctx, next) => {
    if (ctx.path !== "/sse") {
      return await next();
    }
  
    ctx.request.socket.setTimeout(0);
    ctx.req.socket.setNoDelay(true);
    ctx.req.socket.setKeepAlive(true);
  
    ctx.set({
      "Content-Type": "text/event-stream",
      "Cache-Control": "no-cache",
      "Connection": "keep-alive",
    });
  
    const stream = new PassThrough();
  
    ctx.status = 200;
    ctx.body = stream;
    const str = \'赵钱孙李周吴郑王冯陈褚卫蒋沈韩杨朱秦尤许何吕施张孔曹严华金魏陶姜戚谢邹喻柏水窦章云苏潘葛奚范彭郎鲁韦昌马苗凤花方俞任袁柳酆鲍史唐费廉岑薛雷贺倪汤滕殷罗毕郝邬安常乐于时傅皮卞齐康伍余元卜顾孟平黄和穆萧尹姚邵湛汪祁毛禹狄米贝明臧计伏成戴谈宋茅庞熊纪舒屈项祝董梁杜阮蓝闵席季麻强贾路娄危江童颜郭梅盛林刁钟徐邱骆高夏蔡田樊胡凌霍虞万支柯昝管卢莫经房裘缪干解应宗丁宣贲邓郁单杭洪包诸左石崔吉钮龚程嵇邢滑裴陆荣翁荀羊於惠甄曲家封芮羿储靳汲邴糜松井段富巫乌焦巴弓牧隗山谷车侯宓蓬全郗班仰秋仲伊宫宁仇栾暴甘钭厉戎祖武符刘景詹束龙叶幸司韶郜黎蓟薄印宿白怀蒲邰从鄂索咸籍赖卓蔺屠蒙池乔阴鬱胥能苍双闻莘党翟谭贡劳逄姬申扶堵冉宰郦雍郤璩桑桂濮牛寿通边扈燕冀郏浦尚农温别庄晏柴瞿阎充慕连茹习宦艾鱼容向古易慎戈廖庾终暨居衡步都耿满弘匡国文寇广禄阙东欧殳沃利蔚越夔隆师巩厍聂晁勾敖融冷訾辛阚那简饶空曾毋沙乜养鞠须丰巢关蒯相查后荆红游竺权逯盖益桓公万俟司马上官欧阳夏侯诸葛闻人东方赫连皇甫尉迟公羊澹台公冶宗政濮阳淳于单于太叔申屠公孙仲孙轩辕令狐钟离宇文长孙慕容鲜于闾丘司徒司空丌官司寇仉督子车颛孙端木巫马公西漆雕乐正壤驷公良拓跋夹谷宰父谷梁晋楚闫法汝鄢涂钦段干百里东郭南门呼延归海羊舌微生岳帅缑亢况郈有琴梁丘左丘东门西门商牟佘佴伯赏南宫墨哈谯笪年爱阳佟第五言福百家姓终\'
    let index = 0
    setInterval(() => {
        const list = []
        while(list.length < 10) {
            const idx = Math.floor(Math.random() * 568)
            list.push({
                name: str[idx] + (str[idx + 15] || \'\') +  (str[idx - 5] || \'\'),
                value: idx
            })
        }
        const obj = {
            list,
            info: `${new Date()}`,
            index: ++index
        }
        stream.write(\'id: \' + index + \'n\');
        stream.write(`data: ${JSON.stringify(obj)}nn`);
 
        stream.write(\'retry: 10000n\'); // 重连时间
         // ... 处理判断啥时候终止
    }, 3000);
  })
  .use(ctx => {
    ctx.status = 200;
    ctx.body = "ok";
  })
  .listen(5000, () => console.log("Listening 5000"));
```

可以发现，SSE 与 WebSocket 各有优缺点，对于需要客户端与服务端高频交互的场景，WebSocket 确实更适合，但对于只需要服务端单向数据传输的场景，SSE 确实能耗更低，且不需要客户端感知。

![[24bbc0bf01d3806dc7de8fa16e3ab254.png]]

##### 参考资料

介绍：[https://blog.csdn.net/double_sweet1/article/details/138028078?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-138028078-blog-130680011.235^v43^control&spm=1001.2101.3001.4242.2&utm_relevant_index=4](https://blog.csdn.net/double_sweet1/article/details/138028078?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-138028078-blog-130680011.235^v43^control&spm=1001.2101.3001.4242.2&utm_relevant_index=4)