#ifndef ONII_CONFIG_COMPILERS_CRAY_C_HPP
#define ONII_CONFIG_COMPILERS_CRAY_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/cray_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_CRAYC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_CRAYC
/// @brief Defined if one of the following macro is defined: @code _CRAYC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_CRAYC
/////////////////////////////////////////////////

#if defined(_CRAYC)
# define ONII_COMPILER_CRAYC 1
#endif

#endif // ONII_CONFIG_COMPILERS_CRAY_C_HPP
