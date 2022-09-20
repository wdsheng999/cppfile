#pragma once
#include <string>

class Gun
{
public:
    Gun(std::string type){
        this->_bullet_cnt=0;
        this->_type;
    }
    void addbullet(int bullet_num);
    bool shoot();
private:
    std::string _type;
    int _bullet_cnt;
};