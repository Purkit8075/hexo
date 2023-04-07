---
title: 使用 Tebi + PicGo 搭建图床
date: 2023-04-06    
description: 本文介绍如何使用 Tebi 和 PicGo 搭建个人使用的免费图床。
tags: ["Tebi","PicGo"]
categories: 网站
keywords: ["Tebi","PicGo","图床"]
cover: https://img.purkit.ml/tebi-and-picgo
    # C++ 教程： 
---

# 使用 `Tebi` 搭建图床

## 前言

如果您还在用第三方图床或者没有图床可用，那您不妨参考这篇文章自行搭建一个免费的个人的图床。

图床正如大多数东西一样，只有掌握在自己手上才是最安心的。

## 准备工作

* 一个邮箱

* `Tebi` 账号

## 配置 `Tebi`

首先，访问 [Tebi](https://tebi.io/) 并使用邮箱注册账号，在收件箱或者垃圾邮件里点击 `Tebi` 发的链接，完成注册。

接着访问 [Client.tebi.io](https://client.tebi.io/buckets/) ，在右上角的 `Enter bucket name` 中输入您想要的图床域名，例如我的是 `img.purkit.ml` ，然后点击 `ADD BUCKET` 。

<img title="" src="https://img.purkit.ml/ADD%20BUCKET" alt="" data-align="center" width="596">

接着添加 `DNS` 域名解析。给您的域名添加一个 `CNAME` ，`Target` 填 `您的域名 + .s3.tebi.io` 。例如 `img.purkit.ml` 就填 `img.purkit.ml.s3.tebi.io` 。



然后回到 `Tebi` 。点击左边的 `Keys` 。接着 `ADD KEY` （输入框中 `Optional key comment` 填不填都可以）。

在 `EDIT` 中将 `S3 Protocol` 打勾。

<img src="https://img.purkit.ml/add-key" title="" alt="" data-align="center">

回到 `Bucket` ， 点击刚刚创建的 `Bucket` 旁边的 `Edit` 。

<img title="" src="https://img.purkit.ml/click-edit" alt="" data-align="center" width="593">

选择 `Access Control` ，将全部选项都设置成 `Public` 。

<img title="" src="file:///home/purkit/.config/marktext/images/2023-04-07-11-39-41-image.png" alt="" data-align="center" width="540">

在 `DNS` 解析生效之后，点击 `Hosting` ，将 3 个选项全部勾选。

<img title="" src="https://img.purkit.ml/set-hosting" alt="" data-align="center" width="552">

其它选项保持默认，点击 `UPDATE` 。

访问您的图床域名，如果出现 `404` 页面则说明配置成功了。

## 使用 `PicGo`

配置完图床之后，要如何使用呢？

本来我想得是挂载到 `Alist` 网盘上的，后来发现 `PicGo` 有 `S3` 传输的插件。

于是我选择使用 `PicGo` 。

### 配置 `PicGo`

首先，访问 `PicGo` 的仓库：[GitHub](https://github.com/Molunerfinn/PicGo) 。

在 `Release` 中下载与自己系统对应的版本。

安装并运行 `PicGo` 后，转到 `插件设置` ，搜索 `S3` ，下载第一个插件。

<img title="" src="https://img.purkit.ml/download-s3" alt="" data-align="center" width="553">

转到 `图床设置 -> Amazon S3` ，新建一个图床。

配置如图：

<img title="" src="https://img.purkit.ml/config-picgo-s3" alt="" data-align="center" width="492">

图床配置名随意，`应用密钥 ID` 和 `应用密钥` 是在 `Tebi` 中添加的 `Key` 和 `Secret` 。

`桶` 的名称填 `Bucket` 的名称。文件路径参考下表：

| payload      | 描述            |
|:------------:|:-------------:|
| `{year}`     | 当前日期 - 年      |
| `{month}`    | 当前日期 - 月      |
| `{day}`      | 当前日期 - 日      |
| `{fullName}` | 完整文件名（含扩展名）   |
| `{fileName}` | 文件名（不含扩展名）    |
| `{extName}`  | 扩展名（不含`.`）    |
| `{md5}`      | 图片 MD5 计算值    |
| `{sha1}`     | 图片 SHA1 计算值   |
| `{sha256}`   | 图片 SHA256 计算值 |

> 来源：[GitHub PicGo S3 插件](https://github.com/wayjam/picgo-plugin-s3) 。



`地区` 和 `自定义节点` 都填写 `s3.tebi.io` 即可。`自定义域名` 填写您的图床域名，注意 `https://` 。

最后将下方的 3 个选项全部勾选。点击 `确定` 进行保存。

<img title="" src="https://img.purkit.ml/confing-s3" alt="" data-align="center" width="512">

在 `上传区` 将上传的图床设置成 `Amazon S3` 。至此，您就可以使用 `PicGo` 和 `Tebi` 作为图床了。

--------------------

——END——


