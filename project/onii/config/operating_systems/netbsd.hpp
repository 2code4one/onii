#ifndef ONII_CONFIG_OPERATING_SYSTEMS_NETBSD_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_NETBSD_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/netbsd.hpp
/////////////////////////////////////////////////
#define ONII_OS_NETBSD 1
/////////////////////////////////////////////////
/// @def ONII_OS_NETBSD
/// @brief Defined if one of the following macro is defined: @code __NetBSD__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_NETBSD
/////////////////////////////////////////////////

#if defined(__NetBSD__)
# define ONII_OS_NETBSD 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_NETBSD_HPP
