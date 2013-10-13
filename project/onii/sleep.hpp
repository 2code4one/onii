#ifndef ONII_SLEEP_HPP
#define ONII_SLEEP_HPP

#include "physic/unit/time.hpp"
#include "config/operating_systems/windows.hpp"

#ifdef ONII_OS_WINDOWS
# include <windows.h>
#else
# include <unistd.h>
#endif

namespace onii
{
void sleep(physic::unit::time time)
{
    #ifdef ONII_OS_WINDOWS
        Sleep(time.ms());
    #else
        usleep(time.ms() * 1000);
    #endif
}
}

#endif // ONII_SLEEP_HPP
