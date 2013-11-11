#ifndef ONII_CONFIG_OPERATING_SYSTEMS_MINIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_MINIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/minix.hpp
/////////////////////////////////////////////////
#define ONII_OS_MINIX 1
/////////////////////////////////////////////////
/// @def ONII_OS_MINIX
/// @brief Defined if one of the following macro is defined: @code __minix @endcode
/////////////////////////////////////////////////
#undef ONII_OS_MINIX
/////////////////////////////////////////////////

#if defined(__minix)
# define ONII_OS_MINIX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_MINIX_HPP
