#ifndef ONII_CONFIG_COMPILERS_BORLAND_HPP
#define ONII_CONFIG_COMPILERS_BORLAND_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/borland.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_BORLAND 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_BORLAND
/// @brief Defined if one of the following macro is defined: @code __BORLANDC__ __CODEGEARC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_BORLAND
/////////////////////////////////////////////////

#if defined(__BORLANDC__) || defined(__CODEGEARC__)
# define ONII_COMPILER_BORLAND 1
#endif

#endif // ONII_CONFIG_COMPILERS_BORLAND_HPP
