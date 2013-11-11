#ifndef ONII_CONFIG_STANDARDS_POSIX_HPP
#define ONII_CONFIG_STANDARDS_POSIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/standards/posix.hpp
/////////////////////////////////////////////////
#define ONII_STD_POSIX 1
/////////////////////////////////////////////////
/// @def ONII_STD_POSIX
/// @brief Defined if one of the following macro is defined: @code _POSIX_VERSION _POSIX2_C_VERSION @endcode
/////////////////////////////////////////////////
#undef ONII_STD_POSIX
/////////////////////////////////////////////////

#if defined(_POSIX_VERSION) || defined(_POSIX2_C_VERSION)
# define ONII_STD_POSIX 1
#endif

#endif // ONII_CONFIG_STANDARDS_POSIX_HPP
