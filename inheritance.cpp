#include<iostream>
using namespace std;

class A{
    private: int i;//需要初始化
    public:
    //A():i(0){cout<<"A::A()"<<endl;}
    A(int ii):i(ii){cout<<"A::A()"<<endl;}//此时 没有默认的构造函数出错
    ~A(){cout<<"A::~A()"<<endl;}
    void print(){cout<<"A::print()"<<i<<endl;}
    void print(int i){cout<<i<<endl;print();}
    protected:
    void set(int ii){i=ii;}
    //friend class D;
};

class B:public A{
public://initialization list for A, notice the order, parent class first
    B():A(15){cout<<"B::B()"<<endl;}//注意 一定要放public
    ~B(){cout<<"B::~B()"<<endl;}
    void print(){cout<<"B::print()"<<endl;}
};

class C:public B{
    public: void f(){set(20);print();}
};

class D:public A{
    public:
    void g(){
        set(20);
        //i=30;//
        print();
    }
};

int main(){
    B b;
    //b.set(10);//此时当set被开放可以直接使用
    
    b.print();
    //cout<<"thisis C"<<endl;
    //C c;
    //c.f();//这时候c多了一次析构
    b.A::print(200);
    return  0;
}