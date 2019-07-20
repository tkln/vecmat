/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_COMPILER_H
#define VECMAT_COMPILER_H

#if defined(__clang__)
#   define VECMAT_COMPILER_CLANG
#elif (defined(__GNUC__) && !(defined(__INTEL_COMPILER)) || defined(__clang))
#   define VECMAT_COMPILER_GCC
#elif defined(_MSC_VER)
#   define VECMAT_COMPILER_MSVC
#elif defined(__INTEL_COMPILER)
#   define VECMAT_COMPILER_ICC
#else
#   warning Unknown compiler, cannot set compiler specific attributes
#endif

#if defined(VECMAT_NOINLINE)
#   if defined(VECMAT_COMPILER_GCC) || defined(VECMAT_COMPILER_CLANG)
#       define VECMAT_INLINE __attribute__((noinline))
#   elif defined(VECMAT_COMPILER_MSVC)
#       define VECMAT_INLINE __declspec(noinline)
#   elif defined(VECMAT_COMPILER_ICC)
#       warning noinline not supported on icc
#   endif
#else
#   if defined(VECMAT_COMPILER_GCC) || defined(VECMAT_COMPILER_CLANG)
#       define VECMAT_INLINE __attribute__((always_inline)) inline
#   elif defined(VECMAT_COMPILER_ICC) || defined(VECMAT_COMPILER_MSVC)
#       define VECMAT_INLINE __forceinline
#   else
#       define VECMAT_INLINE inline
#   endif
#endif

#if defined(VECMAT_ENABLE_ALIGN)
#   if defined(VECMAT_COMPILER_GCC) || defined(VECMAT_COMPILER_CLANG)
#       define VECMAT_ALIGN __attribute__((aligned(16)))
#   elif defined(VECMAT_COMPILER_MSVC) || defined(VECMAT_COMPILER_ICC)
#       define VECMAT_ALIGN __declspec(align(16))
#   endif
#   if defined(VECMAT_COMPILER_MSVC)
#       define VECMAT_ALIGN_WARN_SUPPRESS \
            __pragma(warning(disable: 4324)) __pragma(warning(disable: 4820))
#   else
#       define VECMAT_ALIGN_WARN_SUPPRESS
#   endif
#else
#   define VECMAT_ALIGN
#   define VECMAT_ALIGN_WARN_SUPPRESS
#endif

/*
 * GCC Warns about missing braces when compiling as C but won't accept the
 * additional braces in C++ mode.
 */
#if defined(VECMAT_COMPILER_GCC) && !defined(__cplusplus)
#   define VECMAT_INIT(type, x, ...) {{{ x, __VA_ARGS__ }}}
#else
#   if __cplusplus == 199711L || __cplusplus == 1
#       define VECMAT_INIT(type, x, ...) type(x, __VA_ARGS__)
#   else
#       define VECMAT_INIT(type, x, ...) { x, __VA_ARGS__ }
#   endif
#endif

#endif
