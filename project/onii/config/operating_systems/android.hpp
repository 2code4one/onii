#ifndef ONII_CONFIG_OPERATING_SYSTEMS_ANDROID_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_ANDROID_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/android.hpp
/////////////////////////////////////////////////
#define ONII_OS_ANDROID 1
/////////////////////////////////////////////////
/// @def ONII_OS_ANDROID
/// @brief Defined if one of the following macro is defined: @code __ANDROID__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_ANDROID
/////////////////////////////////////////////////

#if defined(__ANDROID__)
# define ONII_OS_ANDROID 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_ANDROID_HPP
