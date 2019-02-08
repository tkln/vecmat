/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_VEC2I_H
#define VECMAT_VEC2I_H

#include <stdbool.h>
#include <math.h>

#include "vecmat-compiler.h"

#ifdef __cplusplus
extern "C" {
namespace vm {
#endif /* __cplusplus */

struct vec2i;
static INLINE bool vec2i_eq(const struct vec2i a, const struct vec2i b);
static INLINE struct vec2i vec2i_inv(const struct vec2i v);
static INLINE struct vec2i vec2i_add(const struct vec2i a,
                                     const struct vec2i b);
static INLINE struct vec2i vec2i_sub(const struct vec2i a,
                                     const struct vec2i b);
static INLINE struct vec2i vec2i_adds(const struct vec2i a,
                                      const int s);
static INLINE struct vec2i vec2i_subs(const struct vec2i a,
                                      const int s);
static INLINE struct vec2i vec2i_mul(const struct vec2i a,
                                     const struct vec2i b);
static INLINE struct vec2i vec2i_div(const struct vec2i a,
                                     const struct vec2i b);
static INLINE struct vec2i vec2i_muls(const struct vec2i v, const int s);
static INLINE struct vec2i vec2i_divs(const struct vec2i v, const int s);

struct vec2i {
    int x, y;
};

static const struct vec2i vec2i_ones = { 1, 1 };

static INLINE struct vec2i vec2i_inv(const struct vec2i v)
{
    return (struct vec2i) { -v.x, -v.y };
}

static INLINE bool vec2i_eq(const struct vec2i a, const struct vec2i b)
{
    return (a.x == b.x) && (a.y == b.y);
}

static INLINE struct vec2i vec2i_add(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x + b.x,
        a.y + b.y,
    };
}

static INLINE struct vec2i vec2i_sub(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x - b.x,
        a.y - b.y,
    };
}

static INLINE struct vec2i vec2i_adds(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x + s,
        v.y + s,
    };
}

static INLINE struct vec2i vec2i_subs(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x - s,
        v.y - s,
    };
}

static INLINE struct vec2i vec2i_mul(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x * b.x,
        a.y * b.y,
    };
}

static INLINE struct vec2i vec2i_div(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x / b.x,
        a.y / b.y,
    };
}

static INLINE struct vec2i vec2i_mod(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x % b.x,
        a.y % b.y,
    };
}

static INLINE struct vec2i vec2i_muls(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x * s,
        v.y * s,
    };
}

static INLINE struct vec2i vec2i_divs(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x / s,
        v.y / s,
    };
}

static INLINE struct vec2i vec2i_mods(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x % s,
        v.y % s,
    };
}

static INLINE int vec2i_dot(const struct vec2i a, const struct vec2i b)
{
    struct vec2i c = vec2i_mul(a, b);
    return c.x + c.y;
}

static INLINE int vec2i_norm2(const struct vec2i a)
{
    return vec2i_dot(a, a);
}

#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
