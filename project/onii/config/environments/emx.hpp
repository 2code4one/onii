#ifndef ONII_CONFIG_ENVIRONMENTS_EMX_HPP
#define ONII_CONFIG_ENVIRONMENTS_EMX_HPP

/////////////////////////////////////////////////
/// @file onii/config/environments/emx.hpp
/////////////////////////////////////////////////
#define ONII_ENV_EMX 1
/////////////////////////////////////////////////
/// @def ONII_ENV_EMX
/// @brief Defined if one of the following macro is defined: @code __EMX__ @endcode
/////////////////////////////////////////////////
#undef ONII_ENV_EMX
/////////////////////////////////////////////////

#if defined(__EMX__)
# define ONII_ENV_EMX 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_EMX_HPP
