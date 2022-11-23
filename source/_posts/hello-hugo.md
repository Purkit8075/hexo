---
title: Ubuntu平台下使用Vercel+Hugo搭建静态博客
date: 2022-11-12
description: 从零开始搭建一个静态的个人博客。
tags: ["博客","Vercel","Ubuntu","Hugo"]
categories: ["网站"]
keywords: ["Vercel","Ubuntu","Hugo"]
cover: https://ci.cncn3.cn/1e3275ee00e412741ef8a403afb8b548.png
---

# `Ubuntu` 平台下使用 `Vercel` + `Hugo` 搭建静态博客

> 写在前面：虽然本文是在 `Ubuntu` 系统上操作的，但是 `Windows` 除了安装的方法不一样之外，其它部分都是大同小异的。所以，如果您是 `Windows` 用户，可以查找相关环境的安装方法，然后按本文的步骤进行搭建博客。

## 准备工作

### 安装 `Git`

打开终端，输入以下命令：

```bash
sudo apt update
sudo apt install git
```

安装成功之后，使用以下命令查看 `Git` 是否安装成功。

```bash
git --version
```

如果显示 `Git` 的版本号，则说明安装成功。

### 安装 `Go` 语言

#### 使用命令

您可以使用以下命令安装 `Go` 。

```bash
sudo apt update
sudo apt install golang
```

如果您不希望使用命令，那么您可以采用以下方法。

#### 使用 `snap` 商店

打开 `Ubuntu Software` 。

<img src="https://ci.cncn3.cn/4333928b4a710b00fd5efcda638a1e8b.png" title="" alt="4333928b4a710b00fd5efcda638a1e8b.png" data-align="center">

搜索 `Go` ，找到以下软件。

