#ifndef ONII_CONFIG_COMPILERS_AMSTERDAM_COMPILER_KIT_HPP
#define ONII_CONFIG_COMPILERS_AMSTERDAM_COMPILER_KIT_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/amsterdam_compiler_kit.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_AMSTERDAMKIT 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_AMSTERDAMKIT
/// @brief Defined if one of the following macro is defined: @code __ACK__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_AMSTERDAMKIT
/////////////////////////////////////////////////

#if defined(__ACK__)
# define ONII_COMPILER_AMSTERDAMKIT 1
#endif

#endif // ONII_CONFIG_COMPILERS_AMSTERDAM_COMPILER_KIT_HPP
