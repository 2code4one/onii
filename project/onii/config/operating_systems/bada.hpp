#ifndef ONII_CONFIG_OPERATING_SYSTEMS_BADA_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_BADA_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/bada.hpp
/////////////////////////////////////////////////
#define ONII_OS_BADA 1
/////////////////////////////////////////////////
/// @def ONII_OS_BADA
/// @brief Defined if one of the following macro is defined: @code __nucleus__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_BADA
/////////////////////////////////////////////////

#if defined(__nucleus__)
# define ONII_OS_BADA 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_BADA_HPP
