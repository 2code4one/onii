#include <iostream>
#include "onii/onii.hpp"

template<typename IntT>
void f()
{
    IntT t = 0;
    for(IntT i = 2; i < 1000 + 2; ++i)
        t += i * (i - 1);
    std::cout << std::hex << t << std::endl;
}

int main()
{
    onii::physic::unit::time t;

    {
        onii::scoped_timer timer(t);
        f<long long>();
    }
    std::cout << "long long: " << t.s() << "s" << std::endl;

    {
        onii::scoped_timer timer(t);
        f<onii::big_int>();
    }
    std::cout << "onii::big_int: " << t.s() << "s" << std::endl;

    return 0;
}
