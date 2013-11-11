#ifndef ONII_CONFIG_OPERATING_SYSTEMS_HPUX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_HPUX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/hpux.hpp
/////////////////////////////////////////////////
#define ONII_OS_HPUX 1
/////////////////////////////////////////////////
/// @def ONII_OS_HPUX
/// @brief Defined if one of the following macro is defined: @code _hpux hpux __hpux @endcode
/////////////////////////////////////////////////
#undef ONII_OS_HPUX
/////////////////////////////////////////////////

#if defined(_hpux) || defined(hpux) || defined(__hpux)
# define ONII_OS_HPUX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_HPUX_HPP
