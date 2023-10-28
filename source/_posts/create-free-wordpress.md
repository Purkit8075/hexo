---
title: Pantheon + Render 搭建免费 WordPress 博客
date: 2022-12-25
description: 从零开始零成本搭建 WordPress 博客。
tags: ["WordPress"]
categories: 网站
keywords: ["WordPress","反代","免费"]
cover: https://s3.tebi.io/img.purkit.ml/wordpress-cover.jpg
    # C++ 教程：
---

# 从零开始零成本搭建 WordPress 博客

> 写在前面：
> 
> 本方案由 [Yonzlich](https://yzlab.ml/) 提供，感谢他提供该方案。

## 需要的工具

* 一个谷歌账号
* 一个 GitHub 账号
* 一个 Pantheon 账号
* 一个 Freenom 账号
* 一个 Render 账号
* 一个 Cloudflare 账号

## 注册免费域名

因为是零成本搭建网站，所以我们选择免费的域名。

免费域名有 `.ml` 、`.tk` 、`.cf` 和 `.gq` 。

打开 [Freenom](https://www.freenom.com/) 。使用 `Google` 账号登录。

依次点击 `Services -> Register a New Domain` 。

<img src="https://ci.cncn3.cn/bc088e10b8c123ed8aa3cc68f9206f40.png" title="" alt="bc088e10b8c123ed8aa3cc68f9206f40.png" data-align="center">

在搜索框中输入您想要的域名，记得加上后缀。

例如，我这里选择 `my-new-test.ml` ，然后点击 `Check Availability` 。

<img src="https://ci.cncn3.cn/298297493ad30bde8c7cc95bf6472b15.png" title="" alt="298297493ad30bde8c7cc95bf6472b15.png" data-align="center">

如果域名可用，那它将自动加入购物车。

接着我们点击 `Checkout` ，进入结算界面。

<img src="file:///home/purkit/.config/marktext/images/2022-12-25-14-44-04-image.png" title="" alt="" data-align="center">

下拉 `Period` ，可以看到，一年之内域名是免费的。

<img src="https://ci.cncn3.cn/26d6ee7700102f8aa7ff830a37ba8149.png" title="" alt="26d6ee7700102f8aa7ff830a37ba8149.png" data-align="center">

我们选择 12Months ，即一年，到期时需要进行再次购买，如果再次购买一年之内的，它仍然免费。

接下来的步骤就比较麻烦了。

首先，打开 [IP 查询](https://ip.sb) 查看您的 IP 所对应的地区。

接着打开 [身份生成](https://www.shenfendaquan.com/) ，选择您 IP 所在的地区并生成信息。

然后将身份填入 `Freenom` 中。这样您就能够购买到自己的域名了。

## 域名托管

购买完域名之后，我们打开并注册 [Cloudflare](https://www.cloudflare.com/) 。

我们使用 `Cloudflare` 来托管我们的域名。

登录之后，点击右上角的 `Add site` 。输入域名之后选择免费计划。

在添加 `DNS` 解析界面我们直接点击 `Continue` 。

<img src="https://ci.cncn3.cn/f043285746025924ddbb0cbdc75a01de.png" title="" alt="f043285746025924ddbb0cbdc75a01de.png" data-align="center">

在 `Change your nameservers` 界面停留。

<img src="file:///home/purkit/.config/marktext/images/2022-12-25-15-01-08-image.png" title="" alt="" data-align="center">

返回 `Freenom` ，点击 `Manage Domain` 。

<img src="https://ci.cncn3.cn/6cf936a4617db99b7968adc4b59c144f.png" title="" alt="6cf936a4617db99b7968adc4b59c144f.png" data-align="center">

再依次点击 `Management Tools -> Nameservers` 。

<img src="https://ci.cncn3.cn/3eac7427d26d6175c8718df8b18c819d.png" title="" alt="3eac7427d26d6175c8718df8b18c819d.png" data-align="center">

将 `Cloudflare` 的 `Nameserver` 添加到 `Freenom` 中。

<img src="https://ci.cncn3.cn/250ce06db9e3845c4a5e877f010ebcad.png" title="" alt="250ce06db9e3845c4a5e877f010ebcad.png" data-align="center">

结果如下图：

<img src="https://ci.cncn3.cn/5499dc599f60a8c5d3219a975b26c777.png" title="" alt="5499dc599f60a8c5d3219a975b26c777.png" data-align="center">

在 `Cloudflare` 中选择确定，然后将所有的选项都打勾，最后完成。

## 白嫖 `WordPress`

打开网站 [Pantheon](https://pantheon.io/) 。

注册并登录。点击 `Create New Site` 。

<img src="https://ci.cncn3.cn/855a88b4c242fcb95c5a6f5a06a5f07a.png" title="" alt="855a88b4c242fcb95c5a6f5a06a5f07a.png" data-align="center">

选择 `WordPress` 。然后输入网站的名称。

等待部署完成之后，`Pantheon` 会给我们分配一个三级域名。我们需要绑定自己的域名。

但是，`Pantheon` 的绑定域名服务是收费的。所以我们需要别的方法。

## 使用 `Render` 反代 `Pantheon` 域名

我们注册 `GitHub` 账号。

然后 `import` 这个 [项目](https://github.com/gitiy1/blog) 。建议将仓库设置为私有。

打开 `nginx.conf` 文件，将下图中圈出的区域中的链接替换为您自己的链接。

您也可以选择反代到您的二级域名之下。只需要修改 `my-new-test.ml` 为 `xxx.my-new-test.ml` 即可。

<img src="https://ci.cncn3.cn/2a450b80865f85bf0bf9fb49baa6a9f1.png" title="" alt="2a450b80865f85bf0bf9fb49baa6a9f1.png" data-align="center">

> 以上部分参考 [Yonzlich](https://note.yzlab.ml/zh/articals/render-nginx) 。

打开 [Render](https://render.com/) ，使用 `GitHub` 注册并登录。

选择 `Web Services` 。

<img src="https://ci.cncn3.cn/cbd7bea710bcfb340c0355c072423c0d.png" title="" alt="cbd7bea710bcfb340c0355c072423c0d.png" data-align="center">

连接您自己刚刚 import 的仓库。

填写名称后，添加环境变量 `PORT` 值为 `80` 。

部署完成之后，点击 `Settings` 找到 `Custom Domains` ，进行域名绑定。

至此，您就拥有了一个自己的博客了！

**Now,enjoy writing!**

## 注意事项

* 每三个月都要到 `Pantheon`  中进行一次 `commit` ，否则您的博客会被暂时停止，数据不会丢失。
* `Render` 的免费账户一个月的服务时间一共只有 750 小时，这就意为着，您只能在免费账号中添加一个项目。如果时间用完，那么您的项目将会被停止。

> 最后再次衷心感谢 [Yonzlich](https://yzlab.ml/) 提供该方案！

-----------------------------

——END——
