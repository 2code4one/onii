#ifndef ONII_CONFIG_ARCHITECTURES_EPIPHANY_HPP
#define ONII_CONFIG_ARCHITECTURES_EPIPHANY_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/epiphany.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_EPIPHANY 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_EPIPHANY
/// @brief Defined if one of the following macro is defined: @code __epiphany__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_EPIPHANY
/////////////////////////////////////////////////

#if defined(__epiphany__)
# define ONII_ARCH_EPIPHANY 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_EPIPHANY_HPP
