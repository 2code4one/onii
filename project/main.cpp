#include <iostream>

#include "onii/physic/unit.hpp"

#define PRINT_ANGLE(a)  \
    std::cout << "rad: " << a.radian() << " deg: " << a.degree() << std::endl

int main()
{
    PRINT_ANGLE(onii::physic::unit::angle::radian(onii::physic::unit::angle::pi / 6));
    PRINT_ANGLE((2 * onii::physic::unit::angle::degree(375)));

    return 0;
}
