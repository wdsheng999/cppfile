#include "Gun.h"
#include<iostream>
using namespace std;
void Gun::addbullet(int bullet_num)
{
    this->_bullet_cnt=bullet_num;
}

bool Gun::shoot()
{
    if(_bullet_cnt<=0)
    {
        cout<<"no bullet"<<endl;
        return false;
    }
    this->_bullet_cnt-=1;
    cout<<"shooting a bullet"<<endl;
    return true;

}