#ifndef ONII_CONFIG_ARCHITECTURES_TMS320_HPP
#define ONII_CONFIG_ARCHITECTURES_TMS320_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/tms320.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_TMS320 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_TMS320
/// @brief Defined if one of the following macro is defined: @code _TMS320C2XX __TMS320C2000__ _TMS320C5X __TMS320C55X__ _TMS320C6X __TMS320C6X__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_TMS320
/////////////////////////////////////////////////

#if defined(_TMS320C2XX) || defined(__TMS320C2000__) || defined(_TMS320C5X) || defined(__TMS320C55X__) || defined(_TMS320C6X) || defined(__TMS320C6X__)
# define ONII_ARCH_TMS320 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_TMS320_HPP
