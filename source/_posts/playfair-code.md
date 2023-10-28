---
title: Playfair 密码原理以及 C++ 实现
date: 2023-06-09
description: 本文介绍分析了 Playfair 密码及其 C++ 实现。
tags: ["Playfair"]
categories: 密码学
keywords: ["Playfair"]
cover:  https://s3.tebi.io/img.purkit.ml/playfair-cover
    # C++ 教程： 
---

# Playfair 密码原理以及 C++ 实现

## 什么是 `Playfair` 密码

`Playfair` 密码使用一个 `5 X 5` 的字母矩阵作为密钥，将明文中的成对字母根据矩阵进行替换，从而达到加密的目的。

`Playfair` 的加密原理如下：

1. 首先生成一个 `5 X 5` 的字母矩阵，这就意味着我们要舍去一个字母，我采取的的是**去 Q 留 Z** 的方法。我们生成一个除去 Q 以外的字母矩阵。例如：

```textile
Z W X A H 
R U E N D 
F C G K T 
O Y L V B 
J P M S I
```

2. 将明文字符串进行预处理，因为是 **去 Q 留 Z** ，所以我们先将所有 `Q` 替换成 `Z` ，再在相邻字母相同的中间插入 `Z` ，然后如果字符串的长度是奇数，在末尾加上 `Z` ，如果是偶数则不做改变，最后，我们得到了一个没有 `Q` 的长度为偶数的字符串，如此一来就可以对它们两两进行分组再进行加密操作了。

3. 经过上一步的预处理，我们得到了几对字母对，每个字母对中的两个字母在字母矩阵中可能处于同一行、同一列或者既不在同行也不在同列。它们的操作方法都不相同。
   
   * 对于处于同一行的字母，我们将它们向右移动一位，例如 `ZW` 根据上方的矩阵加密就得到了 `WX` ，如果是 `AH` 就得到了 `HZ` ，以此类推。
   
   * 对于处于同一列的字母的操作方法和处于同一行字母的操作方法相似，只是移动的方向从向右变成向下，例如 `ZR` 加密成 `RF` ，`ZF` 加密成 `RO` ，`OJ` 加密成 `JZ` ，以此类推。
   
   * 对于既不处于同一列也不处于同一行的字母，例如 `ZY` ，我们将这两个字母所处的位置看成矩形的对角，矩形的另外两个角就是 `O` 和 `W` 了，于是我们将 `ZY` 加密成 `OW` ，类似的，`ZL` 加密成 `OX` ，`VG` 加密成 `KL` 等等。

知道了加密的方法，显而易见地，解密的方法就是加密的逆过程，因为预处理的原因，也许解密出来的明文会出现一些没有意义的 `Z` ，这时候就要人为地进行舍去或替换成 `Q` 从而判断密文传递的信息。

既然知道了原理，那就看看如何用代码实现吧。

## C++ 代码实现

我们首先创建一个 `PlayFair` 类，显然，它需要一个 `Box` 作为字母矩阵，为了判断字母矩阵是否为空，我们还需要一个布尔值 `Box_Empty` 。声明如下：

```cpp
class PlayFair
{
private:
    static const int Box_Size = 5;
    char             Box[Box_Size][Box_Size] = {0};
    bool Box_Empty = true; // Judge if the box is empty
};
```

对于 `Box` ，我希望它可以自己生成，也可以手动输入，还可以从文件中读取，同时还要支持输出到文件。因此我创建几个用于操作 `Box` 的函数。

其声明及所需头文件如下：

```cpp
#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using std::string;

class PlayFair
{
public:
    // Read from file
    void ReadinBoxFromFile(string FilePath);
    // Read by typing
    void TypeinBox();
    // Random Generate
    void GenerateBox();
    // Write Box to file
    void WriteBoxToFile();
};
```

其实现如下：

```cpp
void PlayFair::ReadinBoxFromFile(string FilePath)
{
    std::ifstream fin;
    fin.open(FilePath.c_str());
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            char ch;
            fin >> ch;
            Box[i][j] = std::toupper(ch);
        }
    }
    fin.close();
    Box_Empty = false;
    GenerateAlphaBox();
    return;
}

void PlayFair::TypeinBox()
{
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            char ch;
            std::cin >> ch;
            Box[i][j] = std::toupper(ch);
        }
    }
    Box_Empty = false;
    GenerateAlphaBox();
    return;
}

void PlayFair::GenerateBox()
{
    std::srand(std::time(NULL));

    bool Flag[26] = {0}; // hash alpha
    Flag['Q' - 'A'] = 1; // delete Q
    // Generate the Box
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            int Num = rand() % 26; // select from 0 to 25
            while (Flag[Num])      // if not selected
            {
                Num = rand() % 26; // continue to select
            }
            Flag[Num] = 1;         // mark the alpha
            Box[i][j] = Num + 'A'; // write in alpha from A to Z
        }
    }
    Box_Empty = false;
    GenerateAlphaBox();
    return;
}

void PlayFair::WriteBoxToFile()
{
    std::ofstream fout;
    fout.open("PlayFairBox.txt");
    for (int i = 0; i < Box_Size; i++)
        for (int j = 0; j < Box_Size; j++)
            fout << Box[i][j] << " ";

    fout.close();
    return;
}
```

