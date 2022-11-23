---
title: C++ 教程（二）
date: 2022-09-30
description:
tags: ["字符串"]
categories: "C++ 教程"
keywords: ["字符串","类型转换"]
cover: https://ci.cncn3.cn/62147f26003368f0c8cbf7f5973bd526.png
---

# C++教程（二）

## 字符串初探

字符串是由多个字符拼接而成的数据类型，我们用 `""` 括起多个字符以表示字符串。

如 ”Hello World" , "C++" , "1" 等。

如同数字 `123` 可以用 `int` 声明一样，字符串也有对应的声明方式。

如果您对 C语言 有所了解，那么您一定知道 C风格 的字符串的声明方式。

关于 C风格 的字符串我将会在介绍数组时一同介绍。

`C++` 提供了 `string` 类，在使用它时我们需要包含头文件 `<string>` 。

下面演示一下它的简单用法，关于它的其它用法，我会在之后介绍。

示例程序 2.1

```cpp
#include<iostream>
#include<string>

int main(void)
{
    // string类位于名称空间 std 中
    std::string s1;
    s1 = "This is string1";
    std::string s2 = "This is string2";

    using namespace std;    
    //使用 std 名称空间 包括 string 和 cout

    string s3("This is string3");

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    return 0;
}
```

示例程序 2.1中，字符串 `s1` 和 `s2` 的声明与赋值比较易懂。

那么 `s3` 的初始化是怎么回事呢？

正如前文所说，`string` 是一个类，类中往往包含一个或多个构造函数。

这些将涉及 `C++` 面向对象编程的内容，我将在之后的文章中介绍。

初学者目前只需要知道 `s3` 这一字符串使用构造函数进行初始化即可。

这三种的初始化和赋值方式都是可行的，性能上可能会有微小的差别，但影响不大。

对于字符串的，同样可以使用 `cout` 等 `ostream` 类进行输出。

字符串就先介绍这些，下面我们来看看 `C++` 的输入。

## 输入——与用户交互的桥梁

在头文件 `<iostream>` 中，不仅包含了 `ostream` 这一用于输出的类，还包含了名为 `istream` 的用于输入的类。

在名称空间 `std` 中包含了一个 `istream` 对象—— `cin` 。

`cin` 本身可以用来从键盘或者输入源（如文件）中读取数据。

下面我们来看看示例。

示例程序 2.2 

```cpp
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    int x,y;
    string name;

    cout << "Please input x and y" << endl;
    cin >> x >> y;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x + y = " << x + y << endl;

    cout << "Please input your name" << endl;
    cin >> name; //or getline(cin,name);
    cout << "Hello " << name 
        <<", welcome to C++ !" << endl;    //输出的内容可以放在不同行，不影响运行。

    return 0;
}
```

`cout` 使用左移运算符 `<<` 进行输出，而 `cin` 则使用右移运算符 `>>` 实现输入。

和 `cout` 一样，`cin` 也可以使用 `>>` 连接多个需要输入的对象。

`cin` 的输入默认时读取到空格或者换行符时停止。

对于示例程序中的输入名字，如果输入的是英文名，即中间有空格的字符串，要怎么处理呢？

这个时候，我们就使用 `std::getline()` 这一函数进行读取。

这个函数忽略空格，读取到换行符时停止。所以可以将 `cin >> name;` 替换成 `getline(cin,name);` 以达到读取一整行内容的效果。

`getline()` 函数接受三个参数，它的原型是 `istream& getline (istream &is, string &str, char delim)` 。

其中第三个参数是一个符号，当读取到这个符号时停止读取，这个参数默认为 `'\n'` ，即换行符。这是转义字符，关于转义字符我会在之后提到。

## 强制类型转换

在上一篇文章中，我介绍了初始化变量的方法，即使用等号进行赋值。

例如 `int x = 5;` ，将 5 赋值给整型变量 x 。

试考虑以下代码：`int x = 3.1415926` 会发生什么？

答案是 `3.1415926` 被截断，仅保留整数部分。所以 x 的值为 3。

> 注意：浮点数被截断为整数时不会进行四舍五入。所以 `int x = 3.9999;` 中的 x 的值也是 3。

再考虑 `double y = 1/7;` 中，y 的值为多少。

在回答这个问题之前，我有必要说明一下赋值的操作过程和 `C++` 运算的特性。

赋值是将等号右边的值，包括运算的结果和函数的返回值赋给左边的变量。 

对于同类型之间的运算，其结果为相同的类型。对于浮点数与整型之间的运算，其结果是浮点数。

