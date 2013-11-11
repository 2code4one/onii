#ifndef ONII_CONFIG_COMPILERS_IAR_HPP
#define ONII_CONFIG_COMPILERS_IAR_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/iar.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_IAR 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_IAR
/// @brief Defined if one of the following macro is defined: @code __IAR_SYSTEMS_ICC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_IAR
/////////////////////////////////////////////////

#if defined(__IAR_SYSTEMS_ICC__)
# define ONII_COMPILER_IAR 1
#endif

#endif // ONII_CONFIG_COMPILERS_IAR_HPP
