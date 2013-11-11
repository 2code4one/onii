#ifndef ONII_CONFIG_ARCHITECTURES_MIPS_HPP
#define ONII_CONFIG_ARCHITECTURES_MIPS_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/mips.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_MIPS 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_MIPS
/// @brief Defined if one of the following macro is defined: @code __mips__ mips __mips __MIPS__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_MIPS
/////////////////////////////////////////////////

#if defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
# define ONII_ARCH_MIPS 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_MIPS_HPP
