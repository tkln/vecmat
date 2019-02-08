/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_VEC4F_H
#define VECMAT_VEC4F_H

#include <stdbool.h>
#include <math.h>

#include "vecmat-compiler.h"

#ifdef __cplusplus
extern "C" {
namespace vm {
#endif /* __cplusplus */

struct vec4f {
    float x, y, z, w;
};

static const struct vec4f vec4f_ones = { 1.0f, 1.0f, 1.0f, 1.0f };

static INLINE bool vec4f_eq(const struct vec4f a, const struct vec4f b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
}

static INLINE struct vec4f vec4f_inv(const struct vec4f v)
{
    return (struct vec4f) { -v.x, -v.y, -v.z, -v.w };
}

static INLINE struct vec4f vec4f_sub(const struct vec4f a, const struct vec4f b)
{
    return (struct vec4f) {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w,
    };
}

static INLINE struct vec4f vec4f_add(const struct vec4f a, const struct vec4f b)
{
    return (struct vec4f) {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w,
    };
}

static INLINE struct vec4f vec4f_adds(const struct vec4f v, const float s)
{
    return (struct vec4f) {
        v.x + s,
        v.y + s,
        v.z + s,
        v.w + s,
    };
}

static INLINE struct vec4f vec4f_subs(const struct vec4f v, const float s)
{
    return (struct vec4f) {
        v.x - s,
        v.y - s,
        v.z - s,
        v.w - s,
    };
}

static INLINE struct vec4f vec4f_mul(const struct vec4f a, const struct vec4f b)
{
    return (struct vec4f) {
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w,
    };
}

static INLINE struct vec4f vec4f_div(const struct vec4f a, const struct vec4f b)
{
    return (struct vec4f) {
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
        a.w / b.w,
    };
}

static INLINE struct vec4f vec4f_mod(const struct vec4f a, const struct vec4f b)
{
    return (struct vec4f) {
        fmodf(a.x, b.x),
        fmodf(a.y, b.y),
        fmodf(a.z, b.z),
        fmodf(a.w, b.w),
    };
}

static INLINE struct vec4f vec4f_muls(const struct vec4f v, const float s)
{
    return (struct vec4f) {
        v.x * s,
        v.y * s,
        v.z * s,
        v.w * s,
    };
}

static INLINE struct vec4f vec4f_divs(const struct vec4f v, const float s)
{
    return (struct vec4f) {
        v.x / s,
        v.y / s,
        v.z / s,
        v.w / s,
    };
}

static INLINE struct vec4f vec4f_mods(const struct vec4f v, const float s)
{
    return (struct vec4f) {
        fmodf(v.x, s),
        fmodf(v.y, s),
        fmodf(v.z, s),
        fmodf(v.w, s),
    };
}

static INLINE float vec4f_dot(const struct vec4f a, const struct vec4f b)
{
    struct vec4f c = vec4f_mul(a, b);
    return c.x + c.y + c.z + c.w;
}


#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
