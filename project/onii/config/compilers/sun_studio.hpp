#ifndef ONII_CONFIG_COMPILERS_SUN_STUDIO_HPP
#define ONII_CONFIG_COMPILERS_SUN_STUDIO_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/sun_studio.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_SUNSTUDIO 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_SUNSTUDIO
/// @brief Defined if one of the following macro is defined: @code __SUNPRO_C __SUNPRO_CC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_SUNSTUDIO
/////////////////////////////////////////////////

#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
# define ONII_COMPILER_SUNSTUDIO 1
#endif

#endif // ONII_CONFIG_COMPILERS_SUN_STUDIO_HPP
