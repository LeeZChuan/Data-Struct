# jsx语法规则

## 1.1 函数式组件

1. 定义虚拟DOM时，不要用引号。
2. 标签中混入js表达式时要用{}。
3. 内联样式，要用style={{key:value}}得形式去写。
4. 只有一个根标签
5. 标签名必须闭合
6. 标签首字母
    如有小字母开头，则将该标签转化为html中得同名元素，若html中无该标签得对应得同名元素，则报错
    若有大写字母开头，react就去渲染相应组件，若组件没有定义，则报错。

## 1.2 类对象

```javascript
class Person()
{
    constructor(name,age)
    {
        this.name=name;
        this.age=age;
    }
    //一般方法
    speak(){
        //speak方法放在了person类的原型对象上,给实例用的
        console.log('我叫${this.name},我的年龄是${this.age}');
    }
}

const p1=new Person('tom',19);

console.log(p1);

p1.speak();
```


```javascript
//继承
class Person()
{
    constructor(name,age)
    {
        this.name=name;
        this.age=age;
    }
    //一般方法
    speak(){
        //speak方法放在了person类的原型对象上,给实例用的
        //speak中的this就是Person实例
        console.log('我叫${this.name},我的年龄是${this.age}');
    }
}

class Student extends Person{
    //如果学生与人的类一样有的属性那么就不需要写，新的属性需要再写
    //在类里如果使用构造器，那么这时候需要写super()继承之前父类的所有属性
    constructor(name,age,grade)
    {
        super(name,age);//必须在最开始就要调用
        this.grade=grade;
    }
    //重写从Person类集成的speak方法
    speak(){
        //speak方法放在了person类的原型对象上,给实例用的
        //speak中的this就是Person实例
        console.log('我叫${this.name},我的年龄是${this.age},我读的年级是${this.grade}');
    }

}
const s1=new Person('tom',19,'高一');

console.log(s1);

s1.speak();
```

总结：
1. 类中的构造器不是必须写的，要对一些实例进行一些初始化的操作，如添加指定属性时才写，
2. 如果A继承了B，且A类中写了构造器，那么A类中的的super是必须要调用的。
3. 类中所定义的方法都是放在类的原型对象上，供实例去使用。


## 1.3 在React中使用类对象


```javascript
//1. 创建类式组件
class MyComponent extends React.Component{
    render(){//必须要使用该方法
    //必须要有返回值
    //render是放在哪里的？MyComponent的原型对象上，供实例使用
    //render中的this是MyComponent的实例对象，MyComponent组件实例对象
        return <div>xxxxx</div>
    }
}
//2.渲染组件到页面
ReactDOM.render(<MyComponent/>,document.getElementById('test'))

ReactDOM.render(<MyComponent/>...执行了什么：
1.React解析组件标签，找到了MyComponent组件
2.发现该组件是使用类定义的，随后new出来该类的实例，并通过该实例调用到原型上的render方法。
3.将render返回的虚拟DOM，转化为真实DOM，随后呈现在页面上。
```