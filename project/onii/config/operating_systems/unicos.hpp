#ifndef ONII_CONFIG_OPERATING_SYSTEMS_UNICOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_UNICOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/unicos.hpp
/////////////////////////////////////////////////
#define ONII_OS_UNICOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_UNICOS
/// @brief Defined if one of the following macro is defined: @code _UNICOS @endcode
/////////////////////////////////////////////////
#undef ONII_OS_UNICOS
/////////////////////////////////////////////////

#if defined(_UNICOS)
# define ONII_OS_UNICOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_UNICOS_HPP
