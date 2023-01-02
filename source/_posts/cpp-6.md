---
title: C++ 教程（六）
date: 2022-11-06
description: 本文是对于前面博文的补充，包括运算符的其它性质、enum 的特性、字符的性质和 C 风格的输入与输出。
tags: ["C风格","enum","字符","补充"]
categories: "C++ 教程" 
keywords: ["enum","字符"]
cover: https://ci.cncn3.cn/62147f26003368f0c8cbf7f5973bd526.png
---

# C++ 教程（六）

> 写在前面：因为本人能力有限，并且对于 `C++` 并没有掌握得很全面，所以前面的教程有许多疏漏，为了填补前面没有介绍到的东西，特此写一篇博文来补充。
> 
> 所以，这篇文章不会有很多新东西，但是依然值得一看。

## 上一节的练习

### 斐波那契数列

#### Problem

对于给定的 `n` ，输出斐波那契数列的 `1~n` 项。

#### Solve

关于斐波那契数列的写法有很多，由于上一篇文章介绍的是数组，所以这边用数组来实现。

我们令这个数列为 `a` ，下标为 `i` 。

显而易见，当 `i < 3` 时，a<sub>i</sub> = 1。当 `i >= 3` 时，a<sub>i</sub> = a<sub>i-1</sub> + a<sub>i-2</sub> 。

由此，我们可以解决这一问题。实现如下：

```cpp
#include <iostream>

int main(void)
{
    const int ArSize = 200;    //随便定一个数组大小

    int n;
    int a[ArSize] = {0};

    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i < 3)
            a[i] = 1;
        else
            a[i] = a[i - 1] + a[i - 2];
    }

    for (int i = 1; i <= n; i++)    // 也可以在上一个循环中直接输出
        std::cout << a[i] << " ";

    return 0;
}
```

### 复习函数传递实参

#### Problem

写一个函数，包含两个参数，第一个参数是要进行操作的数字，第二个参数是一个整数。

函数的功能是让第一个参数加上第二个参数，并且返回值为 `void` 。

#### Solve

这题就是简单的复习函数的引用参数，也就是传递实参。

由于比较简单，这边只提供函数。

```cpp
void Solve(int& x, int add)
{
    x += add;
}
```

（好像有点水）

## 运算符专题

`C++` 中有各式各样的运算符。

对于它们的分类，我们可以通过它们的操作数个数分为 单目运算符、双目运算符和三目运算符。

什么是操作数个数呢？

举个例子，对于加号 `+` ，我们这么使用它：`a + b` ，那么，它的操作数个数就是 2 。我们将它归类于 双目运算符。

单目运算符在位运算符中比较常见，由于是比较基础的教程，这边暂不探讨位运算符（其实我也不会）。

我们见过的单目运算符有布尔值中的取反符号 `!` ，还有自增自减 `++` 和 `--` ，它们就是单目运算符。

那么三目运算符有什么呢？

其实，`C++` 中的三目运算符只有一个，那就是 `? :` 运算符。

这个运算符有什么作用呢？

其实它就是比较简短的 `if-else` 语句。我们往往使用它来简化代码。

它的使用格式如下：`condition ? true : false` 。

当 `condition` 为真时，它执行或返回 `true` 部分，如果为假，那就执行或返回 `false` 部分。

比如，我输入两个数字，要求程序输出较大的那一个数字。

如果用 `if-else` 语句，那么就要写比较多的代码。如果是用 `? :` 的话，就会大大简化代码。

示例程序 6.1

```cpp
#include <iostream>

int main(void)
{
    int a, b;

    std::cout << "Please input a and b:" << std::endl;

    std::cin >> a >> b;

    std::cout << "The bigger number is: " << (a > b ? a : b)
              << std::endl;

    return 0;
}
```

当然，这个运算符可以进行嵌套。如果要求输出三个数字中最大的数字，那么可以采用如下写法：

示例程序 6.2

