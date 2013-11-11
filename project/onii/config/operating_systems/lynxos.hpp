#ifndef ONII_CONFIG_OPERATING_SYSTEMS_LYNXOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_LYNXOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/lynxos.hpp
/////////////////////////////////////////////////
#define ONII_OS_LYNX 1
/////////////////////////////////////////////////
/// @def ONII_OS_LYNX
/// @brief Defined if one of the following macro is defined: @code __Lynx__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_LYNX
/////////////////////////////////////////////////

#if defined(__Lynx__)
# define ONII_OS_LYNX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_LYNXOS_HPP
