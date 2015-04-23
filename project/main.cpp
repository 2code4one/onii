#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    for(size_t i = 0; i < 10; ++i)
        std::cout << onii::random<int>(100) << std::endl;

    return 0;
}