根据这个特性，`1/7` 这个式子本身时两个整型之间的运算，那么得到的结果仍然是一个整型。

所以 `1/7 = 0.142857` 就会被截断为 0 。于是 y 的值为 0 。

如果要实现将 `1/7` 赋值给 `y` ，有以下几种方法。

示例程序 2.3

```cpp
#include<iostream>

int main(void)
{
    using std::cout;
    using std::endl;

    double y1 = 1/7;
    double y2 = 1*1.0/7;
    double y3 = (double) 1/7;

    cout << y1 << endl;
    cout << y2 << endl;
    cout << y3 << endl;

    return 0;
}
```

其中 `y3 = (double) 1/7;` 就是将 `1/7` 强制转换成 `double` 类型。我个人比较推荐使用这种方法。

> 注意：无论是什么时候，一定要小心这一特性，并且正确处理数据，防止发生严重后果。

示例程序 2.3 中又出现了新的东西

```cpp
using std::cout;
using std::endl;
```

这两行代码告诉编译器只使用名称空间 `std` 中的 `cout` 和 `endl` 这两个 “工具” 。

如果要使用除了这两个以外的对象或函数，则需要在前面加上 `std::` 。

> 为什么要这么做？如果您是学习信息竞赛的同学，那么您可以忽略这一点。
> 
> 如果您有意愿使用 C++ 制作项目，那么，应该尽量使用 `std::` 而不是 `using` 指令的习惯。
> 
> 名称空间存在的意义就是为了防止变量名重复，在制作项目的过程中会有许多变量，如果变量名重复，那名称空间将提供很好的解决方案。
> 
> 如果一个名称空间中的函数或者对象在一个作用域（作用域我会在以后的文章中提到）出现多次，那么你可以使用 `using std::cout;` 这样的指令来进行使用。
> 
> 尽量避免 `using namespace std;` 这种用法，如果一定要使用这条语句，也应该使用于局部。
> 
> 对于信息竞赛的同学而言，则没有这么多的顾虑，因为做题目的时候代码都相对较短，就不需要考虑这一点。
> 
> 当然，这些只是建议，如何使用还是取决于个人，根据个人习惯选择语句，也是提高效率的有效方式之一。关于名称空间，以后我会介绍到，如同函数一样，您也可以自己制作名称空间。

## sizeof 简介 & 常量声明与宏定义

### sizeof

在上一章中，我们介绍了基本数据类型，在附录中有一张表格，其中列举了一些数据类型的取值范围和所占的字节数。

对于数据类型的取值范围我们可以使用头文件 `<climits>` 中的宏定义进行查看。

如果想要查看某一数据类型所占的字节数，要怎么办呢？

这时我们就需要使用 `sizeof` 运算符进行查询。

> 注意：`sizeof` 是一个运算符，并不是一个函数。

示例程序 2.4

```cpp
#include<iostream>

int main(void)
{
    using namespace std;

    cout << "size of int: " << sizeof (int) << endl;
    cout << "size of double: " << sizeof (double) << endl;
    cout << "size of long long: " << sizeof (long long) << endl;

    int a = 5;
    cout << "size of a: " << sizeof a << endl; 

    cout << "size of 0.1: " << sizeof (0.1) << endl;
    cout << "size of (double) a: " 
        << sizeof ( (double) a ) << endl;

    return 0;
}
```

变量所占的字节数与其类型相同。

### 常量声明与宏定义

常量是指不能修改的量。比如数字 `123` ，字符 `'a'` 等等。

对于 `int a = 5;` 来说，`a` 是否属于常量呢？

显然，`a` 的值可以再改变，比如我们可以使用 `a = 8;` 这种赋值的方式修改 `a` 的值。

如果要将 `a` 限定为常量，即不可修改的量，则可以使用 `const` 限定符、 `enum` 枚举或者 `#define`  宏定义进行。

示例程序 2.5

```cpp
#include<iostream>

#define a1 5

enum Example{ a2 = 5 };

const int a3 = 5;

int main(void)
{
    a1 = a2 = a3 = 8;//非法，编译器将报错

    std::cout << a1 << " " << a2 << " "
        << a3 << std::endl;

    return 0;
}
```

对于 `const` 、`enum` 和 `#define` 的用法和特性还有很多，我将在有需要的时候进行介绍。

## 练习

1. 查询您所知道的数据类型（如 `string` 、`float` 等）所占的字节数。
2. **输入**身高与体重，输出相应的 `BMI` 指数。

---

——END——
