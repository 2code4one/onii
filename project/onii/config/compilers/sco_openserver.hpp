#ifndef ONII_CONFIG_COMPILERS_SCO_OPENSERVER_HPP
#define ONII_CONFIG_COMPILERS_SCO_OPENSERVER_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/sco_openserver.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_SCO 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_SCO
/// @brief Defined if one of the following macro is defined: @code _SCO_DS @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_SCO
/////////////////////////////////////////////////

#if defined(_SCO_DS)
# define ONII_COMPILER_SCO 1
#endif

#endif // ONII_CONFIG_COMPILERS_SCO_OPENSERVER_HPP
