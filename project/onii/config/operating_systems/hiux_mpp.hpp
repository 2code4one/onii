#ifndef ONII_CONFIG_OPERATING_SYSTEMS_HIUX_MPP_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_HIUX_MPP_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/hiux_mpp.hpp
/////////////////////////////////////////////////
#define ONII_OS_HIUXMPP 1
/////////////////////////////////////////////////
/// @def ONII_OS_HIUXMPP
/// @brief Defined if one of the following macro is defined: @code __hiuxmpp @endcode
/////////////////////////////////////////////////
#undef ONII_OS_HIUXMPP
/////////////////////////////////////////////////

#if defined(__hiuxmpp)
# define ONII_OS_HIUXMPP 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_HIUX_MPP_HPP
