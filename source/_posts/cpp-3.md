---
title: C++ 教程（三）
date: 2022-10-15
description: 本文介绍了 C++ 中函数的基础知识，和 C++ 中的顺序结构以及分支结构。
tags: ["函数","分支结构","选择结构"]
categories: "C++ 教程"
keywords: ["分支结构","选择结构","函数"]
cover: https://ci.cncn3.cn/62147f26003368f0c8cbf7f5973bd526.png
---

# C++ 教程（三）

## 函数初探

函数是 `C++` 中的重要组成部分，在编程的过程中，为了实现各种各样的目标，我们难免要自己创建函数来达到目标。

可以说，编程的乐趣正是在于编写函数并且实现编程的目标。

`C++` 本身就包含了许多函数，它们位于不同的头文件中。

每个函数（一般不包括 `main` 函数）的地位都是平等的。每个函数都可以调用别的函数包括自己（递归）。

我们用熟悉的 `main` 函数举例。

```cpp
int main(void)
{
    ...
    return 0;
}
```

一个简单的函数包括以下几个元素：

1. 函数名
   
   函数名的定义规则和变量的定义规则是一样的，都不能将数字放在函数名的首位。同时也要避免没有意义的函数名。`main` 就是这个函数的函数名。

2. 参数
   
   参数是一个函数接受的数据。虽然名为参数，但并不仅限于数字，它可以是字符、字符串或者其它类型。函数可以有多个参数，也可以没有参数。对于这个 `main` 函数来说，它没有参数。参数是位于小括号 `()` 中的内容，这里是 `void` 即空——没有参数，这个 `void` 可以省略。对于多个参数中间用逗号 `,` 隔开，之后的例子会演示这种用法。

3. 实现
   
   用大括号 `{}` 扩起来的部分就是函数的实现。无论一个函数有多少语句，它们都要包含在大括号内，这样才算函数的内容。函数内部也可以创建变量，并且这些变量不能为外部所用。

4. 返回值
   
   对于一个函数，它的返回值类型是位于函数名前面的类型。对于这个 `main` 函数，它的返回值类型就是 `int` 。一个函数返回值用 `return` 语句进行。当函数执行到 `return` 语句之后，就会跳出函数，执行其它的操作。返回值要与返回值类型对应。与参数一样，返回值的类型可以是 `void` ，这时候，您可以省略 `return` 语句，也可以写成 `return;` 的形式将函数终止。

接下来，我们来看看示例程序 3.1

这个程序包含一个获取个人信息的函数，以及计算 `BMI指数` 的函数（怎么又是 `BMI`）。

示例程序 3.1

```cpp
#include <iostream>
#include <string>

//函数声明，就像声明变量一样
std::string GetName();
double BMI(std::string Name);
void Solve();

int main(void)
{
    Solve();
    return 0;
}

std::string GetName()
{
    std::string name;

    std::cout << "Please enter your name:";
    std::getline(std::cin, name);

    return name;
}

double BMI(std::string Name)
{
    using namespace std;

    double height, weight;

    cout << "Hello " << Name
         << ",please enter your height: " << endl;

    cin >> height;

    cout << "Then enter your weight: " << endl;

    cin >> weight;

    // double bmi = weight / (height * height);
    // return bmi;
    // That's OK

    return weight / (height * height);
}

void Solve()
{
    std::string name = GetName();
    double bmi = BMI(name);

    std::cout << "OK " << name
              << ", your BMI is: " << bmi << std::endl;

    // return;
    // it's OK
}
```

在编程的过程中，我们应尽可能地使用函数，而不是将所有代码放在 `main()` 中。

这样做可以让编程模块化，方便将来维护。

程序运行的结果如下：

