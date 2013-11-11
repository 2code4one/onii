#ifndef ONII_CONFIG_ARCHITECTURES_SPARC_HPP
#define ONII_CONFIG_ARCHITECTURES_SPARC_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/sparc.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_SPARC 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_SPARC
/// @brief Defined if one of the following macro is defined: @code __sparc__ __sparc @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_SPARC
/////////////////////////////////////////////////

#if defined(__sparc__) || defined(__sparc)
# define ONII_ARCH_SPARC 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_SPARC_HPP
