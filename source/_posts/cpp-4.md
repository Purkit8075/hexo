---
title: C++ 教程（四）
date: 2022-10-22
description: 本文介绍 C++ 的循环结构，并且通过制作一个简单计算器的例子来复习之前的知识。
tags: ["复习","循环结构"]
categories: "C++ 教程" 
keywords: ["循环结构"]
cover: https://s3.tebi.io/img.purkit.ml/cpp-cover.jpg
---

# C++ 教程（四）

## 循环结构

`C++` 中，循环结构有三种写法，我们要接触到 3 个新的关键字，分别是 `while` 、`do` 和 `for` 。

接下来，我将逐一介绍它们。

### while 语句

`while` 循环的基本结构如下：

```cpp
while (/* condition */)
{
    /* code */
}
```

其中，`condition` 部分是一个条件，就像 `if` 后面的语句一样，是一个布尔值或者条件表达式。

`while` 循环的执行顺序是

```
判断条件->如果条件符合->执行块中的语句->判断条件->符合就重复第3步，不符合就跳出
判断条件->如果条件不符合->执行 while 之后的语句
```

如果要输出从 1 到 n 之间所有的整数，用 `while` 循环可以这么写：

示例程序 4.1

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i = 1;

    cout << "Please input n: ";

    cin >> n;

    while (i <= n)
    {
        cout << i << endl;
        i++;
    }

    return 0;
}
```

程序中出现了 `i++` 的写法，这条语句的意思是将 `i` 自增 1。其中 `++` 属于一种运算符。

如果要自减的话，就使用 `--` 运算符。关于运算符还有许多细节，将来我会写一篇专题来介绍。

如果要让程序进入死循环，只需要让条件恒为真，所以您可以这么写 `while(1)` 。

### do while 语句

`do while` 的使用率比较少，它的基本结构如下：

```cpp
do
{
    /* code */
} while (/* condition */);
```

`while` 是在循环的入口判断条件，而 `do while` 是在循环的出口判断条件。

示例程序 4.2

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    int i = 1;

    do
    {
        cout << i << endl;
    } while (i < 1);

    return 0;
}
```

可以看到，i 为 1，不符合 `i < 1` 的条件，但是因为是在出口处判断条件，所以仍然会输出 i 的值。

> **注意：** `do while` 结构中 `while` 的末尾有一个分号，不要忘记这个细节。

### for 语句

`for` 语句的基本结构如下：

```cpp
for (type i = 0; i < count; i++)
{
    /* code */
}

//for (1；2；3)
//{
//    4
//}
```

`for` 循环的执行顺序是这样的：

```
1 -> 2 -> 4 -> 3 -> 2 -> 4 -> 3
```

`1` 部分是初始化一个变量，在 `C语言` 中，不能在 `1` 的位置声明新的变量，但 `C++` 可以。

在一个循环中 `1` 部分只执行一次。

`2` 部分是循环的条件，每次执行前都要判断一次条件。

`3` 部分是每次循环的语句块结束之后进行的操作。执行完这部分之后就判断条件。

`4` 部分是要循环的步骤。

如果要输出从 `1` 到 `n` 之间所有的整数，用 `for` 循环可以这么写：

示例程序 4.3

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    int n;

    cout << "Please input n: " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cout << i << endl;

    return 0;
}
```

`for` 循环也可以省略 `1` 、`2` 、`3`  中的内容。如果写成 `for( ; ; )` 的形式，那就是一个死循环了。

### 循环的其它内容

#### continue 和 break

`continue` 的用法是直接跳过这次循环，进行下一次循环的判断和执行。

`break` 的作用是直接跳出该循环。

示例程序 4.4

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    int i = 0;

    while (i <= 10)
    {
        if (i == 5)
        {
            i++;
            continue;
        }
        else if (i == 8)
            break;
        else
            cout << i << endl;
        i++;
    }

    return 0;
}
```

该程序的输出结果如下：

```
0
1
2
3
4
6
7
```

可以看到，程序没有输出 `5` ，因为当 `i==5` 时使用了 `continue` 导致此次循环被跳过。

程序只输出到 `7` 是因为当 `i==8` 时使用了 `break` ，跳出了循环。

