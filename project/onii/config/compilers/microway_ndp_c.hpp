#ifndef ONII_CONFIG_COMPILERS_MICROWAY_NDP_C_HPP
#define ONII_CONFIG_COMPILERS_MICROWAY_NDP_C_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/microway_ndp_c.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_NDPC 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_NDPC
/// @brief Defined if one of the following macro is defined: @code __NDPC__ __NDPX__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_NDPC
/////////////////////////////////////////////////

#if defined(__NDPC__) || defined(__NDPX__)
# define ONII_COMPILER_NDPC 1
#endif

#endif // ONII_CONFIG_COMPILERS_MICROWAY_NDP_C_HPP
