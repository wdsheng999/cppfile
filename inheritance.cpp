#include<iostream>
using namespace std;

class A{
    private: int i;//需要初始化
    public:
    A():i(0){cout<<"A::A()"<<endl;}
    ~A(){cout<<"A::~A()"<<endl;}
    void print(){cout<<"A::f"<<i<<endl;}
    protected:
    void set(int ii){i=ii;}
};

class B:public A{

};

class C:public B{
    public: void f(){set(20);print();}
};

class D:public A{
    public:
    void g(){
        set(20);
        i=30;//
        print();
    }
};

int main(){
    B b;
    b.set(10);//此时当set被开放可以直接使用
    
    b.print();
    cout<<"thisis C"<<endl;
    C c;
    c.f();//这时候c多了一次析构

    return  0;
}