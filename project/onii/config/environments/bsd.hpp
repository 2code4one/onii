#ifndef ONII_CONFIG_ENVIRONMENTS_BSD_HPP
#define ONII_CONFIG_ENVIRONMENTS_BSD_HPP

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
# define ONII_ENV_BSD 1
#endif

#endif // ONII_CONFIG_ENVIRONMENTS_BSD_HPP