也许您注意到了 `GenerateAlphaBox()` 这一函数。这个函数是实现什么的呢？根据 `Playfair` 的加密原理，加密的时候我们需要找到字母在 `Box` 中的位置，如果每次我们都用遍历的方法寻找字母，那么明文长度越长，所用的时间就越长，因此，我定义一个结构体 `Point` 用于记录点的横纵坐标，而 `AlphaBox` 就是一个 `Point` 的数组。其声明如下：

```cpp
class PlayFair
{
private:
    struct Point
    {
        int x = 0;
        int y = 0;
    };
    // every alpha's location in Box
    Point AlphaBox[26] = {0};

public:
    // record alpha location
    void GenerateAlphaBox();
};
```

`GenerateAlphaBox()` 实现如下：

```cpp
void PlayFair::GenerateAlphaBox()
{
    // ignore Q
    AlphaBox['Q' - 'A'].x = -1;
    AlphaBox['Q' - 'A'].y = -1;
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            int index = std::toupper(Box[i][j]) - 'A';
            AlphaBox[index].x = j;
            AlphaBox[index].y = i;
        }
    }
    return;
}
```

处理完 `Box` 之后，我们就要对明文进行预处理了。

我们定义一个 `Preprocess` 方法，其声明如下：

```cpp
class PlayFair
{
public:
    // Operate PlainText
    string Preprocess(string PlainText);
};
```

其实现如下：

```cpp
string PlayFair::Preprocess(string PlainText)
{
    string AfterPreprocess = "";
    // remove not alpha char
    for (int i = 0; i < PlainText.length(); i++)
    {
        if (std::isalpha(PlainText[i]))
        {
            if (PlainText[i] != 'Q' && PlainText[i] != 'q')
                AfterPreprocess += std::toupper(PlainText[i]);
            else
                AfterPreprocess += 'Z';
        }
    }

    // use Z to separate the same alpha
    for (int i = 1; i < AfterPreprocess.length(); i++)
    {
        if (std::toupper(AfterPreprocess[i - 1]) ==
            std::toupper(AfterPreprocess[i]))
        {
            if (std::toupper(AfterPreprocess[i] == 'Z'))
                AfterPreprocess.insert(i, "H");
            else
                AfterPreprocess.insert(i, "Z");
        }
    }

    // use Z to make the PlainText.length() to even
    if (AfterPreprocess.length() % 2)
        AfterPreprocess +=
            ((AfterPreprocess[AfterPreprocess.length() - 1] == 'Z') ? 'H' : 'Z');

    return AfterPreprocess;
}
```

注意，这里有一个细节，因为要在两个相同的字母中间插入 `Z` ，但如果这两个相同的字母是 `ZZ` 怎么办呢？这时候就要在它们中间插入另一个不常用的字母，我这里选择的是 `H` 。同理，如果最后一个字母是 `Z` 且字符串长度为奇数，也要在末尾加上 `H` 。

至此，`Playfair` 加密的准备工作都做好了，接下来就是真正的加密解密环节了。

首先声明方法：

```cpp
class PlayFair
{
public:
    // Encode
    string EnCode(string pt);
    // Decode
    string DeCode(string ct);
};
```

这里先给出 `EnCode()` 的代码：

