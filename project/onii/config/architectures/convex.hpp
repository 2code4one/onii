#ifndef ONII_CONFIG_ARCHITECTURES_CONVEX_HPP
#define ONII_CONFIG_ARCHITECTURES_CONVEX_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/convex.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_CONVEX 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_CONVEX
/// @brief Defined if one of the following macro is defined: @code __convex__ @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_CONVEX
/////////////////////////////////////////////////

#if defined(__convex__)
# define ONII_ARCH_CONVEX 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_CONVEX_HPP