#### 三种循环结构的选用

对于 `while` 、`do while` 和 `for` 三种循环语句，恰当地选择使用可以让编程的条理更清楚。

如果是进行一个区间内的循环，那么使用 `for` 是一个不错的选择。

如果是让程序主体重复执行或者死循环，那么 `while` 和 `do while` 都要优于 `for` 。

接下来，我将用制作一个简单的计算器来复习之前学过的内容。

## 简单的计算器

因为我们还没有介绍自定义头文件的方法，所以这个简单的小项目将所有的函数放在同一个文件中。

这样子会大大增加单个文件的长度，如果使用自定义的头文件，那将使单个文件更简短。

进入正题，这个简单的计算器只需要能计算简单的四则运算。

我们首先需要一个菜单。对于菜单，我们需要两个函数。

一个函数用于重复输出一个字符，另一个函数用于输出选项。如下：

```cpp
void PutChar(char ch);
void PutMenu();

void PutChar(char ch)
{
    const int LIMIT = 20;

    for (int i = 0; i < LIMIT; i++)
        std::cout << ch;
    std::cout << std::endl;

    return;
}

void PutMenu()
{
    using std::cout;
    using std::endl;

    const std::string space = "   ";

    int choice;

    PutChar('*');
    cout << "请选择需要的运算方法" << endl;
    PutChar('-');
    cout << space << "[1] 加法" << endl;
    cout << space << "[2] 减法" << endl;
    cout << space << "[3] 乘法" << endl;
    cout << space << "[4] 除法" << endl;
    cout << space << "[q] 退出" << endl;
    PutChar('*');

    return;
}
```

在 `PutMenu()` 中的 `space` 的作用是让选项居中输出。让菜单更整洁。

对于选项的选择，我们需要一个 `choice` 变量，再让用户输入这个变量。

然后 5 个选项分别对应 5 个数字。然后用 `switch` 判断 `choice` 属于哪一类运算。

那么怎么定义 5 个选项所对应的数字呢？

如果只是在脑海里“记住”对应的数字，那样是非常不靠谱的。

编程的时候，代码中应尽量有意义的变量或常量名，而不是单一的数字。

这个时候我们就需要使用之前提到过的常量的定义。这里我使用的是 `enum` ，也顺便演示一下 `enum` 的一般用法。

```cpp
enum DEVICE
{
    QUIT = 0,          // 退出
    ADDITION = 1,      // 加法
    SUBSTRACTION = 2, // 减法
    MULT = 3,          // 乘法
    DIVISION = 4      // 除法
};
```

有了这个思路之后，我们先来考虑怎么解决退出的问题。

这里就需要介绍一个新的函数 `exit()` ，它是定义在头文件 `<cstdio>` 中的函数。

> 头文件名称中的“前缀”：因为 `C++` 是由 C语言 发展而来的，所以仍然包括 C语言原有的库。
> 
> 这些头文件为了区别原有的头文件，就在文件名的前面加上了 `c` 来显示它是 C语言 的头文件。
> 
> 这些头文件中的东西也是包含在 `std` 名称空间中的。所以在使用时要记得使用 `std` 名称空间。

这个函数接受一个整数参数，然后退出程序。 

如果成功退出则参数为 `0` 或 `EXIT_SUCCESS` ，如果失败则可以使用 `EXIT_FAILURE` 来退出。

这里我们就使用 `EXIT_SUCCESS` 来进行退出。

之后就在 `switch` 中解决运算的过程。

这里要注意当选择的运算方法为除法时，要判读第二个数字是否为 0 。

如果为 0 的话，那就要求用户重新输入第二个数字。

所以 `Solve()` 函数的定义如下：

