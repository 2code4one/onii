#ifndef ONII_CONFIG_OPERATING_SYSTEMS_TRU64_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_TRU64_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/tru64.hpp
/////////////////////////////////////////////////
#define ONII_OS_TRU64 1
/////////////////////////////////////////////////
/// @def ONII_OS_TRU64
/// @brief Defined if one of the following macro is defined: @code __osf__ __osf @endcode
/////////////////////////////////////////////////
#undef ONII_OS_TRU64
/////////////////////////////////////////////////

#if defined(__osf__) || defined(__osf)
# define ONII_OS_TRU64 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_TRU64_HPP
