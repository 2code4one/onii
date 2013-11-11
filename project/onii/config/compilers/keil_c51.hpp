#ifndef ONII_CONFIG_COMPILERS_KEIL_C51_HPP
#define ONII_CONFIG_COMPILERS_KEIL_C51_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/keil_c51.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_KEILC51 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_KEILC51
/// @brief Defined if one of the following macro is defined: @code __C51__ __CX51__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_KEILC51
/////////////////////////////////////////////////

#if defined(__C51__) || defined(__CX51__)
# define ONII_COMPILER_KEILC51 1
#endif

#endif // ONII_CONFIG_COMPILERS_KEIL_C51_HPP
