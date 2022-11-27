#include "helplerfunc.h"

//also deal with multiple parens
string deParens(string str)
{
    while (str[0] == '(' && str[str.length() - 1] == ')')
    {
        str = str.substr(1, str.length() - 2);
        //str=deParens(str);
    }
        return str;//base
}
//(39) is also a number 
bool stringIsInteger(string str)
{
    str=deParens(str);
    for (auto i : str)
    {
        int offset = i - '0';
        if (offset >= 0 && offset <= 9)
        {
            continue;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}
//(39)==39
int stringToInteger(string str)
{
    str=deParens(str);
    int res = 0;
    int count = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        int offset = str[i] - '0';
        if (offset >= 0 && offset <= 9)
        {
            res += offset * pow(10, count);
        }
        count++;
    }
    return res;
}

int getOppIndex(string str)
{
    //str=deParens(str);
    int parens = 0;
    // ignore first left paren
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == '(')
        {
            parens++;
        }
        else if (c == ')')
        {
            parens--;
        }
        if (parens == 0 && (c == '+' || c == '*'))
        {
            return i;
        }
    }
    return 0;
}

char getOperator(string str)
{
    int index = getOppIndex(str);
    return str[index];
}

string getLeft(string str)
{
    str=deParens(str);

    return str.substr(0, getOppIndex(str) );

}
string getRight(string str)
{
    str=deParens(str);
    int index = getOppIndex(str);
    str=str.substr(1 + index, str.length() - index );

    return str;
}

int evaluate(string str)
{
    str=deParens(str);
    if (stringIsInteger(str))
    {
        return stringToInteger(str);
    }
    else
    {
        char op = getOperator(str);
        string left = getLeft(str);
        string right = getRight(str);
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

int main()
{
    cout << "hello" << endl;
    string str = "((1*3)+(4*5)+2)";
    string fake = "(15*9+(5+(9*6)))";
    // cout << "(39) is 39:" << stringIsInteger("(39)") << endl;

    // string depare;
    // depare=deParens("((39))");

    // cout<<depare<<endl;

    // cout<<"((39))=="<<stringToInteger("((39))")<<endl;

    // cout << "(4*5):" << evaluate("(4*5)") << endl;

    cout << "dddddddddddddddddd" << endl;

    //cout<<evaluate("(8+(1*8))")<<endl;
    cout<<evaluate(fake)<<endl;

    return 0;
}