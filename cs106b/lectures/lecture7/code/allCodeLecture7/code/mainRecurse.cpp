// To compile:
// gcc -g mainRecurse.cpp -o mainRecurse
//
// To run:
// ./mainRecurse
//
// goal1 创建单词排除集
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define small_test

#ifdef exclusion
set<string> exclusion_set;
#endif
// small test
#ifdef small_test
set<int> int_set;
set<bool> bool_set;
set<double> double_set;
#endif

void print(set<int> const &s)
{
    for (auto const &i : s)
    {
        std::cout << i << " ";
    }
}
void print_bool(set<bool> const &s)
{
    for (auto const &i : s)
    {
        std::cout << i << " ";
    }
}
void print_double(set<double> const &s)
{
    for (auto const &i : s)
    {
        std::cout << i << " ";
    }
}
int main()
{
    // exclusion_set.insert("the");
    for (int i = -5; i < 5; i++)
    {
        int_set.insert(i);
        if (i % 2 == 0)
            bool_set.insert(true);
        else
            bool_set.insert(false);
        double_set.insert((double)i);
        
    }
    print(int_set);
    cout<<endl;
    print_bool(bool_set);
    cout<<endl;

    print_double(double_set);
    return 0;
}
