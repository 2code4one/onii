#ifndef ONII_CONFIG_COMPILERS_PELLES_C_HPP
#define ONII_CONFIG_COMPILERS_PELLES_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/pelles_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_PELLESC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_PELLESC
/// @brief Defined if one of the following macro is defined: @code __POCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_PELLESC
/////////////////////////////////////////////////

#if defined(__POCC__)
# define ONII_COMPILER_PELLESC 1
#endif

#endif // ONII_CONFIG_COMPILERS_PELLES_C_HPP
