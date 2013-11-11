#ifndef ONII_CONFIG_ARCHITECTURES_TMS470_HPP
#define ONII_CONFIG_ARCHITECTURES_TMS470_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/tms470.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_TMS470 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_TMS470
/// @brief Defined if one of the following macro is defined: @code __TMS470__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_TMS470
/////////////////////////////////////////////////

#if defined(__TMS470__)
# define ONII_ARCH_TMS470 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_TMS470_HPP
