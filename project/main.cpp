#include <iostream>
#include "onii/onii.hpp"

int main()
{
    int s = 16;
    onii::big_int n(s, false);
    for(int i = -s; i < s; ++i)
        onii::big_int t = (++n).hex();

    std::cout << std::endl;
    onii::big_int ui("FFFFFFFFFFFFFFFF"); // uint64_t maximum
    onii::big_int bi("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"); // double !

    return 0;
}
