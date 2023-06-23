---
title: C++ 教程（七）
date: 2022-11-18
description: 本文将介绍 C++ 中的结构体以及共用体的用法，让读者对面向对象编程有个初步的了解。
tags: ["结构体","共用体","struct","union"]
categories: "C++ 教程"
keywords: ["结构体","共用体","struct","union"]
cover: https://img.purkit.ml/cpp-cover.jpg

---

# C++ 教程（七）

## 结构体

### 声明结构体与创建结构体变量

关于结构体，我们首先用一个问题引入：怎么记录一个班级所有学生的座号、名字和成绩？

也许，以您现有的知识，您会创建三个数组，然后分别记录这三个信息。

但是这样存在一个问题，就是这三个数组不易管理。

那么是否存在一种方法，使得这些信息便于管理？

这里，我们使用结构体来实现这一目的。

未来，我们会使用更加高级的类来实现这一目的。

结构体使用关键字 `struct` 声明。

比如，我们声明一个 `Student` 结构体，那么 `C++` 实现如下：

```cpp
#include <iostream>
#include <string>

struct Student
{
    std::string Name;
    int         SitNumber;
    int         Score;
};    // 注意分号 ;
```

其中， `Student` 是类型名，`Name` 、`SitNumber` 和 `Score` 是成员。

以上是声明结构体的方法。接下来，我们来看如何创建结构体变量。

我们可以像使用 `int` 、`double` 等类型一样来使用 `Student` 创建变量。

当然，我们也可以在声明结构体的同时声明变量。

该示例程序还演示了结构体所占的字节数是多少。

示例程序 7.1

```cpp
// 声明 Student 变量
#include <iostream>
#include <string>

struct Student
{
    std::string Name;
    int         SitNumber;
    int         Score;
} stu1, stu2; // 在声明结构体的同时声明变量

int main(void)
{
    using std::cout;
    using std::endl;

    Student stu3; // 普通的声明方式

    cout << "size of string: " << sizeof(std::string)
         << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of Student: " << sizeof(Student) << endl;
    return 0;
}
```

输出结果如下：

