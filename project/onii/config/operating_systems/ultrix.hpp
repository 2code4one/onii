#ifndef ONII_CONFIG_OPERATING_SYSTEMS_ULTRIX_HPP
#define ONII_CONFIG_OPERATING_SYSTEMS_ULTRIX_HPP

#if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
# define ONII_OS_ULTRIX 1
#endif

#endif // ONII_CONFIG_OPERATING_SYSTEMS_ULTRIX_HPP
