#ifndef ONII_CONFIG_ARCHITECTURES_AMD64_HPP
#define ONII_CONFIG_ARCHITECTURES_AMD64_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/amd64.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_AMD64 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_AMD64
/// @brief Defined if one of the following macro is defined: @code __amd64__ __amd64 __x86_64__ __x86_64 _M_X64 _M_AMD64 @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_AMD64
/////////////////////////////////////////////////

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
# define ONII_ARCH_AMD64 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_AMD64_HPP
