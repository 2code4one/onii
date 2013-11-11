#ifndef ONII_CONFIG_OPERATING_SYSTEMS_VMS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_VMS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/vms.hpp
/////////////////////////////////////////////////
#define ONII_OS_VMS 1
/////////////////////////////////////////////////
/// @def ONII_OS_VMS
/// @brief Defined if one of the following macro is defined: @code VMS __VMS @endcode
/////////////////////////////////////////////////
#undef ONII_OS_VMS
/////////////////////////////////////////////////

#if defined(VMS) || defined(__VMS)
# define ONII_OS_VMS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_VMS_HPP
