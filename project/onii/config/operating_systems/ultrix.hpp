#ifndef ONII_CONFIG_OPERATING_SYSTEMS_ULTRIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_ULTRIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/ultrix.hpp
/////////////////////////////////////////////////
#define ONII_OS_ULTRIX 1
/////////////////////////////////////////////////
/// @def ONII_OS_ULTRIX
/// @brief Defined if one of the following macro is defined: @code ultrix __ultrix __ultrix__ (unix && vax) @endcode
/////////////////////////////////////////////////
#undef ONII_OS_ULTRIX
/////////////////////////////////////////////////

#if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
# define ONII_OS_ULTRIX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_ULTRIX_HPP
