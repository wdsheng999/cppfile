#include<string>
#include<iostream>
using namespace std;

class Point
{
private:
    /* data */
    int i,j,k;
public:
    Point(/* args */){i=j=k=0;};
    Point(int ii, int jj, int kk){i=ii;j=jj;k=kk;}
    void print(string msg){
        if (msg.size()!=0)
        {
            /* code */
            cout<<msg<<endl;
            cout<<"i="<<i<<","
                <<"j="<<j<<","
                <<"k="<<k<<endl;
        }
    }
    ~Point(){};
};

// Point::Point(/* args */)
// {
// }

// Point::~Point()
// {
// }

int main(){
    Point p, q(1,2,3);
    p.print("value of p");
    q.print("value of q");
}