![9e81ddf4458837cc11a5a45d7304a16a.png](https://ci.cncn3.cn/9e81ddf4458837cc11a5a45d7304a16a.png)

注意，`Student` 结构体包含了两个 `int` 类型的数据。

通过输出我们可以得出结构体所占的字节数等于它各个成员所占字节数只和。

### 访问成员和结构体初始化

在介绍完声明结构体和结构体变量之后，我们介绍如何访问结构体的成员。

`C++` 中，使用 `.` 符号进行访问结构体成员。

当我们访问成员之后，就可以将这个整体看成成员对应的类型。

比如 `stu1.Name` 就是访问 `stu1` 的 `Name` 成员。此时，我们将 `stu1.Name` 看作是 `string` 类型。

这就意味着，我们可以像使用 `string` 一样使用 `stu1.Name` ，包括输出和赋值。

示例程序 7.2

```cpp
#include <iostream>
#include <string>

struct Student
{
    std::string Name;
    int         SitNumber;
    int         Score;
} stu1;

int main(void)
{
    stu1.Name = "Purkit";

    std::cout << "Please input sit number:\n";
    std::cin >> stu1.SitNumber;
    std::cout << "Please input this student's score:\n";
    std::cin >> stu1.Score;

    std::cout << "Name: " << stu1.Name << '\n'
              << "Sit number: " << stu1.SitNumber << '\n'
              << "Score: " << stu1.Score << '\n';
    return 0;
}
```

输入输出示例如下：

![147f27524f3a73e4212f582b900182a0.png](https://ci.cncn3.cn/147f27524f3a73e4212f582b900182a0.png)

如果我要使 `SitNumber` 和 `Score` 默认为 `0` ，那要怎么操作呢？

这里，我们可以使用类似类的构造函数的方法或者直接赋值的方法进行。

示例程序 7.3

```cpp
#include <iostream>
#include <string>

struct Student1
{
    std::string Name;
    int         Score;
    int         SitNumber;

    Student1() { Score = SitNumber = 0; }
} stu1;

struct Student2
{
    std::string Name;
    int         Score = 0;
    int         SitNumber = 0;
} stu2;

int main(void)
{
    using std::cout;

    cout << "In Student1:" << '\n';
    cout << "stu1.Score = " << stu1.Score << '\n';
    cout << "stu1.SitNumber = " << stu1.SitNumber << '\n';

    cout << '\n';

    cout << "In Student2: " << '\n';
    cout << "stu2.Score = " << stu2.Score << '\n';
    cout << "stu2.SitNumber = " << stu2.SitNumber << '\n';

    return 0;
}
```

如果要初始化一个结构体变量，我们不仅可以使用简单的赋值，也可以通过别的方式进行。

比如像初始化数组一样，使用大括号 `{}` 初始化结构体。

```cpp
#include <iostream>
#include <string>

struct Student
{
    std::string Name;
    int         SitNumber;
    int         Score;
} stu1 = {"Purkit", 80, 75}, stu2;

// 错误写法：
// stu2 = {"Error", -1, -1};

int main(void)
{
    using std::cout;

    stu2 = stu1;    //直接将整个 stu1 结构体赋值给 stu2

    cout << "Name: " << stu1.Name << '\n';
    cout << "SitNumber: " << stu1.SitNumber << '\n';
    cout << "Score: " << stu1.Score << '\n';

    cout << '\n';

    cout << "Name: " << stu2.Name << '\n';
    cout << "SitNumber: " << stu2.SitNumber << '\n';
    cout << "Score: " << stu2.Score << '\n';

    return 0;
}
```

当然，您也可以使用构造函数的方法进行初始化。

如果这么做，就有点违背结构体存在的意义了。我们一般在类中使用构造函数，如果给结构体定义构造函数或者方法，就会显得有点不伦不类了。

因此，我们建议在定义默认值的时候采用 示例程序 7.3 中 `Student2` 的定义方法。

如果是初始化，则建议使用类似数组的初始化方式。

### 结构体与指针

上一篇博文中我们介绍了 `C++` 中的指针。

那么结构体的指针有什么不同之处呢？

在声明上，结构体指针的声明方式和普通类型的声明方式是一样的。

但是，在访问成员的时候，则需要注意符号的使用。

比如，我们定义一个结构体为 `Node` ，其中包含两个 `int` 为 `x` 和 `y` 。

声明一个 `Node` 结构体变量为 `n1` ，声明一个指针 `*ptr` 指向 `n1` 。

要使用该指针对 `n1` 的成员进行赋值等操作则需要注意访问的语法。

如果只使用 `ptr` ，则需要使用 `->` 进行访问成员。如果使用 `*ptr` ，则使用 `.` 进行访问成员。

示例程序 7.4

```cpp
#include <iostream>

struct Node
{
    int x, y;
};


int main(void)
{
    using std::cout;

    Node  n1;
    Node* ptr = &n1;

    ptr->x = 10;
    (*ptr).y = 20;    //注意运算符优先级

    cout << "x = " << ptr->x << '\n';
    cout << "y = " << (*ptr).y << '\n';

    return 0;
}
```

对于指针，我们建议使用 `->` 访问成员。

## 共用体

我们在生活中会用到许多账号，这些账号有长有短，如果要对它们进行存储，要使用什么类型呢？

对于相对长的账号，我们也许使用字符串进行存储。

如果是比较短的账号，使用字符串进行存储就显得有点浪费空间了。

如果我们希望对于长的账号使用字符串进行存储，而对于短的账号使用 `int` 或者 `long long` 进行存储。那要怎么实现呢？

这里我们就需要用到 `C++` 中的共用体。

共用体的关键字为 `union` ，它的声明方式和结构体类似。

```cpp
union Account
{
    int  int_val; // or long long long_long_val;
    char ch_val[20];
};
```

对于一个 `Account` 对象，它的类型在一定时刻内只能是共用体中的一种。

我们直接看示例。

示例程序 7.5

```cpp
#include <iostream>

union Account
{
    int  int_val; // or long long long_long_val;
    char ch_val[20];
};

int main(void)
{
    using std::cout;
    using std::endl;

    Account a1;
    bool    account_type;

    cout << "Please input the type of account(0 is short,1 "
            "is long): "
         << endl;
    std::cin >> account_type;

    cout << "Please input your account:" << endl;

    if (account_type)
    {
        std::cin >> a1.ch_val;
        cout << "Your account: " << a1.ch_val << endl;
    }
    else
    {
        std::cin >> a1.int_val;
        cout << "Your account: " << a1.int_val << endl;
    }

    return 0;
}
```

输出结果如下：

![891580a4003d907a416b30387c01bf26.png](https://ci.cncn3.cn/891580a4003d907a416b30387c01bf26.png)

既然共用体和结构体那么相似，那为什么会存在共用体呢？

这里我们观察以下共用体所占的字节数：

示例程序 7.6

```cpp
#include <iostream>

union Account
{
    int  int_val;
    char ch_val[20];
};

int main(void)
{
    using std::cout;
    using std::endl;

    cout << sizeof(int) << endl;
    cout << sizeof(char[20]) << endl;
    cout << sizeof(Account) << endl;

    return 0;
}
```

输出结果如下：

![d6bcaee3cc7a62e02fbe3997be78d269.png](https://ci.cncn3.cn/d6bcaee3cc7a62e02fbe3997be78d269.png)

可以看到，共用体所占的字节数的大小取决于它内部最大的类型所占的字节数。

这就是共用体存在的意义：节省空间。

这一篇博客的内容就是这些了。

-----------------

——END——
