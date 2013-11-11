#ifndef ONII_CONFIG_OPERATING_SYSTEMS_ECOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_ECOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/ecos.hpp
/////////////////////////////////////////////////
#define ONII_OS_ECOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_ECOS
/// @brief Defined if one of the following macro is defined: @code __ECOS @endcode
/////////////////////////////////////////////////
#undef ONII_OS_ECOS
/////////////////////////////////////////////////

#if defined(__ECOS)
# define ONII_OS_ECOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_ECOS_HPP
