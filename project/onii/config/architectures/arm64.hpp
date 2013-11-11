#ifndef ONII_CONFIG_ARCHITECTURES_ARM64_HPP
#define ONII_CONFIG_ARCHITECTURES_ARM64_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/arm64.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_ARM64 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_ARM64
/// @brief Defined if one of the following macro is defined: @code __aarch64__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_ARM64
/////////////////////////////////////////////////

#if defined(__aarch64__)
# define ONII_ARCH_ARM64 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_ARM64_HPP
