#include <iostream>
#include "onii/onii.hpp"

int main()
{
    for(onii::big_int i = -0x10; i <= 0x10; i -= -1)
        std::cout << i << std::endl;

    return 0;
}
