#ifndef ONII_CORE_CONFIG_ARCHITECTURES_INTEL_X86_HPP
#define ONII_CORE_CONFIG_ARCHITECTURES_INTEL_X86_HPP

#if defined(i386) || defined(__i386) || defined(__i386__) || defined(__i386) || defined(__i386) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__)
# define ONII_ARCH_X86 1
#endif

#endif // ONII_CORE_CONFIG_ARCHITECTURES_INTEL_X86_HPP
