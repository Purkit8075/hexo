---
title: Vigenere 密码以及 C++ 实现
date: 2023-06-17
description: 本文介绍了 Vigenere 密码并提供其 C++ 源码。
tags: ["Vigenere"]
categories: 密码学
keywords: ["Vigenere","密码学","C++ 实现"]
cover: https://img.purkit.ml/vigenere-cover.png
    # C++ 教程： 
---

# Vigenere 密码以及 C++ 实现

## `Vigenere` 密码原理

`Vigenere` 密码是一种加密只含字母的字符串的一种加密算法。

它的加密过程如下：

1. 选择一个任意长度的密钥，密钥也是只含字符的字符串。

2. 用密钥填充明文，使每个明文字母都对应一个密钥中的字符。例如：

```textile
SecureKey:    THE
PlainText:    THISISPURKIT
Fill:         THETHETHETHE
```

3. 将填充之后每个明文字母对应的密钥中的字母处于字母表中的位置作为凯撒密码的位移量，然后将明文中单个字符使用该位移量进行凯撒加密。得到密文。例如：

```textile
SecureKey:    THE
PlainText:    THISISPURKIT
Fill:         THETHETHETHE
CipherText:   NPNMQXJCWEQY
```

同样地，对于 `Vigenere` 的解密过程就是用相同的密钥进行加密的逆过程。

对于该加密算法，每一次加密都应当选择不同的密钥，从而提高该加密方法的安全性。

知道了 `Vigenere` 的加密方法，我们就可以用代码实现了。

## C++ 代码实现

因为加密的过程需要用到凯撒密码进行，那么对于凯撒密码的实现请移步 [凯撒密码原理及其 C++ 实现](https://blog.purkit.ml/2023/06/04/caesar-code/) 。

对于 `Vigenere` 的代码实现，需要用到我在 [凯撒密码原理及其 C++ 实现](https://blog.purkit.ml/2023/06/04/caesar-code/) 中写到的 `caesar.h` 头文件。

我们首先声明一个 `Vigenere` 类，其私有类成员包含一个密钥字符串和一个 `Caesar` 对象。

`Vigenere` 类的公有类方法需要实现以下几个目的：

* 构造函数用于初始化密钥。

* 设置密钥。

* 从键盘中读取密钥。

* 从文件中读取密钥。

* 随机生成指定长度的密钥。

* 加密。

* 解密。

* 显示密钥。

* 判断密钥是否为空，如果为空则不能进行加密和解密。

因此，我们可以创建如下 `vigenere.h` 文件：

```cpp
#ifndef _VIGENERE_H_
#define _VIGENERE_H_

#include "caesar.h"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using std::string;

static const char * EmptyWarning = "The secure key is empty!";

class Vignere
{
private:
    string SecureKey;
    Caesar caesar;

public:
    /*Constructors*/

    Vignere(string sk);
    Vignere();

    // read key from keyboard
    void InputSecureKey();
    // read key from file
    void ReadSecureKeyFromFile(string FilePath);
    // random key
    void RandomKey(int Len = 4); // default key length
    // reset key
    void ResetSecureKey(string sk) { SecureKey = sk; }

    // judge securekey is empty or not
    bool SecureKeyEmpty() { return !SecureKey.length(); }

    // Encode
    string EnCode(string PlainText);

    // Decode
    string DeCode(string CipherText);

    // Show SerucreKey
    void ShowSecureKey() { std::cout << SecureKey << '\n'; }
};

#endif //!_VIGENERE_H_
```

对于密钥的操作比较简单，这里提供一下参考代码：

```cpp
Vignere::Vignere(string sk)
{
    SecureKey = ""; // init SecureKey

    // if is alpha add to SecureKey
    for (int i = 0; i < sk.length(); i++)
        if (std::isalpha(sk[i]))
            SecureKey += std::toupper(sk[i]);
}

Vignere::Vignere()
    : SecureKey("")
{
}

void Vignere::InputSecureKey()
{
    string sk = ""; // init
    std::cin >> sk; // read from keyboard
    for (int i = 0; i < sk.length(); i++)
        if (std::isalpha(sk[i]))
            SecureKey += std::toupper(sk[i]);

    return;
}

void Vignere::ReadSecureKeyFromFile(string FilePath)
{
    std::ifstream fin;
    fin.open(FilePath.c_str()); // open file
    string ReadString = "";     // init strings
    string ResultString = "";

    while (!fin.eof())
    {
        std::getline(fin, ReadString); // read a line of key
        ResultString += ReadString;    // add to result key
    }

    fin.close(); // close file

    for (int i = 0; i < ResultString.length(); i++)
        if (std::isalpha(ResultString[i]))
            SecureKey += std::toupper(ResultString[i]);
    return;
}

void Vignere::RandomKey(int Len)
{
    std::srand(std::time(0));                  // set random seed
    for (int i = 0; i < Len; i++)
        SecureKey += (std::rand() % 26) + 'A'; // generate key
    return;
}
```

重点是加密的步骤，`Vigenere` 的加密原理中有一点是填充，用代码实现时，也许直观的想法是再声明一个字符串模拟填充，但实际上，可以用取模的方法来节省空间。

明文字符串的每个字符的下标对密钥的长度进行取模就相当于填充了，因此，我们可以很简单地得到 `EnCode()` 方法和 `DeCode()` 方法的具体实现。

```cpp
string Vignere::EnCode(string PlainText)
{
    if (SecureKeyEmpty()) // if empty, return waring
        return EmptyWarning;

    string CipherText = "";
    int    KeyLength = SecureKey.length();
    for (int i = 0; i < PlainText.length(); i++)
    {
        if (!std::isalpha(PlainText[i]))
            continue;

        string temp = "";
        temp += PlainText[i];
        CipherText += caesar.EnCode(temp, SecureKey[i % KeyLength] - 'A' + 1);
    }
    return CipherText;
}

string Vignere::DeCode(string CipherText)
{
    if (SecureKeyEmpty())
        return EmptyWarning;

    string PlainText = "";
    int    KeyLength = SecureKey.length();

    for (int i = 0; i < CipherText.length(); i++)
    {
        if (!std::isalpha(CipherText[i]))
            continue;
        string temp = "";
        temp += CipherText[i];
        PlainText += caesar.DeCode(temp, SecureKey[i % KeyLength] - 'A' + 1);
    }
    return PlainText;
}
```

## `Vigenere` 密码分析

如果在密钥长度已知的情况下，`Vigenere` 密码还是不安全的。如果密钥长度和明文长度相同的话，那就达到了理论上的绝对安全，因为谁也不知道明文和密钥到底哪个是哪个。

在密钥长度不够或者密钥重复使用的情况下，`Vigenere` 密码的安全性就会随之降低。

这也许就是 `Vigenere` 密码不被现在密码系统所接受的原因之一吧。

---------------

——END——
