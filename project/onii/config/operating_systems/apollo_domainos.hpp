#ifndef ONII_CONFIG_OPERATING_SYSTEMS_APOLLO_DOMAINOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_APOLLO_DOMAINOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/apollo_domainos.hpp
/////////////////////////////////////////////////
#define ONII_OS_APOLLODOMAINOS 1
/////////////////////////////////////////////////
/// @def ONII_OS_APOLLODOMAINOS
/// @brief Defined if one of the following macro is defined: @code apollo @endcode
/////////////////////////////////////////////////
#undef ONII_OS_APOLLODOMAINOS
/////////////////////////////////////////////////

#if defined(apollo)
# define ONII_OS_APOLLODOMAINOS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_APOLLO_DOMAINOS_HPP
