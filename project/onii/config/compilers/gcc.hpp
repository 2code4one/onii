#ifndef ONII_CONFIG_COMPILERS_GCC_HPP
#define ONII_CONFIG_COMPILERS_GCC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/gcc.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_GCC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_GCC
/// @brief Defined if one of the following macro is defined: @code __GNUC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_GCC
/////////////////////////////////////////////////

#if defined(__GNUC__)
# define ONII_COMPILER_GCC 1
#endif

#endif // ONII_CONFIG_COMPILERS_GCC_HPP
