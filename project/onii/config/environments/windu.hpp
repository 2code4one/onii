#ifndef ONII_CONFIG_ENVIRONMENTS_WINDU_HPP
#define ONII_CONFIG_ENVIRONMENTS_WINDU_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/windu.hpp
/////////////////////////////////////////////////
#define ONII_ENV_WINDU 1
/////////////////////////////////////////////////
/// @def ONII_ENV_WINDU
/// @brief Defined if one of the following macro is defined: @code _WINDU_SOURCE @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_WINDU
/////////////////////////////////////////////////

#if defined(_WINDU_SOURCE)
# define ONII_ENV_WINDU 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_WINDU_HPP
