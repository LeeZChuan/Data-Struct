# JavaScript 数组方法

## JavaScript 方法 toString() 把数组转换为数组值（逗号分隔）的字符串。

```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
document.getElementById("demo").innerHTML = fruits.toString(); 
```

## JavaScript join() 方法也可将所有数组元素结合为一个字符串。

## JavaScript pop() 方法从数组中删除最后一个元素：

## JavaScript push() 方法（在数组结尾处）向数组添加一个新的元素：

```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
var x =  fruits.push("Kiwi");   //  x 的值是 5
```

## JavaScript shift() 方法会删除首个数组元素，并把所有其他元素“位移”到更低的索引。


```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits.shift();            // 从 fruits 删除第一个元素 "Banana"
```
## JavaScript unshift() 方法（在开头）向数组添加新元素，并“反向位移”旧元素

```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits.unshift("Lemon");    // 向 fruits 添加新元素 "Lemon"
```

## JavaScript length 属性提供了向数组追加新元素的简易方法：

```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits[fruits.length] = "Kiwi";          // 向 fruits 追加 "Kiwi"
```

## 既然 JavaScript 数组属于对象，其中的元素就可以使用 JavaScript delete 运算符来删除：

```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
delete fruits[0];           // 把 fruits 中的首个元素改为 undefined
```
## 既然 JavaScript splice() 方法可用于向数组添加新项/使用 splice() 来删除元素

```javascript
var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits.splice(0, 1);        // 删除 fruits 中的第一个元素
```
## 既然 JavaScript concat() 方法通过合并（连接）现有数组来创建一个新数组：

```javascript
var myGirls = ["Cecilie", "Lone"];
var myBoys = ["Emil", "Tobias", "Linus"];
var myChildren = myGirls.concat(myBoys);   // 连接 myGirls 和 myBoys

var myChildren = arr1.concat(arr2, arr3);   // 将arr1、arr2 与 arr3 连接在一起

var myChildren = arr1.concat(["Emil", "Tobias", "Linus"]); //实例（将数组与值合并）
```
   concat() 方法不会更改现有数组。它总是返回一个新数组。
   concat() 方法可以使用任意数量的数组参数：
   
## 既然 JavaScript slice() 方法创建新数组。它不会从源数组中删除任何元素。

```javascript
var fruits = ["Banana", "Orange", "Lemon", "Apple", "Mango"];
var citrus = fruits.slice(3); 
```

slice() 可接受两个参数，比如 (1, 3)。

该方法会从开始参数选取元素，直到结束参数（不包括）为止。

如果结束参数被省略，比如第一个例子，则 slice() 会切出数组的剩余部分。


##  JavaScript sort() 方法以字母顺序对数组进行排序：

默认地，sort() 函数按照字符串顺序对值进行排序。

该函数很适合字符串（"Apple" 会排在 "Banana" 之前）。

不过，如果数字按照字符串来排序，则 "25" 大于 "100"，因为 "2" 大于 "1"。

正因如此，sort() 方法在对数值排序时会产生不正确的结果。

我们通过一个比值函数来修正此问题：


##  JavaScript reverse() 方法反转数组中的元素。

您可以使用它以降序对数组进行排序：

##  JavaScript 比值函数。


比值函数
比较函数的目的是定义另一种排序顺序。

比较函数应该返回一个负，零或正值，这取决于参数：

```javascript
var points = [40, 100, 1, 5, 25, 10];
points.sort(function(a, b){return b - a});
 ```

     以随机顺序排序数组:

```javascript
var points = [40, 100, 1, 5, 25, 10];
points.sort(function(a, b){return 0.5 - Math.random()});
 ```


##  JavaScript 查找最高（或最低）的数组值。

```javascript
var points = [40, 100, 1, 5, 25, 10];
points.sort(function(a, b){return a - b});//升序排序

// 现在 points[0] 包含最低值
// 而 points[points.length-1] 包含最高值
```

##  JavaScript 对数组使用 Math.max()方法/自定义查找最大最小方法

     您可以使用 Math.max.apply 来查找数组中的最高值：
     您可以使用 Math.min.apply 来查找数组中的最低值：


```javascript
function myArrayMax(arr) {
    return Math.max.apply(null, arr);
}

Math.max.apply([1, 2, 3]) 等于 Math.max(1, 2, 3)。
```

```javascript
//自定义查找方法
function myArrayMax(arr) {
    var len = arr.length
    var max = -Infinity;
    while (len--) {
        if (arr[len] > max) {
            max = arr[len];
        }
    }
    return max;
}
```

# JavaScript 数组迭代方法

## Array.forEach() forEach() 方法为每个数组元素调用一次函数（回调函数）。

```javascript
var txt = "";
var numbers = [45, 4, 9, 16, 25];
numbers.forEach(myFunction);

function myFunction(value, index, array) {
  txt = txt + value + "<br>"; 
}
```

## Array.map()

     map() 方法通过对每个数组元素执行函数来创建新数组。

     map() 方法不会对没有值的数组元素执行函数。

     map() 方法不会更改原始数组。

     这个例子将每个数组值乘以2：
 
```javascript
 var numbers1 = [45, 4, 9, 16, 25];
var numbers2 = numbers1.map(myFunction);

function myFunction(value, index, array) {
  return value * 2;
}
```

## Array.filter()

filter() 方法创建一个包含通过测试的数组元素的新数组

这个例子用值大于 18 的元素创建一个新数组：

```javascript
var numbers = [45, 4, 9, 16, 25];
var over18 = numbers.filter(myFunction);

function myFunction(value, index, array) {
  return value > 18;
}
```

## Array.reduce()

     reduce() 方法在每个数组元素上运行函数，以生成（减少它）单个值。

     reduce() 方法在数组中从左到右工作。另请参阅 reduceRight()。

     reduce() 方法不会减少原始数组。     


```javascript
var numbers1 = [45, 4, 9, 16, 25];
var sum = numbers1.reduce(myFunction);

function myFunction(total, value, index, array) {
  return total + value;
}
```

## Array.every()


```javascript
//every() 方法检查所有数组值是否通过测试。

//这个例子检查所有数组值是否大于 18：

var numbers = [45, 4, 9, 16, 25];
var allOver18 = numbers.every(myFunction);

function myFunction(value, index, array) {
  return value > 18;
}
```

## Array.indexOf()

```javascript
//indexOf() 方法在数组中搜索元素值并返回其位置。
//注释：第一个项目的位置是 0，第二个项目的位置是 1，以此类推。
var fruits = ["Apple", "Orange", "Apple", "Mango"];
var a = fruits.indexOf("Apple");
```