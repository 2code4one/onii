#ifndef ONII_CONFIG_COMPILERS_PACIFIC_C_HPP
#define ONII_CONFIG_COMPILERS_PACIFIC_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/pacific_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_PACIFICC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_PACIFICC
/// @brief Defined if one of the following macro is defined: @code __PACIFIC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_PACIFICC
/////////////////////////////////////////////////

#if defined(__PACIFIC__)
# define ONII_COMPILER_PACIFICC 1
#endif

#endif // ONII_CONFIG_COMPILERS_PACIFIC_C_HPP
