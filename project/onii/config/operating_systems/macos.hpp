#ifndef ONII_CONFIG_OPERATING_SYSTEMS_MACOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_MACOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/macos.hpp
/////////////////////////////////////////////////
#define ONII_OS_MACOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_MACOS
/// @brief Defined if one of the following macro is defined: @code macintosh Macintosh (__APPLE__ && __MACH__) @endcode
/////////////////////////////////////////////////
#undef ONII_OS_MACOS
/////////////////////////////////////////////////

#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
# define ONII_OS_MACOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_MACOS_HPP
