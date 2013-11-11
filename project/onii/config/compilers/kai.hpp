#ifndef ONII_CONFIG_COMPILERS_KAI_HPP
#define ONII_CONFIG_COMPILERS_KAI_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/kai.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_KAI 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_KAI
/// @brief Defined if one of the following macro is defined: @code __KCC @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_KAI
/////////////////////////////////////////////////

#if defined(__KCC)
# define ONII_COMPILER_KAI 1
#endif

#endif // ONII_CONFIG_COMPILERS_KAI_HPP
