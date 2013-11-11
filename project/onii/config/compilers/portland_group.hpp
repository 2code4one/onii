#ifndef ONII_CONFIG_COMPILERS_PORTLAND_GROUP_HPP
#define ONII_CONFIG_COMPILERS_PORTLAND_GROUP_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/portland_group.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_PORTLANDGRP 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_PORTLANDGRP
/// @brief Defined if one of the following macro is defined: @code __PGI @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_PORTLANDGRP
/////////////////////////////////////////////////

#if defined(__PGI)
# define ONII_COMPILER_PORTLANDGRP 1
#endif

#endif // ONII_CONFIG_COMPILERS_PORTLAND_GROUP_HPP
