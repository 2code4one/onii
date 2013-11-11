#ifndef ONII_CONFIG_COMPILERS_LCC_HPP
#define ONII_CONFIG_COMPILERS_LCC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/lcc.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_LCC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_LCC
/// @brief Defined if one of the following macro is defined: @code __LCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_LCC
/////////////////////////////////////////////////

#if defined(__LCC__)
# define ONII_COMPILER_LCC 1
#endif

#endif // ONII_CONFIG_COMPILERS_LCC_HPP
