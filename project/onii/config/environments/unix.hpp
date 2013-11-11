#ifndef ONII_CONFIG_ENVIRONMENTS_UNIX_HPP
#define ONII_CONFIG_ENVIRONMENTS_UNIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/unix.hpp
/////////////////////////////////////////////////
#define ONII_ENV_UNIX 1
/////////////////////////////////////////////////
/// @def ONII_ENV_UNIX
/// @brief Defined if one of the following macro is defined: @code __unix__ __unix @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_UNIX
/////////////////////////////////////////////////

#if defined(__unix__) || defined(__unix)
# define ONII_ENV_UNIX 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_UNIX_HPP