![eb05659725a038a3686a12f957ee7014.png](https://ci.cncn3.cn/eb05659725a038a3686a12f957ee7014.png)

然后选择合适的版本安装。

#### 检查

无论您使用哪一种方法安装，最后都可以使用以下指令查看是否安装成功。

```bash
go version
```

### 安装 `Hugo`

直接在 `Ubuntu Software` 中搜索 `Hugo` 。

![9e86900ed06a5cbc97b1a885276e4861.png](https://ci.cncn3.cn/9e86900ed06a5cbc97b1a885276e4861.png)

进入这个软件。

**注意：** 此时需要选择合适的版本。我使用的版本如下：

![7125693223ac182c6793fe3a6707886d.png](https://ci.cncn3.cn/7125693223ac182c6793fe3a6707886d.png)

选择的版本将影响到博客主题能否正常使用。

比如我使用的 `stack` 主题需要使用该版本。所以，读者可以根据自己需要选择 `Hugo` 版本。

最后，使用以下命令查看 `Hugo` 的版本：

```bash
hugo version
```

### 注册 `Github`

打开网站 [Github](https://github.com/) 。

点击 `Sign up`，按照提示注册 `Github` 账号。

**注意：** 不要使用 QQ 邮箱进行注册，据说会有一些限制。

### 注册 `Vercel`

打开网站 [Vercel](https://vercel.com/) 。

直接使用 `Github` 登录。

至此，所有的准备工作就完成了。接下来上重头戏。

## 搭建 `Hugo`

在 `Vercel` 的 `dashboard` 中，依次点击 `Add New... -> Project` 。

在新的界面中，右边有一个 `Clone Template` 。点击 `Browse All Templates →`。点击 `Hugo` 。

此时，需要我们选择一个仓库来存放 `Hugo` 博客。在 `Create Git Repository` 一栏中选择 `Github` 。

输入仓库名称。

![f08d1feee3e30c9c0c92f389da0e9097.png](https://ci.cncn3.cn/f08d1feee3e30c9c0c92f389da0e9097.png)

名称可以使用默认名称，无伤大雅。

等待部署完毕之后，我们需要配置 `ssh` 来更好地进行上传代码。

### `Git` 配置

打开终端，输入以下命令：

```bash
git config --global user.name Example-Name
git config --global user.email Example-Email
```

将 `Example-Name` 和 `Example-Email` 分别替换成您自己的用户名和邮箱。

这里的用户名不一定是您 `Github` 上的用户名。这个用户名是您用于 `commit` 时的用户名。

关于 `commit` ，我将马上介绍。

之后运行以下命令生成 `ssh` 密钥：

```bash
ssh-keygen -t rsa
```

这里直接一路按 `Enter` 。最后在密钥文件生成的目录下（默认为 `/Home/.ssh` ）打开文件 `id_rsa.pub` 。

复制文件中的所有内容，然后回到 `Github` 。

点击右上角自己的头像，然后点击 `Settings` 。

在新的界面中点击 `SSH and GPG keys -> New SSH key` 。

`Title` 随便填，`Key type` 使用默认的 `Authentication Key` 。下面的 `Key` 中粘贴刚刚复制的内容。然后完成。

接着回到刚刚创建的仓库，复制 `SSH` 的链接。

![3d6a88fa5e305b68d6819b1755253212.png](https://ci.cncn3.cn/3d6a88fa5e305b68d6819b1755253212.png)

然后在本地选择一个文件夹，打开终端。这里为了方便，我选择的是桌面文件夹。

这时，我们要用 `Git` 将 `Github` 上的仓库克隆到本地。运行以下命令：

```bash
git clone your-ssh-link
```

将 `your-ssh-link` 替换成刚刚复制的 `SSH` 链接。

此时，桌面上出现一个和仓库同名的文件夹。

### 更换 `stack` 主题

`Hugo` 拥有许多主题，每种主题的安装方式都有一定差别。

这里，我以安装我自己使用的 `stack` 主题为例。

> 以下内容参考 [锦李本鲤](https://jinli.cyou/p/%E4%B8%AA%E4%BA%BA%E7%BD%91%E7%AB%99%E7%9A%84%E5%BB%BA%E7%AB%8B%E8%BF%87%E7%A8%8B%E4%B8%89hugo%E4%B8%BB%E9%A2%98stack%E7%9A%84%E4%BD%BF%E7%94%A8%E4%B8%8E%E4%BC%98%E5%8C%96/) 。

先将终端的目录切换到刚刚克隆的文件夹中。运行以下命令：

```bash
cd hugo-teach/
```

接着打开 `stack` 的 [Github 仓库](https://github.com/CaiJimmy/hugo-theme-stack) 。

复制仓库的 `https` 链接。

![204811c8a31f85adb0c11d567de15c5b.png](https://ci.cncn3.cn/204811c8a31f85adb0c11d567de15c5b.png)

然后在终端运行以下命令，将该仓库克隆到 `themes/hugo-theme-stack` 目录下。

```bash
git clone https://github.com/CaiJimmy/hugo-theme-stack/ themes/hugo-theme-stack
```

接着将 `hugo-theme-stack` 下 `exampleSite` 中的内容复制到博客的根目录。

```bash
cp -r themes/hugo-theme-stack/exampleSite/* ./
```

删除文件 `config.toml` ，防止与主题配置文件冲突。

然后运行以下两条命令：

```bash
hugo
hugo server
```

打开链接 `http://localhost:1313/` 就可以看到自己的站点了。

之后就是配置 `config.yaml` 文件了。具体的操作请查看主题对应的文档。

## `Hugo` 使用

### 写文章

在根目录的 `content/post` 中可以写文章，文章使用 `Markdown` 语法书写。

关于 `Markdown` 的编辑器可以使用 [Marktext](https://github.com/marktext/marktext) 。这是一个开源并且免费的编辑器。

当然，您也可以使用 `Typora` 进行写作。但是 `Typora` 是一个收费软件。

这二者在使用的体验上差距不大。

关于 `Markdown` 语法，请阅读 [官方文档](https://markdown.com.cn/) 。

写完文章，还需要配置 `Front matter` ，关于 `Front matter` 的配置请参考主题的官方文档。

之后，我们使用以下命令生成文章：

```bash
hugo
```

### `Github` 更新

在本地写完文章或者更新完站点的配置之后，我们需要将它们推送到 `Github` 的仓库上。

如果您是按照上面介绍的方式克隆仓库，那么您只需要在终端输入以下指令：

```bash
git add .
git commit -m 'your-commit'
git push
```

`your-commit` 可以是您这次更改的内容。这里的单引号 `''` 可以使用双引号 `""` 代替，但不能省略。

`git add .` 是将有更改的文件放入缓冲区，然后使用 `commit` 给它们 “贴上标签” ，最后 `push` 到仓库上。

之后，`Vercel` 会自动检测仓库变化，并自动部署。

因为主题也是通过克隆的方式下载到本地的，所以主题文件夹中也会有一个 `.git` 的文件夹。

而这个文件夹的存在会导致以上指令报错，解决方法就是将该文件夹删除，该操作没有风险。

**注意：** 写完文章之后，一定要 `hugo` 一下，然后使用 `hugo server` 预览，没有问题之后再 `push` 。

至此，您就已经成功搭建了一个静态博客。现在，享受写作吧！

如果有什么问题，请在评论区提出，我会及时回复。

-------------------------------------------------

——END——
