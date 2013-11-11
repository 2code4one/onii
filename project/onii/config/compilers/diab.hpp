#ifndef ONII_CONFIG_COMPILERS_DIAB_HPP
#define ONII_CONFIG_COMPILERS_DIAB_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/diab.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_DIAB 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_DIAB
/// @brief Defined if one of the following macro is defined: @code __DCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_DIAB
/////////////////////////////////////////////////

#if defined(__DCC__)
# define ONII_COMPILER_DIAB 1
#endif

#endif // ONII_CONFIG_COMPILERS_DIAB_HPP
