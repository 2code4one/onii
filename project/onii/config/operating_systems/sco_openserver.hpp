#ifndef ONII_CONFIG_OPERATING_SYSTEMS_SCO_OPENSERVER_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_SCO_OPENSERVER_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/sco_openserver.hpp
/////////////////////////////////////////////////
#define ONII_OS_SCOOPENSERVER 1
/////////////////////////////////////////////////
/// @def ONII_OS_SCOOPENSERVER
/// @brief Defined if one of the following macro is defined: @code M_I386 M_XENIX _SCO_DS @endcode
/////////////////////////////////////////////////
#undef ONII_OS_SCOOPENSERVER
/////////////////////////////////////////////////

#if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
# define ONII_OS_SCOOPENSERVER 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_SCO_OPENSERVER_HPP
