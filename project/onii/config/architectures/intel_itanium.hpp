#ifndef ONII_CONFIG_ARCHITECTURES_INTEL_ITANIUM_HPP
#define ONII_CONFIG_ARCHITECTURES_INTEL_ITANIUM_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/intel_itanium.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_IA64 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_IA64
/// @brief Defined if one of the following macro is defined: @code __ia64__ _IA64 __IA64__ __ia64 _M_IA64 _M_IA64 __itanium__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_IA64
/////////////////////////////////////////////////

#if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(_M_IA64) || defined(__itanium__)
# define ONII_ARCH_IA64 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_INTEL_ITANIUM_HPP
