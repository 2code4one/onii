#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    float Price = 200;
    Price -= onii::percentage(10);      // Apply a sale
    std::cout << Price << std::endl;    // Print "180"

    return 0;
}
