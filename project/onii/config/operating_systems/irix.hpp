#ifndef ONII_CONFIG_OPERATING_SYSTEMS_IRIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_IRIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/irix.hpp
/////////////////////////////////////////////////
#define ONII_OS_IRIX 1
/////////////////////////////////////////////////
/// @def ONII_OS_IRIX
/// @brief Defined if one of the following macro is defined: @code sgi __sgi @endcode
/////////////////////////////////////////////////
#undef ONII_OS_IRIX
/////////////////////////////////////////////////

#if defined(sgi) || defined(__sgi)
# define ONII_OS_IRIX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_IRIX_HPP