```cpp
#include <iostream>

int main(void)
{
    int a, b, c;

    std::cout << "Please input a, b and c:" << std::endl;

    std::cin >> a >> b >> c;

    std::cout << "The biggest number is: "
              << (a > (b > c ? b : c) ? a : (b > c ? b : c))
              << std::endl;

    return 0;
}
```

当然，`true` 和 `false` 的部分也可以是语句。多条语句之间使用逗号 `,` 隔开。

同样是求三个数字中的最大值。我们可以这么写：

示例程序 6.3

```cpp
#include <iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    int a, b, c;
    int temp;

    cout << "Please input a, b and c:" << endl;

    std::cin >> a >> b >> c;

    cout << "The biggest number is: ";

    (a > (temp = (b > c ? b : c)) ? cout << a,
     cout << endl                 : cout << temp);

    return 0;
}
```

我们使用三目运算符的目的是简化代码。

如果像上面这样写，不仅达不到简化的目的，反而会让程序变得难懂，降低了程序的可读性。

所以，对于三目运算符的使用，还需要视情况而定。

如果要给一个变量加上一个数字，比如让 `a` 加上 `n` ，那么我们可以这么写：`a = a + n;` 。

`C++` 中还提供了简写的方式，即 `a += n;` ，这类运算符叫做复合赋值操作符。

常见的复合赋值操作符有以下这些：

| 运算符 | 使用     | 含义                                                    |
|:---:|:------:|:-----------------------------------------------------:|
| +=  | a += n | 将 `a + n` 的值赋值给 `a` ，当 `n == 1` 时，等效于 `a++` 或 `++a` 。 |
| -=  | a -= n | 将 `a - n` 的值赋值给 `a` ，当 `n == 1` 时，等效于 `a--` 或 `--a` 。 |
| *=  | a *= n | 将 `a * n` 的值赋值给 `a` 。                                 |
| /=  | a /= n | 将 `a / n` 的值赋值给 `a` 。                                 |
| %=  | a %= n | 将 `a % n` 的值赋值给 `a` 。                                 |

关于自增和自减运算符 `++` 和 `--` ，还有一些细节的内容。

当它们分别放在变量的前后时，其意义是不一样的。

下面，我们用一个示例程序看看其中的差别。

示例程序 6.4

```cpp
#include <iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    int a = 1;

    cout << "Now, a = " << a << endl;
    a++;
    cout << "After a++, a = " << a << endl;
    ++a;
    cout << "After ++a, a = " << a << endl;
    cout << "Using a++ directly, a++ = " << a++ << endl;
    cout << "Now a = " << a << endl;
    cout << "Using ++a directly, ++a = " << ++a << endl;

    return 0;
}
```

可以看到输出结果如下：

