#ifndef ONII_CONFIG_OPERATING_SYSTEMS_PYRAMID_DCOSX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_PYRAMID_DCOSX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/pyramid_dcosx.hpp
/////////////////////////////////////////////////
#define ONII_OS_PYRAMID 1
/////////////////////////////////////////////////
/// @def ONII_OS_PYRAMID
/// @brief Defined if one of the following macro is defined: @code pyr @endcode
/////////////////////////////////////////////////
#undef ONII_OS_PYRAMID
/////////////////////////////////////////////////

#if defined(pyr)
# define ONII_OS_PYRAMID 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_PYRAMID_DCOSX_HPP
