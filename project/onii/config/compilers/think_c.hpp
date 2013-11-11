#ifndef ONII_CONFIG_COMPILERS_THINK_C_HPP
#define ONII_CONFIG_COMPILERS_THINK_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/think_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_THINKC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_THINKC
/// @brief Defined if one of the following macro is defined: @code THINKC3 THINKC4 @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_THINKC
/////////////////////////////////////////////////

#if defined(THINKC3) || defined(THINKC4)
# define ONII_COMPILER_THINKC 1
#endif

#endif // ONII_CONFIG_COMPILERS_THINK_C_HPP
