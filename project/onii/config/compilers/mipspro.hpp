#ifndef ONII_CONFIG_COMPILERS_MIPSPRO_HPP
#define ONII_CONFIG_COMPILERS_MIPSPRO_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/mipspro.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MIPS 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MIPS
/// @brief Defined if one of the following macro is defined: @code __sgi sgi @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MIPS
/////////////////////////////////////////////////

#if defined(__sgi) || defined(sgi)
# define ONII_COMPILER_MIPS 1
#endif

#endif // ONII_CONFIG_COMPILERS_MIPSPRO_HPP
