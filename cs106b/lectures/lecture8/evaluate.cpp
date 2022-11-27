#include "helplerfunc.h"

int main()
{
    string str;
    int res=0;
    do
    {
        cout << "welcome to calculation, please input you string" << endl;
        getline(cin,str);
        res=evaluate(str);
        cout<<"the result is:"<<res<<endl;

    }while(str!="exit");
    

    return 0;
}