```cpp
void Solve();

void Solve()
{
    double firnum, secnum;
    int choice;

    std::cin >> choice;

    if (choice == QUIT)
    {
        std::cout << "再见！" << std::endl;
        sleep(2000);
        std::exit(EXIT_SUCCESS);
    }

    std::cout << "请输入第一个数: "
              << std::endl;
    std::cin >> firnum;
    std::cout << "请输入第二个数: "
              << std::endl;
    std::cin >> secnum;

    switch (choice)
    {
        case ADDITION:
        {
            std::cout << firnum << " + " << secnum
                    << " = " << firnum + secnum
                    << std::endl;
            break;
        }
        case SUBSTRACTION:
        {
            std::cout << firnum << " - " << secnum
                    << " = " << firnum - secnum
                    << std::endl;
            break;
        }
        case MULT:
        {
            std::cout << firnum << " * " << secnum
                    << " = " << firnum * secnum
                    << std::endl;
            break;
        }
        case DIVISION:
        {
            while (secnum == 0)
            {
                std::cout << "除数不能为 0, 请重新输入除数"
                        << std::endl;
                std::cin >> secnum;
            }

            std::cout << firnum << " / " << secnum
                    << " = " << firnum / secnum
                    << std::endl;
            break;
        }
    }

    return;
}
```

可以看到，程序中还有一个新的函数 `sleep()` ，这个函数是用来使程序进入等待。

它接受一个参数，以毫秒为单位，作为程序等待的时长。

在 `Linux` 系统下，它包含在头文件 `<unistd.h>` 中，而在 `Windows` 系统下，则包含在头文件 `<windows.h>`  中。

因为运算不可能只有一次，所以我们需要一个循环来让用户达到多次选择并计算的效果。

最后放出所有的源代码。

```cpp
#include <iostream>
#include <string>
#include <cstdio>     //使用 exit()
#include <unistd.h>    // 如果是在 Windows 系统下，则替换成 <windows.h>

enum DEVICE
{
    QUIT = 0,          // 退出
    ADDITION = 1,      // 加法
    SUBSTRACTION = 2, // 减法
    MULT = 3,          // 乘法
    DIVISION = 4      // 除法
};

// function statements
void PutChar(char ch);
void PutMenu();
void Solve();

int main(void)
{
    while (1)
    {
        PutMenu();
        Solve();
    }
    return 0;
}

void PutChar(char ch)
{
    const int LIMIT = 20;

    for (int i = 0; i < LIMIT; i++)
        std::cout << ch;
    std::cout << std::endl;

    return;
}

void PutMenu()
{
    using std::cout;
    using std::endl;

    const std::string space = "   ";

    int choice;

    PutChar('*');
    cout << "请选择需要的运算方法" << endl;
    PutChar('-');
    cout << space << "[1] 加法" << endl;
    cout << space << "[2] 减法" << endl;
    cout << space << "[3] 乘法" << endl;
    cout << space << "[4] 除法" << endl;
    cout << space << "[q] 退出" << endl;
    PutChar('*');

    return;
}

void Solve()
{
    double firnum, secnum;
    int choice;
    std::cin >> choice;

    if (choice == QUIT)
    {
        std::cout << "再见！" << std::endl;
        sleep(2000);
        std::exit(EXIT_SUCCESS);
    }

    std::cout << "请输入第一个数: "
              << std::endl;
    std::cin >> firnum;
    std::cout << "请输入第二个数: "
              << std::endl;
    std::cin >> secnum;

    switch (choice)
    {
        case ADDITION:
        {
            std::cout << firnum << " + " << secnum
                    << " = " << firnum + secnum
                    << std::endl;
            break;
        }
        case SUBSTRACTION:
        {
            std::cout << firnum << " - " << secnum
                    << " = " << firnum - secnum
                    << std::endl;
            break;
        }
        case MULT:
        {
            std::cout << firnum << " * " << secnum
                    << " = " << firnum * secnum
                    << std::endl;
            break;
        }
        case DIVISION:
        {
            while (secnum == 0)
            {
                std::cout << "除数不能为 0, 请重新输入除数"
                        << std::endl;
                std::cin >> secnum;
            }

            std::cout << firnum << " / " << secnum
                    << " = " << firnum / secnum
                    << std::endl;
            break;
        }
    }

    return;
}
```

## 练习

1. 在本例计算器的基础上增加计算阶乘的功能和计算乘方的功能。
2. 对于给定的一个大写字母，输出如下图的金字塔。

![89df47d3f13f5f36647ea702b4993521.png](https://ci.cncn3.cn/89df47d3f13f5f36647ea702b4993521.png)

---------------------

 ——END——
