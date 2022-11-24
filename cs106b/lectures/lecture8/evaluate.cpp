#include <iostream>
#include <string>
#include <cmath>
#include"helplerfunc.h"
using namespace std;
int evaluate(string exp);

//----------helper func-----------

char getOperator(string str);
string getLeftExp(string str);
string getRightExp(string str);

int main()
{
    // string str;
    // cout << "input a numerical string" << endl;
    // while (cin >> str)
    // {
    //     evaluate(str); // exp = "((1*3)+(4*5)+2)"
    //     cout << "input a numerical string" << endl;
    // }
    cout<<"hello"<<endl;
    string str="39";
    string fake="nono";
    cout<<stringIsInteger(str)<<endl;
    int num=stringToInteger(str);
    cout<<num<<endl;
    cout<<stringIsInteger(fake)<<endl;
    return 0;
}
int evaluate(string exp)
{
    if (stringIsInteger(exp))
    {
        return stringToInteger(exp);
    }
    else
    {
        char op = getOperator(exp);
        string left = getLeftExp(exp);
        string right = getRightExp(exp);
        int leftRes = evaluate(left);
        int rightRes = evaluate(right);
        if (op == '+')
        {
            return leftRes + rightRes;
        }
        else if (op == '*')
        {
            return leftRes * rightRes;
        }
    }
}

//============helper func===============


int getOperatorIndex(string str)
{
    int parenthesis = 0;
    for (int i = 1; i < str.length(); i++)
    {
        // ignore the first coming paren
        char c = str[i];
        if (c == '(')
            parenthesis++;
        else if (c == ')')
            parenthesis--;

        if (parenthesis == 0 && (c == '+' || c == '*'))
        {
            return i;
        }
    }
}

char getOperator(string str){
    int index=getOperatorIndex(str);
    return str[index];
}

string getLeftExp(string str){

}