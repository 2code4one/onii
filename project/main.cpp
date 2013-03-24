#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::core::any a(32);

    std::cout << a.is<int>() << std::endl;

    a.get<char>() = 'b';

    std::cout << a.get<char>() << std::endl;

    return 0;
}
