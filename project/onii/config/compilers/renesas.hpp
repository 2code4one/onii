#ifndef ONII_CONFIG_COMPILERS_RENESAS_HPP
#define ONII_CONFIG_COMPILERS_RENESAS_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/renesas.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_RENESAS 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_RENESAS
/// @brief Defined if one of the following macro is defined: @code __RENESAS__ __HITACHI__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_RENESAS
/////////////////////////////////////////////////

#if defined(__RENESAS__) || defined(__HITACHI__)
# define ONII_COMPILER_RENESAS 1
#endif

#endif // ONII_CONFIG_COMPILERS_RENESAS_HPP
