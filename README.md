# 华科 AIA C语言课程设计部分工具（仿win）

在C语言课程设计（AIA）仿windows资源管理器中，用到/制作的工具or代码。

截止到目前，本项目包含了：

- 简易图片写屏工具

## 目录

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [目录](#目录)
- [背景](#背景)
- [安装](#安装)
- [使用说明](#使用说明)
  - [简易图片写屏工具](#简易图片写屏工具)
    - [环境配置](#环境配置)
    - [目录说明](#目录说明)
    - [使用步骤](#使用步骤)
    - [调用示例](#调用示例)
- [如何贡献](#如何贡献)
- [使用许可](#使用许可)

<!-- /code_chunk_output -->

## 背景

由于以前以为制作的图片写屏工具太过于潦草&没有含金量，所以之前并未计划将其完善并分享。后来发现（居然！）有同学尝试使用。由于配置过程太过复杂，因此将之前使用MATALB实现的部分使用python重写并完善。

顺便整理一下C课设代码，将其可能有用的地方整理出来。

## 安装

本项目配套API适用于基于Borland C++ 3.1的C语言课程设计。

- 简易图片写屏工具：python（with pillow包）、windows环境、Borland C++ 3.1

## 使用说明

### 简易图片写屏工具

本工具由python和windows环境编译出的exe文件实现，请确认使用环境。

此外，配合本工具的C代码仅支持win256色，请配合图片编辑工具将图片转变为win256的索引颜色模式（推荐使用PS，使用[win256色板](PhotoPixelTool/file/win.act)作为索引颜色）

#### 环境配置

本工具使用PIL库（python）用于读取图像。请先确认python环境是否安装pillow包。

#### 目录说明

本工具位于`PhotoPixelTool`目录下。

```text
PhotoPixelTool
├─file //需要使用的文件和C代码
│  │  win.act //win256色板，适用于PS
│  │
│  └─code //配套代码文件
│      │  icdr.cpp
│      │  icdr.h //配套使用的写屏C代码
│      │
│      ├─mouse //鼠标C代码
│      │
│      └─SVGA //SVGA图形驱动和配套代码
│              SVGA256.BGI
│              SVGA256.H
│              SVGAUTIL.cpp
│              SVGAUTIL.H
│
├─oldphoto //绘制的部分仿win图标（png格式）
│
└─work //工具工作目录
    │  readpng.py
    │  writepixel_bitfile.exe
    │
    ├─buffer //输出中间文件目录
    │
    ├─code // exe工具源代码
    │      writepixel_bitfile.c
    │
    ├─data //放置（仿色后的）原始图片
    │  └─old // 处理后图片目录
    │
    └─out //输出数据文件，可被配套API直接读取
```

#### 使用步骤

以下默认工作目录为`PhotoPixelTool/work`。

1. 将经过仿色处理后的图片文件置于`data`文件夹中（可以是多个文件）；
2. cmd（或conda命令行）运行`readpng.py`文件；
3. 图片解析成功后`out`文件夹中的输出即可使用[配套API](PhotoPixelTool/file/code/icdr.cpp)直接读取。

#### 调用示例

这里给出`PhotoPixelTool/file/code/icdr.cpp`文件中的部分API示例。详细说明可见[源文件](PhotoPixelTool/file/code/icdr.cpp)。

- SVGA初始化；

```cpp
#include"icdr.h"

int main(void)
{
    // 初始化变量

    // 初始化SGVA和win256色调色板
    initsvga256(); // 本函数已将图像模式加载、SVGA加载等封装，无需调用其他
    initcolor256(); // 本函数必须严格配套win256色色板使用

    // 关闭SGVA
    closesvga256();
}
```

- 读取py程序生成的数据文件，将其写到屏幕上
`void write_photodata(char *filename, int x, int y)`；

```cpp
void warningico_write(int x,int y)
{
    write_photodata("C:\\win_pro\\etc\\ico\\warning", x, y);
}
```

- 复制屏幕的一部分保存到文件and将文件中的图像写到屏幕上（需要一一对应）
`void record_imagedata(int x1, int x2, int y1, int y2, char *filename);`
`void write_imagedata(int x1, int x2, int y1, int y2, char *filename);`。

```cpp
void pop_properties\frac{struct My_filenode *theNode}//弹窗函数
{
    //……
    clrmous(MouseX, MouseY); // 防止复制到鼠标
    record_imagedata(328, 138, 696, 574, "c:\\win_pro\\etc\\data\\IMDATA_2");
    //……
    clrmous(MouseX, MouseY);
    write_imagedata(328, 138, 696, 574, "c:\\win_pro\\etc\\data\\IMDATA_2");
    //……
}
```

## 如何贡献

本项目的初衷在于希望能让深受C课设荼毒的AIA学子（若有其他同病相怜的人儿也一并计入吧）能更加方便地完成C课设。个人的力量是渺小的。欢迎任何人的加入！

提一个 Issue 或者提交一个 Pull Request。

## 使用许可

[MIT](LICENSE) © CodeCatMeow
