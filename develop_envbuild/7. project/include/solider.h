#pragma once

#include <string.h>
#include "Gun.h"
class Solider
{
private:
    std::string _name;
    Gun *_ptr_gun;

public:
    Solider(std::string name);
    void addBulletToGun(int num);
    void addGun(Gun *_ptr_gun);
    bool fire();
    ~Solider();//因为用指针所以, 但这个系够函数写的有问题
};