#ifndef ONII_CORE_CONFIG_STANDARDS_POSIX_HPP
#define ONII_CORE_CONFIG_STANDARDS_POSIX_HPP

#if defined(_POSIX_VERSION) || defined(_POSIX2_C_VERSION)
# define ONII_STD_POSIX 1
#endif

#endif // ONII_CORE_CONFIG_STANDARDS_POSIX_HPP
