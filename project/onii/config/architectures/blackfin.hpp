#ifndef ONII_CONFIG_ARCHITECTURES_BLACKFIN_HPP
#define ONII_CONFIG_ARCHITECTURES_BLACKFIN_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/blackfin.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_BLACKFIN 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_BLACKFIN
/// @brief Defined if one of the following macro is defined: @code __bfin __BFIN__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_BLACKFIN
/////////////////////////////////////////////////

#if defined(__bfin) || defined(__BFIN__)
# define ONII_ARCH_BLACKFIN 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_BLACKFIN_HPP
