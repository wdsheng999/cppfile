#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    while(1)
    {
        cout<<"input a bracket string"<<endl;
        string str;
        cin>>str;
        stack<char> s;
        
        for(char ch:str){
            if (ch=='{'||'['||'(')
            {
                s.push(ch);
            }
            else if(ch=='}'||']'||')')
            {
                s.pop();
            }
        }

        if(s.empty()) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    

}