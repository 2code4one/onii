#ifndef ONII_CONFIG_OPERATING_SYSTEMS_MSDOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_MSDOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/msdos.hpp
/////////////////////////////////////////////////
#define ONII_OS_MSDOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_MSDOS
/// @brief Defined if one of the following macro is defined: @code MSDOS __MSDOS__ _MSDOS __DOS__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_MSDOS
/////////////////////////////////////////////////

#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
# define ONII_OS_MSDOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_MSDOS_HPP
