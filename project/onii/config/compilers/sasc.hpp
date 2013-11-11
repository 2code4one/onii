#ifndef ONII_CONFIG_COMPILERS_SASC_HPP
#define ONII_CONFIG_COMPILERS_SASC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/sasc.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_SASC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_SASC
/// @brief Defined if one of the following macro is defined: @code SASC __SASC __SASC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_SASC
/////////////////////////////////////////////////

#if defined(SASC) || defined(__SASC) || defined(__SASC__)
# define ONII_COMPILER_SASC 1
#endif

#endif // ONII_CONFIG_COMPILERS_SASC_HPP
