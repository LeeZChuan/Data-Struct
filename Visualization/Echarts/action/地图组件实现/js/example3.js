(function () {
    require.config({
        paths: {
            echarts: 'js/dist'
        },
        packages: [
            {
                name: 'BMap',
                location: 'js',
                main: 'main'
            }
        ]
    });

    require(
        [
            'echarts',
            'BMap',
            'echarts/chart/map'
        ],
        function (echarts, BMapExtension) {

            // 初始化地图
            var BMapExt = new BMapExtension($('#main')[0], BMap, require('echarts'), require('zrender'));
            var map = BMapExt.getMap();
            var container = BMapExt.getEchartsContainer();
            var startPoint = {
                x: 104.114129,
                y: 37.550339
            };
            map.centerAndZoom(new BMap.Point(105.403119, 38.028658), 5); // 初始化地图,设置中心点坐标和地图级别
            map.setMapStyle(mapConfig);//地图样式
            map.enableScrollWheelZoom(true);
            //本地数据读取
            $.ajax({                                                                                                        // 读取json文件到didiData
                url: './data/data.json',
                async: false,
                success: function (data) {
                    // var pointerData=[];
                    pointerData = data;
                }
            });

            console.log(pointerData);
            var carList = [];
            var geoCoordList = {};


            for (let i = 0; i < 85; i++) {
                carList.push({
                    name: pointerData[i].carID,
                    value: 50,
                    geoCoord: [pointerData[i].lat, pointerData[i].lon]
                });
                //geoCoordList列表

            }
            //坐标转化方法
            function kvobj() {
                let res = {};
                for (let i = 0; i < 85; i++) {
                    res[pointerData[i].carID] = ([Number(pointerData[i].lat), Number(pointerData[i].lon)]);
                }
                return res;
            }


            option = {
                color: ['red', 'green', 'yello'],
                borderColor: ['black'],
                title: {
                    text: '各地区车辆分布情况',
                    subtext: 'DEMO测试',
                    x: 'center',
                    textStyle: {
                        color: 'black'
                    }
                },
                legend: {
                    orient: 'vertical',
                    x: 'left',
                    data: ['强', '中', '弱'],
                    textStyle: {
                        color: 'black'
                    }
                },
                toolbox: {
                    show: true,
                    orient: 'vertical',
                    x: 'right',
                    y: 'center',
                    feature: {
                        mark: { show: true },
                        dataView: { show: true, readOnly: false },
                        restore: { show: true },
                        saveAsImage: { show: true }
                    }
                },
                series: [
                    {
                        name: '弱',
                        type: 'map',
                        mapType: 'none',
                        //  itemStyle:{
                        //      normal:{
                        //          borderColor:'rgba(100,149,237,1)',
                        //          borderWidth:1.5,
                        //          areaStyle:{
                        //              color: '#1b1b1b'
                        //          }
                        //      }
                        //  },
                        geoCoord: kvobj(),
                        data: [],
                        markPoint: {
                            symbolSize: 8,
                            large: true,
                            effect: {
                                show: true
                            },
                            data: carList
                        }
                    },
                    {
                        name: '中',
                        type: 'map',
                        mapType: 'none',
                        data: [],
                        markPoint: {
                            symbolSize: 8,
                            large: true,
                            effect: {
                                show: true
                            },
                            data: carList
                        }
                    },
                    {
                        name: '强',
                        type: 'map',
                        mapType: 'none',
                                //  hoverable: false,
                                //  roam:true,
                        data: [],
                        markPoint: {
                            symbol: 'diamond',
                            symbolSize: 18,
                            large: true,
                            effect: {
                                show: true
                            },
                            data: carList
                        },
                    }
                ]
            };


            var myChart = BMapExt.initECharts(container);
            window.onresize = myChart.resize;
            BMapExt.setOption(option);

        }
    );
})();