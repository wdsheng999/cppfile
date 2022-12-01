#include <iostream>
#include <string>

using namespace std;

long factorial(long n)
{
    if (n == 1)
    {
        return n;
    }
    else
    {
        return n * factorial(n - 1);
    }
}



int main()
{
    int n;
    while (1)
    {
        cin >> n;
        cout << "res:" << factorial(n) << endl;
    }

    return 0;
}