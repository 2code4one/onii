#ifndef ONII_CONFIG_COMPILERS_MINGW_HPP
#define ONII_CONFIG_COMPILERS_MINGW_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/mingw.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MINGW32 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MINGW32
/// @brief Defined if one of the following macro is defined: @code __MINGW32__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MINGW32
/////////////////////////////////////////////////

#if defined(__MINGW32__)
# define ONII_COMPILER_MINGW32 1
#endif

#endif // ONII_CONFIG_COMPILERS_MINGW_HPP
