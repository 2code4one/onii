#ifndef ONII_CONFIG_COMPILERS_MIRACLE_C_HPP
#define ONII_CONFIG_COMPILERS_MIRACLE_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/miracle_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MIRACLEC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MIRACLEC
/// @brief Defined if one of the following macro is defined: @code MIRACLE @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MIRACLEC
/////////////////////////////////////////////////

#if defined(MIRACLE)
# define ONII_COMPILER_MIRACLEC 1
#endif

#endif // ONII_CONFIG_COMPILERS_MIRACLE_C_HPP
