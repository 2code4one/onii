#ifndef ONII_CONFIG_OPERATING_SYSTEMS_OS2_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_OS2_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/os2.hpp
/////////////////////////////////////////////////
#define ONII_OS_OS2 1
/////////////////////////////////////////////////
/// @def ONII_OS_OS2
/// @brief Defined if one of the following macro is defined: @code OS2 _OS2 __OS2__ __TOS_OS2__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_OS2
/////////////////////////////////////////////////

#if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
# define ONII_OS_OS2 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_OS2_HPP
