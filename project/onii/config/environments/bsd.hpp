#ifndef ONII_CONFIG_ENVIRONMENTS_BSD_HPP
#define ONII_CONFIG_ENVIRONMENTS_BSD_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/bsd.hpp
/////////////////////////////////////////////////
#define ONII_ENV_BSD 1
/////////////////////////////////////////////////
/// @def ONII_ENV_BSD
/// @brief Defined if one of the following macro is defined: @code __FreeBSD__ __NetBSD__ __OpenBSD__ __bsdi__ __DragonFly__ _SYSTYPE_BSD @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_BSD
/////////////////////////////////////////////////

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
# define ONII_ENV_BSD 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_BSD_HPP
