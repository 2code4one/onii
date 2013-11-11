#ifndef ONII_CONFIG_OPERATING_SYSTEMS_APOLLO_AEGIS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_APOLLO_AEGIS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/apollo_aegis.hpp
/////////////////////////////////////////////////
#define ONII_OS_APOLLOAEGIS 1
/////////////////////////////////////////////////
/// @def ONII_OS_APOLLOAEGIS
/// @brief Defined if one of the following macro is defined: @code aegis @endcode
/////////////////////////////////////////////////
#undef ONII_OS_APOLLOAEGIS
/////////////////////////////////////////////////

#if defined(aegis)
# define ONII_OS_APOLLOAEGIS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_APOLLO_AEGIS_HPP
