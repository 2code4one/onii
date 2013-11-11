#ifndef ONII_CONFIG_COMPILERS_STRATUS_VOS_C_HPP
#define ONII_CONFIG_COMPILERS_STRATUS_VOS_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/stratus_vos_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_VOSC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_VOSC
/// @brief Defined if one of the following macro is defined: @code __VOSC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_VOSC
/////////////////////////////////////////////////

#if defined(__VOSC__)
# define ONII_COMPILER_VOSC 1
#endif

#endif // ONII_CONFIG_COMPILERS_STRATUS_VOS_C_HPP
