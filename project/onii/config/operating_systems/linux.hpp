#ifndef ONII_CONFIG_OPERATING_SYSTEMS_LINUX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_LINUX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/linux.hpp
/////////////////////////////////////////////////
#define ONII_OS_LINUX 1
/////////////////////////////////////////////////
/// @def ONII_OS_LINUX
/// @brief Defined if one of the following macro is defined: @code __gnu_linux__ __linux__ linux __linux @endcode
/////////////////////////////////////////////////
#undef ONII_OS_LINUX
/////////////////////////////////////////////////

#if defined(__gnu_linux__) || defined(__linux__) || defined(linux) || defined(__linux)
# define ONII_OS_LINUX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_LINUX_HPP
