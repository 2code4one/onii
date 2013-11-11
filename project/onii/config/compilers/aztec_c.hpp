#ifndef ONII_CONFIG_COMPILERS_AZTEC_C_HPP
#define ONII_CONFIG_COMPILERS_AZTEC_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/aztec_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_AZTECC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_AZTECC
/// @brief Defined if one of the following macro is defined: @code AZTEC_C __AZTEC_C__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_AZTECC
/////////////////////////////////////////////////

#if defined(AZTEC_C) || defined(__AZTEC_C__)
# define ONII_COMPILER_AZTECC 1
#endif

#endif // ONII_CONFIG_COMPILERS_AZTEC_C_HPP
