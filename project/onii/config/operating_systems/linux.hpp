#ifndef ONII_CONFIG_OPERATING_SYSTEMS_LINUX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_LINUX_HPP

#if defined(__gnu_linux__) || defined(__linux__) || defined(linux) || defined(__linux)
# define ONII_OS_LINUX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_LINUX_HPP
