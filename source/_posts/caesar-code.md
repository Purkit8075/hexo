---
title: 凯撒密码原理及其 C++ 实现
date: 2023-06-05
description: 本文介绍凯撒密码原理并使用 C++ 实现其加密和解密。
tags: ["Caesar"]
categories: "密码学"
keywords: ["Caesar","凯撒密码"]
cover: https://img.purkit.ml/caesar-cover
    # C++ 教程： 
---

# 凯撒密码原理及其 C++ 实现

## 前言

最近读了一本科普密码学的书（还没读完），又因为各种原因导致长时间没有练习编程，遂决定通过实现一些加密过程来练习编程，再顺便 ~~水一下博客~~。

## 什么是凯撒密码

凯撒密码是一种最简单的加密技术，它是一种替换加密的技术。它只支持对字母进行加密。

加密方法就是将每个字母按照字母表的顺序向后（或向前）移动相同的位数（我称之为位移量）。当然，如果是在末尾的字母就再从头算起。

同理，它的解密方法就是将每个字母按照字母表顺序向前（或向后）移动相同的位数。

例如，对于字符串 `"ABC"` ，如果位移量为 4 ，那么输出的结果就是 `"EFG"` 。

如果输入是 `"XYZ` ，位移量仍为 4 ，那么输出的结果就是 `"BCD"` 。

## C++ 代码实现

我们用字符串 `PlainText` 表示明文，用字符串 `CipherText` 表示密文，用整型变量 `index` 表示位移量。

那么以下就是凯撒密码的加密公式：

```cpp
CipherText[i] = (PlainText[i] + index) % 26
```

凯撒密码的解密公式就是：

```cpp
PlainText[i] = (CipherText[i] - index) % 26
```

其中 `i` 是字符串的每一位的下标。

当然，这里给出的只是通用的公式，在实现的过程中还有许多细节需要考虑。

例如，如果文本中出现非字母字符如何处理？大小写字母如何处理？求余要注意什么？

以上的问题都是需要考虑的。我会在后文提供我的解决方案。

先来看我们需要的东西：

```cpp
#ifndef _CAESAR_H_
#define _CAESAR_H_

#include <cctype>
#include <string>
using std::string;

class Caesar
{
public:
    string EnCode(string PlainText, int index = 4);
    string DeCode(string CipherText, int index = 4);
};

#endif //!_CAESAR_H_
```

定义一个 `Caesar` 类，用于实现凯撒密码。一个 `EnCode` 函数和一个 `DeCode` 函数分别用于实现凯撒密码的加密和解密。位移量 `index` 默认为 4 。

对于上文提到的问题，我的解决方案是保留非字母字符，不做变动，再将所有字母转换成大写字母。

因为加密和解密过程相似，因此这里我只介绍 `EnCode` 函数的具体实现过程。

先给出 `EnCode` 方法的具体代码：

```cpp
string Caesar::EnCode(string PlainText, int index)
{
    string CipherText = "";
    index %= 26;
    for (int i = 0; i < PlainText.length(); i++)
    {
        if (!std::isalpha(PlainText[i]))
        {
            CipherText += PlainText[i];
            continue;
        }
        CipherText +=
            (std::toupper(PlainText[i]) - 'A' + index + 26) % 26 + 'A';
    }
    return CipherText;
}
```

函数第一行的 `CipherText` 作为密文字符串返回，第而行的 `index %= 26` 则是将 `index` 限定在 `(-26,26)` 之间。

然后我们遍历 `PlainText` ，使用 `std::isalpha()` 进行判断该字符是否是字母。如果不是字母就直接将它加在密文尾部，并跳过。

> 注： `isalpha()` 函数包含在 `<cctype>` 文件中。

最后就是最关键的加密步骤了。我用 `std::toupper()` 函数将字母转换成大写字母，减去字符 `'A'` 就相当于用明文字符的 ASCII 码减去 'A' 的 ASCII 码，即可得到该字母在字母表中的位置。

> 注：此处将 A 记作字母表的第0 位，B 记作字母表的第 1 位，以此类推。

然后将该数字加上位移量 `index` 即可得到移位后的字母的字母表位置，对 26 求余就将该数字限制在 `(0,26)` 之间了，这是用于解决末尾字母位移问题的方法，最后加上 'A' 的 ASCII 码就得到了我们需要的加密字符，将它加在 `CihperText` 的末尾即可。

