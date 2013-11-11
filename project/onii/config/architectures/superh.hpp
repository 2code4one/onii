#ifndef ONII_CONFIG_ARCHITECTURES_SUPERH_HPP
#define ONII_CONFIG_ARCHITECTURES_SUPERH_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/superh.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_SUPERH 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_SUPERH
/// @brief Defined if one of the following macro is defined: @code __sh__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_SUPERH
/////////////////////////////////////////////////

#if defined(__sh__)
# define ONII_ARCH_SUPERH 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_SUPERH_HPP
