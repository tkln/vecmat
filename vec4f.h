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
namespace vm {
extern "C" {
#endif /* __cplusplus */

struct vec4f;
static INLINE bool vec4f_eq(const struct vec4f a, const struct vec4f b);
static INLINE struct vec4f vec4f_inv(const struct vec4f v);
static INLINE struct vec4f vec4f_add(const struct vec4f a,
                                     const struct vec4f b);
static INLINE struct vec4f vec4f_sub(const struct vec4f a,
                                     const struct vec4f b);
static INLINE struct vec4f vec4f_adds(const struct vec4f a,
                                      const float s);
static INLINE struct vec4f vec4f_subs(const struct vec4f a,
                                      const float s);
static INLINE struct vec4f vec4f_mul(const struct vec4f a,
                                     const struct vec4f b);
static INLINE struct vec4f vec4f_div(const struct vec4f a,
                                     const struct vec4f b);
static INLINE struct vec4f vec4f_muls(const struct vec4f v, const float s);
static INLINE struct vec4f vec4f_divs(const struct vec4f v, const float s);

struct vec4f {
    float x, y, z, w;
#ifdef __cplusplus
    INLINE vec4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
    {
    }
#endif /* __cplusplus */
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

static INLINE float vec4f_norm2(const struct vec4f v)
{
    return vec4f_dot(v, v);
}

static INLINE float vec4f_norm(const struct vec4f v)
{
    return sqrtf(vec4f_norm2(v));
}

static INLINE struct vec4f vec4f_normalized(const struct vec4f v)
{
    return vec4f_divs(v, vec4f_norm(v));
}

#ifdef __cplusplus
} /* extern "C" */

INLINE bool operator==(const vec4f a, const vec4f b)
{
    return vec4f_eq(a, b);
}

INLINE bool operator!=(const vec4f a, const vec4f b)
{
    return !vec4f_eq(a, b);
}

INLINE vec4f operator+(const vec4f v)
{
    return v;
}

INLINE vec4f operator-(const vec4f v)
{
    return vec4f_inv(v);
}

INLINE vec4f operator+(const vec4f a, const vec4f b)
{
    return vec4f_add(a, b);
}

INLINE vec4f operator-(const vec4f a, const vec4f b)
{
    return vec4f_sub(a, b);
}

INLINE vec4f operator+(const vec4f v, const float s)
{
    return vec4f_adds(v, s);
}

INLINE vec4f operator-(const vec4f v, const float s)
{
    return vec4f_subs(v, s);
}

INLINE vec4f operator+(const float s, const vec4f v)
{
    return vec4f_adds(v, s);
}

INLINE vec4f operator-(const float s, const vec4f v)
{
    return vec4f_adds(v, -s);
}

INLINE vec4f operator*(const vec4f a, const vec4f b)
{
    return vec4f_mul(a, b);
}

INLINE vec4f operator/(const vec4f a, const vec4f b)
{
    return vec4f_div(a, b);
}

INLINE vec4f operator%(const vec4f a, const vec4f b)
{
    return vec4f_mod(a, b);
}

INLINE vec4f operator*(const vec4f v, const float s)
{
    return vec4f_muls(v, s);
}

INLINE vec4f operator/(const vec4f v, const float s)
{
    return vec4f_divs(v, s);
}

INLINE vec4f operator%(const vec4f v, const float s)
{
    return vec4f_mods(v, s);
}

INLINE vec4f operator*(const float s, const vec4f v)
{
    return vec4f_muls(v, s);
}

INLINE vec4f operator/(const float s, const vec4f v)
{
    return vec4f(s, s, s, s) / v;
}

INLINE vec4f operator%(const float s, const vec4f v)
{
    return vec4f(s, s, s, s) % v;
}

} /* namespace vm */
#endif

#endif