![9c410cc7d552643b80f8ca7825d38a1b.png](https://ci.cncn3.cn/9c410cc7d552643b80f8ca7825d38a1b.png)

（图片仅供参考，请以实物为准）

在示例程序 3.1 中，我编写了三个函数，它们实现各自的目标。

`GetName()` 用于获取用户名字，`BMI()` 用于计算用户的 `BMI` 指数。`Solve()` 用于实现编程的目标。

可以看出，程序从 `main()` 开始执行，然后转到 `Solve()` 函数中，再逐句执行。

所以函数的执行并不复杂，只是执行到函数时就进入函数。

对于返回值的作用，`Solve()` 函数中演示得很清楚了。返回值的作用可以简单理解为将一个函数看作一个数据，这个数据可以用于赋值等操作。

例如第 51 行，就是先执行 `GetName()` 的内容，再将获得的用户名字返回，然后赋值给 `Solve()` 中的 `name` 。

函数可以不进行声明，即您可以省略示例程序 3.1 中的 5 至 7 行。如果这么做，您将需要考虑定义函数的次序。

如果您省略声明，那么示例程序 3.1 就需要改写成如下

```cpp
#include <iostream>
#include <string>

std::string GetName()
{
    std::string name;

    std::cout << "Please enter your name:";
    std::getline(std::cin, name);

    return name;
}

double BMI(std::string Name)
{
    using namespace std;

    double height, weight;

    cout << "Hello " << Name
         << ",please enter your height: " << endl;

    cin >> height;

    cout << "Then enter your weight: " << endl;

    cin >> weight;

    // double bmi = weight / (height * height);
    // return bmi;
    // That's OK

    return weight / (height * height);
}

void Solve()
{
    std::string name = GetName();
    double bmi = BMI(name);

    std::cout << "OK " << name
              << ", your BMI is: " << bmi << std::endl;

    // return;
    // it's OK
}

int main(void)
{
    Solve();
    return 0;
}
```

如果您将 `Solve()` 函数的定义放到其它两个函数之前，而 `Solve()` 函数中又恰巧有使用到 `BMI()` 和 `GetName()` 函数。

那么对于 `Solve()` 来说，另外两个函数是未定义的。这样子编译器将会报错。

如果您使用声明，则只需要将声明置于程序前方。即所有函数之前就不会报错。

> **注意：** 在制作大的项目时，应该尽可能地使用声明。如果只是一些简短的代码则不需要考虑是否需要函数声明。
> 
> 我个人建议是尽量使用声明，这样可以让程序更加容易读懂。让他人以及自己知道这个程序有哪些函数，便于后期维护。

关于函数，还有许多用法，我将在之后更深入的讲解。

## C++ 的三大结构

`C++` 的三大结构分别是 顺序结构 、分支结构（选择结构）、循环结构。

顺序结构给程序提供执行的次序，在之前的例子中已经渗透了它的用法。

分支结构给程序提供决策的能力，让程序得以处理不同的情况。

循环结构让程序执行重复的工作，正是这一点，让信息技术成为提高我们工作效率的有力工具。

关于这三大结构，我先分别介绍它们的内容。

然后通过制作一个简单的计算器的例子来复习三大结构和函数的用法，让读者初步体会制作小项目的感觉。

### 顺序结构

我们在编程的时候，每一条语句都是讲给编译器的话。编译器听到之后作出反应，生成可执行程序。

正如和人类对话一般，说话要有先后次序，否则交流就会受到阻碍。

编程的时候，编译器从文件的第一行读到最后一行，如果中间出现了前面完全没有出现过的东西，就会报错。

这里完全没有出现过意思是没有定义或者声明过。例如，对于变量 `a` 的赋值：

```cpp
int a;
a = 1;    //it's ok
```

```cpp
a = 1;
int a;    //it can't work
```

您不能将声明和赋值的操作顺序互换。包括上文所说的函数的声明，也是顺序结构的体现。

顺序结构是最基本的结构，是编程的基础。

### 分支结构（选择结构）

在介绍分支结构和循环结构之前，我有必要补充一下布尔值的知识。

#### 布尔值简介

布尔值 (`bool`) 是一种 `C++` 的数据类型。 `C语言` 中并没有这一类型。

对于 `C语言` ，如果需要使用 `bool` 这一数据类型，需要包含头文件 `stdbool.h` 。

布尔值只占 2 字节，它只有 `true` 和 `false` 两个值。`true` 为真，`false` 为假。

> **注意：** 这里的真假并不涉及哲学上的真假。比如 `1>0` 就是真，`1<0` 即为假。
> 
> 在您自己的程序中，您甚至可以自己定义真假。比如您可以让一个函数当 `1>0` 时返回假。
> 
> 当然，我不建议这么做。

在 `C++` 中， `false` 可以用 `0` 代替，而 `true` 可以用所有非零的数据代替，我们一般用 `1` 代替。

如果您输出 `true` 或者 `false` ，那么控制台会对应输出 `1` 或 `0` 。

这里还要顺带提一下 `C++` 的关系运算符。所谓关系运算符就是数学上的大于小于等等。

| 符号   | 意义  |
|:----:|:---:|
| `>`  | 大于  |
| `<`  | 小于  |
| `>=` | 大等于 |
| `<=` | 小等于 |
| `==` | 等于  |
| `!=` | 不等于 |

尤其需要注意等于的符号，是两个等号 `==` ，不要将它和赋值的一个等号 `=` 混淆。

这时候，问题来了，如果我要判断一个数字是否在一个区间内要用什么符号呢？

比如我要判断变量 `a` 是否在 `[10,20]` 这个区间内，要怎么编写条件表达式呢？

也许您会想到 `10 <= a <= 20` 这种数学上的写法。

不幸的是，对于人来说，这很好理解，但编译器并不接受这种写法。

这时候就需要用到布尔值中常常听到的 与、或、非了。

| 符号   | 意义  |
|:----:|:---:|
| `&&` | 与   |
| `    |     |
| `!`  | 非   |

`&&` 前后连接两个表达式，如果两个都为真，则返回真。如果一个为假，则返回假。

`||` 前后连接两个表达式，如果其中一个为真，则返回真。如果都为真，则返回真。都为假，则返回假。

`!` 后接一个表达式，它与这个表达式对着干，如果表达式为真，则返回假。若为假，则返回真。

那么对于`10 <= a <= 20` 则应该写成 `a<=20 && a>=10` 的形式。

这一点需要特别注意。初学者难免犯这种错误。

回到分支结构，分支结构有三种写法。这里将一一介绍。

#### if / else if / else

先看一个示例程序。该程序接受一个分数，并且根据其所处区间输出建议。

示例程序 3.2

```cpp
#include <iostream>

int main(void)
{
    using namespace std;

    int score;

    cout << "Please input your score: ";
    cin >> score;

    if (score >= 90 && score <= 100)
        cout << "Excellent!" << endl;
    else if (score >= 60 && score < 90)
        cout << "Good!" << endl;
    else if (score < 60 && score >= 0)
        cout << "Try hard!" << endl;
    else
    {
        cout << "Please input a right score!" << endl;
        cout << "The score must between 0 and 100." << endl;
        cout << "You can input a score like 90." << endl;
    }

    return 0;
}
```

这种的分支结构，只能有一个 `if` 和 `else` ，但可以有多个 `else if` 。有的时候也可以只有一个 `if` 。

如果这些关键字之后只有一条语句，则可以不使用大括号 `{}` 将其扩起。如果有多条语句，则需要使用大括号，就像函数一样。

考虑这么一个问题：如果示例中的区间有重合，那会发生什么？

示例程序 3.2

```cpp
#include <iostream>

int main(void)
{
    using namespace std;

    int score;

    cout << "Please input your score: ";
    cin >> score;

    if (score >= 90 && score <= 100)
        cout << "Excellent!" << endl;
    else if (score >= 50 && score < 90)
        cout << "Good!" << endl;
    else if (score < 60 && score >= 0)
        cout << "Try hard!" << endl;

    else
    {
        cout << "Please input a right score!" << endl;
        cout << "The score must between 0 and 100." << endl;
        cout << "You can input a score like 90." << endl;
    }

    return 0;
}
```

这个时候，如果输入 `55` 会发生什么呢？

运行之后，发现程序只输出了 `Good！` 而不是输出 `Good` 和 `Try hard!` 两条语句。

这是因为，当程序执行到这个结构的时候，只要有一个条件符合，它就会跳出这个分支结构，直接执行之后的操作。

当条件都不符合的时候，它就会查看 `else` 之后的语句。如果没有 `else` ，就会继续执行后面的语句。

所以，在很多时候，`else` 往往会被省略。

> 如果只有一条语句，一定要注意缩进，让代码看起来层次分明。

#### switch

看到这个关键字，可不要和某游戏机混淆。

`switch` 的结构大致如下：

```cpp
switch (tag)
{
    case condition:
        ...
        break;
    case condition:
        ... 
        break;
    default:
        ...
        break;
}
```

它的结构和 `if / else if /else` 相似。其中，`tag` 是一个整数。当然，字符 `char` 也是一个整数，因为它通过 `ASCII` 码与整数一一对应。

`case` 后面跟整数值，如果相等，就执行对应操作。

> **注意：** `case` 后面使用冒号 `:`  连接语句，冒号之后也可以使用大括号将内容扩起。如果有其它结构需要嵌套，则需要使用大括号扩起。

那么 `break` 的作用是什么呢？

在循环中，`break` 是用来跳出循环的，那么 `switch` 中的作用是什么呢？这里，我们看一个示例程序。

示例程序 3.3

```cpp
#include <iostream>

int main(void)
{
    using namespace std;

    int tag;

    cin >> tag;

    switch (tag)
    {
    case 1:
        cout << 10 << endl;
    case 2:
        cout << 20 << endl;
    case 3:
        cout << 30 << endl;
    default:
        cout << "Can't work!" << endl;
    }

    return 0;
}
```

如果我输入 `1` ，我期望的是输出 `10` ，运行结果如下：

![6aef5f8fb2abdfa868cf1713b54fdcf3.png](https://ci.cncn3.cn/6aef5f8fb2abdfa868cf1713b54fdcf3.png)

没有 `break` 的结果就是，它会一直执行下去，直到 `break` 或者结束。

所以，我们需要加上 `break` ，达到我们的目的。

最后一个 `default` 的作用和 `else` 相似。

最后，示例程序 3.3 就可以修改成如下：

示例程序 3.4

```cpp
#include <iostream>

int main(void)
{
    using namespace std;

    int tag;

    cin >> tag;

    switch (tag)
    {
    case 1:
        cout << 10 << endl;
        break;
    case 2:
        cout << 20 << endl;
        break;
    case 3:
        cout << 30 << endl;
        break;
    default:
        cout << "Can't work!" << endl;
        break;
    }

    return 0;
}
```

#### goto语句

许多编程语言都有 `goto` 语句，它是一种更灵活的分支结构。但是，我们不提倡使用 `goto` 语句。

因为大多数的 `goto` 都可以用循环结构代替，当然，有些情况下使用 `goto` 也不失一种明智之举。鉴于此，我只简单介绍它的用法。

示例程序 3.5

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    int a;
    goto GOTO_;

    cin >> a;

GOTO_:
    a = 10;
    cout << a << endl;

    return 0;
}
```

运行之后，就会发现，程序跳过了输入的语句，直接输出了 `10` 。

`goto` 语句，就是跳转到一个标识处，然后执行标识处一下的代码。

由于它实现的原理问题，它被认为是不安全的。所以我们应使用其它的结构来代替它。

> 由于篇幅的原因，循环结构和简单的计算器的制作将在下一篇博文介绍。

## 练习

1. 任意输入一个数字，输出它是奇数还是偶数。

2. 使用 `switch` 语句完成对学校食堂的评分反馈。
   
   分数从 `0~10`，如果是 8 分以上，则输出 `Good`，如果是 5 分以上则输出 `Just so so` ，如果是 5 分以下，则输出 `Bad` 。

-------

——END——
