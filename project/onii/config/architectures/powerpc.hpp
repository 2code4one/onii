#ifndef ONII_CONFIG_ARCHITECTURES_POWERPC_HPP
#define ONII_CONFIG_ARCHITECTURES_POWERPC_HPP

/////////////////////////////////////////////////
/// @file onii/config/architectures/powerpc.hpp
/////////////////////////////////////////////////
#define ONII_ARCH_POWERPC 1
/////////////////////////////////////////////////
/// @def ONII_ARCH_POWERPC
/// @brief Defined if one of the following macro is defined: @code __powerpc __powerpc__ __powerpc64__ __POWERPC__ __ppc__ __ppc64__ _M_PPC _ARCH_PPC @endcode
/////////////////////////////////////////////////
#undef ONII_ARCH_POWERPC
/////////////////////////////////////////////////

#if defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(_M_PPC) || defined(_ARCH_PPC)
# define ONII_ARCH_POWERPC 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_POWERPC_HPP
