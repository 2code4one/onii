#ifndef ONII_CONFIG_OPERATING_SYSTEMS_INTEGRITY_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_INTEGRITY_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/integrity.hpp
/////////////////////////////////////////////////
#define ONII_OS_INTEGRITY 1
/////////////////////////////////////////////////
/// @def ONII_OS_INTEGRITY
/// @brief Defined if one of the following macro is defined: @code __INTEGRITY @endcode
/////////////////////////////////////////////////
#undef ONII_OS_INTEGRITY
/////////////////////////////////////////////////

#if defined(__INTEGRITY)
# define ONII_OS_INTEGRITY 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_INTEGRITY_HPP
