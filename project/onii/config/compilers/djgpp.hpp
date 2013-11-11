#ifndef ONII_CONFIG_COMPILERS_DJGPP_HPP
#define ONII_CONFIG_COMPILERS_DJGPP_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/djgpp.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_DJGPP 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_DJGPP
/// @brief Defined if one of the following macro is defined: @code __DJGPP__ __GO32__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_DJGPP
/////////////////////////////////////////////////

#if defined(__DJGPP__) || defined(__GO32__)
# define ONII_COMPILER_DJGPP 1
#endif

#endif // ONII_CONFIG_COMPILERS_DJGPP_HPP
