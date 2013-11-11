#ifndef ONII_CONFIG_COMPILERS_LLVM_HPP
#define ONII_CONFIG_COMPILERS_LLVM_HPP

/////////////////////////////////////////////////
/// @file onii/config/compilers/llvm.hpp
/////////////////////////////////////////////////
#define ONII_COMPILER_LLVM 1
/////////////////////////////////////////////////
/// @def ONII_COMPILER_LLVM
/// @brief Defined if one of the following macro is defined: @code __llvm__ @endcode
/////////////////////////////////////////////////
#undef ONII_COMPILER_LLVM
/////////////////////////////////////////////////

#if defined(__llvm__)
# define ONII_COMPILER_LLVM 1
#endif

#endif // ONII_CONFIG_COMPILERS_LLVM_HPP
