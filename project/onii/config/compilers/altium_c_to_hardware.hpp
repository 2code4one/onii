#ifndef ONII_CONFIG_COMPILERS_ALTIUM_C_TO_HARDWARE_HPP
#define ONII_CONFIG_COMPILERS_ALTIUM_C_TO_HARDWARE_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/altium_c_to_hardware.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_ALTIUMCTOHARDWARE 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_ALTIUMCTOHARDWARE
/// @brief Defined if one of the following macro is defined: @code __CHC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_ALTIUMCTOHARDWARE
/////////////////////////////////////////////////

#if defined(__CHC__)
# define ONII_COMPILER_ALTIUMCTOHARDWARE 1
#endif

#endif // ONII_CONFIG_COMPILERS_ALTIUM_C_TO_HARDWARE_HPP
