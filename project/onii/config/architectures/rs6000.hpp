#ifndef ONII_CONFIG_ARCHITECTURES_RS6000_HPP
#define ONII_CONFIG_ARCHITECTURES_RS6000_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/rs6000.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_RS6000 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_RS6000
/// @brief Defined if one of the following macro is defined: @code __THW_RS6000 _IBMR2 _POWER _ARCH_PWR _ARCH_PWR2 _ARCH_PWR3 _ARCH_PWR4 @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_RS6000
/////////////////////////////////////////////////

#if defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || defined(_ARCH_PWR4)
# define ONII_ARCH_RS6000 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_RS6000_HPP
