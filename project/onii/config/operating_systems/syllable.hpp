#ifndef ONII_CONFIG_OPERATING_SYSTEMS_SYLLABLE_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_SYLLABLE_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/syllable.hpp
/////////////////////////////////////////////////
#define ONII_OS_SYLLABLE 1
/////////////////////////////////////////////////
/// @def ONII_OS_SYLLABLE
/// @brief Defined if one of the following macro is defined: @code __SYLLABLE__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_SYLLABLE
/////////////////////////////////////////////////

#if defined(__SYLLABLE__)
# define ONII_OS_SYLLABLE 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_SYLLABLE_HPP
