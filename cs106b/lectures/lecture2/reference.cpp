#include<iostream>
using namespace std;

void datingRange(int age, int &min, int &max)
{
    min=age/2+7;
    max=(age-7)*2;

}

int main()
{
    int young;
    int old;
    datingRange(32,young,old);
    cout<<"32 year-old could date between "\
    <<young<<" to "<<old<<" years old."<<endl;
    return 0;
}