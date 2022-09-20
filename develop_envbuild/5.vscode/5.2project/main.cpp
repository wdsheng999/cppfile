#include"swap.h"

int main()
{
    swap Myswap(15,26);
    Myswap.printInfo();
    Myswap.run();
    std::cout<<"after swap"<<std::endl;
    Myswap.printInfo();

    
    return 0;
}