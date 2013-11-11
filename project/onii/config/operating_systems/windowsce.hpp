#ifndef ONII_CONFIG_OPERATING_SYSTEMS_WINDOWSCE_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_WINDOWSCE_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/windowsce.hpp
/////////////////////////////////////////////////
#define ONII_OS_WINDOWSCE 1
/////////////////////////////////////////////////
/// @def ONII_OS_WINDOWSCE
/// @brief Defined if one of the following macro is defined: @code _WIN32_WCE @endcode
/////////////////////////////////////////////////
#undef ONII_OS_WINDOWSCE
/////////////////////////////////////////////////

#if defined(_WIN32_WCE)
# define ONII_OS_WINDOWSCE 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_WINDOWSCE_HPP
