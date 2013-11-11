#ifndef ONII_CONFIG_COMPILERS_EKOPATH_HPP
#define ONII_CONFIG_COMPILERS_EKOPATH_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/ekopath.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_EKOPATH 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_EKOPATH
/// @brief Defined if one of the following macro is defined: @code __PATHCC__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_EKOPATH
/////////////////////////////////////////////////

#if defined(__PATHCC__)
# define ONII_COMPILER_EKOPATH 1
#endif

#endif // ONII_CONFIG_COMPILERS_EKOPATH_HPP
