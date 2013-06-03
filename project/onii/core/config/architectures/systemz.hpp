#ifndef ONII_CORE_CONFIG_ARCHITECTURES_SYSTEMZ_HPP
#define ONII_CORE_CONFIG_ARCHITECTURES_SYSTEMZ_HPP

#if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
# define ONII_ARCH_SYSTEMZ 1
#endif

#endif // ONII_CORE_CONFIG_ARCHITECTURES_SYSTEMZ_HPP
