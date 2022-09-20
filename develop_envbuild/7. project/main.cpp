#include "Gun.h"
#include "solider.h"

void test()
{
    Solider sanduo("sd");
    sanduo.addGun(new Gun("AK47"));
    sanduo.addBulletToGun(20);
    sanduo.fire();
}

int main()
{
    int bug;
    test();
    return 0;
}