#ifndef ONII_CONFIG_COMPILERS_SYMANTEC_HPP
#define ONII_CONFIG_COMPILERS_SYMANTEC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/symantec.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_SYMANTEC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_SYMANTEC
/// @brief Defined if one of the following macro is defined: @code __SC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_SYMANTEC
/////////////////////////////////////////////////

#if defined(__SC__)
# define ONII_COMPILER_SYMANTEC 1
#endif

#endif // ONII_CONFIG_COMPILERS_SYMANTEC_HPP
