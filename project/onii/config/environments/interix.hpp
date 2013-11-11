#ifndef ONII_CONFIG_ENVIRONMENTS_INTERIX_HPP
#define ONII_CONFIG_ENVIRONMENTS_INTERIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/interix.hpp
/////////////////////////////////////////////////
#define ONII_ENV_INTERIX 1
/////////////////////////////////////////////////
/// @def ONII_ENV_INTERIX
/// @brief Defined if one of the following macro is defined: @code __INTERIX @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_INTERIX
/////////////////////////////////////////////////

#if defined(__INTERIX)
# define ONII_ENV_INTERIX 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_INTERIX_HPP
