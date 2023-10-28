---
title: 使用 Waline 作为 Butterfly 主题的评论系统
date: 2022-12-31
description: 本文介绍如何使用 Waline +Vercel + bit.io 作为 Butterfly 主题的评论系统。 
tags: ["Waline","Vercel","bit.io"]
categories: 网站
keywords: ["Waline","Vercel","bit.io"]
cover: https://s3.tebi.io/img.purkit.ml/waline-cover.jpg
    # C++ 教程： 
---

# 使用 Waline 作为 Butterfly 主题的评论系统

## 背景

之前，我的博客使用 `Valine` 作为评论系统，后来发现 `Valine` 具有重大的安全问题，于是决定更换 `Waline` 作为博客的评论系统。

> [Valine 的安全问题](https://ttys3.dev/post/please-stop-using-valine-js-comment-system-until-it-fixed-the-privacy-leaking-problem/) 详见该文章。

## 准备工作

在开始之前，您需要：

* `GitHub` 账号

* `Vercel` 账号

* `bit.io` 账号

## 创建数据库

登录 [bit.io](https://bit.io) 。点击 New 。

<img src="https://ci.cncn3.cn/70e93ea80a7317bca6d55a477290ae9a.png" title="" alt="70e93ea80a7317bca6d55a477290ae9a.png" data-align="center">

填写数据库名称之后打开 [waline.pgsql](https://github.com/walinejs/waline/blob/main/assets/waline.pgsql)  ，复制文件内容，粘贴到 `bit.io` 的 `Query Editor` 中，点击 `Run Query` 。

<img src="https://ci.cncn3.cn/b8f3ed3f52ab78596201ca9740dbb38d.png" title="" alt="b8f3ed3f52ab78596201ca9740dbb38d.png" data-align="center">

至此，数据库的创建就完成了。先将这个页面放到后台，后面还会用到。

## 部署到 `Vercel`

[![](https://vercel.com/button)](https://vercel.com/new/clone?repository-url=https%3A%2F%2Fgithub.com%2Fwalinejs%2Fwaline%2Ftree%2Fmain%2Fexample)

点击上方按钮，进入 `Vercel` 的部署界面，选择仓库之后，点击 `Create` 。

部署成功之后，在项目界面，点击 `Settings -> Environment Variables` 。

添加以下环境变量。

| 环境变量名称        | 必填  | 默认值       | 备注                         |
| ------------- | --- | --------- | -------------------------- |
| `PG_DB`       | ✅   |           | PostgreSQL 数据库库名           |
| `PG_USER`     | ✅   |           | PostgreSQL 数据库的用户名         |
| `PG_PASSWORD` | ✅   |           | PostgreSQL 数据库的密码          |
| `PG_HOST`     |     | 127.0.0.1 | PostgreSQL 服务的地址           |
| `PG_PORT`     |     | 3211      | PostgreSQL 服务的端口           |
| `PG_PREFIX`   |     | `wl_`     | PostgreSQL 数据表的表前缀         |
| `PG_SSL`      |     | `false`   | 是否使用 SSL 连接 PostgreSQL 数据库 |

> 来源：[Waline 官方文档](https://waline.js.org/guide/database.html#postgresql) 。

其中，`PG_PREFIX` 不需要填写，`PG_SSL` 填写 `true` 。

其它的选项您可以在 `bit.io` 项目中的 `Connect` 中找到。

<img src="https://ci.cncn3.cn/2a7cbc46491fd3e8dec0082dcaeb010c.png" title="" alt="2a7cbc46491fd3e8dec0082dcaeb010c.png" data-align="center">

在 `Vercel` 界面中重新部署。然后访问 `Vercel` 的域名。在页面中测试一下能否发送评论。

因为 `Vercel` 的域名在国内无法访问，所以我们需要给 `Vercel` 绑定一下域名，如何给 `Vercel` 绑定域名比较简单，这里就不做介绍。

## 添加到 `Butterfly` 主题中

打开 `_config.butterfly.yml` 文件，找到 `Waline` 选项。

`serverURL` 填写您的 `Waline` 域名。

至此，`Waline` 评论系统就添加成功了。



> 参考：[Waline 官方文档](https://waline.js.org/)

--------------------------------

——END——
