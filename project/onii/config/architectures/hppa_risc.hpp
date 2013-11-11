#ifndef ONII_CONFIG_ARCHITECTURES_HPPA_RISC_HPP
#define ONII_CONFIG_ARCHITECTURES_HPPA_RISC_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/hppa_risc.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_HPPA 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_HPPA
/// @brief Defined if one of the following macro is defined: @code __hppa__ __HPPA__ __hppa @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_HPPA
/////////////////////////////////////////////////

#if defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
# define ONII_ARCH_HPPA 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_HPPA_RISC_HPP
