#include <iostream>

#include "onii/onii.hpp"

#define PRINT(o)  \
    std::cout << #o << " -> " << o << std::endl

#define PRINT_ANGLE(a)  \
    PRINT("");  \
    PRINT((a).rad());  \
    PRINT((a).deg())

#define PRINT_LENGTH(l)  \
    PRINT("");  \
    PRINT((l).mm());  \
    PRINT((l).cm());  \
    PRINT((l).m());  \
    PRINT((l).km())

#define PRINT_MASS(m)  \
    PRINT("");  \
    PRINT((m).g());  \
    PRINT((m).kg());  \
    PRINT((m).t())

#define PRINT_TIME(t)  \
    PRINT("");  \
    PRINT((t).ms());  \
    PRINT((t).s());  \
    PRINT((t).min())

int main()
{
    using namespace onii::physic::unit;

    PRINT_ANGLE(angle::rad(angle::pi / 6));
    PRINT_ANGLE(2 * angle::deg(375));

    PRINT_LENGTH(length::m(1) + length::cm(10));
    PRINT_LENGTH(2 * length::km(1));

    PRINT_MASS(mass::kg(1) + mass::g(100));
    PRINT_MASS(2 * mass::t(1));

    PRINT_TIME(time::s(1) - time::ms(10));
    PRINT_TIME(2 * time::min(1));

    return 0;
}
