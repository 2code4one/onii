#ifndef ONII_CONFIG_OPERATING_SYSTEMS_IBM_OS400_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_IBM_OS400_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/ibm_os400.hpp
/////////////////////////////////////////////////
#define ONII_OS_IBMOS400 1
/////////////////////////////////////////////////
/// @def ONII_OS_IBMOS400
/// @brief Defined if one of the following macro is defined: @code __OS400__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_IBMOS400
/////////////////////////////////////////////////

#if defined(__OS400__)
# define ONII_OS_IBMOS400 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_IBM_OS400_HPP
