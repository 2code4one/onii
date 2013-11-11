#ifndef ONII_CONFIG_COMPILERS_HP_ANSI_HPP
#define ONII_CONFIG_COMPILERS_HP_ANSI_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/hp_ansi.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_HPANSIC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_HPANSIC
/// @brief Defined if one of the following macro is defined: @code __HP_cc @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_HPANSIC
/////////////////////////////////////////////////

#if defined(__HP_cc)
# define ONII_COMPILER_HPANSIC 1
#endif

#endif // ONII_CONFIG_COMPILERS_HP_ANSI_HPP
