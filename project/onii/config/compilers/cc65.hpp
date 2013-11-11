#ifndef ONII_CONFIG_COMPILERS_CC65_HPP
#define ONII_CONFIG_COMPILERS_CC65_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/cc65.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_CC65 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_CC65
/// @brief Defined if one of the following macro is defined: @code __CC65__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_CC65
/////////////////////////////////////////////////

#if defined(__CC65__)
# define ONII_COMPILER_CC65 1
#endif

#endif // ONII_CONFIG_COMPILERS_CC65_HPP
