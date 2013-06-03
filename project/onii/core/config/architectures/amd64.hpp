#ifndef ONII_CORE_CONFIG_ARCHITECTURES_AMD64_HPP
#define ONII_CORE_CONFIG_ARCHITECTURES_AMD64_HPP

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
# define ONII_ARCH_AMD64 1
#endif

#endif // ONII_CORE_CONFIG_ARCHITECTURES_AMD64_HPP
