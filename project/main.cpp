#include <cassert>
#include <iostream>
#include "onii/onii.hpp"

int main()
{
    onii::ai::fuzzy::variable flv("distance");
    flv("proche", onii::ai::fuzzy::set::left_shoulder(0, 1, 2));
    flv("moyen", onii::ai::fuzzy::set::triangle(1, 2, 3));
    flv("loin", onii::ai::fuzzy::set::right_shoulder(2, 3, 4));

    onii::ai::fuzzy::manifold m = flv(2.1);

    std::cout << m.variable() << " "
              << m.set("proche") << " "
              << m.set("moyen") << " "
              << m.set("loin") << std::endl;

    return 0;
}
