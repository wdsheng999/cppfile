#include<vector>
#include<iostream>
using namespace std;

bool part(vector<int> rest, int sum1, int sum2)
{
    if(rest.empty()){
        return sum1==sum2;  //base case
    }else{
        int n=rest[0];
        rest.erase(rest.begin());
        bool answer=part(rest, sum1+n,sum2)||part(rest,sum1,sum2+n);
        rest.insert(rest.begin(),n);   //value restoration
        return answer;
    }
}

bool part(vector<int>& numstring)
{
    return part(numstring, 0, 0);//no sums yet
}

int main(){
    vector<int> string;
    int num[]={1,1,2,3,5};
    string.assign(num,num+5);
    cout<<"origin string is:";
    for(vector<int>::iterator it=string.begin();it!=string.end();it++){
        cout<<' '<<*it;
        
    }cout<<endl;
    cout<<"partitionable or not: "<<part(string)<<endl;
    
    return 0;
}