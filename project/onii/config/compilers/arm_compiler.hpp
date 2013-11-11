#ifndef ONII_CONFIG_COMPILERS_ARM_COMPILER_HPP
#define ONII_CONFIG_COMPILERS_ARM_COMPILER_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/arm_compiler.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_ARM 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_ARM
/// @brief Defined if one of the following macro is defined: @code __CC_ARM @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_ARM
/////////////////////////////////////////////////

#if defined(__CC_ARM)
# define ONII_COMPILER_ARM 1
#endif

#endif // ONII_CONFIG_COMPILERS_ARM_COMPILER_HPP
