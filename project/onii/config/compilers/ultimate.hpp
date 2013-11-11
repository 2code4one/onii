#ifndef ONII_CONFIG_COMPILERS_ULTIMATE_HPP
#define ONII_CONFIG_COMPILERS_ULTIMATE_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/ultimate.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_ULTIMATE 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_ULTIMATE
/// @brief Defined if one of the following macro is defined: @code _UCC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_ULTIMATE
/////////////////////////////////////////////////

#if defined(_UCC)
# define ONII_COMPILER_ULTIMATE 1
#endif

#endif // ONII_CONFIG_COMPILERS_ULTIMATE_HPP
