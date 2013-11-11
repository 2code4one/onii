#ifndef ONII_CONFIG_ENVIRONMENTS_SVR4_HPP
#define ONII_CONFIG_ENVIRONMENTS_SVR4_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/svr4.hpp
/////////////////////////////////////////////////
#define ONII_ENV_SVR4 1
/////////////////////////////////////////////////
/// @def ONII_ENV_SVR4
/// @brief Defined if one of the following macro is defined: @code __sysv__ __SVR4 __svr4__ _SYSTYPE_SVR4 @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_SVR4
/////////////////////////////////////////////////

#if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
# define ONII_ENV_SVR4 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_SVR4_HPP
