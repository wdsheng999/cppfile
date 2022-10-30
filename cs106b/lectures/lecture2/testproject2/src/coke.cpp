#include<iostream>
#include"console.h"
using namespace std;

const string DRINK_TYPE = "coke";

void bottles(int count){
    cout<<count<<"bottles of "<<DRINK_TYPE<<"."<<endl;
    cout<<"take one down, pass it around" \
       <<(count-1)<<"bottles of"<< DRINK_TYPE\
      <<"on the wall."<<endl<<endl;

}

int main(){
    for (int i=99;i>0;i--){
        bottles(i);
    }
    return 0;
}
