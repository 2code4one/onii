#ifndef ONII_CONFIG_OPERATING_SYSTEMS_CONVEXOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_CONVEXOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/convexos.hpp
/////////////////////////////////////////////////
#define ONII_OS_CONVEX 1
/////////////////////////////////////////////////
/// @def ONII_OS_CONVEX
/// @brief Defined if one of the following macro is defined: @code __convex__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_CONVEX
/////////////////////////////////////////////////

#if defined(__convex__)
# define ONII_OS_CONVEX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_CONVEXOS_HPP
