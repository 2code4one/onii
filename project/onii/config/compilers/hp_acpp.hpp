#ifndef ONII_CONFIG_COMPILERS_HP_ACPP_HPP
#define ONII_CONFIG_COMPILERS_HP_ACPP_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/hp_acpp.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_HPACPP 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_HPACPP
/// @brief Defined if one of the following macro is defined: @code __HP_aCC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_HPACPP
/////////////////////////////////////////////////

#if defined(__HP_aCC)
# define ONII_COMPILER_HPACPP 1
#endif

#endif // ONII_CONFIG_COMPILERS_HP_ACPP_HPP
