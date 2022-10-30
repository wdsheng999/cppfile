#include<iostream>
using namespace std;

void grow_value(int age)
{
    age=age+1;
    cout<<"grow age is "<<age<<endl;
}
void grow_reference(int &age)
{
    age=age+1;
    cout<<"grow age is "<<age<<endl;
}

int main()
{
    int age=20;
    cout<<"main age is "<<age<<endl;
    grow_value(age);
    
    cout<<"main age is(value) "<<age<<endl;
    grow_reference(age);

    cout<<"main age is(reference) "<<age<<endl;
    return 0;
}