![79199e0030239969c567aa9864723d76.png](https://ci.cncn3.cn/79199e0030239969c567aa9864723d76.png)

在语句外使用 `a++` 和 `++a` 的效果是一样的，但是直接输出 `a++` 和 `++a` 的结果却是不一样的。

这是因为 `a++` 是 “先用再变” ，而 `++a` 是 “先变再用” 。

所以直接输出 `a++` 时，其实是先输出 `a` ，然后再改变 `a` 的值。

所以在语句中使用时要特别注意这一特性。

运算符还有一个很重要的内容，那就是运算的优先级。

就像数学中的四则运算，先乘除后加减。`C++` 也有它独特的运算优先级。

关于这部分内容，参考这篇文章： [传送门](https://blog.csdn.net/zb_915574747/article/details/99704639) 。

如果记不住这么多的优先级，可以使用小括号 `()` 来将你想要先执行的运算括起来。

程序从内层小括号往外计算。注意，`C++` 中的中括号 `[]` 和大括号 `{}` 与数学中的含义是不一样的。

它们不能起到改变运算优先级的作用。关于运算符目前就补充这么多了。

## 关于 `enum`

之前只介绍了 `enum` 的显式用法，现在补充以下它的隐式用法。

示例程序 6.5

```cpp
#include <iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    enum { Zero, One, Two };

    cout << "Zero = " << Zero << endl;
    cout << "One = " << One << endl;
    cout << "Two = " << Two << endl;

    return 0;
}
```

输出结果如下：

![73dfd6ecc1faefb998efa556d55f5e8e.png](https://ci.cncn3.cn/73dfd6ecc1faefb998efa556d55f5e8e.png)

可以看到，`enum` 的首个元素默认为 `0` ，那么它之后的元素的默认值遵循什么规则呢？

这里我们再看一个例子：

示例程序 6.6

```cpp
#include <iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    enum { First = 10, Second, Third };

    cout << "First = " << First << endl;
    cout << "Second = " << Second << endl;
    cout << "Third = " << Third << endl;

    cout << endl;

    enum { Fir = 10, Sec = 5, Thr };

    cout << "Fir = " << Fir << endl;
    cout << "Sec = " << Sec << endl;
    cout << "Thr = " << Thr << endl;

    return 0;
}
```

输出结果如下：

![d79fa2b263dd5b55a21078610ae2048c.png](https://ci.cncn3.cn/d79fa2b263dd5b55a21078610ae2048c.png)

由此可见，对于 `enum` 中的元素，其默认值为前一个元素的值加 `1` 。

## 关于字符

在前面的教程中，我们或多或少接触到了字符这一类型。

这里，我们介绍以下转义字符。

| 符号      | 转义序列       |
|:-------:|:----------:|
| 换行符     | `\n`       |
| 反斜杠     | `\\`       |
| 水平制表符   | `\t`       |
| 问号      | `?` 或 `\?` |
| 垂直制表符   | `\v`       |
| 单引号     | `\'`       |
| 退格符     | `\b`       |
| 双引号     | `\"`       |
| 回车符     | `\r`       |
| null 字符 | `\0`       |
| 换页符     | `\f`       |
| 八进制     | `\ooo`     |
| 警报（响铃）  | `\a`       |
| 十六进制    | `\xhhh`    |

来源：[Microsoft learn](https://learn.microsoft.com/zh-cn/cpp/cpp/string-and-character-literals-cpp?view=msvc-170) 。

有了转义字符之后，我们输出回车就可以不使用 `std::endl` ，而用 `\n` 代替。

**注意**，虽然转义字符由两个单独的字符组成，但它仍然是一个字符，也可以用 `'\n'` 这样的形式表达。

## C- 风格的 `I/O`

C- 风格的输入输出主要依赖于两个函数：`printf()` 和 `scanf()` 。

下面看一个示例程序。

示例程序 6.7

```cpp
#include <cstdio> //using printf() and scanf()

int main(void)
{
    using std::printf;
    using std::scanf;

    int n;

    printf("Please input n:\n");
    scanf("%d", &n);
    printf("n = %d\n", n);

    return 0;
}
```

运行结果如下：

![aa1d39fb9313c46228769d7281d83b87.png](https://ci.cncn3.cn/aa1d39fb9313c46228769d7281d83b87.png)

程序中出现的 `%d` 是什么东西呢？

这是C语言中的转换说明，其中 `%d` 就是 `int` 对应的转换说明。

常用的转换说明详见 [这篇文章](https://www.cnblogs.com/yyy6/p/8994656.html) 。

`printf()` 和 `scanf()` 函数可以接受多个参数，您要输出或者输入多少个数据，就可以有多少个参数。

注意，`scanf()` 接受的是一个地址，所以要记得加上 `&` 。

如果是读取字符串，那就不需要加上 `&` 。

示例程序 6.8

```cpp
#include <cstdio> //using printf() and scanf()

int main(void)
{
    using std::printf;
    using std::scanf;

    const int StrLen = 80;
    char str[StrLen];

    printf("Please input a string:\n");
    scanf("%s", str);
    printf("The string is: %s\n", str);

    return 0;
}
```

通过上面的文章，可以看到 C- 风格的输出在格式化方面会相对简单，而 `C++` 则需要记忆许多新的函数等。

当然，`cout` 的输出比 `printf()` 输出要更简单，不用记忆那么多的转换说明。所以这二者可以视情况使用。

---------

——END——