
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
namespace vm {
extern "C" {
#endif /* __cplusplus */

struct vec3f;
static INLINE bool vec3f_eq(const struct vec3f a, const struct vec3f b);
static INLINE struct vec3f vec3f_inv(const struct vec3f v);
static INLINE struct vec3f vec3f_add(const struct vec3f a,
                                     const struct vec3f b);
static INLINE struct vec3f vec3f_sub(const struct vec3f a,
                                     const struct vec3f b);
static INLINE struct vec3f vec3f_adds(const struct vec3f a,
                                      const float s);
static INLINE struct vec3f vec3f_subs(const struct vec3f a,
                                      const float s);
static INLINE struct vec3f vec3f_mul(const struct vec3f a,
                                     const struct vec3f b);
static INLINE struct vec3f vec3f_div(const struct vec3f a,
                                     const struct vec3f b);
static INLINE struct vec3f vec3f_muls(const struct vec3f v, const float s);
static INLINE struct vec3f vec3f_divs(const struct vec3f v, const float s);
static INLINE struct vec3f vec3f_cross(const struct vec3f a,
                                       const struct vec3f b);
static INLINE struct vec3f vec3f_normalized(const struct vec3f v);

struct vec3f {
    float x, y, z;
#ifdef __cplusplus
    INLINE vec3f(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    INLINE vec3f normalized() const
    {
        return vec3f_normalized(*this);
    }
#endif /* __cplusplus */
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

static INLINE float vec3f_norm2(const struct vec3f v)
{
    return vec3f_dot(v, v);
}

static INLINE float vec3f_norm(const struct vec3f v)
{
    return sqrtf(vec3f_norm2(v));
}

static INLINE struct vec3f vec3f_normalized(const struct vec3f v)
{
    return vec3f_divs(v, vec3f_norm(v));
}

static INLINE struct vec3f vec3f_cross(const struct vec3f a, const struct vec3f b)
{
    return (struct vec3f) { a.y * b.z - a.z * b.y,
                            a.x * b.z - a.z * b.x,
                            a.x * b.y - a.y * b.x };
}

#ifdef __cplusplus
} /* extern "C" */

INLINE bool operator==(const vec3f a, const vec3f b)
{
    return vec3f_eq(a, b);
}

INLINE bool operator!=(const vec3f a, const vec3f b)
{
    return !vec3f_eq(a, b);
}

INLINE vec3f operator+(const vec3f v)
{
    return v;
}

INLINE vec3f operator-(const vec3f v)
{
    return vec3f_inv(v);
}

INLINE vec3f operator+(const vec3f a, const vec3f b)
{
    return vec3f_add(a, b);
}

INLINE vec3f operator-(const vec3f a, const vec3f b)
{
    return vec3f_sub(a, b);
}

INLINE vec3f operator+(const vec3f v, const float s)
{
    return vec3f_adds(v, s);
}

INLINE vec3f operator-(const vec3f v, const float s)
{
    return vec3f_subs(v, s);
}

INLINE vec3f operator+(const float s, const vec3f v)
{
    return vec3f_adds(v, s);
}

INLINE vec3f operator-(const float s, const vec3f v)
{
    return vec3f_adds(v, -s);
}

INLINE vec3f operator+=(vec3f &a, const vec3f b)
{
    return a = a + b;
}

INLINE vec3f operator-=(vec3f &a, const vec3f b)
{
    return a = a - b;
}

INLINE vec3f operator+=(vec3f &a, const float b)
{
    return a = a + b;
}

INLINE vec3f operator-=(vec3f &a, const float b)
{
    return a = a - b;
}

INLINE vec3f operator*(const vec3f a, const vec3f b)
{
    return vec3f_mul(a, b);
}

INLINE vec3f operator/(const vec3f a, const vec3f b)
{
    return vec3f_div(a, b);
}

INLINE vec3f operator%(const vec3f a, const vec3f b)
{
    return vec3f_mod(a, b);
}

INLINE vec3f operator*(const vec3f v, const float s)
{
    return vec3f_muls(v, s);
}

INLINE vec3f operator/(const vec3f v, const float s)
{
    return vec3f_divs(v, s);
}

INLINE vec3f operator%(const vec3f v, const float s)
{
    return vec3f_mods(v, s);
}

INLINE vec3f operator*(const float s, const vec3f v)
{
    return vec3f_muls(v, s);
}

INLINE vec3f operator/(const float s, const vec3f v)
{
    return vec3f(s, s, s) / v;
}

INLINE vec3f operator%(const float s, const vec3f v)
{
    return vec3f(s, s, s) % v;
}

INLINE float dot(const vec3f a, const vec3f b)
{
    return vec3f_dot(a, b);
}

INLINE vec3f cross(const vec3f a, const vec3f b)
{
    return vec3f_cross(a, b);
}

} /* namespace vm */
#endif

#endif
