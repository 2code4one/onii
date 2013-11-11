#ifndef ONII_CONFIG_COMPILERS_ALTIUM_MICROBLAZE_C_HPP
#define ONII_CONFIG_COMPILERS_ALTIUM_MICROBLAZE_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/altium_microblaze_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_ALTIUMMICROBLAZEC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_ALTIUMMICROBLAZEC
/// @brief Defined if one of the following macro is defined: @code __CMB__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_ALTIUMMICROBLAZEC
/////////////////////////////////////////////////

#if defined(__CMB__)
# define ONII_COMPILER_ALTIUMMICROBLAZEC 1
#endif

#endif // ONII_CONFIG_COMPILERS_ALTIUM_MICROBLAZE_C_HPP
