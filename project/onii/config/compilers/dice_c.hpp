#ifndef ONII_CONFIG_COMPILERS_DICE_C_HPP
#define ONII_CONFIG_COMPILERS_DICE_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/dice_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_DICEC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_DICEC
/// @brief Defined if one of the following macro is defined: @code _DICE @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_DICEC
/////////////////////////////////////////////////

#if defined(_DICE)
# define ONII_COMPILER_DICEC 1
#endif

#endif // ONII_CONFIG_COMPILERS_DICE_C_HPP
