#ifndef ONII_CONFIG_COMPILERS_DIGNUS_SYSTEMS_HPP
#define ONII_CONFIG_COMPILERS_DIGNUS_SYSTEMS_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/dignus_systems.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_DIGNUSSYSTEMS 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_DIGNUSSYSTEMS
/// @brief Defined if one of the following macro is defined: @code __SYSC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_DIGNUSSYSTEMS
/////////////////////////////////////////////////

#if defined(__SYSC__)
# define ONII_COMPILER_DIGNUSSYSTEMS 1
#endif

#endif // ONII_CONFIG_COMPILERS_DIGNUS_SYSTEMS_HPP
