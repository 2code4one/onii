#ifndef ONII_CONFIG_OPERATING_SYSTEMS_DGUX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_DGUX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/dgux.hpp
/////////////////////////////////////////////////
#define ONII_OS_DGUX 1
/////////////////////////////////////////////////
/// @def ONII_OS_DGUX
/// @brief Defined if one of the following macro is defined: @code DGUX __DGUX__ __dgux__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_DGUX
/////////////////////////////////////////////////

#if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
# define ONII_OS_DGUX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_DGUX_HPP
