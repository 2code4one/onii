#ifndef ONII_CONFIG_COMPILERS_USL_C_HPP
#define ONII_CONFIG_COMPILERS_USL_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/usl_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_USLC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_USLC
/// @brief Defined if one of the following macro is defined: @code __USLC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_USLC
/////////////////////////////////////////////////

#if defined(__USLC__)
# define ONII_COMPILER_USLC 1
#endif

#endif // ONII_CONFIG_COMPILERS_USL_C_HPP
