#ifndef ONII_CONFIG_OPERATING_SYSTEMS_STRATUS_VOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_STRATUS_VOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/stratus_vos.hpp
/////////////////////////////////////////////////
#define ONII_OS_STRATUSVOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_STRATUSVOS
/// @brief Defined if one of the following macro is defined: @code __VOS__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_STRATUSVOS
/////////////////////////////////////////////////

#if defined(__VOS__)
# define ONII_OS_STRATUSVOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_STRATUS_VOS_HPP