```cpp
string PlayFair::EnCode(string pt)
{
    // judge if the Box is empty
    if (Box_Empty)
        return "The Box is empty!";

    string CipherText = "";
    string PlainText = Preprocess(pt);

    for (int i = 0; i < PlainText.length(); i += 2)
    {
        // Get letter location
        int FirstLetterX = AlphaBox[PlainText[i] - 'A'].x;
        int FirstLetterY = AlphaBox[PlainText[i] - 'A'].y;
        int SecondLetterX = AlphaBox[PlainText[i + 1] - 'A'].x;
        int SecondLetterY = AlphaBox[PlainText[i + 1] - 'A'].y;

        // the same row
        if (FirstLetterY == SecondLetterY)
        {
            CipherText += Box[FirstLetterY][(FirstLetterX + 1) % Box_Size];
            CipherText += Box[SecondLetterY][(SecondLetterX + 1) % Box_Size];
        }
        else if (FirstLetterX == SecondLetterX) // the same column
        {
            CipherText += Box[(FirstLetterY + 1) % Box_Size][FirstLetterX];
            CipherText += Box[(SecondLetterY + 1) % Box_Size][SecondLetterX];
        }
        else
        {
            CipherText += Box[SecondLetterY][FirstLetterX];
            CipherText += Box[FirstLetterY][SecondLetterX];
        }
    }

    return CipherText;
}
```

对处于同一行或者同一列的字母，由于存在从行末尾或者列末尾移动到行开头或者列开头的情况，我们可以使用取模的手段达到这一目的。

至此，代码部分就完成了，最后给出所有源代码。

**playfair.h**

```cpp
#ifndef _PLAYFAIR_H_
#define _PLAYFAIR_H_

#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using std::string;

class PlayFair
{
private:
    struct Point
    {
        int x = 0;
        int y = 0;
    };

    static const int Box_Size = 5;
    char             Box[Box_Size][Box_Size] = {0};

    // every alpha's location in Box
    Point AlphaBox[26] = {0};

    bool Box_Empty = true; // Judge if the box is empty

public:
    /*Get Box Methods*/
    // Read from file
    void ReadinBoxFromFile(string FilePath);
    // Read by typing
    void TypeinBox();
    // Random Generate
    void GenerateBox();

    /*Operate Box*/
    // Show Box
    void ShowBox();
    // Write Box to file
    void WriteBoxToFile();
    // record alpha location
    void GenerateAlphaBox();

    // For debug
    void ShowAlphaBox();

    // Operate PlainText
    string Preprocess(string PlainText);

    // Encode
    string EnCode(string pt);
    // Decode
    string DeCode(string ct);
};

#endif //!_PLAYFAIR_H_
```

**playfair.cpp**

