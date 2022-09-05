#include<iostream>
using namespace std;

class B
{
	public:
	B(int i){}
	B(){}//如果没有使用初始化列表，则每个对象需要有一个default constructor
};


class A {
private:
	int i;
	int *p;
	B b;
public:
	// A() {p = 0; cout << "A::A()" << endl; }
	A():p(0){b=0;}
	~A() { if (p) delete p; cout << "A::~A(),i=" << i << endl; }//在析构的时候打印i的值

	void set(int i) { this->i = i; }//要让set的形参向class的成员变量传值，要么使用不同的名字
	void f() { cout << "hello<<endl"; }
	void g(A *q) { cout <<"A::g() ,q->i="<< q->i<<endl; }
};

int main() {
//	A a;
	A* p = new A[10];
	for (int i = 0; i < 10; i++) {
		p[i].set(i);
	}
	//delete p;
	//delete[] p;
	//a.f();
	A b;
	b.set(100);
	p[9].g(&b);
	delete[] p;
	return 0;
}