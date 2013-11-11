#ifndef ONII_CONFIG_COMPILERS_FUJITSU_HPP
#define ONII_CONFIG_COMPILERS_FUJITSU_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/fujitsu.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_FUJITSU 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_FUJITSU
/// @brief Defined if one of the following macro is defined: @code __FCC_VERSION @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_FUJITSU
/////////////////////////////////////////////////

#if defined(__FCC_VERSION)
# define ONII_COMPILER_FUJITSU 1
#endif

#endif // ONII_CONFIG_COMPILERS_FUJITSU_HPP
