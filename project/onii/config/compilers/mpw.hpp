#ifndef ONII_CONFIG_COMPILERS_MPW_HPP
#define ONII_CONFIG_COMPILERS_MPW_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/mpw.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MPW 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MPW
/// @brief Defined if one of the following macro is defined: @code __MRC__ MPW_C MPW_CPLUS @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MPW
/////////////////////////////////////////////////

#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
# define ONII_COMPILER_MPW 1
#endif

#endif // ONII_CONFIG_COMPILERS_MPW_HPP
