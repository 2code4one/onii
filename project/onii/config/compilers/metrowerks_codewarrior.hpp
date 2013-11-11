#ifndef ONII_CONFIG_COMPILERS_METROWERKS_CODEWARRIOR_HPP
#define ONII_CONFIG_COMPILERS_METROWERKS_CODEWARRIOR_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/metrowerks_codewarrior.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MWERKS 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MWERKS
/// @brief Defined if one of the following macro is defined: @code __MWERKS__ __CWCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MWERKS
/////////////////////////////////////////////////

#if defined(__MWERKS__) || defined(__CWCC__)
# define ONII_COMPILER_MWERKS 1
#endif

#endif // ONII_CONFIG_COMPILERS_METROWERKS_CODEWARRIOR_HPP
