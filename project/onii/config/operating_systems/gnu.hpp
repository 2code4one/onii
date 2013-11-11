#ifndef ONII_CONFIG_OPERATING_SYSTEMS_GNU_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_GNU_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/gnu.hpp
/////////////////////////////////////////////////
#define ONII_OS_GNU 1
/////////////////////////////////////////////////
/// @def ONII_OS_GNU
/// @brief Defined if one of the following macro is defined: @code __GNU__ __gnu_hurd__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_GNU
/////////////////////////////////////////////////

#if defined(__GNU__) || defined(__gnu_hurd__)
# define ONII_OS_GNU 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_GNU_HPP
