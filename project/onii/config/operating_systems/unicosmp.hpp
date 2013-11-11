#ifndef ONII_CONFIG_OPERATING_SYSTEMS_UNICOSMP_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_UNICOSMP_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/unicosmp.hpp
/////////////////////////////////////////////////
#define ONII_OS_UNICOSMP 1
/////////////////////////////////////////////////
/// @def ONII_OS_UNICOSMP
/// @brief Defined if one of the following macro is defined: @code _CRAY __crayx1 @endcode
/////////////////////////////////////////////////
#undef ONII_OS_UNICOSMP
/////////////////////////////////////////////////

#if defined(_CRAY) || defined(__crayx1)
# define ONII_OS_UNICOSMP 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_UNICOSMP_HPP
