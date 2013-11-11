#ifndef ONII_CONFIG_COMPILERS_IBM_XL_HPP
#define ONII_CONFIG_COMPILERS_IBM_XL_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/ibm_xl.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_IBMXL 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_IBMXL
/// @brief Defined if one of the following macro is defined: @code __xlc__ __xlC__ __IBMC__ __IBMCPP__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_IBMXL
/////////////////////////////////////////////////

#if defined(__xlc__) || defined(__xlC__) || defined(__IBMC__) || defined(__IBMCPP__)
# define ONII_COMPILER_IBMXL 1
#endif

#endif // ONII_CONFIG_COMPILERS_IBM_XL_HPP
