---
tags: ["new","delete","数组","指针"]
title: C++ 教程（八）
date: 2022-12-24
description: 本文介绍 C++ 的多维数组以及动态内存分配。
categories: "C++ 教程"
keywords: ["new","delete","动态数组","数组","指针"]
cover: https://ci.cncn3.cn/62147f26003368f0c8cbf7f5973bd526.png
---

# C++ 教程（八）

## 多维数组

前面我们介绍了一维的数组，即形如 `int a[10];` 的数组。有的时候我们要用数组来模拟二维座标系，如果这个时候只用一维数组就显得不够直观。

因此，我们有必要学习多维数组。

我们以二维数组为例。

### 二维数组的创建

二维数组的声明可以类比一维数组，比如我们要声明一个大小为 `10 * 10` 的数组 `Arr` ，其声明形式如下：

```cpp
const int ArSize = 10;
int Arr[ArSize][ArSize] = {0};
```

对于二维数组的初始化，我们同样可以使用 `= {0}` 的这种方式。

如果要初始化成不同的数据，也可以类比一维数组的操作。如下：

```cpp
const int ArSize = 10;

int Arr[ArSize][ArSize] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
};
```

这里只初始化了前两行的前几列，通过这个初始化的方式，可以看出，二维数组实际上是由多个一维数组组成的，对于多维数组，也可以看成由低维数组组成。

如果要将多维数组清零，同样可以使用 `memset()` 函数进行。例如：

```cpp
std::memset(Arr, 0, sizeof(Arr));
```

### 二维数组的遍历

对于一维数组，我们使用一层循环进行遍历，那么对于二维数组，我们就需要嵌套一个循环，使用两层循环进行遍历。

示例程序 8.1

```cpp
#include <iostream>

int main(void)
{
    const int ArSize = 10;

    int Arr[ArSize][ArSize] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
    };

    for (int i = 0; i < ArSize; i++)
    {
        for (int j = 0; j < ArSize; j++)
            std::cout << Arr[i][j] << " ";
        std::cout << '\n';
    }
    return 0;
}
```

输出结果如下：

<img title="8.1" src="https://ci.cncn3.cn/3d6b47da0b3f826eabd8d5711a5481e2.png" alt="3d6b47da0b3f826eabd8d5711a5481e2.png" data-align="center">

可以看到，未初始化的元素默认未 0 。

## 数组与指针

前面我们介绍了指针与变量和结构体的用法，那么指针与数组的用法有什么不同之处呢？

### 数组指针的声明

我们以声明一个数组 `a[4]` 和一个指向该数组的指针 `*ptr` 为例。其声明方式如下：

```cpp
const int ArSize = 4;
int  a[ArSize] = {1, 2, 3, 4};
int* ptr = a;
```

细心的读者也许已经发现，这里指针的赋值与前面提到的不一样。

如果是一个 `int` 类型的变量 `x` ，那么指针的声明是 `int* ptr = &x` ，那为什么数组没有使用 `&` 符号呢？

实际上，数组的名称即本例中的 `a` 就是代表数组第一个元素的地址。

所以，`a` 实际上等效于 `&a[0]` 。因此，声明数组指针时不需要使用 `&` 符号。

### 用数组指针访问数组元素

知道如何声明数组指针之后，那要怎么访问数组的每一个元素呢？

对于数组中的元素，它们的存储是连续的，即它们的地址是相邻的。

而指针指向地址，如果对指针进行加减的操作，实际上就是改变指针指向的地址。

我们通过一张图片来直观感受以下：

<img src="https://ci.cncn3.cn/85d6fb706adc6bab9ce6be9d370e0445.png" title="" alt="85d6fb706adc6bab9ce6be9d370e0445.png" data-align="center">

从上图可以看出使用指针访问数组的语法。我们用一个使用该语法输出数组中所有元素的例子来加深理解。

示例程序 8.2

```cpp
#include <iostream>

int main(void)
{
    const int ArSize = 4;

    int  a[ArSize] = {1, 2, 3, 4};
    int* ptr = a;

    for (int i = 0; i < ArSize; i++)
        std::cout << *(ptr + i) << " ";
    return 0;
}
```

## 初探 `new` 和 `delete`

前面介绍过，指针不能指向未知的地址。即你不能这么写 `int* ptr = 5;` 。

但如果我想声明一个指针，并且它的值是 5 ，那要怎么做呢？

指针是指向一个地址，如果我们可以将一块未分配的地址分配出来并用指针指向它，这样就可以实现我们的目的了。

而 `C++` 也提供这样的方法，即使用 `new` 来分配内存。

因此我们可以将 `int* ptr = 5;` 改写成 `int* ptr = new int(5);` 。

其中，后面的 `int` 指定了类型，括号中是要赋的值。

当我们使用完动态分配的内存之后，我们可以使用 `delete` 将它 "删除” 。

比如 `delete ptr` 。此时，`*ptr` 指向的就是为分配的地址。

我们用一个例子来加深理解。

示例程序 8.3

```cpp
#include <iostream>

int main(void)
{
    using std::cout;

    int* ptr = new int(5);
    cout << "Now *ptr = " << *ptr << '\n';
    delete ptr;
    cout << "After delete,*ptr = " << *ptr << '\n';
    return 0;
}
```

> **注意：** 不要连续将一个指针 `delete` 两次，那样的结果是危险的。

当 `delete` 一个指针之后，您可以再次使用 `new` 来给它分配内存。

## 动态数组

到目前为止，我们接触的数组都是大小确定的数组。但在实际应用中，如果数组太大而实际使用又太少，那就会导致浪费内存；反之，如果数组太小，那也会导致程序运行错误。

相比于在程序执行之前定义数组大小，能不能在程序执行的阶段来确定数组的大小并创建呢？

这时，我们就要使用动态数组了。

动态数组实际上就是数组指针的动态内存分配。

类比上面的方法，我们声明一个指针 `*ptr` 为数组指针，它的大小为 `5` ，其声明如下：

```cpp
const int ArSize = 5;
int* ptr = new int[ArSize];
```

如果要初始化，则直接在它后面使用大括号 `{}` 初始化，例如：

```cpp
const int ArSize = 5;
int*      ptr = new int[ArSize] {1, 2, 3, 4, 5};
```

如果要用 `delete` 删除该指针，它的语法如下：

```cpp
delete[] ptr;
```

那么，为什么说它是动态的数组呢？

因为，在上面的例子中，`ArSize` 可以是一个变量，因为 `int* ptr = new int[ArSize]` 实际上是申请内存，这就意为着，`ArSize` 可以是一个变量。

由此，我们就实现了动态数组。下面看一个具体例子：

示例程序 8.4

```cpp
#include <iostream>

int main(void)
{
    using std::cout;

    int ArSize = 0;
    cout << "Please input array\'s size: ";

    std::cin >> ArSize;    //创建动态数组
    int* arr = new int[ArSize] {0};

    cout << "Please input numbers:\n";
    for (int i = 0; i < ArSize; i++)
        std::cin >> *(arr + i);
    cout << "Array is:\n";
    for (int i = 0; i < ArSize; i++)
        cout << *(arr + i) << " ";
    delete[] arr;
    return 0;
}
```

运行结果如下：

<img src="https://ci.cncn3.cn/724233959d214623e3e4aaa8a0c78a65.png" title="" alt="724233959d214623e3e4aaa8a0c78a65.png" data-align="center">

## 写在最后

用 `new` 分配的内存要用 `delete` 及时清除掉。

同时，不要对同一个指针连续 `delete` 两次。

----------------------------------

——END——