```cpp
#include "playfair.h"

void PlayFair::ReadinBoxFromFile(string FilePath)
{
    std::ifstream fin;
    fin.open(FilePath.c_str());
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            char ch;
            fin >> ch;
            Box[i][j] = std::toupper(ch);
        }
    }
    fin.close();
    Box_Empty = false;
    GenerateAlphaBox();
    return;
}

void PlayFair::TypeinBox()
{
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            char ch;
            std::cin >> ch;
            Box[i][j] = std::toupper(ch);
        }
    }
    Box_Empty = false;
    GenerateAlphaBox();
    return;
}

void PlayFair::GenerateBox()
{
    std::srand(std::time(NULL));

    bool Flag[26] = {0}; // hash alpha
    Flag['Q' - 'A'] = 1; // delete Q
    // Generate the Box
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            int Num = rand() % 26; // select from 0 to 25
            while (Flag[Num])      // if not selected
            {
                Num = rand() % 26; // continue to select
            }
            Flag[Num] = 1;         // mark the alpha
            Box[i][j] = Num + 'A'; // write in alpha from A to Z
        }
    }
    Box_Empty = false;
    GenerateAlphaBox();
    return;
}

void PlayFair::ShowBox()
{
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            std::cout << Box[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void PlayFair::WriteBoxToFile()
{
    std::ofstream fout;
    fout.open("PlayFairBox.txt");
    for (int i = 0; i < Box_Size; i++)
        for (int j = 0; j < Box_Size; j++)
            fout << Box[i][j] << " ";

    fout.close();
    return;
}

void PlayFair::GenerateAlphaBox()
{
    // ignore Q
    AlphaBox['Q' - 'A'].x = -1;
    AlphaBox['Q' - 'A'].y = -1;
    for (int i = 0; i < Box_Size; i++)
    {
        for (int j = 0; j < Box_Size; j++)
        {
            int index = std::toupper(Box[i][j]) - 'A';
            AlphaBox[index].x = j;
            AlphaBox[index].y = i;
        }
    }
    return;
}

void PlayFair::ShowAlphaBox()
{
    for (int i = 0; i < 26; i++)
        std::cout << (char)(i + 'A') << " " << AlphaBox[i].x << " "
                  << AlphaBox[i].y << '\n';

    std::cout << AlphaBox['A' - 'A'].y << '\n';
    std::cout << AlphaBox['B' - 'A'].y << '\n';
    return;
}

string PlayFair::Preprocess(string PlainText)
{
    string AfterPreprocess = "";
    // remove not alpha char
    for (int i = 0; i < PlainText.length(); i++)
    {
        if (std::isalpha(PlainText[i]))
        {
            if (PlainText[i] != 'Q' && PlainText[i] != 'q')
                AfterPreprocess += std::toupper(PlainText[i]);
            else
                AfterPreprocess += 'Z';
        }
    }

    // use Z to separate the same alpha
    for (int i = 1; i < AfterPreprocess.length(); i++)
    {
        if (std::toupper(AfterPreprocess[i - 1]) ==
            std::toupper(AfterPreprocess[i]))
        {
            if (std::toupper(AfterPreprocess[i] == 'Z'))
                AfterPreprocess.insert(i, "H");
            else
                AfterPreprocess.insert(i, "Z");
        }
    }

    // use Z to make the PlainText.length() to even
    if (AfterPreprocess.length() % 2)
        AfterPreprocess +=
            ((AfterPreprocess[AfterPreprocess.length() - 1] == 'Z') ? 'H' : 'Z');

    return AfterPreprocess;
}

string PlayFair::EnCode(string pt)
{
    // judge if the Box is empty
    if (Box_Empty)
        return "The Box is empty!";

    string CipherText = "";
    string PlainText = Preprocess(pt);

    for (int i = 0; i < PlainText.length(); i += 2)
    {
        // Get letter location
        int FirstLetterX = AlphaBox[PlainText[i] - 'A'].x;
        int FirstLetterY = AlphaBox[PlainText[i] - 'A'].y;
        int SecondLetterX = AlphaBox[PlainText[i + 1] - 'A'].x;
        int SecondLetterY = AlphaBox[PlainText[i + 1] - 'A'].y;

        // the same row
        if (FirstLetterY == SecondLetterY)
        {
            CipherText += Box[FirstLetterY][(FirstLetterX + 1) % Box_Size];
            CipherText += Box[SecondLetterY][(SecondLetterX + 1) % Box_Size];
        }
        else if (FirstLetterX == SecondLetterX) // the same column
        {
            CipherText += Box[(FirstLetterY + 1) % Box_Size][FirstLetterX];
            CipherText += Box[(SecondLetterY + 1) % Box_Size][SecondLetterX];
        }
        else
        {
            CipherText += Box[SecondLetterY][FirstLetterX];
            CipherText += Box[FirstLetterY][SecondLetterX];
        }
    }

    return CipherText;
}

string PlayFair::DeCode(string ct)
{
    if (Box_Empty)
        return "The Box is empty!";

    string CipherText = Preprocess(ct);
    string PlainText = "";

    for (int i = 0; i < CipherText.length(); i += 2)
    {
        // Get letter location
        int FirstLetterX = AlphaBox[CipherText[i] - 'A'].x;
        int FirstLetterY = AlphaBox[CipherText[i] - 'A'].y;
        int SecondLetterX = AlphaBox[CipherText[i + 1] - 'A'].x;
        int SecondLetterY = AlphaBox[CipherText[i + 1] - 'A'].y;

        // the same row
        if (FirstLetterY == SecondLetterY)
        {
            PlainText +=
                Box[FirstLetterY][(FirstLetterX - 1 + Box_Size) % Box_Size];
            PlainText +=
                Box[SecondLetterY][(SecondLetterX - 1 + Box_Size) % Box_Size];
        }
        else if (FirstLetterX == SecondLetterX) // the same column
        {
            PlainText +=
                Box[(FirstLetterY - 1 + Box_Size) % Box_Size][FirstLetterX];
            PlainText +=
                Box[(SecondLetterY - 1 + Box_Size) % Box_Size][SecondLetterX];
        }
        else
        {
            PlainText += Box[SecondLetterY][FirstLetterX];
            PlainText += Box[FirstLetterY][SecondLetterX];
        }
    }

    return PlainText;
}
```

## `Playfair` 密码分析

`Playfair` 密码在一定程度上抵抗住了字母频率分析，因为同一个密文字母可能对应不同的明文字母，密文字母对应的明文字母取决于字母对中另一个字母与它的相对位置。因此会出现一个密文字母对应多个明文字母的情况。

`Playfair` 如果使用暴力破解基本上是不可能的，但是它的明文和密文中的字母仍然是一一对应的，对于足够长的密文，它的结构是有可能被分析出来的，因此它不被认为是安全的加密算法，但它仍给予了我们许多对抗字母频率分析的启示。

> 最后，如果本文有哪里出现错误，欢迎在底部评论区提出。

------------------------

——END——
