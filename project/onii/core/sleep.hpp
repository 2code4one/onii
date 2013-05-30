#ifndef ONII_CORE_SLEEP_HPP
#define ONII_CORE_SLEEP_HPP

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "../physic/unit/time.hpp"

namespace onii
{
namespace core
{
void sleep(physic::unit::time time)
{
    #ifdef _WIN32
        Sleep(time.ms());
    #else
        usleep(time.ms() * 1000);
    #endif
}
}
}

#endif // ONII_CORE_SLEEP_HPP
