#ifndef ONII_CONFIG_COMPILERS_TINY_C_HPP
#define ONII_CONFIG_COMPILERS_TINY_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/tiny_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_TINYC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_TINYC
/// @brief Defined if one of the following macro is defined: @code __TINYC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_TINYC
/////////////////////////////////////////////////

#if defined(__TINYC__)
# define ONII_COMPILER_TINYC 1
#endif

#endif // ONII_CONFIG_COMPILERS_TINY_C_HPP
