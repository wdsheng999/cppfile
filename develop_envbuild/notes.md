# 使用vscode开发c/cpp环境linux配置教程
## 第一章 linux篇
- 目录结构
  bin 可以运行的文件 dev 外设 home 家文件 etc 存储一些配置文件 proc 进程运行时的 root 管理员的家目录 
  sbin  tmp临时 usr unix system resource var系统/程序的日志 mnt外设挂载

## 第二章 开发环境搭建
- 安装gcc gdb
  ```
    sudo apt update
    # 通过以下命令安装编译器和调试器
    sudo apt install build-essential gdb
    ```
- 安装成功确认
    ```
    gcc --version
    g++ --version
    gdb --version
    ```
- CMake安装
    ``sudo apt install cmake``
    ``cmake --version``
## 第三章 gcc编译器
支持范围
>前言：
    1. GCC 编译器支持编译 Go、Objective-C，Objective-C ++，Fortran，Ada，D 和 BRIG（HSAIL）
    等程序；
    2. Linux 开发C/C++ 一定要熟悉 GCC
    3. VSCode是通过调用GCC编译器来实现C/C++的编译工作的；
- 过程
>
1. 预处理-Pre-Processing //.i文件
```
# -E 选项指示编译器仅对输入文件进行预处理
g++-E test.cpp -o test.i //.i文件
```
2. 编译-Compiling // .s文件
```
# -S 编译选项告诉 g++ 在为 C++ 代码产生了汇编语言文件后停止编译
#g++产生的汇编语言文件的缺省扩展名是 .s
g++ -S test.i -o test.s
```
3. 汇编-Assembling // .o文件
```
# -c 选项告诉 g++ 仅把源代码编译为机器语言的目标代码
# 缺省时 g++ 建立的目标代码文件有一个 .o 的扩展名。
g++ -c test.s-o test.o
```
4. 链接-Linking // bin文件
```
# -o 编译选项来为将产生的可执行文件用指定的文件名
g++ test.o -o test
```
- 编译重要参数
-g 带调试信息的可执行文件
-O 优化源代码 -O0不优化 1为默认优化 2指令调整 3包括循环展开等优化 
带-O编译速度变慢 但文件运行会便快
-l -L 指定库 制定库路径 
指定库时 需要在/lib /usr/lib /usr/local/lib三个文件夹内
    ```
    # 链接glog库
    g++ -lglog test.cpp
    ```
    通过-L指定目录
    ```
    # 链接mytest库，libmytest.so在/home/bing/mytestlibfolder目录下
    g++ -L/home/bing/mytestlibfolder -lmytest test.cpp
    ```
  -I 指定头文件搜索目录
  如果头文件不再/usr/include目录下,就需要加上头文件的位置 紧跟在-I后
  ``g++ -I/myinclude test.cpp``
  -Wall 打印警告信息
  ``g++ -Wall test.cpp``
  -w 关闭警告信息
  -std=c++11 设置编译标准 使用c++11编译
  -o 输出文件名
  -D定义宏
  常用于-DDEBUG 在测试代码中如果出现啦``#ifdef DEBUG``此时会被执行
- 实战
在 3.gccbuild文件夹中存在的结构
    ```
    1# 最初目录结构
        
    3├── include
    4│
    5├── main.cpp
    6└── src
        └── Swap.h
        └── Swap.cpp
    8
    9
    2 directories, 3 files
    ```
方法1.直接编译


## 第四章 odb调试器

## 第五章 VSCode IDE

## 第六章 CMake  

## 第七章 实战 利用vscode进行完整开发