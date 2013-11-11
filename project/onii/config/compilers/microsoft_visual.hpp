#ifndef ONII_CONFIG_COMPILERS_MICROSOFT_VISUAL_HPP
#define ONII_CONFIG_COMPILERS_MICROSOFT_VISUAL_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/microsoft_visual.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_VISUAL 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_VISUAL
/// @brief Defined if one of the following macro is defined: @code _MSC_VER @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_VISUAL
/////////////////////////////////////////////////

#if defined(_MSC_VER)
# define ONII_COMPILER_VISUAL 1
#endif

#endif // ONII_CONFIG_COMPILERS_MICROSOFT_VISUAL_HPP
