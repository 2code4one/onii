#ifndef ONII_CONFIG_COMPILERS_PALM_HPP
#define ONII_CONFIG_COMPILERS_PALM_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/palm.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_PALM 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_PALM
/// @brief Defined if one of the following macro is defined: @code _PACC_VER @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_PALM
/////////////////////////////////////////////////

#if defined(_PACC_VER)
# define ONII_COMPILER_PALM 1
#endif

#endif // ONII_CONFIG_COMPILERS_PALM_HPP
