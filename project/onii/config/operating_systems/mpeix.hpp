#ifndef ONII_CONFIG_OPERATING_SYSTEMS_MPEIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_MPEIX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/mpeix.hpp
/////////////////////////////////////////////////
#define ONII_OS_MPEIX 1
/////////////////////////////////////////////////
/// @def ONII_OS_MPEIX
/// @brief Defined if one of the following macro is defined: @code mpeix __mpexl @endcode
/////////////////////////////////////////////////
#undef ONII_OS_MPEIX
/////////////////////////////////////////////////

#if defined(mpeix) || defined(__mpexl)
# define ONII_OS_MPEIX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_MPEIX_HPP
