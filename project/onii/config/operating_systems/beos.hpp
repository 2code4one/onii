#ifndef ONII_CONFIG_OPERATING_SYSTEMS_BEOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_BEOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/beos.hpp
/////////////////////////////////////////////////
#define ONII_OS_BEOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_BEOS
/// @brief Defined if one of the following macro is defined: @code __BEOS__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_BEOS
/////////////////////////////////////////////////

#if defined(__BEOS__)
# define ONII_OS_BEOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_BEOS_HPP
