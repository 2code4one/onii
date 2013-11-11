#include <iostream>
#include "onii/onii.hpp"

#define TEST(type, str)  \
    {  \
        type tmp = onii::sto<type>(str);  \
        std::cout << tmp << std::endl;  \
    }

int main()
{
    TEST(int, "1")
    TEST(long, "2")
    TEST(long long, "-3")
    TEST(unsigned long, "-4")
    TEST(unsigned long long, "5.2")
    TEST(float, "6.4")
    TEST(double, "7.3")
    TEST(long double, "8.2")

    return 0;
}
