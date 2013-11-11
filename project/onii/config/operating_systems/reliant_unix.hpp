#ifndef ONII_CONFIG_OPERATING_SYSTEMS_RELIANT_UNIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_RELIANT_UNIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/reliant_unix.hpp
/////////////////////////////////////////////////
#define ONII_OS_RELIANT 1
/////////////////////////////////////////////////
/// @def ONII_OS_RELIANT
/// @brief Defined if one of the following macro is defined: @code sinux @endcode
/////////////////////////////////////////////////
#undef ONII_OS_RELIANT
/////////////////////////////////////////////////

#if defined(sinux)
# define ONII_OS_RELIANT 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_RELIANT_UNIX_HPP
