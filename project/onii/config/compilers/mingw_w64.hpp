#ifndef ONII_CONFIG_COMPILERS_MINGW_W64_HPP
#define ONII_CONFIG_COMPILERS_MINGW_W64_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/mingw_w64.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_MINGW64 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_MINGW64
/// @brief Defined if one of the following macro is defined: @code __MINGW64__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_MINGW64
/////////////////////////////////////////////////

#if defined(__MINGW64__)
# define ONII_COMPILER_MINGW64 1
#endif

#endif // ONII_CONFIG_COMPILERS_MINGW_W64_HPP
