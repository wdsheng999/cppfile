#include<iostream>
using namespace std;
class A{
    public:
    int i;
    A():i(10){}
};

class B: public A{
    private:
    int j;
    public:
    B():j(30){}
    void f(){cout<<"B.j="<<j<<endl;}
};

int main(){
    A a;
    B b;
    cout<<a.i<<" "<<b.i<<endl;
    cout<<sizeof(a)<<" "<<sizeof(b)<<endl;
    int*p=(int*)&a;//取出地址之后就可以操作了

    cout<<p<<" "<<*p<<endl;

    p=(int*)&b;//整数类型指针 b的地址
    *p=20;
    cout<<p<<" "<<*p<<endl;
    //*p就是取了内容,既然有地址了,则可以赋值
    //此时即便出现了private, 仍然可以改
    p++;//指向了下一个内容, 由于class就是struct 可以得值是另一个参数
    *p=50;
    b.f();
    return 0;
}