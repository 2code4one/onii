#ifndef ONII_CONFIG_STANDARDS_XOPEN_HPP
#define ONII_CONFIG_STANDARDS_XOPEN_HPP

/////////////////////////////////////////////////
/// @file onii/config/standards/xopen.hpp
/////////////////////////////////////////////////
#define ONII_STD_XOPEN 1
/////////////////////////////////////////////////
/// @def ONII_STD_XOPEN
/// @brief Defined if one of the following macro is defined: @code _XOPEN_VERSION @endcode
/////////////////////////////////////////////////
#undef ONII_STD_XOPEN
/////////////////////////////////////////////////

#if defined(_XOPEN_VERSION)
# define ONII_STD_XOPEN 1
#endif

#endif // ONII_CONFIG_STANDARDS_XOPEN_HPP