也许您会有些疑问：为什么 `index` 要先对 26 取模？为什么 `(std::toupper(PlainText[i]) - 'A' + index + 26) % 26 + 'A'` 的括号中最后要加上 26 ？

上文提到过凯撒密码的移位可以向前也可以向后，这个 `EnCode()` 函数接受的 `index` 参数可以为负数，即向前位移，那么在加密语句，即 `(std::toupper(PlainText[i]) - 'A' + index + 26) % 26 + 'A'` 中，如果加上一个为负数的 `index` ，就会导致对 26 取模的结果也是负数。

这里就要补充一下 `C++` 中的取模特性了。在 `C++` 中，一个负数 `a` 对一个正数 `b` 取模，其结果为 `-((-a) % b)` ，即一个负数对一个正数取模，其结果必然是非正数。

这就是为什么要加上 26 的原因了，也许您觉得这么做会对加密结果产生影响，但事实上，取模具有一个性质，即：`(a + b) % p = a % p + b % p` 。

根据该性质，在加密语句中加上一个 26 并不会影响最终的结果，因为 `26 % 26 = 0` 。

为了防止 `index` 过小（例如 `index = -100` ）导致加上 26 不起作用，我们必须将 `index` 限制在 `(-26,26)` 之间，而 `index %= 26` 就是实现这一目标的有效方法。

最后提供凯撒密码的源代码：

**caesar.h**

```cpp
#ifndef _CAESAR_H_
#define _CAESAR_H_

#include <cctype>
#include <string>
using std::string;

class Caesar
{
public:
    string EnCode(string PlainText, int index = 4);
    string DeCode(string CipherText, int index = 4);
};

#endif //!_CAESAR_H_
```

**caesar.cpp**

```cpp
#include "caesar.h"

string Caesar::EnCode(string PlainText, int index)
{
    string CipherText = "";
    index %= 26;
    for (int i = 0; i < PlainText.length(); i++)
    {
        if (!std::isalpha(PlainText[i])) // ignore non-alphabetic
        {
            CipherText += PlainText[i];
            continue;
        }
        CipherText +=
            (std::toupper(PlainText[i]) - 'A' + index + 26) % 26 + 'A';
    }
    return CipherText;
}

string Caesar::DeCode(string CipherText, int index)
{
    string PlainText = "";
    index %= 26;
    for (int i = 0; i < CipherText.length(); i++)
    {
        if (!std::isalpha(CipherText[i])) // ignore non-alphabetic
        {
            PlainText += CipherText[i];
            continue;
        }
        char ch = (std::toupper(CipherText[i]) - 'A' - index + 26) % 26 + 'A';

        PlainText += ch;
    }
    return PlainText;
}
```

**main.cpp**

```cpp
#include "caesar.h"
#include <iostream>
#include <string>

int main(void)
{
    using std::cout;

    std::string s1 = "abc";
    std::string s2 = "xyz";

    Caesar caesar;

    cout << caesar.EnCode(s1) << '\n';
    cout << caesar.DeCode(caesar.EnCode(s1)) << '\n';

    cout << caesar.EnCode(s2, -5) << '\n';
    cout << caesar.DeCode(caesar.EnCode(s2, -5), -5) << '\n';

    return 0;
}
```

输出结果为：

```textile
EFG
ABC
STU
XYZ
```

## 凯撒密码的不足

通过这个凯撒密码的加密过程，可以很明显地发现，它的破解十分容易。

最简单的破解方法就是尝试所有的位移量，可以得到 25 个明文，再判断哪个明文是有效的。

这种方法需要人对明文进行判断，效率不够高。我们还可以使用另一种方法：字母频率分析法。

事实上，对于有意义的明文，其字母出现的频率是不同的，而凯撒密码属于简单的替换密码，每个字母对应另一个字母，也就是说密文中的字母出现的频率和明文中对应字母出现的频率相同。

因此，我们可以对密文中字母出现的频率进行统计，再参照字母频率表进行判断，这种方法破解的效率更高。当然，密文越长字母出现的频率才会越趋于预期值，这就意味着密文越长，字母频率分析越有效。

事实上，现代的密码系统都应当能够抵抗字母频率分析，并且尽量避免穷举攻击。而古典密码的发展在一定程度上就是在抵抗字母频率分析的破解方法。



------------------

——END——
