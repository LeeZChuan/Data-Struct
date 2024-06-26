### 五个要点：


1. Hierarchic Structure（复杂结构）
![[Pasted image 20240625094318.png]]

2. Relative Primitives（相对原函数）
需要开发者需要更高的抽象能力，将业务逻辑抽离出来形成一个一个的基础函数或者基础组件

3. Separation of Concerns （关注点分离，组件分离）
组件内之间的联系比组件间的联系更强；

4. Common Patterns（常见的设计模式）

5. Stable Intermediate Forms（稳定的中间形式） 
![[Pasted image 20240625094957.png]]
![[Pasted image 20240625094903.png]]


### Tips：



**The discovery of common abstractions and mechanisms greatly facilitates our understanding of complex systems. （常見抽象和機制的發現極大地促進了我們對複雜系統的理解。）**

![[Pasted image 20240625100036.png]]

* ***The Limitations of the Human Capacity for Dealing with Complexity（人類處理複雜性的能力的局限性）**
* ***It takes the mind about five seconds to accept a new chunk of information（大腦大約需要五秒鐘才能接受新的訊息）**
* **“The technique of mastering complexity has been known since ancient times: divide et impera (divide and rule)”“掌握複雜性的技術自古以來就為人所知：divide et impera（分而治之）”***

### 为何要进行封装和抽象？


**Stein observes, “Structured programming appears to fall apart when applications exceed 100,000 lines or so of code” Stein 所觀察到的，「當應用程式的程式碼超過 100,000 行左右時，結構化程式設計似乎就會崩潰」**

### 如何进行封装和抽象？

大多数方法可以分为以下几类
 most methods can be categorized as one of three kinds：
 ■ Top-down structured design 
 ■ Data-driven design 
 ■ Object-oriented design

作者提到：Structured design does not scale up well for extremely complex systems, and this method is largely inappropriate for use with object-based and object-oriented programming languages.（对于极其复杂的系统，结构化设计不能很好地扩展，并且这种方法在很大程度上不适合基于对象和面向对象的编程语言。）


*（案例分享数据驱动demo）*
### The Role of Abstraction（抽象的作用）

**an individual can comprehend only about seven, plus or minus two, chunks of information at one time. (一个人一次只能理解大约七个（正负两个）信息块。)**

 **we manage to break . . . this informational bottleneck” [35]. In contemporary terms, we call this process chunking or abstraction.(我们设法打破了……这种信息瓶颈”[35]。用现代术语来说，我们称这个过程为分块或抽象。)**

### The Role of Hierarchy(层次化的作用)

**Once we have exposed these hierarchies, however, the structure of a complex system, and in turn our understanding of it, becomes vastly simplified. （然而，一旦我们揭示了这些层次结构，复杂系统的结构以及我们对它的理解就会变得大大简单。）**


**however, we must study the principles on which object-oriented development is founded, namely, abstraction, encapsulation, modularity, hierarchy, typing, concurrency, and persistence（然而，我们必须研究面向对象开发所基于的原则，即抽象、封装、模块化、层次结构、类型、并发性和持久性）**


总结

■ Software is inherently complex; the complexity of software systems often exceeds the human intellectual capacity.

■ 软件本质上是复杂的；软件系统的复杂性往往超出了人类的智力能力。

■ The task of the software development team is to engineer the illusion of simplicity.

■ 软件开发团队的任务是营造简单的假象。

■ Complexity often takes the form of a hierarchy; it is useful to model both the “is a” and the “part of” hierarchies of a complex system.

■ 复杂性通常表现为层次结构的形式；对复杂系统的“是”和“一部分”层次结构进行建模很有用。

■ Complex systems generally evolve from stable intermediate forms.

■ 复杂系统通常从稳定的中间形式演化而来。

■ There are fundamental limiting factors of human cognition; we can address these constraints through the use of decomposition, abstraction, and hierarchy

■ 人类认知存在根本的限制因素；我们可以通过使用分解、抽象和层次来解决这些限制

■ Complex systems can be viewed by focusing on either things or processes; there are compelling reasons for applying object-oriented decomposition, in which we view the world as a meaningful collection of objects that collaborate to achieve some higher-level behavior. 

■ 复杂系统可以通过关注事物或过程来查看；有令人信服的理由应用面向对象的分解，在这种分解中，我们将世界视为一个有意义的对象集合，这些对象协作以实现某些更高级别的行为。

■ Object-oriented analysis and design is the method that leads us to an objectoriented decomposition; object-oriented design uses a notation and process for constructing complex software systems and offers a rich set of models with which we may reason about different aspects of the system under consideration.

■ 面向对象的分析和设计是引导我们进行面向对象分解的方法；面向对象设计使用符号和过程来构建复杂的软件系统，并提供了一组丰富的模型，我们可以利用这些模型推断所考虑系统的不同方面。



Object-oriented Indeed, it is founded in the best ideas from prior technologies.
面向对象，事实上，它建立在先前技术的最佳理念之上。


### 什么是OOP？

*Object-oriented programming is a method of implementation in which programs are organized as cooperative collections of objects, each of which represents an instance of some class, and whose classes are all members of a hierarchy of classes united via inheritance relationships.（面向对象编程是一种实现方法，其中程序被组织为对象的协作集合，每个对象代表某个类的一个实例，并且其类都是通过继承关系联合起来的类层次结构的成员。）*


