#ifndef ONII_CONFIG_OPERATING_SYSTEMS_AMIGAOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_AMIGAOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/amigaos.hpp
/////////////////////////////////////////////////
#define ONII_OS_AMIGA 1
/////////////////////////////////////////////////
/// @def ONII_OS_AMIGA
/// @brief Defined if one of the following macro is defined: @code AMIGA __amigaos__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_AMIGA
/////////////////////////////////////////////////

#if defined(AMIGA) || defined(__amigaos__)
# define ONII_OS_AMIGA 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_AMIGAOS_HPP
