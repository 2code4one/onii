#ifndef ONII_CONFIG_COMPILERS_INTEL_HPP
#define ONII_CONFIG_COMPILERS_INTEL_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/intel.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_INTEL 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_INTEL
/// @brief Defined if one of the following macro is defined: @code __INTEL_COMPILER __ICC __ECC __ICL @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_INTEL
/////////////////////////////////////////////////

#if defined(__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL)
# define ONII_COMPILER_INTEL 1
#endif

#endif // ONII_CONFIG_COMPILERS_INTEL_HPP
