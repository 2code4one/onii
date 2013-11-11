#ifndef ONII_CONFIG_COMPILERS_CLANG_HPP
#define ONII_CONFIG_COMPILERS_CLANG_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/clang.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_CLANG 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_CLANG
/// @brief Defined if one of the following macro is defined: @code __clang__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_CLANG
/////////////////////////////////////////////////

#if defined(__clang__)
# define ONII_COMPILER_CLANG 1
#endif

#endif // ONII_CONFIG_COMPILERS_CLANG_HPP
