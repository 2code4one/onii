#ifndef ONII_CONFIG_COMPILERS_METAWARE_HIGH_HPP
#define ONII_CONFIG_COMPILERS_METAWARE_HIGH_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/metaware_high.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_HIGHC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_HIGHC
/// @brief Defined if one of the following macro is defined: @code __HIGHC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_HIGHC
/////////////////////////////////////////////////

#if defined(__HIGHC__)
# define ONII_COMPILER_HIGHC 1
#endif

#endif // ONII_CONFIG_COMPILERS_METAWARE_HIGH_HPP
