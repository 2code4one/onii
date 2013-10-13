#ifndef ONII_CONFIG_ARCHITECTURES_ARM_HPP
#define ONII_CONFIG_ARCHITECTURES_ARM_HPP

#if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT)
# define ONII_ARCH_ARM 1
#endif

#endif // ONII_CONFIG_ARCHITECTURES_ARM_HPP
