以下是 **Markdown (MD) 文档** 的详细使用 API，包含常用的语法和功能，以 Markdown 格式列出，适合新手和进阶用户参考。

# Markdown 使用 API

## 1. 标题（Headings）

Markdown 支持六个级别的标题，通过在文本前加 `#` 实现，`#` 的数量表示标题的级别。

  

```md

# 一级标题

## 二级标题

### 三级标题

#### 四级标题

##### 五级标题

###### 六级标题

  

**示例**：

  

**一级标题**

  

**二级标题**
```

  

**2. 段落与换行（Paragraphs and Line Breaks）**

  

• 段落之间需要空行隔开。

• 行内换行可以通过在行末添加两个或更多空格来实现。

  

这是一个段落。  

  

这是另一个段落。

  

**3. 强调文本（Emphasis）**

  

使用 * 或 _ 实现斜体和粗体。

  

_*斜体*_ 或 __斜体__

****粗体**** 或 **__粗体__**

******_*加粗斜体*_****** 或 **__**__加粗斜体__**__**

  

**示例**：

_斜体_

**粗体**

**_加粗斜体_**

  

**4. 列表（Lists）**

  

**4.1 无序列表（Unordered Lists）**

  

使用 -、* 或 + 实现无序列表。

  

- 项目1

- 项目2

  - 子项目2.1

  - 子项目2.2

  

**示例**：

  

• 项目1

• 项目2

• 子项目2.1

• 子项目2.2

  

**4.2 有序列表（Ordered Lists）**

  

数字后面加 . 实现有序列表。

  

1. 第一项

2. 第二项

   1. 子项2.1

   2. 子项2.2

  

**示例**：

  

1. 第一项

2. 第二项

1. 子项2.1

2. 子项2.2

  

**5. 链接（Links）**

  

使用 [显示文本](URL) 来创建链接。

  

[Markdown 官方文档](https://daringfireball.net/projects/markdown/)

  

**示例**：

[Markdown 官方文档](https://daringfireball.net/projects/markdown/)

  

**6. 图片（Images）**

  

和链接类似，只需在前面加 !。格式为：![替代文本](图片URL)

  

![Markdown logo](https://markdown-here.com/img/icon256.png)

  

**示例**：

  

**7. 引用（Blockquotes）**

  

使用 > 表示引用。可以多层嵌套。

  

> 这是一个引用。

>> 嵌套引用。

  

**示例**：

  

这是一个引用。

  

嵌套引用。

  

**8. 代码（Code）**

  

**8.1 行内代码（Inline Code）**

  

使用反引号 ` 包裹行内代码片段。

  

这是 `行内代码`。

  

**示例**：

这是 行内代码。

  

**8.2 代码块（Code Blocks）**

  

使用三个反引号 ``` 表示代码块，可以指定语言进行语法高亮。

  

```python

def hello_world():

    print("Hello, World!")

```


**示例**：

```python

def hello_world():

    print("Hello, World!")


```

**9. 分割线（Horizontal Rules）**

  

使用三个或更多的 -、* 或 _ 实现分割线。

  

---

*******

**__**___

  

**示例**：

  

**10. 表格（Tables）**

  

使用 | 来创建表格，列之间用 | 分隔。第二行用 - 定义表头和表体的分隔。

  
```
| 头1 | 头2 | 头3 |

| --- | --- | --- |

| 内容1 | 内容2 | 内容3 |

| 内容A | 内容B | 内容C |

  

**示例**：

  

**头1** **头2** **头3**

内容1 内容2 内容3

内容A 内容B 内容C

  
```
**11. 转义字符（Escaping Characters）**

  

Markdown 使用反斜杠 \ 来转义特殊字符。

  

\* 斜体将不会被渲染 \_*_

  

**示例**：

* 斜体将不会被渲染 *

  

**12. 任务列表（Task Lists）**

  

使用 - [ ] 表示未完成的任务，- [x] 表示已完成的任务。

  

- [x] 已完成任务

- [ ] 未完成任务

  

**示例**：

  

• 已完成任务

• 未完成任务

  

**13. 注脚（Footnotes）**

  

使用 [^1] 定义注脚，在文末解释。

  

这是一个注脚示例[^1]。

  

[^1]: 这里是注脚内容。

  

**示例**：

这是一个注脚示例[^1](%E8%BF%99%E9%87%8C%E6%98%AF%E6%B3%A8%E8%84%9A%E5%86%85%E5%AE%B9%E3%80%82)。

  

**14. 数学公式（Math Expressions）**

  

Markdown 支持 LaTeX 语法来表示数学公式（通常通过扩展插件实现，如在 GitHub 上）。

  

行内公式使用单个 $ 包裹，块级公式使用 $$ 包裹。

  

行内公式：$E=mc^2$

  

块级公式：

$$

E = mc^2

$$

  

**15. 折叠内容（Details）**

  

部分 Markdown 实现支持折叠内容。使用 <details> 标签可以折叠内容。

  

<details>

  <summary>点击展开内容</summary>

  这是展开后的内容。

</details>

  

**示例**：

  

<details>

  <summary>点击展开内容</summary>

  这是展开后的内容。

</details>

  

  

**16. 其他扩展**

  

Markdown 的功能可以通过扩展来增强。以下是一些常见的扩展：

  

• **表情符号**：通过 :smile: 等表示表情符号

• **脚注**：许多 Markdown 渲染器支持注脚

• **任务列表**：用于创建任务清单

  

**17. Markdown 渲染器**

  

不同的平台或工具对 Markdown 的渲染略有不同。常见的 Markdown 渲染器包括：

  

• GitHub Flavored Markdown (GFM)

• Markdown Here（浏览器插件）

• Jekyll（静态网站生成器支持 Markdown）

• Hugo（静态网站生成器支持 Markdown）

  

**18. 参考文档**

  

• [Markdown 官方文档](https://daringfireball.net/projects/markdown/)

• [GitHub Flavored Markdown](https://github.github.com/gfm/)

  

这份 Markdown API 列表详细介绍了 Markdown 的各个功能，从基础到一些扩展和高级特性，非常适合用来学习或参考 Markdown 语法。