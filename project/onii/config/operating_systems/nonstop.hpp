#ifndef ONII_CONFIG_OPERATING_SYSTEMS_NONSTOP_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_NONSTOP_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/nonstop.hpp
/////////////////////////////////////////////////
#define ONII_OS_NONSTOP 1
/////////////////////////////////////////////////
/// @def ONII_OS_NONSTOP
/// @brief Defined if one of the following macro is defined: @code __TANDEM @endcode
/////////////////////////////////////////////////
#undef ONII_OS_NONSTOP
/////////////////////////////////////////////////

#if defined(__TANDEM)
# define ONII_OS_NONSTOP 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_NONSTOP_HPP
