#ifndef ONII_CONFIG_ARCHITECTURES_ARM_HPP
#define ONII_CONFIG_ARCHITECTURES_ARM_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/arm.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_ARM 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_ARM
/// @brief Defined if one of the following macro is defined: @code __arm__ __thumb__ __TARGET_ARCH_ARM __TARGET_ARCH_THUMB _ARM _M_ARM _M_ARMT @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_ARM
/////////////////////////////////////////////////

#if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT)
# define ONII_ARCH_ARM 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_ARM_HPP
