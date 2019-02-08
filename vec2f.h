/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_VEC2F_H
#define VECMAT_VEC2F_H

#include <stdbool.h>
#include <math.h>

#include "vecmat-compiler.h"

#ifdef __cplusplus
extern "C" {
namespace vm {
#endif /* __cplusplus */

struct vec2f {
    float x, y;
};

static const struct vec2f vec2f_ones = { 1.0f, 1.0f };

static INLINE bool vec2f_eq(const struct vec2f a, const struct vec2f b)
{
    return (a.x == b.x) && (a.y == b.y);
}

static INLINE struct vec2f vec2f_inv(const struct vec2f v)
{
    return (struct vec2f) { -v.x, -v.y };
}

static INLINE struct vec2f vec2f_add(const struct vec2f a, const struct vec2f b)
{
    return (struct vec2f) {
        a.x + b.x,
        a.y + b.y,
    };
}

static INLINE struct vec2f vec2f_sub(const struct vec2f a, const struct vec2f b)
{
    return (struct vec2f) {
        a.x - b.x,
        a.y - b.y,
    };
}

static INLINE struct vec2f vec2f_adds(const struct vec2f a, const float s)
{
    return (struct vec2f) {
        a.x + s,
        a.y + s,
    };
}

static INLINE struct vec2f vec2f_subs(const struct vec2f a, const float s)
{
    return (struct vec2f) {
        a.x - s,
        a.y - s,
    };
}

static INLINE struct vec2f vec2f_mul(const struct vec2f a, const struct vec2f b)
{
    return (struct vec2f) {
        a.x * b.x,
        a.y * b.y,
    };
}

static INLINE struct vec2f vec2f_div(const struct vec2f a, const struct vec2f b)
{
    return (struct vec2f) {
        a.x / b.x,
        a.y / b.y,
    };
}

static INLINE struct vec2f vec2f_mod(const struct vec2f a, const struct vec2f b)
{
    return (struct vec2f) {
        fmodf(a.x, b.x),
        fmodf(a.y, b.y),
    };
}

static INLINE struct vec2f vec2f_muls(const struct vec2f v, const float s)
{
    return (struct vec2f) {
        v.x * s,
        v.y * s,
    };
}

static INLINE struct vec2f vec2f_divs(const struct vec2f v, const float s)
{
    return (struct vec2f) {
        v.x / s,
        v.y / s,
    };
}

static INLINE struct vec2f vec2f_mods(const struct vec2f v, const float s)
{
    return (struct vec2f) {
        fmodf(v.x, s),
        fmodf(v.y, s),
    };
}

static INLINE float vec2f_dot(const struct vec2f a, const struct vec2f b)
{
    struct vec2f c = vec2f_mul(a, b);
    return c.x + c.y;
}

static INLINE float vec2f_norm2(const struct vec2f v)
{
    return vec2f_dot(v, v);
}

static INLINE float vec2f_norm(const struct vec2f v)
{
    return sqrtf(vec2f_norm2(v));
}

static INLINE struct vec2f vec2f_normalized(const struct vec2f v)
{
    return vec2f_divs(v, vec2f_norm(v));
}

#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
