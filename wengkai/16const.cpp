// #include<iostream>
// using namespace std;
#include<stdio.h>
int main(){
    //char *s="hello world";
    const char *s="safe hello world";

    // cout <<s<<endl;
    //s[0]='b';//骗过编译器
    // cout<<s<<endl;
       //数组的话 数组的等号和指针的等号不同,数组涉及到内存分配,是一个顺序分派
    //指针是简单的放置
    char a[]="safe hello world";
    printf("s=%p\n",s);
    printf("a=%p\n",a);
    printf("main=%p\n",main);
    return 0;
}