#ifndef ONII_CONFIG_COMPILERS_TURBO_HPP
#define ONII_CONFIG_COMPILERS_TURBO_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/turbo.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_TURBO 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_TURBO
/// @brief Defined if one of the following macro is defined: @code __TURBOC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_TURBO
/////////////////////////////////////////////////

#if defined(__TURBOC__)
# define ONII_COMPILER_TURBO 1
#endif

#endif // ONII_CONFIG_COMPILERS_TURBO_HPP
