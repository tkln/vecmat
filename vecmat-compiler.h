/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_COMPILER_H
#define VECMAT_COMPILER_H

#if defined(VECMAT_NOINLINE)
#   if defined(__clang__) || (defined(__GNUC__) && !defined(__INTEL_COMPILER))
#       define VECMAT_INLINE __attribute__((noinline))
#   elif defined(_MSC_VER)
#       define VECMAT_INLINE __declspec(noinline)
#   elif defined(__INTEL_COMPILER)
#       warning Unsuported compiler for force noinline
#   else
#       warning Unknown compiler, cannot force noinline
#   endif
#else
#   if defined(__clang__) || (defined(__GNUC__) && !defined(__INTEL_COMPILER))
#       define VECMAT_INLINE __attribute__((always_inline)) inline
#   elif defined(_MSC_VER) || defined(__INTEL_COMPILER)
#       define VECMAT_INLINE __forceinline
#   else
#       warning Unknown compiler, cannot force inline
#       define VECMAT_INLINE inline
#   endif
#endif

#endif
