#ifndef ONII_CONFIG_OPERATING_SYSTEMS_AIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_AIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/aix.hpp
/////////////////////////////////////////////////
#define ONII_OS_AIX 1
/////////////////////////////////////////////////
/// @def ONII_OS_AIX
/// @brief Defined if one of the following macro is defined: @code _AIX __TOS_AIX__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_AIX
/////////////////////////////////////////////////

#if defined(_AIX) || defined(__TOS_AIX__)
# define ONII_OS_AIX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_AIX_HPP
