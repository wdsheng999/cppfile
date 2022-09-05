# 笔记
1. cpp的程序在编译的过程中都会被翻译成c，其中的程序名会被加上下划线 structure和class都可以定义类
2. declaration definition 在编译的过程中，一个cpp文件是一个编译的单元，每次以一个单元为核心进行编译，于是当重复的定义发生时候会报错， 未声明的定义会报错。
```
#ifndef _name_h
#define _name_h
...
#endif
```
3. 声明在.h文件中进行包括：
   1. extern variables
   2. function prototypes
   3. class/struct decalration
4. 从对象的角度看问题 就是从内容的角度 以时钟程序为例
   11：03 前两位和后两位 并且有一定的相似
   >mydisplay:ClockDisplay-->NumberDisplay11 NumberDisplay03


5. 成员变量 local本地变量，存在在函数里。在成员函数里 命名相同的变量以本地变量为准。由于成员变量写在类的声明里，成员变量的位置：成员变量不在类里面，在类中进行了声明，但是在构造时候赋值，此时在main函数中的对象里，出现了成员变量。
   但函数是属于类的，不属于对象。
   this的作用 this是一个指针 ``printf("this=%p\n",this)``所有的成员变量前面都有一个this->
6. 构造和析构 C++与java不同，java在添加成员的时候会将对象初始化，c++要自己写
   constuctor 名字和类的名称相同，没有返回值，会在对象创建的时候自动运行 可以传参数
   析构函数 ~类的名字 没有参数
7. 对象初始化 default constructor 没有缺省参数的就是 初始化的错误， 
8. new and delete new用来制造一个对象 类似于c的malloc free 
   delete p; delete[] p; new带括号 则delete带
   动态申请空间 int * psome=new int [10]; delete[] psome;
   在申请的空间较小的时候 并不涉及操作系统。
   new的时候 表上记录 地址 大小。所以不要用delete释放不是new的。
   但delete null是安全的
   当int *a=new int[10]; a++; delete[] a;这时候会找不到a
   new了不delete 内存泄漏。
9. 访问限制 private和public protected自己和子孙
    同一个类的对象中间可以访问私有的变量 private的检查只限于编译时刻。在运行的时候，可以访问私有的。他的.o完全丧失了cpp的特性，只要有办法。只是对类的
    友元friends 让可以访问私有 在**运算符的重载**有用
    在**class**中， 缺省的访问属性就是**private** **struct**则为**public**
    