#include <iostream>
#include <cassert>
#include "onii/onii.hpp"

int main()
{
    assert(
        onii::physic::unit::time::min(1.1)
            >=
        onii::physic::unit::time::s(60)
    );

    return 0;
}
