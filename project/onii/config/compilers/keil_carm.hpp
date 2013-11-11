#ifndef ONII_CONFIG_COMPILERS_KEIL_CARM_HPP
#define ONII_CONFIG_COMPILERS_KEIL_CARM_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/keil_carm.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_KEILCARM 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_KEILCARM
/// @brief Defined if one of the following macro is defined: @code __CA__ __KEIL__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_KEILCARM
/////////////////////////////////////////////////

#if defined(__CA__) || defined(__KEIL__)
# define ONII_COMPILER_KEILCARM 1
#endif

#endif // ONII_CONFIG_COMPILERS_KEIL_CARM_HPP
