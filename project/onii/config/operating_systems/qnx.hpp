#ifndef ONII_CONFIG_OPERATING_SYSTEMS_QNX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_QNX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/qnx.hpp
/////////////////////////////////////////////////
#define ONII_OS_QNX 1
/////////////////////////////////////////////////
/// @def ONII_OS_QNX
/// @brief Defined if one of the following macro is defined: @code __QNX__ __QNXNTO__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_QNX
/////////////////////////////////////////////////

#if defined(__QNX__) || defined(__QNXNTO__)
# define ONII_OS_QNX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_QNX_HPP
