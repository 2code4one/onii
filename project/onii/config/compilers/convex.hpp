#ifndef ONII_CONFIG_COMPILERS_CONVEX_HPP
#define ONII_CONFIG_COMPILERS_CONVEX_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/convex.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_CONVEXC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_CONVEXC
/// @brief Defined if one of the following macro is defined: @code __convexc__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_CONVEXC
/////////////////////////////////////////////////

#if defined(__convexc__)
# define ONII_COMPILER_CONVEXC 1
#endif

#endif // ONII_CONFIG_COMPILERS_CONVEX_HPP
