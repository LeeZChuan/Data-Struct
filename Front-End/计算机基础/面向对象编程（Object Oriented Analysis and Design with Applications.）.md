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
