#ifndef ONII_CONFIG_COMPILERS_EDG_FRONTEND_HPP
#define ONII_CONFIG_COMPILERS_EDG_FRONTEND_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/edg_frontend.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_EDG 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_EDG
/// @brief Defined if one of the following macro is defined: @code __EDG__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_EDG
/////////////////////////////////////////////////

#if defined(__EDG__)
# define ONII_COMPILER_EDG 1
#endif

#endif // ONII_CONFIG_COMPILERS_EDG_FRONTEND_HPP
