#include<iostream>
using namespace std;
class A{
    int i;
    public:
    A():i(0){}
    void f(){cout<<"f()"<<endl;}
    void f()const{cout<<"f()const"<<endl;}
};
int main(){
    const A a;
    a.f();
    return 0;
}