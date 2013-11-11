#ifndef ONII_CONFIG_COMPILERS_KEIL_C166_HPP
#define ONII_CONFIG_COMPILERS_KEIL_C166_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/keil_c166.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_KEILC166 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_KEILC166
/// @brief Defined if one of the following macro is defined: @code __C166__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_KEILC166
/////////////////////////////////////////////////

#if defined(__C166__)
# define ONII_COMPILER_KEILC166 1
#endif

#endif // ONII_CONFIG_COMPILERS_KEIL_C166_HPP
