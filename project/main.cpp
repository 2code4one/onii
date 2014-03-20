#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::ai::fuzzy::set::abstract_set const &set =
        onii::ai::fuzzy::hedge::very(
            onii::ai::fuzzy::set::triangle(1, 2, 3));

    for(float i = 0.f; i < 4.f; i += 0.1f)
        std::cout << "i = " << onii::round(i) << " -> "
            << onii::round(set.membership(i)) << std::endl;

    return 0;
}
