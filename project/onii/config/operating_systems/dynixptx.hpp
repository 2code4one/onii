#ifndef ONII_CONFIG_OPERATING_SYSTEMS_DYNIXPTX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_DYNIXPTX_HPP

/////////////////////////////////////////////////
/// @file onii/config/operating_systems/dynixptx.hpp
/////////////////////////////////////////////////
#define ONII_OS_DYNIXPTX 1
/////////////////////////////////////////////////
/// @def ONII_OS_DYNIXPTX
/// @brief Defined if one of the following macro is defined: @code _SEQUENT_ sequent @endcode
/////////////////////////////////////////////////
#undef ONII_OS_DYNIXPTX
/////////////////////////////////////////////////

#if defined(_SEQUENT_) || defined(sequent)
# define ONII_OS_DYNIXPTX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_DYNIXPTX_HPP
