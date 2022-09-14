#include<iostream>
using namespace std;

class A{
   public:
    int i;

    A():i(10){}
    virtual void f(){cout<<"A::f()"<<i<<endl;}
};

int main(){
    A a;
    a.f();
    cout<<sizeof(a)<<endl;
    int *p=(int*)&a;
    cout<<p<<endl;
    A b;
    int *q=(int*)&b;

    cout<<q<<endl;
    cout<<*p<<" "<<*q<<endl;
 //   p,q不一样,但是其指向的虚函数表是一样的
    //再看虚函数表内部的内容
    int* x=(int*)*p;
    cout<<x<<endl;
    return 0;
}