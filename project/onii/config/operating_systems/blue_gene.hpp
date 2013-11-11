#ifndef ONII_CONFIG_OPERATING_SYSTEMS_BLUE_GENE_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_BLUE_GENE_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/blue_gene.hpp
/////////////////////////////////////////////////
#define ONII_OS_BLUEGENE 1
/////////////////////////////////////////////////
/// @def ONII_OS_BLUEGENE
/// @brief Defined if one of the following macro is defined: @code __bg__ @endcode
/////////////////////////////////////////////////
#undef ONII_OS_BLUEGENE
/////////////////////////////////////////////////

#if defined(__bg__)
# define ONII_OS_BLUEGENE 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_BLUE_GENE_HPP
