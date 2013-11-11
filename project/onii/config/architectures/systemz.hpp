#ifndef ONII_CONFIG_ARCHITECTURES_SYSTEMZ_HPP
#define ONII_CONFIG_ARCHITECTURES_SYSTEMZ_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/systemz.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_SYSTEMZ 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_SYSTEMZ
/// @brief Defined if one of the following macro is defined: @code __370__ __THW_370__ __s390__ __s390x__ __zarch__ __SYSC_ZARCH__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_SYSTEMZ
/////////////////////////////////////////////////

#if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
# define ONII_ARCH_SYSTEMZ 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_SYSTEMZ_HPP
