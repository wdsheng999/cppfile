#include<iostream>
#include"console.h"
using namespace std;

int larger(int a,int b)
{
    if(a>b) return a;
    else return b;
}



int main(){
    int bigger1=larger(17,42);

    int bigger2=larger(29,-3);

    int bigger3=larger(bigger1,bigger2);

    cout<<"the biggest is "<<bigger3<<endl;

    return 0;
}
