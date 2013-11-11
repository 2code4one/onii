#ifndef ONII_CONFIG_OPERATING_SYSTEMS_MICROWARE_OS9_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_MICROWARE_OS9_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/microware_os9.hpp
/////////////////////////////////////////////////
#define ONII_OS_MICROWAREOS9 1
/////////////////////////////////////////////////
/// @def ONII_OS_MICROWAREOS9
/// @brief Defined if one of the following macro is defined: @code __OS9000 _OSK @endcode
/////////////////////////////////////////////////
#undef ONII_OS_MICROWAREOS9
/////////////////////////////////////////////////

#if defined(__OS9000) || defined(_OSK)
# define ONII_OS_MICROWAREOS9 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_MICROWARE_OS9_HPP
