#ifndef ONII_CONFIG_COMPILERS_COMEAU_HPP
#define ONII_CONFIG_COMPILERS_COMEAU_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/comeau.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_COMEAU 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_COMEAU
/// @brief Defined if one of the following macro is defined: @code __COMO__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_COMEAU
/////////////////////////////////////////////////

#if defined(__COMO__)
# define ONII_COMPILER_COMEAU 1
#endif

#endif // ONII_CONFIG_COMPILERS_COMEAU_HPP
