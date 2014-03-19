#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::ai::fuzzy::set::abstract_set const &set =
        onii::ai::fuzzy::set::rectangle(2, 3)
        && !onii::ai::fuzzy::set::triangle(1, 2, 4);

    for(float i = 0.f; i < 4.f; i += 0.5f)
        std::cout << "i = " << onii::round(i) << " -> "
            << onii::round(set.membership(i)) << std::endl;

    return 0;
}