### 什么是OOD？

**Object-oriented design is a method of design encompassing the process of objectoriented decomposition and a notation for depicting both logical and physical as well as static and dynamic models of the system under design.（面向对象设计是一种设计方法，包括面向对象分解的过程以及描述设计系统的逻辑和物理以及静态和动态模型的符号。）**

简单来说就是：使用不同的表示法来表达设计逻辑（类和对象的结构）和物理设计（模块和处理架构）

For all things object-oriented, the conceptual framework is the object model. There are four major elements of this model:
对于所有面向对象的东西，概念框架就是对象模型。
该模型有四个主要元素：

1.Abstraction 2. Encapsulation 3. Modularity 4. Hierarchy
1. 抽象
2. 封装
3. 模块化
4. 层次结构
![[Pasted image 20240626112321.png]]

![[Pasted image 20240626112417.png]]

*(案例分享：table组件封装)*


### 抽象的重要性

**An abstraction denotes the essential characteristics of an object that distinguish it from all other kinds of objects and thus provide crisply defined conceptual boundaries, relative to the perspective of the viewer.（抽象表示对象的基本特征，这些特征将其与所有其他类型的对象区分开来，从而相对于观察者的视角提供了明确定义的概念边界。）**

![[Pasted image 20240626110317.png]]

### 封装的意义

封装简单来说就是：
**Encapsulation is the process of compartmentalizing the elements of an abstraction that constitute its structure and behavior; encapsulation serves to separate the contractual interface of an abstraction and its implementation.（封装是将构成抽象结构和行为的元素进行划分的过程；封装用于分离抽象的契约接口及其实现。）**


### 模块化的意义

Modularity is the property of a system that has been decomposed into a set of cohesive and loosely coupled modules.（模块化是系统的属性，被分解为一组高内聚，低耦合的模块。）

这也是函数式编程的核心含义；

https://worktile.com/kb/ask/2579011.html

https://docs.pingcode.com/ask/167223.html

### 层次化的意义

#### Examples of Hierarchy: Single Inheritance（单继承）
继承是最重要的“是一种”层次结构

![[Pasted image 20240626130655.png]]

#### Examples of Hierarchy: Multiple Inheritance（多继承）

ts：如何实现多继承：
https://juejin.cn/post/7001720162164408327
https://blog.csdn.net/weixin_44364444/article/details/104212895

![[Pasted image 20240626131324.png]]
多重继承经常被滥用。例如，棉花糖是一种糖果，但它显然不是一种棉花。同样，继承的试金石也适用：如果 B 不是 A 的一种，那么 B 就不应该从 A 继承。格式错误的多重继承格应尽可能简化为单个超类加上子类对其他类的聚合。


#### Examples of Hierarchy: Aggregation（聚合）

*Composition(组合)与Aggregation(聚合)的区别*

*含义在“重构”这本书有反复提及，感兴趣可以下来自行查阅*



### 类型定义的重要性

As Tesler points out, there are a number of important benefits to be derived from using strongly typed languages: 
■ Without type checking, a program in most languages can ‘crash’ in mysterious ways at runtime. 
■ In most systems, the edit-compile-debug cycle is so tedious that early error detection is indispensable. 
■ Type declarations help to document programs. 
■ Most compilers can generate more efficient object code if types are declared. [72]

正如 Tesler 指出的那样，使用强类型语言有许多重要的好处：
■ 如果没有类型检查，大多数语言中的程序在运行时可能会以神秘的方式“崩溃”。
■ 在大多数系统中，编辑-编译-调试循环非常繁琐，因此早期错误检测必不可少。
■ 类型声明有助于记录程序。
■ 如果声明了类型，大多数编译器可以生成更高效的目标代码。[72]
![[Pasted image 20240626132209.png]]


#### 借用书中比喻来说明对象的重要性

**Both the engineer and the artist must be intimately familiar with the**
**materials of their trade. Oils versus watercolors, steel versus aluminum,**
**bolts versus nails, object versus classes—each of these materials serves**
**similar functions (e.g., bolts and nails are both fasteners), yet each has**
**its own specific properties and uses.** 
**（工程师和艺术家都必须非常熟悉各自行业的材料。油画与水彩画、钢与铝、螺栓与钉子、物体与类别——每种材料都具有类似的功能（例如，螺栓和钉子都是紧固件），但每种材料都有其特定的属性和用途。）**


但是同一个对象可能在不同场景中扮演不同的角色：

**In the course of one day, the same person may play the role of mother, doctor, gardener, and movie critic（在一天的时间里，同一个人可能扮演母亲、医生、园丁和电影评论家的角色）**

***这恰恰能够体验使用对象在代码开发中的灵活性与复用性***

### 对象之间的关系有，链接、聚合

### 类之间有：继承、多态；但是我认为多态可以在具体实现中使用，频率非常小
![[Pasted image 20240626134427.png]]

![[Pasted image 20240626133606.png]]



Experience suggests that the object-oriented development process requires a subtly different partitioning of skills, compared with traditional methods. We have found the following three roles to be central to the technical development team for an object-oriented project: 
1. Project architect 
2. Component lead 
3. Application engineer

经验表明，与传统方法相比，面向对象的开发过程需要对技能进行细微的划分。我们发现，面向对象项目的技术开发团队需要以下三个角色：
1. 项目架构师
2. 组件负责人
3. 应用工程师