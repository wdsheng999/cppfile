#include<iostream>
#include<cmath>
using namespace std;

bool stringIsInteger(string str){
    for (auto i : str){
        int offset=i-'0';
        if(offset>=0 && offset<=9){
            continue;
        }else{
            return false;
            break;
        }
    }
    return true;
}

int stringToInteger(string str){
    int res=0;
    int count =0;    
    for (int i=str.length()-1;i>=0;i--){        
        int offset=str[i]-'0';
        if(offset>=0 && offset<=9){
            res+=offset*pow(10,count);
        }
        count++;
    }
    return res;
}

// int main(){
//     cout<<"hello"<<endl;
//     string str="39";
//     string fake="nono";
//     cout<<stringIsInteger(str)<<endl;
//     int num=stringToInteger(str);
//     cout<<num<<endl;
//     cout<<stringIsInteger(fake)<<endl;
//     return 0;
// }