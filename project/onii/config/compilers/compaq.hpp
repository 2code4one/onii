#ifndef ONII_CONFIG_COMPILERS_COMPAQ_HPP
#define ONII_CONFIG_COMPILERS_COMPAQ_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/compaq.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_COMPAQ 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_COMPAQ
/// @brief Defined if one of the following macro is defined: @code __DECC __DECCXX __VAXC VAXC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_COMPAQ
/////////////////////////////////////////////////

#if defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)
# define ONII_COMPILER_COMPAQ 1
#endif

#endif // ONII_CONFIG_COMPILERS_COMPAQ_HPP
