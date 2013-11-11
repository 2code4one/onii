#ifndef ONII_CONFIG_OPERATING_SYSTEMS_DRAGONFLY_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_DRAGONFLY_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/dragonfly.hpp
/////////////////////////////////////////////////
#define ONII_OS_DRAGONFLY 1
/////////////////////////////////////////////////
/// @def ONII_OS_DRAGONFLY
/// @brief Defined if one of the following macro is defined: @code __DragonFly__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_DRAGONFLY
/////////////////////////////////////////////////

#if defined(__DragonFly__)
# define ONII_OS_DRAGONFLY 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_DRAGONFLY_HPP
