#ifndef ONII_CONFIG_COMPILERS_SMALL_DEVICE_C_COMPILER_HPP
#define ONII_CONFIG_COMPILERS_SMALL_DEVICE_C_COMPILER_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/small_device_c_compiler.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_SDCC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_SDCC
/// @brief Defined if one of the following macro is defined: @code SDCC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_SDCC
/////////////////////////////////////////////////

#if defined(SDCC)
# define ONII_COMPILER_SDCC 1
#endif

#endif // ONII_CONFIG_COMPILERS_SMALL_DEVICE_C_COMPILER_HPP
