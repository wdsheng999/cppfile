
#include<iostream>
#include<string>
using namespace std;

void stringDiamond();
void Diamond();

int main()
{
    string s1=string("hi")+"there";
    // string s2="hi"+"there"; //c string cannot operand
    string str="CHRIS";
    stringDiamond(str);
    Diamond(str);
    return 0;

}


void stringDiamond(string str){
    
    int n=str.length();
    for(int i=0;i<n;i++){
        for (int j = 0; j <= i; j++)
        {
            cout<<str[j];
        }
        cout<<endl;
    }
    for(int x=0;x<n-1;x++)
    {
        for (int y = 0; y <=x; y++)
        {
            cout<<' ';
        }
        for (int z = x+1; z < n; z++)
        {
            cout<<str[z];
        }
        cout<<endl;
    }
}


void Diamond(string s){
    int len=(int) s.length();
    //print top half
    for(int i=1;i<=len;i++){
        cout<<s.substr(0,i)<<endl;
    }
    //print bottom half
    for(int i=1;i<len;i++){
        for(int j=0;j<i;j++){//indent
            cout<<" ";
        }
        cout<<s.substr(i,len-i)<<endl;
    }
}