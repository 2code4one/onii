#ifndef ONII_CONFIG_OPERATING_SYSTEMS_PALM_OS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_PALM_OS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/palm_os.hpp
/////////////////////////////////////////////////
#define ONII_OS_PALM 1
/////////////////////////////////////////////////
/// @def ONII_OS_PALM
/// @brief Defined if one of the following macro is defined: @code __palmos__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_PALM
/////////////////////////////////////////////////

#if defined(__palmos__)
# define ONII_OS_PALM 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_PALM_OS_HPP
