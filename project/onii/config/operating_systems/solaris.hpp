#ifndef ONII_CONFIG_OPERATING_SYSTEMS_SOLARIS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_SOLARIS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/solaris.hpp
/////////////////////////////////////////////////
#define ONII_OS_SOLARIS 1
/////////////////////////////////////////////////
/// @def ONII_OS_SOLARIS
/// @brief Defined if one of the following macro is defined: @code sun __sun @endcode
/////////////////////////////////////////////////
#undef ONII_OS_SOLARIS
/////////////////////////////////////////////////

#if defined(sun) || defined(__sun)
# define ONII_OS_SOLARIS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_SOLARIS_HPP
