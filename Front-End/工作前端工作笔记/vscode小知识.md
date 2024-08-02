
1. 在vscode中使用快捷键ctrl+shift+p打开搜索，然后搜索“打开键盘快捷键”，然后打开对应的json，就可以按照下方方式修改快捷键的内容
```
// 将键绑定放在此文件中以覆盖默认值
[
    {
        "key": "shift+alt+f",
        "command": "prettier.forceFormatDocument"
    },
    {
        "key": "shift+alt+a", // 您想要绑定的快捷键
        "command": "editor.action.insertSnippet",
        "when": "editorTextFocus",
        "args": {
          "snippet": "/** $0 */"
        }
      }
]
```