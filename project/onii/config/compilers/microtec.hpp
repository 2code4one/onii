#ifndef ONII_CONFIG_COMPILERS_MICROTEC_HPP
#define ONII_CONFIG_COMPILERS_MICROTEC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/microtec.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MRI 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MRI
/// @brief Defined if one of the following macro is defined: @code _MRI @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MRI
/////////////////////////////////////////////////

#if defined(_MRI)
# define ONII_COMPILER_MRI 1
#endif

#endif // ONII_CONFIG_COMPILERS_MICROTEC_HPP
