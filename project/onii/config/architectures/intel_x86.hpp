#ifndef ONII_CONFIG_ARCHITECTURES_INTEL_X86_HPP
#define ONII_CONFIG_ARCHITECTURES_INTEL_X86_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/intel_x86.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_X86 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_X86
/// @brief Defined if one of the following macro is defined: @code i386 __i386 __i386__ __IA32__ _M_I86 _M_IX86 __X86__ _X86_ __THW_INTEL__ __I86__ __INTEL__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_X86
/////////////////////////////////////////////////

#if defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__)
# define ONII_ARCH_X86 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_INTEL_X86_HPP
