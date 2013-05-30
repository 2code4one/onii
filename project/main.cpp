#include <iostream>
#include "onii/onii.hpp"

int main()
{
    for(int i = 0; i < 10; ++i)
    {
        std::cout << onii::core::random<float>() << std::endl;
        onii::core::sleep(0.1f);
    }

    return 0;
}
