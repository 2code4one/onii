#ifndef ONII_CONFIG_OPERATING_SYSTEMS_NUCLEUS_RTOS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_NUCLEUS_RTOS_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/nucleus_rtos.hpp
/////////////////////////////////////////////////
#define ONII_OS_NUCLEUS 1
/////////////////////////////////////////////////
/// @def ONII_OS_NUCLEUS
/// @brief Defined if one of the following macro is defined: @code __nucleus__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_NUCLEUS
/////////////////////////////////////////////////

#if defined(__nucleus__)
# define ONII_OS_NUCLEUS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_NUCLEUS_RTOS_HPP
