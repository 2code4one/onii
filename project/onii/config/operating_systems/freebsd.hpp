#ifndef ONII_CONFIG_OPERATING_SYSTEMS_FREEBSD_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_FREEBSD_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/freebsd.hpp
/////////////////////////////////////////////////
#define ONII_OS_FREEBSD 1
/////////////////////////////////////////////////
/// @def ONII_OS_FREEBSD
/// @brief Defined if one of the following macro is defined: @code __FreeBSD__ __FreeBSD_kernel__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_FREEBSD
/////////////////////////////////////////////////

#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
# define ONII_OS_FREEBSD 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_FREEBSD_HPP
