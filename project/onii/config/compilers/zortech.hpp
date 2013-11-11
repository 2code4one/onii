#ifndef ONII_CONFIG_COMPILERS_ZORTECH_HPP
#define ONII_CONFIG_COMPILERS_ZORTECH_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/zortech.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_ZORTECH 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_ZORTECH
/// @brief Defined if one of the following macro is defined: @code __ZTC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_ZORTECH
/////////////////////////////////////////////////

#if defined(__ZTC__)
# define ONII_COMPILER_ZORTECH 1
#endif

#endif // ONII_CONFIG_COMPILERS_ZORTECH_HPP
