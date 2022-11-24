#include<iostream>
#include<string>
using namespace std;
int evaluate(string exp);

//----------helper func-----------
bool stringIsInteger(string str);
int stringToInteger(string str);
char getOperator(string str);
string getLeftExp(string str);
string getRightExp(string str);


int main(){
    string str;
    cout<<"input a numerical string"<<endl;
    while (cin>>str)
    {
        evaluate(str);
        cout<<"input a numerical string"<<endl;
    }
    
    
}
int evaluate(string exp){
    if(stringIsInteger(exp)){
        return stringToInteger(exp);
    }else{
        char op=getOperator(exp);
        string left=getLeftExp(exp);
        string right=getRightExp(exp);
        int leftRes=evaluate(left);
        int rightRes=evaluate(right);
        if(op=='+'){
            return leftRes+rightRes;
        }else if(op=='*'){
            return leftRes*rightRes;
        }
    }

}
