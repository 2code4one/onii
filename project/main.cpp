#include <iostream>
#include "onii/onii.hpp"

int main()
{
    std::cout << onii::big_number::lcm(0x3, 0x6) << std::endl;
    std::cout << onii::big_number::lcm(0x2, 0x6) << std::endl;
    std::cout << onii::big_number::lcm(0x9, 0x3) << std::endl;
    std::cout << onii::big_number::lcm(0x3, 0x4) << std::endl;

    return 0;
}
