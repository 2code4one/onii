#ifndef ONII_CONFIG_OPERATING_SYSTEMS_AMDAHL_UTS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_AMDAHL_UTS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/amdahl_uts.hpp
/////////////////////////////////////////////////
#define ONII_OS_AMDAHLUTS 1
/////////////////////////////////////////////////
/// @def ONII_OS_AMDAHLUTS
/// @brief Defined if one of the following macro is defined: @code UTS @endcode
/////////////////////////////////////////////////
#undef ONII_OS_AMDAHLUTS
/////////////////////////////////////////////////

#if defined(UTS)
# define ONII_OS_AMDAHLUTS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_AMDAHL_UTS_HPP
