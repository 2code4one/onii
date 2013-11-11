#ifndef ONII_CONFIG_COMPILERS_GREEN_HILL_HPP
#define ONII_CONFIG_COMPILERS_GREEN_HILL_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/green_hill.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_GREENHILL 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_GREENHILL
/// @brief Defined if one of the following macro is defined: @code __ghs__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_GREENHILL
/////////////////////////////////////////////////

#if defined(__ghs__)
# define ONII_COMPILER_GREENHILL 1
#endif

#endif // ONII_CONFIG_COMPILERS_GREEN_HILL_HPP
