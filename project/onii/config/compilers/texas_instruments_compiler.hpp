#ifndef ONII_CONFIG_COMPILERS_TEXAS_INSTRUMENTS_COMPILER_HPP
#define ONII_CONFIG_COMPILERS_TEXAS_INSTRUMENTS_COMPILER_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/texas_instruments_compiler.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_TI 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_TI
/// @brief Defined if one of the following macro is defined: @code __TI_COMPILER_VERSION__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_TI
/////////////////////////////////////////////////

#if defined(__TI_COMPILER_VERSION__)
# define ONII_COMPILER_TI 1
#endif

#endif // ONII_CONFIG_COMPILERS_TEXAS_INSTRUMENTS_COMPILER_HPP
