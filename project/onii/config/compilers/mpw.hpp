#ifndef ONII_CONFIG_COMPILERS_MPW_HPP
#define ONII_CONFIG_COMPILERS_MPW_HPP

#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
# define ONII_COMPILER_MPW 1
#endif

#endif // ONII_CONFIG_COMPILERS_MPW_HPP
