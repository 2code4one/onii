#ifndef ONII_SLEEP_HPP
#define ONII_SLEEP_HPP

/////////////////////////////////////////////////
/// @file onii/sleep.hpp
/////////////////////////////////////////////////

#include "unit/time.hpp"
#include "config/operating_systems/windows.hpp"

#ifdef ONII_OS_WINDOWS
# include <windows.h>
#else
# include <unistd.h>
#endif

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @brief Make the thread sleep for the given time
///
/// @param time - sleeping time
/////////////////////////////////////////////////
void sleep(unit::time time)
{
    #ifdef ONII_OS_WINDOWS
        Sleep(time.ms());
    #else
        usleep(time.ms() * 1000);
    #endif
}
}

#endif // ONII_SLEEP_HPP
