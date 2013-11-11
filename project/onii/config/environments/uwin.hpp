#ifndef ONII_CONFIG_ENVIRONMENTS_UWIN_HPP
#define ONII_CONFIG_ENVIRONMENTS_UWIN_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/uwin.hpp
/////////////////////////////////////////////////
#define ONII_ENV_UWIN 1
/////////////////////////////////////////////////
/// @def ONII_ENV_UWIN
/// @brief Defined if one of the following macro is defined: @code _UWIN @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_UWIN
/////////////////////////////////////////////////

#if defined(_UWIN)
# define ONII_ENV_UWIN 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_UWIN_HPP
