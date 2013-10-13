#include <iostream>
#include "onii/onii.hpp"

int main()
{
    ONII_THREAD_SAFE_BEGIN
        std::cout << "Thread safe IO" << std::endl;
    ONII_THREAD_SAFE_END

    return 0;
}
