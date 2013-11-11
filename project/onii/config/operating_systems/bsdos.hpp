#ifndef ONII_CONFIG_OPERATING_SYSTEMS_BSDOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_BSDOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/bsdos.hpp
/////////////////////////////////////////////////
#define ONII_OS_BSDOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_BSDOS
/// @brief Defined if one of the following macro is defined: @code __bsdi__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_BSDOS
/////////////////////////////////////////////////

#if defined(__bsdi__)
# define ONII_OS_BSDOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_BSDOS_HPP
