#ifndef ONII_CONFIG_COMPILERS_TENDRA_HPP
#define ONII_CONFIG_COMPILERS_TENDRA_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/tendra.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_TENDRA 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_TENDRA
/// @brief Defined if one of the following macro is defined: @code __TenDRA__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_TENDRA
/////////////////////////////////////////////////

#if defined(__TenDRA__)
# define ONII_COMPILER_TENDRA 1
#endif

#endif // ONII_CONFIG_COMPILERS_TENDRA_HPP
