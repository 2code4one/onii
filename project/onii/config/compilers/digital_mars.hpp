#ifndef ONII_CONFIG_COMPILERS_DIGITAL_MARS_HPP
#define ONII_CONFIG_COMPILERS_DIGITAL_MARS_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/digital_mars.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_DMC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_DMC
/// @brief Defined if one of the following macro is defined: @code __DMC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_DMC
/////////////////////////////////////////////////

#if defined(__DMC__)
# define ONII_COMPILER_DMC 1
#endif

#endif // ONII_CONFIG_COMPILERS_DIGITAL_MARS_HPP
