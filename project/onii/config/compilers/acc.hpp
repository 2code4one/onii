#ifndef ONII_CONFIG_COMPILERS_ACC_HPP
#define ONII_CONFIG_COMPILERS_ACC_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/acc.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_ACC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_ACC
/// @brief Defined if one of the following macro is defined: @code _ACC_ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_ACC
/////////////////////////////////////////////////

#if defined(_ACC_)
# define ONII_COMPILER_ACC 1
#endif

#endif // ONII_CONFIG_COMPILERS_ACC_HPP
