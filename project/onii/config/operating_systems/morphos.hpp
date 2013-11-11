#ifndef ONII_CONFIG_OPERATING_SYSTEMS_MORPHOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_MORPHOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/morphos.hpp
/////////////////////////////////////////////////
#define ONII_OS_MORPHOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_MORPHOS
/// @brief Defined if one of the following macro is defined: @code __MORPHOS__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_MORPHOS
/////////////////////////////////////////////////

#if defined(__MORPHOS__)
# define ONII_OS_MORPHOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_MORPHOS_HPP
