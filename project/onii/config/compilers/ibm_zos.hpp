#ifndef ONII_CONFIG_COMPILERS_IBM_ZOS_HPP
#define ONII_CONFIG_COMPILERS_IBM_ZOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/ibm_zos.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_IBMZOS 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_IBMZOS
/// @brief Defined if one of the following macro is defined: @code __IBMC__ __IBMCPP__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_IBMZOS
/////////////////////////////////////////////////

#if defined(__IBMC__) || defined(__IBMCPP__)
# define ONII_COMPILER_IBMZOS 1
#endif

#endif // ONII_CONFIG_COMPILERS_IBM_ZOS_HPP
