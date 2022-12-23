---
title: Ubuntu 软件推荐(持续更新)
date: 2022-11-21
description: 本文分享了我在 Ubuntu 上使用的软件。
tags: ["Software","Ubuntu"]
categories: ["Ubuntu"]
keywords: ["Ubuntu","vscode","SynthWave","tabout","c++","洛雪音乐助手","QQ","Icalingua++"]
cover: https://ci.cncn3.cn/1e2854aef14210752eb7d9267e08675a.png
---

# Ubuntu 软件推荐

## 起因

自从转 `Ubuntu` 之后，因为系统生态的原因，我不得不寻找 `Windows` 下各种软件的替代品。这篇文章就是分享我在 `Ubuntu` 上使用的各种软件。

## 正文

### 代码编辑器： `Visual Studio Code`

先放一张截图：

<img src="https://ci.cncn3.cn/4202084f6eb8ff1565896a7ecc861c72.png" title="" alt="4202084f6eb8ff1565896a7ecc861c72.png" data-align="center">

这个由微软发布代码编辑器深受大众喜爱。如果您要下载它，建议不要使用 `Snap` 商店。因为它不支持中文输入。

这里直接放出官网的下载链接：[Download VsCode](https://code.visualstudio.com/Download) 。

如果访问和下载速度较慢，则可以使用我的网盘进行下载： [网盘下载](https://share.purkit.ml/Linux%20Software/Ubuntu-share/code_1.72.0-1664926972_amd64.deb) 。

这里再顺便提一下我安装的 `VsCode` 插件和一些配置。

#### 安装 `C++` 环境

使用 `VsCode` 编写代码并运行需要安装一些插件和配置一些环境。相关的教程很多，这里以配置 `C++` 环境为例。

首先下载 `gcc` 、`g++` 和 `gdb` 。

```bash
sudo apt-get update
sudo apt-get install gcc
sudo apt-get install g++
sudo apt-get install gdb
```

然后通过以下指令查看是否安装成功：

```bash
gcc -v
g++ -v
gdb -v
```

如果显示版本号则说明安装成功。

接下来安装插件。

在扩展商店中搜索并安装 `C/C++` 和 `C/C++ Extension Pack` 。

然后安装 `Code Runner` 。该插件用于运行代码。

此时打开设置 `Settings` ，您可以点击快捷键 `Ctrl + ,` 进入设置界面。搜索 `Run In Terminal` ，将 `Whether to run code in integrated Terminal` 勾选。这样您就可以在终端里看到自己运行代码的结果了。

如果您需要配置调试环境的话，请参阅这篇文章： [配置调试环境](https://zhuanlan.zhihu.com/p/80659895) 。

如果不配置调试环境其实也能运行代码，只是不能调试。

如果您觉得字体太小，您可以在 `Settings` 中搜索 `zoom` ，将 `Editor: Mouse Wheel Zoom` 勾选，这样您就可以使用 `Ctrl + 滚轮` 进行缩放编辑界面大小了。

如果您想配置其它语言的环境，可以上网查找相关教程。

如果您用过 `Visual Studio` ，您一定会喜欢其中的自动格式化代码，而 `VsCode` 中没有内置这一功能。所以我们需要自行配置。

我使用的是 `clang` 进行格式化，首先在终端中运行以下指令：

```bash
sudo apt-get install clang
```

然后使用如下指令查看版本：

```bash
clang -v
```

然后在打开的文件夹下新建一个名为 `.clang-format` 的文件。

在其中填入配置信息，这里提供我自己的配置：

```
# 语言: None, Cpp, Java, JavaScript, ObjC, Proto, TableGen, TextProto
Language:        Cpp
# BasedOnStyle:  LLVM
# 访问说明符(public、private等)的偏移
AccessModifierOffset: -4
# 开括号(开圆括号、开尖括号、开方括号)后的对齐: Align, DontAlign, AlwaysBreak(总是在开括号后换行)
AlignAfterOpenBracket: Align
# 对齐数组列
AlignArrayOfStructures: None
# 对齐连续宏定义
AlignConsecutiveMacros: None
# 连续赋值时，对齐所有等号
AlignConsecutiveAssignments: None
# 对齐连续位字段
AlignConsecutiveBitFields: None
# 连续声明时，对齐所有声明的变量名
AlignConsecutiveDeclarations: true
# 左对齐逃脱换行(使用反斜杠换行)的反斜杠
AlignEscapedNewlines: Left
# 水平对齐二元和三元表达式的操作数
AlignOperands:   Align
# 对齐连续的尾随的注释
AlignTrailingComments: true
# 允许函数声明的所有参数在放在下一行
AllowAllParametersOfDeclarationOnNextLine: true
# 允许短的枚举放在同一行
AllowShortEnumsOnASingleLine: true
# 允许短的块放在同一行
AllowShortBlocksOnASingleLine: Never
# 允许短的case标签放在同一行
AllowShortCaseLabelsOnASingleLine: false
# 允许短的函数放在同一行
AllowShortFunctionsOnASingleLine: Inline
# 允许短的匿名函数放在同一行
AllowShortLambdasOnASingleLine: All
# 允许短的if语句保持在同一行
AllowShortIfStatementsOnASingleLine: Never
# 允许短的循环保持在同一行
AllowShortLoopsOnASingleLine: false
# 总是在返回类型后换行
AlwaysBreakAfterReturnType: None
# 总是在多行string字面量前换行
AlwaysBreakBeforeMultilineStrings: false
# 总是在template声明后换行
AlwaysBreakTemplateDeclarations: MultiLine
AttributeMacros:
  - __capability
# false表示函数实参要么都在同一行，要么都各自一行
BinPackArguments: true
# false表示所有形参要么都在同一行，要么都各自一行
BinPackParameters: true
# 大括号换行，只有当 BreakBeforeBraces 设置为Custom时才有效
BraceWrapping:
  AfterCaseLabel:  true
  AfterClass:      true
  AfterControlStatement: Always
  AfterEnum:       false
  AfterFunction:   true
  AfterNamespace:  true
  AfterObjCDeclaration: false
  AfterStruct:     true
  AfterUnion:      true
  AfterExternBlock: false
  BeforeCatch:     true
  BeforeElse:      true
  BeforeLambdaBody: false
  BeforeWhile:     false
  IndentBraces:    false
  SplitEmptyFunction: false
  SplitEmptyRecord: true
  SplitEmptyNamespace: true
# 在二元运算符前换行
BreakBeforeBinaryOperators: None
# 在concept前换行
BreakBeforeConceptDeclarations: true
# 在大括号前换行: Attach(始终将大括号附加到周围的上下文)
BreakBeforeBraces: Custom
# 继承列表样式
BreakInheritanceList:  AfterColon
# 在三元运算符前换行
BreakBeforeTernaryOperators: true
# 构造函数初始值设定项换行样式
BreakConstructorInitializers: BeforeComma
# 在java字段的注释后换行
BreakAfterJavaFieldAnnotations: false
# 每行字符的限制，0表示没有限制
ColumnLimit:     60
# 描述具有特殊意义的注释的正则表达式，它不应该被分割为多行或以其它方式改变
CommentPragmas:  '^ IWYU pragma:'
# 在新行上声明每个命名空间
CompactNamespaces: false
# 构造函数的初始化列表的缩进宽度
ConstructorInitializerIndentWidth: 4
# 延续的行的缩进宽度
ContinuationIndentWidth: 4
# 去除C++11的列表初始化的大括号{后和}前的空格
Cpp11BracedListStyle: true
# 继承最常用的换行方式
DeriveLineEnding: true
# 继承最常用的指针和引用的对齐方式
DerivePointerAlignment: false
# 关闭格式化
DisableFormat:   false
# 删除访问修饰符后的所有空行
EmptyLineAfterAccessModifier: Never
# 仅当访问修饰符开始一个新的逻辑块时才添加空行
EmptyLineBeforeAccessModifier: LogicalBlock
# 自动检测函数的调用和定义是否被格式为每行一个参数(Experimental)
ExperimentalAutoDetectBinPacking: false
# 自动补充namespace注释
FixNamespaceComments: true
# 需要被解读为foreach循环而不是函数调用的宏
ForEachMacros:
  - foreach
  - Q_FOREACH
  - BOOST_FOREACH
IfMacros:
  - KJ_IF_MAYBE
# 多个#include块合并在一起并排序为一个
IncludeBlocks:   Merge
# 可以定义负数优先级从而保证某些#include永远在最前面
IncludeCategories:
  - Regex:           '^"(llvm|llvm-c|clang|clang-c)/'
    Priority:        2
    SortPriority:    0
    CaseSensitive:   false
  - Regex:           '^(<|"(gtest|gmock|isl|json)/)'
    Priority:        3
    SortPriority:    0
    CaseSensitive:   false
  - Regex:           '.*'
    Priority:        1
    SortPriority:    0
    CaseSensitive:   false
IncludeIsMainRegex: '(Test)?$'
IncludeIsMainSourceRegex: ''
# 缩进访问修饰符
IndentAccessModifiers: false
# 缩进case标签
IndentCaseLabels: true
# case 标签后面的块使用与 case 标签相同的缩进级别
IndentCaseBlocks: false
# 缩进goto标签。
IndentGotoLabels: false
# 缩进预处理器指令
IndentPPDirectives: None
# 向后兼容缩进外部块
IndentExternBlock: AfterExternBlock
# 缩进模板中的requires子句
IndentRequires:  false
# 缩进宽度
IndentWidth:     4
# 函数返回类型换行时，缩进函数声明或函数定义的函数名
IndentWrappedFunctionNames: false
# 插入尾随逗号
InsertTrailingCommas: None
# 保留JavaScript字符串引号
JavaScriptQuotes: Leave
# 包装 JavaScript 导入/导出语句
JavaScriptWrapImports: true
# 保留在块开始处的空行
KeepEmptyLinesAtTheStartOfBlocks: true
# 相对于 lambda 签名对齐 lambda 主体
LambdaBodyIndentation: Signature
# 开始一个块的宏的正则表达式
MacroBlockBegin: ''
# 结束一个块的宏的正则表达式
MacroBlockEnd:   ''
# 连续空行的最大数量
MaxEmptyLinesToKeep: 4
# 命名空间的缩进
NamespaceIndentation: All
ObjCBinPackProtocolList: Auto
# 使用ObjC块时缩进宽度
ObjCBlockIndentWidth: 4
ObjCBreakBeforeNestedBlockParam: true
# 在ObjC的@property后添加一个空格
ObjCSpaceAfterProperty: false
# 在ObjC的protocol列表前添加一个空格
ObjCSpaceBeforeProtocolList: true
PenaltyBreakAssignment: 2
PenaltyBreakBeforeFirstCallParameter: 19
PenaltyBreakComment: 300
PenaltyBreakFirstLessLess: 120
PenaltyBreakString: 1000
PenaltyBreakTemplateDeclaration: 10
PenaltyExcessCharacter: 1000000
PenaltyReturnTypeOnItsOwnLine: 60
PenaltyIndentedWhitespace: 0
# 指针的对齐: Left, Right, Middle
PointerAlignment: Left
# 缩进预处理器语句的列数
PPIndentWidth:   -1
# 引用的对齐
ReferenceAlignment: Pointer
# 允许重新排版注释
ReflowComments:  true
# 短命名空间跨越的最大展开行数
ShortNamespaceLines: 1
# 允许排序#include
SortIncludes:    CaseSensitive
# java静态导入放在非静态导入之前
SortJavaStaticImport: Before
# 对using声明排序
SortUsingDeclarations: true
# 在C风格类型转换后添加空格
SpaceAfterCStyleCast: false
# 在!后添加空格
SpaceAfterLogicalNot: false
# 在Template关键字后添加空格
SpaceAfterTemplateKeyword: true
# 在赋值运算符之前添加空格
SpaceBeforeAssignmentOperators: true
# 不在case冒号之前添加空格
SpaceBeforeCaseColon: false
# 不在C++11大括号列表之前添加空格
SpaceBeforeCpp11BracedList: true
# 在构造函数初始化器冒号之前添加空格
SpaceBeforeCtorInitializerColon: true
# 在继承冒号前添加空格
SpaceBeforeInheritanceColon: true
# 开圆括号之前添加一个空格: Never, ControlStatements, Always
SpaceBeforeParens: ControlStatements
# 不要确保指针限定符周围有空格，而是使用 PointerAlignment
SpaceAroundPointerQualifiers: Default
# 在基于范围的for循环冒号之前添加空格
SpaceBeforeRangeBasedForLoopColon: true
# {}中间不添加空格
SpaceInEmptyBlock: false
# 在空的圆括号中添加空格
SpaceInEmptyParentheses: false
# 在尾随的评论前添加的空格数(只适用于//)
SpacesBeforeTrailingComments: 1
# 在尖括号的<后和>前添加空格
SpacesInAngles:  Never
# 不在if/for/switch/while条件周围插入空格
SpacesInConditionalStatement: false
# 在容器(ObjC和JavaScript的数组和字典等)字面量中添加空格
SpacesInContainerLiterals: true
# 在C风格类型转换的括号中添加空格
SpacesInCStyleCastParentheses: false
# 行注释开头允许有多少个空格。要禁用最大值，请将其设置为-1，除此之外，最大值优先于最小值
SpacesInLineCommentPrefix:
  Minimum:         1
  Maximum:         -1
# 在圆括号的(后和)前添加空格
SpacesInParentheses: false
# 在方括号的[后和]前添加空格，lamda表达式和未指明大小的数组的声明不受影响
SpacesInSquareBrackets: false
# 不在[前添加空格
SpaceBeforeSquareBrackets: false
# 位域:每边都添加空格
BitFieldColonSpacing: Both
# 标准
Standard:        Auto
# 在语句前面被忽略的宏定义，就好像它们是一个属性一样
StatementAttributeLikeMacros:
  - Q_EMIT
# 应该被解释为完整语句的宏定义
StatementMacros:
  - Q_UNUSED
  - QT_REQUIRE_VERSION
# tab宽度
TabWidth:        4
# 使用\n换行
UseCRLF:         false
# 使用tab字符：ForIndentation——仅将制表符用于缩进
UseTab:          ForIndentation
# 对空格敏感的宏定义
WhitespaceSensitiveMacros:
  - STRINGIZE
  - PP_STRINGIZE
  - BOOST_PP_STRINGIZE
  - NS_SWIFT_NAME
  - CF_SWIFT_NAME
```

您也可以参考[官方文档](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) 进行配置。

完成这一步之后，打开 `Settings` ，搜索 `format` ，将以下几个选项勾选：

<img src="https://ci.cncn3.cn/9f034f12d742653b01321b99af290200.png" title="" alt="9f034f12d742653b01321b99af290200.png" data-align="center">

这样，您就可以在打字和保存文件的时候进行代码格式化了。

#### 代码前端插件推荐

* `indent-rainbow`

该插件可以用彩虹色为您标明行首的空格以及 `Tab` 宽度。

* `TabOut`

如果您也和我一样，喜欢使用 `Tab` 键来跳出括号或者引号，那么这个插件是一个不错

#### 配置主题

看得顺眼的主题可以让您在敲代码时少些疲惫。

通过上方的截图，您或许看到了我使用的发光主题以及透明背景。

我使用的主题是 `SynthWave '84` ，安装之后，启用该主题，字体并不会发光。您需要点击 `Ctrl + Shift + P` ，输入 `Enable Neon Dreams` ，然后打开该选项。在 `Ubuntu` 平台下，右下角会弹出提示，要求以管理员身份运行 `VsCode` 。

如果要以管理员身份运行 `VsCode` ，在终端输入以下命令：

```bash
 sudo chown -R ${whoami} /usr/share/code
```

将 `${whoami}` 替换为您的用户名。如果要移除 `VsCode` 的管理员权限，则使用如下命令：

```bash
 sudo chown -R root /usr/share/code
```

此时，您就可以成功打开霓虹灯了。

接下来是修改背景透明度。搜索并安装插件 `GlassIt-VSC` ，启用之后，您可以使用快捷键 `Ctrl + Alt + Z` 和 `Ctrl + Alt + C` 进行透明度的调整。

`VsCode` 默认的文件图标也许并不好看，您可以使用 `vscode-icons` 来更改文件图标。

## 音乐软件的替代品：洛雪音乐助手

如果您想要一款跨平台并且包含海量歌曲的音乐软件，那么洛雪音乐助手将是一个不错的选择，除了上述的特点以外，它还有一个最大的特点就是，它的所有音乐都是免费的并且支持下载。

您可以在 `Github` 上找到它： [洛雪音乐助手](https://github.com/lyswhut/lx-music-desktop) 。

下载您可以通过 [Releases 页面](https://github.com/lyswhut/lx-music-desktop/releases) 或者 [我的网盘](https://share.purkit.ml/Linux%20Software/Ubuntu-share/lx-music-desktop.v1.22.3.x64.deb) 进行下载。

对于该软件的使用，您可以参阅 [官方文档](https://lxmusic.toside.cn/) 。

这里我简单地介绍一下它的下载功能和桌面歌词功能。

首先是它的下载功能。软件默认是不开启下载功能的。

您可以在设置中打开该功能并进行配置。

<img src="https://ci.cncn3.cn/189e9be52783eba9f4c4acb233bb7ce2.png" title="" alt="189e9be52783eba9f4c4acb233bb7ce2.png" data-align="center">

接下来是它的桌面歌词，我觉得洛雪音乐助手的桌面歌词非常简洁，比市面上的音乐软件的桌面歌词好看很多。

放一张截图：

<img src="https://ci.cncn3.cn/525b79485970ed2b945325af1f9d8a62.png" title="" alt="525b79485970ed2b945325af1f9d8a62.png" data-align="center">

右边绿色的就是洛雪的桌面歌词。

同样的，您可以在设置中打开并设置它。

<img src="https://ci.cncn3.cn/46672999414bfd02cc8ef2e4fa437ec9.png" title="" alt="46672999414bfd02cc8ef2e4fa437ec9.png" data-align="center">

## `QQ` 的客户端

我本人是十分不喜欢 `QQ` 的，但为了和周围的人保持联系，只能使用比较大众的 `QQ` 进行即时通讯。

如果您使用的是 `Ubuntu` ，那就不难发现，官方 `Linux` 版的 `QQ` 做的实在差劲。

于是我们需要一些第三方的客户端。这里我提供两种。

一种是 `VsCode` 的扩展。直接在扩展商店中搜索 `QQ` 就可以安装了。这种的 `QQ` 功能很少，不能收发文件。

还有一种是 `Icalingua++` ，它是一个 `QQ` 的第三方客户端。您可以在这里看到关于它的介绍：[Icalingua++](https://github.com/Icalingua-plus-plus/Icalingua-plus-plus) 。

使用它有一定风险，因为腾讯是不喜欢别人动摇它的垄断地位的，所以，使用第三方客户端会有冻结账号的风险，读者们量力而行。

对于它的下载，您可以在 [Releases 页面](https://github.com/Icalingua-plus-plus/Icalingua-plus-plus/releases) 进行下载也可以在 [我的网盘](https://share.purkit.ml/Linux%20Software/Ubuntu-share/icalingua_2.7.5_amd64.deb) 进行下载。

因为我对于 `Ubuntu` 的探索也还不够深，所以之后我会在这篇文章中继续推荐软件，欢迎大家关注。
