#include <iostream>
#include "onii/onii.hpp"

int main()
{
    int s = 8;
    onii::big_int n(s, false);
    for(int i = -s; i < s; ++i)
        onii::big_int t = (++n).hex();

    std::cout << std::endl;
    onii::big_int ui("FFFFFFFFFFFFFFFF"); // uint64_t maximum
    onii::big_int bi("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"); // double !

    std::cout << std::endl;
    onii::big_int a(2), b(3);
    std::cout << "^ " << (a ^ b) << std::endl;
    std::cout << "& " << (a & b) << std::endl;
    std::cout << "| " << (a | b) << std::endl;

    return 0;
}
