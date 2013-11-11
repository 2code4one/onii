#ifndef ONII_CONFIG_ARCHITECTURES_ALPHA_HPP
#define ONII_CONFIG_ARCHITECTURES_ALPHA_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/alpha.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_ALPHA 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_ALPHA
/// @brief Defined if one of the following macro is defined: @code __alpha__ __alpha _M_ALPHA @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_ALPHA
/////////////////////////////////////////////////

#if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
# define ONII_ARCH_ALPHA 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_ALPHA_HPP
