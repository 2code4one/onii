#ifndef ONII_CONFIG_OPERATING_SYSTEMS_OPENBSD_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_OPENBSD_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/openbsd.hpp
/////////////////////////////////////////////////
#define ONII_OS_OPENBSD 1
/////////////////////////////////////////////////
/// @def ONII_OS_OPENBSD
/// @brief Defined if one of the following macro is defined: @code __OpenBSD__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_OPENBSD
/////////////////////////////////////////////////

#if defined(__OpenBSD__)
# define ONII_OS_OPENBSD 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_OPENBSD_HPP
