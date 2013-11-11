#ifndef ONII_CONFIG_COMPILERS_NWCC_HPP
#define ONII_CONFIG_COMPILERS_NWCC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/nwcc.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_NWCC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_NWCC
/// @brief Defined if one of the following macro is defined: @code __NWCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_NWCC
/////////////////////////////////////////////////

#if defined(__NWCC__)
# define ONII_COMPILER_NWCC 1
#endif

#endif // ONII_CONFIG_COMPILERS_NWCC_HPP
