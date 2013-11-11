#ifndef ONII_CONFIG_COMPILERS_SN_COMPILER_HPP
#define ONII_CONFIG_COMPILERS_SN_COMPILER_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/sn_compiler.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_SNC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_SNC
/// @brief Defined if one of the following macro is defined: @code __SNC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_SNC
/////////////////////////////////////////////////

#if defined(__SNC__)
# define ONII_COMPILER_SNC 1
#endif

#endif // ONII_CONFIG_COMPILERS_SN_COMPILER_HPP
