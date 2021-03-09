#  Echarts多图联动

## 建立联动api

* echarts. connect
* 
* 有这样一个方法可以实现多图联动，多个图表实例实现联动。

参数：

group group 的 id，或者图表实例的数组。

* 示例：
```javascript
// 分别设置每个实例的 group id
chart1.group = 'group1';
chart2.group = 'group1';
echarts.connect('group1');
// 或者可以直接传入需要联动的实例数组
echarts.connect([chart1, chart2]);
```

## 解除联动api

* echarts. disconnectFunction
* 
* 
(group:string)
解除图表实例的联动，如果只需要移除单个实例，可以将通过将该图表实例 group 设为空。

参数：

* group：group 的 id。