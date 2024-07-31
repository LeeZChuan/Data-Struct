#### 前情提要
1. Websocket是什么？能解决什么问题？；
2. 前端是如何使用的；
3. 后端是如何使用的；
#### 1  Websocket是什么？能解决什么问题？
#### **背景：**

WebSocket 协议可以实现对股票市场的实时监测。它可以在需要时实时更新股市价格。
#### **Websocket发明的背景：**

HTTP 协议有一个缺陷：通信只能由客户端发起。
举例来说，我们想了解今天的天气，只能是客户端向服务器发出请求，服务器返回查询结果。HTTP 协议做不到服务器主动向客户端推送信息。
这种单向请求的特点，注定了如果服务器有连续的状态变化，客户端要获知就非常麻烦。我们只能使用["轮询"](https://www.pubnub.com/blog/2014-12-01-http-long-polling/)：每隔一段时候，就发出一个询问，了解服务器有没有新的信息。最典型的场景就是聊天室。
轮询的效率低，非常浪费资源（因为必须不停连接，或者 HTTP 连接始终打开）。因此，工程师们一直在思考，有没有更好的方法。WebSocket 就是这样发明的。
#### **WebSocket 的优缺点：**
##### **优点：**
双向通信： WebSocket允许服务器主动推送数据到客户端，而不必等待客户端请求，从而实现了双向通信。  
实时性： 与HTTP请求–响应协议不同，WebSocket可以在客户端和服务器之间建立长久的连接，从而大大减少了通信延迟，实现实时性。  
性能： 与轮询（Polling）和长轮询（Long-polling）相比，WebSocket连接是一次性的，只需要建立一次连接，之后通信过程中不用不断地发送请求进行数据交换，减少了服务器的负载，提高了性能。  
节约流量： 由于WebSocket连接始终保持打开状态，因此不需要在每个HTTP请求中重复发送标头信息，从而减少数据包的大小。
##### **缺点：**
兼容性问题： WebSocket技术还没有普及，一些老旧的浏览器不支持WebSocket，需要进行降级处理，同时也有些防火墙和代理可能会阻止WebSocket协议的使用。  
保持连接： WebSocket连接始终保持打开状态，需要保持长久连接，长时间运行可能会导致资源消耗或权限被滥用。  
安全性： WebSocket连接要求服务器端和客户端都具备保密性和数据完整性保护机制，因此在资源限制或网络不安全的环境下有可能会导致安全问题。

#### **2  前端是如何使用的？**
##### **1 原生使用websocket实现。**

```js
// 原生
const ws = new WebSocket("wss://echo.websocket.org");
ws.onopen = function(evt) {
// 连接Socket
  console.log("Connection open ...");
  ws.send("Hello WebSockets!");
};
 
ws.onmessage = function(evt) {
// 收到服务器响应
  console.log( "Received Message: " + evt.data);
  ws.close();
};
 
ws.onclose = function(evt) {
//关闭Socket连接
  console.log("Connection closed.");
};
```

```js

// 原生js
 
// 当前浏览器Location对象
const nowLocation = window.location;
// 协议 => http、https
const protocol = nowLocation.protocol;
// hostName => ip
const hostName = nowLocation.hostname;
// host => ip:port
const host = nowLocation.host;
// websocket api 地址
// 这个判断就是根据当前项目环境 自动确定使用 ws 还是 wss 的路由地址
const websocket_pattern = (hostName == '域名') ? 'wss-websocket-api' : 'websocket-api';
 
// websocket 请求地址前缀
const webSocketApiUrl =  ((protocol.startsWith('https')) ? 'wss://' : 'ws://') + host + '/' + websocket_pattern;
 
 
// 当前WebSocket的请求地址前缀,
// /websocket/template-push/ 就是我后端配置的websocket端点地址
let REQUEST_WEBSOCKET_URL_PREFIX = webSocketApiUrl + '/websocket/template-push/';
// 当前的WwebSocket对象
let CURRENT_SOCKET = null;
// 当前请求WebSocket的指令代码
let CURRENT_INDICATE_CODE = null;
 
 
let ENABLE_CONFIG = {
 
  WEBSOCKET_PUSH_VIDEO_ENABLE: true,
}
 
/**
 * 1. 初始化WebSocket连接对象
 * @param {*} clientKey 当前客户端Key
 */
function openWebSocket(clientKey) {
    if (CURRENT_SOCKET != null) {
        CURRENT_SOCKET.close();
        CURRENT_SOCKET = null;
    }
 
    CURRENT_SOCKET = new WebSocket(REQUEST_WEBSOCKET_URL_PREFIX + clientKey);
 
    CURRENT_SOCKET.onopen = event => {
        console.log('连接Socket');
    };
 
    // 从服务器接受到信息时的回调函数
    CURRENT_SOCKET.onmessage = event => {
        console.log('收到服务器响应 , 响应数据信息==>' , event.data);
    };
 
    CURRENT_SOCKET.onclose = event => {
        console.log('关闭Socket连接!');
    };
 
    //监听窗口关闭事件，当窗口关闭时，主动去关闭websocket连接，防止连接还没断开就关闭窗口，server端会抛异常。
    window.onbeforeunload = () => {
        CURRENT_SOCKET.close();
        CURRENT_SOCKET = null;
    };
}
 
function getWebSocketConnection() {
    return CURRENT_SOCKET;
}
```
##### 2 Socket.IO 代码库
https://github.com/socketio/socket.io

```ts
// ts中如何使用Socket.IO
 
import { io } from "socket.io-client";
 
// same origin version-同源
const socket = io("/admin");
// cross origin version-不同源
const socket = io("https://server-domain.com/admin");
 
socket.on("connect", () => {
// 连接成功的业务操作
  const engine = socket.io.engine;
  console.log(engine.transport.name); // in most cases, prints "polling"
});
 
socket.on("error", (error) => {
  // ...连接错误的操作
});
 
socket.on("reconnect", (attempt) => {
  // ...重新连接，其中attempt是重新连接尝试次数，这里可以编写终止逻辑
});
 
socket.on("reconnect_attempt", (attempt) => {
  // ...重新连接尝试，attempt重新连接尝试次数
});
```

##### 3 ws 是一个“简单易用、快速且经过全面测试的 WebSocket 客户端和 Node.js 服务器”。
##### https://github.com/websockets/ws



##### 4 µWebSockets代码库，使用c++编写的websocket服务端
##### https://github.com/uNetworking/uWebSockets

##### 5 SockJS代码库
[https://github.com/sockjs/sockjs-client](https://github.com/sockjs/sockjs-client)
兼容性：
![[24bbc0bf01d3806dc7de8fa16e3ab254.png]]
#### **3  后端是如何使用的？**

**1 Socket.IO 是一个库，可以在客户端和服务器之间实现 低延迟, 双向和基于事件的通信，提供了java和nodejs版本的代码库。**

[https://github.com/socketio/socket.io](https://github.com/socketio/socket.io)

nodejs文档:[https://socket.nodejs.cn/docs/v4/server-api/](https://socket.nodejs.cn/docs/v4/server-api/)

```ts
// 服务端nodejs代码
 
const express = require('express');
const http = require('http');
const socketIO = require('socket.io');
 
const app = express();
const server = http.createServer(app);
const io = socketIO(server);
 
// 监听客户端连接
io.on('connection', (socket) => {
  console.log('a user connected');
 
  // 监听客户端发送的chat message事件
  socket.on('chat message', (msg) => {
    console.log('message: ' + msg);
 
    // 将消息广播给所有客户端
    io.emit('chat message', msg);
  });
 
  // 监听客户端断开连接
  socket.on('disconnect', () => {
    console.log('user disconnected');
  });
});    
 
// 启动服务
server.listen(3000, () => {
  console.log('listening on *:3000');
});
```

 **2 ws 是一个“简单易用、快速且经过全面测试的 WebSocket 客户端和 Node.js 服务器”。**
[https://github.com/websockets/ws](https://github.com/websockets/ws)

```ts
// nodejs-websocket
// 服务端nodejs代码
 
const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });
wss.on('connection', function connection(ws) {
    ws.on('message', function incoming(message) {
    console.log('received: %s', message);
    });
    ws.send('something');
});
```

**3 µWebSockets代码库，使用c++编写的websocket服务端**
https://github.com/uNetworking/uWebSockets

μWS 是 ws 的直接替代品，它特别注重性能和稳定性。据我所知，μWS 离最快的 WebSocket 服务器仅有一步之遥。SocketCluster 就是由它驱动的，关于 SocketCluster 我将在下面说到。

由于作者出于哲学上的原因试图将 μWS 从 NPM 中提取出来，近来围绕 μWS 引发了一些争议，但 μWS 最新的可运行版本仍然在 NPM 上，并且可以从 NPM 安装时明确指定该版本。也就是说，作者正在开发 一个新版本，其附带的 node.js 绑定 也在 开发中。

```ts
// nodejs-websocket
// 服务端nodejs代码
 
const WebSocketServer = require('uws').Server;
const wss = new WebSocketServer({ port: 3000 });
function onMessage(message) {
    console.log('received: ' + message);
}
 
wss.on('connection', function(ws) {
    ws.on('message', onMessage);
    ws.send('something');
});
```


#### 参考资料


websocket介绍:https://www.ruanyifeng.com/blog/2017/05/websocket.html
适用于node的websocket库:https://www.nxrte.com/jishu/im/45490.html
WebSockets 与长轮询的较量:https://ably.com/blog/websockets-vs-long-polling
使用 WebSocket 和 CSS3 魔法:https://medium.com/outsystems-engineering/making-magic-with-websockets-and-css3-ec22c1dcc8a8#.4d13ybtra
WebRTC 与 WebSockets 教程 — Web 端的实时通信:https://requestum.com/blog/webrtc-vs-websockets
[译] WebRTC 与 WebSockets 教程 — Web 端的实时通信:https://juejin.cn/post/7138015673850003493
WEBSOCKET开源框架_常用WEBSOCKET库汇总整理:https://www.goeasy.io/articles/820.html
Vue项目配置WebSocket连接{ws、wss 连接方式}:https://blog.csdn.net/weixin_44321065/article/details/134314213#31__125
java如何实现websocket:https://luoxin1992.github.io/2017/06/25/java-web-socket-basic-and-lifecycle/