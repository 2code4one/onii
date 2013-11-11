#ifndef ONII_CONFIG_COMPILERS_IMAGECRAFT_C_HPP
#define ONII_CONFIG_COMPILERS_IMAGECRAFT_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/imagecraft_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_IMAGECRAFT 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_IMAGECRAFT
/// @brief Defined if one of the following macro is defined: @code __IMAGECRAFT__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_IMAGECRAFT
/////////////////////////////////////////////////

#if defined(__IMAGECRAFT__)
# define ONII_COMPILER_IMAGECRAFT 1
#endif

#endif // ONII_CONFIG_COMPILERS_IMAGECRAFT_C_HPP
