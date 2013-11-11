#ifndef ONII_CONFIG_ENVIRONMENTS_CYGWIN_HPP
#define ONII_CONFIG_ENVIRONMENTS_CYGWIN_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/cygwin.hpp
/////////////////////////////////////////////////
#define ONII_ENV_CYGWIN 1
/////////////////////////////////////////////////
/// @def ONII_ENV_CYGWIN
/// @brief Defined if one of the following macro is defined: @code __CYGWIN__ @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_CYGWIN
/////////////////////////////////////////////////

#if defined(__CYGWIN__)
# define ONII_ENV_CYGWIN 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_CYGWIN_HPP
