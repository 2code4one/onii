#ifndef ONII_CONFIG_OPERATING_SYSTEMS_UNIXWARE_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_UNIXWARE_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/unixware.hpp
/////////////////////////////////////////////////
#define ONII_OS_UNIXWARE 1
/////////////////////////////////////////////////
/// @def ONII_OS_UNIXWARE
/// @brief Defined if one of the following macro is defined: @code sco _UNIXWARE7 @endcode
/////////////////////////////////////////////////
#undef ONII_OS_UNIXWARE
/////////////////////////////////////////////////

#if defined(sco) || defined(_UNIXWARE7)
# define ONII_OS_UNIXWARE 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_UNIXWARE_HPP
