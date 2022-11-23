---
title: C++ 教程（五）
date: 2022-10-29
description:
tags: ["函数","地址","字符串","指针","数组"]
categories: "C++ 教程" 
keywords: ["函数","地址","字符串","指针","数组"]
cover: https://ci.cncn3.cn/62147f26003368f0c8cbf7f5973bd526.png
---

# C++ 教程（五）

## 上一节的练习题

上一节中，第 1 题相对简单，那么第 2 题要怎么做呢？

题目如下：

对于给定的一个大写字母，输出如下图的金字塔。

![89df47d3f13f5f36647ea702b4993521.png](https://ci.cncn3.cn/89df47d3f13f5f36647ea702b4993521.png)

先分析一下这个金字塔由什么构成。

1. 行首的空格。
2. 正向输出字母。
3. 反向输出字母。
4. 换行。

我们首先使用一个大的循环，来输出换行符。可以看到，行数等于字母在字母表中的位置`pos` 。所以输出的换行符个数为 `line = pos - 1` 。

然后观察输出空格的个数与行数之间的关系。

空格的个数为 `line - i + 1` ，其中 `i` 为行数。

接着我们正向输出字母，在反向输出字母，就解决了。

所以我们要用到 4 个循环，其中 3 个循环嵌套在 1 个循环中。

代码如下：

```cpp
#include<iostream>

int main(void)
{
    using namespace std;

    char ch;
    cin >> ch;

    int line = ch - 'A';    //获得行数

    for (int i = 0; i <= line;i++)    //输出换行符
    {
        for (int j = 1; j <= line - i + 1; j++)    //输出空格
            cout << " ";

        for (int j = 0; j <= i; j++)    //正向输出字母
            cout << (char)(j + 'A');

        for (int j = i-1; j >= 0; j--)    //反向输出字母
            cout << (char)(j + 'A');

        cout << endl;
    }

    return 0;
}
```

## 数组

数组是一种用于存储有限元素的集合。

在 `C++` 中，一种数组只能存储同一类型的数据。数组的声明方式如下：

```cpp
int arr[100];
```

其中，`arr` 是数组名，中括号 `[]` 中的常量指定该数组包含多少元素。前面的 `int` 指明了该数组的类型为 `int` 。

数组除了声明之外，数组的下标也是至关重要的。

元素存储在数组中时，每个元素都对应一个下标，我们可以通过下标访问某个元素。

数组的下标从 `0` 开始，对于 `int arr[100]` 这个数组来说，它的下标是 `0~99` ，即不存在 `100` 下标。

所以，数组的最后一个元素的下标是定义的元素个数减 1 。

对于数组的初始化，我们可以使用赋值的方式。

```cpp
#include<iostream>
using namespace std;

int main(void)
{
    const int ArSize = 100;

    int a[ArSize];

    a[0] = 20;
    a[1] = 30;
    a[2] = 40;

    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;

    return 0;
}
```

数组使用 `a[pos]` （`pos` 为数组下标） 的形式表达数组中的第 `pos` 个元素。

这个时候，可以将 `a[pos]` 看作一个 `int` 类型的变量。并像普通的 `int` 类型数据一样进行操作。

比如进行运算或者赋值等。

回到初始化，如果像上面那样一个一个赋值，那效率会十分低下。

我们可以使用大括号 `{}` 在数组声明时进行初始化赋值。

```cpp
#include<iostream>
using namespace std;

int main(void)
{
    const int ArSize = 100;

    int a[ArSize] = {20, 30, 40};

    // a[0] = 20;
    // a[1] = 30;
    // a[2] = 40;

    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;

    return 0;
}
```

其中，20、30、40 分别对应下标 0、1、2 。每两个值之间用逗号 `,` 隔开。

之后的元素都被自动初始化为 0 。

如果要将数组全部初始化为 0 。那么可以写成 `int a[ArSize] = {0};` 的形式。

当然，您也可以使用循环进行赋值。

```cpp
#include<iostream>
using namespace std;

int main(void)
{
    const int ArSize = 5;

    int a[ArSize];

    for (int i = 0; i < ArSize;i++)
        a[i] = 0;

    for (int i = 0; i < ArSize;i++)
        cout << a[i] << endl;

    return 0;
}
```

通过这种方式，您也可以将数组初始化成别的值。

这里提供一个函数 `memset()` ，它是定义在 `<cstring>` 中的一个函数。

我们也可以使用这个函数来将数组清零。

```cpp
#include<iostream>
#include<cstring>

int main(void)
{
    const int ArSize = 10;

    int a[ArSize];

    std::memset(a, 0, sizeof(a));

    for (int i = 0; i < ArSize;i++)
        std::cout << a[i] << " ";

    return 0;
}
```

> 为什么要对数组进行初始化？
> 
> 无论是什么数据类型，我们都应尽量将其初始化。
> 
> 对于数组，在不初始化的情况下，访问任意元素的结果是不确定的。
> 
> 数组不会自动初始化为 0 ，这一点读者可以自己试验一下。
> 
> 在能初始化的情况下，我们因尽量将每个变量进行初始化，防止不必要的意外发生。

## 再谈字符串

数组是一个相同元素的集合，如果一个数组的元素是字符的话，那么它就是一个字符串。

示例程序 5.1 

```cpp
#include<iostream>

int main(void)
{
    const int StrSize = 40;

    char str[StrSize] = "This is a string";

    std::cout << str << std::endl;

    return 0;
}
```

可以看到，字符数组可以直接用 `cout` 进行输出，并且可以直接用字符串进行赋值初始化。

当然，您也可以采用上述的初始化方法，但那样会非常麻烦。

```cpp
char str[StrSize] = {'T', 'h', 'i', 's' ......};
```

这就是之前提到的 C 风格 的字符串。关于 C- 风格字符串的相关操作，我们可以使用 `<cstring>` 中的函数进行。

对于 `C++` 而言，我们应尽量使用 `string` 而不是 C- 风格的字符串。

但是，`string` 的实现还是有依靠 `<cstring>` 中的函数实现的。

感兴趣的读者可以自行研究 `<cstring>` 头文件中的函数。

C- 风格的字符串和 `string` 类都可以通过中括号 `[]`  访问其中元素。

## 地址与指针初探

地址和指针是 `C++` 中比较难懂的部分。能够熟练地使用指针，可以让程序更易于管理。

当然，如果使用不当，也会引发十分严重的后果。

### 地址

地址是什么？

地址是变量存储在内存中的位置。我们可以通过 `&` 符号查看某一变量的地址。

示例程序 5.2 

```cpp
#include<iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    int a = 1, b = 2, c = 3;

    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << endl;
    cout << "&c: " << &c << endl;

    return 0;
}
```

输出结果如下：

![d8578dae1cd8fd70477a1905833e687d.png](https://ci.cncn3.cn/d8578dae1cd8fd70477a1905833e687d.png)

因为电脑不同，所以输出的结果会有差别。

注意看这些地址，它们是以十六进制显示的。

仔细观察 `a` 和 `b` 的地址的差为 4，`b` 与 `c` 的地址的差也为 4 。

这里的 4 是有意义的，之前我们就介绍过，`int` 所占的字节数为 4 。

我们可以看出变量在内存中存储的大致样子。

现在考虑一个问题，如果我们需要写一个函数来实现两个变量的交换，那么要怎么实现？

也许您会这么想：

```cpp
void MySwap1(int x,int y)
{
    int temp = x;
    x = y;
    y = temp;
}
```

这看起来是可行的，我们用下列程序测试一下：

```cpp
#include<iostream>

void MySwap1(int x,int y)
{
    int temp = x;
    x = y;
    y = temp;

    std::cout << "In MySwap1():" << std::endl;
    std::cout << x << " " << y << std::endl;
}

int main(void)
{
    int a = 5, b = 10;
    MySwap1(a, b);

    std::cout << "In main():" << std::endl;
    std::cout << a << " " << b << std::endl;

    return 0;
}
```

程序运行结果如下：

![812f7dac06348a24459e1aecaf4f0ddb.png](https://ci.cncn3.cn/812f7dac06348a24459e1aecaf4f0ddb.png)

可以看到，两个变量的值并没有互换。这是为什么呢？

这里我们就需要补充一下 形式参数 和 实际参数 的区别了。

所谓 形式参数 （简称 形参）只是一个形式上的参数，就好比只传递了一层外壳，而不是整个整体。

而 实际参数（简称 实参）是将整个变量传入函数。是将整个整体传入函数。

而 `MySwap1()` 函数中传递的就是两个形参，所以只有在函数中，`x` 和 `y` 实现了互换。

那么要怎么实现交换两个变量的操作呢？

这里我们传值就不能传一个简单的变量了，就需要传递地址。

传递地址是 C- 的说法，在 `C++` 中，我们把它称为 引用。

具体的实现如下：

示例程序 5.3

```cpp
#include<iostream>

void MySwap1(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;

    std::cout << "In MySwap1():" << std::endl;
    std::cout << x << " " << y << std::endl;
}

int main(void)
{
    int a = 5, b = 10;
    MySwap1(a, b);

    std::cout << "In main():" << std::endl;
    std::cout << a << " " << b << std::endl;

    return 0;
}
```

这里传递的参数为 实参，达到了交换两个变量的目的。

### 指针

在了解完地址之后，我们来介绍指针。

指针是一个很形象的称呼，它用来指向一个地址。指针的声明如下：

```cpp
int *ptr;
```

这样子我们就声明了一个指针。

指针应当直接初始化，让它指向一个变量。如下：

```cpp
int a = 10;

int *ptr = &a;
```

此时，`*ptr` 和 `a` 是一样的。因此我们可以直接输出 `*ptr` 。

示例程序 5.4

```cpp
#include<iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int *ptr = &a;

    cout << *ptr << endl;

    cout << *ptr + 100 << endl;

    return 0;
}
```

那么指针有什么用呢？

之后我们会介绍使用指针来实现动态数组的作用。由于这篇只是开个头，所以暂不探讨。

## 练习

1. 对于给定的 `n` ，输出斐波那契数列的 `1~n` 项。[什么是斐波那契数列？](https://baike.baidu.com/item/%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97/99145)
2. 写一个函数，包含两个参数，第一个参数是要进行操作的数字，第二个参数是一个整数，函数的功能是让第一个参数加上第二个参数，并且返回值为 `void` 。
3. 定义不同类型的指针，复习指针的用法。

-------------

——END——
