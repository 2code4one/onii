#ifndef ONII_CONFIG_OPERATING_SYSTEMS_WINDOWS_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_WINDOWS_HPP

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
# define ONII_OS_WINDOWS 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_WINDOWS_HPP
