#ifndef ONII_CONFIG_OPERATING_SYSTEMS_KFREEBSD_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_KFREEBSD_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/kfreebsd.hpp
/////////////////////////////////////////////////
#define ONII_OS_KFREEBSD 1
/////////////////////////////////////////////////
/// @def ONII_OS_KFREEBSD
/// @brief Defined if one of the following macro is defined: @code (__FreeBSD_kernel__ && __GLIBC__) @endcode
/////////////////////////////////////////////////
#undef ONII_OS_KFREEBSD
/////////////////////////////////////////////////

#if (defined(__FreeBSD_kernel__) && defined(__GLIBC__))
# define ONII_OS_KFREEBSD 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_KFREEBSD_HPP
