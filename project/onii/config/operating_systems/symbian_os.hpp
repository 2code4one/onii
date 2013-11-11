#ifndef ONII_CONFIG_OPERATING_SYSTEMS_SYMBIAN_OS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_SYMBIAN_OS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/symbian_os.hpp
/////////////////////////////////////////////////
#define ONII_OS_SYMBIAN 1
/////////////////////////////////////////////////
/// @def ONII_OS_SYMBIAN
/// @brief Defined if one of the following macro is defined: @code __SYMBIAN32__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_SYMBIAN
/////////////////////////////////////////////////

#if defined(__SYMBIAN32__)
# define ONII_OS_SYMBIAN 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_SYMBIAN_OS_HPP
