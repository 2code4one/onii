#include <iostream>
#include <cassert>
#include "onii/onii.hpp"

int main()
{
    assert(
        60
            >=
        onii::physic::unit::time::s(60)
    );

    return 0;
}
