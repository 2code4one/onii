#ifndef ONII_CONFIG_OPERATING_SYSTEMS_ZOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_ZOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/zos.hpp
/////////////////////////////////////////////////
#define ONII_OS_ZOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_ZOS
/// @brief Defined if one of the following macro is defined: @code __MVS__ __HOS_MVS__ __TOS_MVS__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_ZOS
/////////////////////////////////////////////////

#if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
# define ONII_OS_ZOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_ZOS_HPP
