# Echarts图表操作

ECharts 中支持的图表行为，通过 dispatchAction 触发。

注： 代码中的 ?: 表示该属性是可选的。EVENT: 是 action 对应触发的事件。

## 高亮指定的数据图形。

```javascript
// 如果要高亮系列：
dispatchAction({
    type: 'highlight',

    // 用 index 或 id 或 name 来指定系列。
    // 可以使用数组指定多个系列。
    seriesIndex?: number | number[],
    seriesId?: string | string[],
    seriesName?: string | string[],

    // 数据项的 index，如果不指定也可以通过 name 属性根据名称指定数据项
    dataIndex?: number | number[],
    // 可选，数据项名称，在有 dataIndex 的时候忽略
    name?: string | string[],
});

// 如果要高亮 geo 组件（从 `v5.1.0` 开始支持）：
dispatchAction({
    type: 'highlight',

    // 用 index 或 id 或 name 来指定 geo 组件。
    // 可以用数组指定多个 geo 组件。
    geoIndex?: number | number[],
    geoId?: string | string[],
    geoName?: string | string[],

    // geo 组件中 region 名称。
    // 可以是一个数组指定多个名称。
    name?: string | string[],
});
```
## 如果要取消高亮

```javascript
// 如果要取消高亮系列：
dispatchAction({
    type: 'downplay',

    // 用 index 或 id 或 name 来指定系列。
    // 可以使用数组指定多个系列。
    seriesIndex?: number | number[],
    seriesId?: string | string[],
    seriesName?: string | string[],

    // 数据项的 index，如果不指定也可以通过 name 属性根据名称指定数据项
    dataIndex?: number | number[],
    // 可选，数据项名称，在有 dataIndex 的时候忽略
    name?: string | string[],
})

// 如果要取消高亮 geo 组件（从 `v5.1.0` 开始支持）：
dispatchAction({
    type: 'downplay',

    // 用 index 或 id 或 name 来指定 geo 组件。
    // 可以用数组指定多个 geo 组件。
    geoIndex?: number | number[],
    geoId?: string | string[],
    geoName?: string | string[],

    // geo 组件中 region 名称。
    // 可以是一个数组指定多个名称。
    name?: string | string[],
});

```

## 选中指定的数据。选中数据会使用 select 配置的样式。

```javascript

dispatchAction({
    type: 'select',

    // 用 index 或 id 或 name 来指定系列。
    // 可以使用数组指定多个系列。
    seriesIndex?: number | number[],
    seriesId?: string | string[],
    seriesName?: string | string[],

    // 数据项的 index，如果不指定也可以通过 name 属性根据名称指定数据项
    dataIndex?: number | number[],
    // 可选，数据项名称，在有 dataIndex 的时候忽略
    name?: string | string[],
})

```

## 取消选中指定的数据。

```javascript
dispatchAction({
    type: 'unselect',

    // 用 index 或 id 或 name 来指定系列。
    // 可以使用数组指定多个系列。
    seriesIndex?: number | number[],
    seriesId?: string | string[],
    seriesName?: string | string[],

    // 数据项的 index，如果不指定也可以通过 name 属性根据名称指定数据项
    dataIndex?: number | number[],
    // 可选，数据项名称，在有 dataIndex 的时候忽略
    name?: string | string[],
})

```


## 数据区域缩放组件相关的行为，必须引入数据区域缩放组件后才能使用。

action.dataZoom. dataZoomAction


dispatchAction({
    type: 'dataZoom',
    // 可选，dataZoom 组件的 index，多个 dataZoom 组件时有用，默认为 0
    dataZoomIndex: number,
    // 开始位置的百分比，0 - 100
    start: number,
    // 结束位置的百分比，0 - 100
    end: number,
    // 开始位置的数值
    startValue: number,
    // 结束位置的数值
    endValue: number
})