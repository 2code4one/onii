#ifndef ONII_CONFIG_LIBRARIES_MICROSOFT_FOUNDATION_CLASSES_HPP
#define ONII_CONFIG_LIBRARIES_MICROSOFT_FOUNDATION_CLASSES_HPP

/////////////////////////////////////////////////
/// @file onii/config/libraries/microsoft_foundation_classes.hpp
/////////////////////////////////////////////////
#define ONII_LIB_MFC 1
/////////////////////////////////////////////////
/// @def ONII_LIB_MFC
/// @brief Defined if one of the following macro is defined: @code _MFC_VER @endcode
/////////////////////////////////////////////////
#undef ONII_LIB_MFC
/////////////////////////////////////////////////

#if defined(_MFC_VER)
# define ONII_LIB_MFC 1
#endif

#endif // ONII_CONFIG_LIBRARIES_MICROSOFT_FOUNDATION_CLASSES_HPP
