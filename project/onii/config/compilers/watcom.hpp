#ifndef ONII_CONFIG_COMPILERS_WATCOM_HPP
#define ONII_CONFIG_COMPILERS_WATCOM_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/watcom.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_WATCOM 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_WATCOM
/// @brief Defined if one of the following macro is defined: @code __WATCOMC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_WATCOM
/////////////////////////////////////////////////

#if defined(__WATCOMC__)
# define ONII_COMPILER_WATCOM 1
#endif

#endif // ONII_CONFIG_COMPILERS_WATCOM_HPP
