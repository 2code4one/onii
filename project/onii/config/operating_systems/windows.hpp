#ifndef ONII_CONFIG_OPERATING_SYSTEMS_WINDOWS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_WINDOWS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/windows.hpp
/////////////////////////////////////////////////
#define ONII_OS_WINDOWS 1
/////////////////////////////////////////////////
/// @def ONII_OS_WINDOWS
/// @brief Defined if one of the following macro is defined: @code _WIN16 _WIN32 _WIN64 __WIN32__ __TOS_WIN__ __WINDOWS__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_WINDOWS
/////////////////////////////////////////////////

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
# define ONII_OS_WINDOWS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_WINDOWS_HPP
