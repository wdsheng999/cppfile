#include<string>
using namespace std;

class Student
{
private:
    /* data */
    string name;
public:
    Student(string s);
    ~Student();
};

Student::Student(string s)
{
    
}

Student::~Student()
{
}

//initailization before constructor
Student::Student(string s):name(s){}

//assignment
Student::Student(string s){name=s;}

//reusing
class Person{};
class Currency{};
class SavingAccount{
public:
    SavingAccount(const char* name,const char* address, int cents);
    ~SavingAccount();
    void print();
private:
    Person m_saver;
    Currency m_balance;//如果这个成员 是public 则可以从外部更改
};

//这里时初始化函数的真真定义,不去
SavingAccount::SavingAccount(
    const char*name, const char* address, int cents
):m_balance(),m_saver(){}//

void SavingAccount::print(){
    m_saver.print();
    m_balance.print();
}