#ifndef ONII_CONFIG_ARCHITECTURES_MOTOROLA_68K_HPP
#define ONII_CONFIG_ARCHITECTURES_MOTOROLA_68K_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/motorola_68k.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_M68K 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_M68K
/// @brief Defined if one of the following macro is defined: @code __m68k__ M68000 __MC68K__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_M68K
/////////////////////////////////////////////////

#if defined(__m68k__) || defined(M68000) || defined(__MC68K__)
# define ONII_ARCH_M68K 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_MOTOROLA_68K_HPP
