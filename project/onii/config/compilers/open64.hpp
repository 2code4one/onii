#ifndef ONII_CONFIG_COMPILERS_OPEN64_HPP
#define ONII_CONFIG_COMPILERS_OPEN64_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/open64.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_OPEN64 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_OPEN64
/// @brief Defined if one of the following macro is defined: @code __OPEN64__ __OPENCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_OPEN64
/////////////////////////////////////////////////

#if defined(__OPEN64__) || defined(__OPENCC__)
# define ONII_COMPILER_OPEN64 1
#endif

#endif // ONII_CONFIG_COMPILERS_OPEN64_HPP
