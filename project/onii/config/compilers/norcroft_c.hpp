#ifndef ONII_CONFIG_COMPILERS_NORCROFT_C_HPP
#define ONII_CONFIG_COMPILERS_NORCROFT_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/norcroft_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_NORCROFTC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_NORCROFTC
/// @brief Defined if one of the following macro is defined: @code __CC_NORCROFT @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_NORCROFTC
/////////////////////////////////////////////////

#if defined(__CC_NORCROFT)
# define ONII_COMPILER_NORCROFTC 1
#endif

#endif // ONII_CONFIG_COMPILERS_NORCROFT_C_HPP
