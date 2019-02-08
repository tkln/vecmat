
/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_VEC3F_H
#define VECMAT_VEC3F_H

#include <stdbool.h>
#include <math.h>

#include "vecmat-compiler.h"

#ifdef __cplusplus
extern "C" {
namespace vm {
#endif /* __cplusplus */

struct vec3f {
    float x, y, z;
};

static const struct vec3f vec3f_ones = { 1.0f, 1.0f, 1.0f };

static INLINE bool vec3f_eq(const struct vec3f a, const struct vec3f b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

static INLINE struct vec3f vec3f_inv(const struct vec3f v)
{
    return (struct vec3f) { -v.x, -v.y, -v.z };
}

static INLINE struct vec3f vec3f_adds(const struct vec3f a, const float s)
{
    return (struct vec3f) {
        a.x + s,
        a.y + s,
        a.z + s,
    };
}

static INLINE struct vec3f vec3f_subs(const struct vec3f a, const float s)
{
    return (struct vec3f) {
        a.x - s,
        a.y - s,
        a.z - s,
    };
}

static INLINE struct vec3f vec3f_add(const struct vec3f a, const struct vec3f b)
{
    return (struct vec3f) {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
    };
}

static INLINE struct vec3f vec3f_sub(const struct vec3f a, const struct vec3f b)
{
    return (struct vec3f) {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
    };
}

static INLINE struct vec3f vec3f_mul(const struct vec3f a, const struct vec3f b)
{
    return (struct vec3f) {
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
    };
}

static INLINE struct vec3f vec3f_div(const struct vec3f a, const struct vec3f b)
{
    return (struct vec3f) {
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
    };
}

static INLINE struct vec3f vec3f_mod(const struct vec3f a, const struct vec3f b)
{
    return (struct vec3f) {
        fmodf(a.x, b.x),
        fmodf(a.y, b.y),
        fmodf(a.z, b.z),
    };
}

static INLINE struct vec3f vec3f_muls(const struct vec3f v, const float s)
{
    return (struct vec3f) {
        v.x * s,
        v.y * s,
        v.z * s,
    };
}

static INLINE struct vec3f vec3f_divs(const struct vec3f v, const float s)
{
    return (struct vec3f) {
        v.x / s,
        v.y / s,
        v.z / s,
    };
}

static INLINE struct vec3f vec3f_mods(const struct vec3f v, const float s)
{
    return (struct vec3f) {
        fmodf(v.x, s),
        fmodf(v.y, s),
        fmodf(v.z, s),
    };
}

static INLINE float vec3f_dot(const struct vec3f a, const struct vec3f b)
{
    struct vec3f c = vec3f_mul(a, b);
    return c.x + c.y + c.z;
}

#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
