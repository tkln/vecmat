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
namespace vm {
extern "C" {
#endif /* __cplusplus */

struct vec2f;
static INLINE bool vec2f_eq(const struct vec2f a, const struct vec2f b);
static INLINE struct vec2f vec2f_inv(const struct vec2f v);
static INLINE struct vec2f vec2f_add(const struct vec2f a,
                                     const struct vec2f b);
static INLINE struct vec2f vec2f_sub(const struct vec2f a,
                                     const struct vec2f b);
static INLINE struct vec2f vec2f_adds(const struct vec2f a,
                                      const float s);
static INLINE struct vec2f vec2f_subs(const struct vec2f a,
                                      const float s);
static INLINE struct vec2f vec2f_mul(const struct vec2f a,
                                     const struct vec2f b);
static INLINE struct vec2f vec2f_div(const struct vec2f a,
                                     const struct vec2f b);
static INLINE struct vec2f vec2f_muls(const struct vec2f v, const float s);
static INLINE struct vec2f vec2f_divs(const struct vec2f v, const float s);
static INLINE struct vec2f vec2f_normalized(const struct vec2f v);
static INLINE float vec2f_norm2(const struct vec2f v);
static INLINE float vec2f_norm(const struct vec2f v);

struct vec2f {
    float x, y;
#ifdef __cplusplus
    INLINE vec2f(float x, float y) : x(x), y(y)
    {
    }

    INLINE float norm2() const
    {
        return vec2f_norm2(*this);
    }

    INLINE float norm() const
    {
        return vec2f_norm(*this);
    }

    INLINE vec2f normalized() const
    {
        return vec2f_normalized(*this);
    }
#endif /* __cplusplus */
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
} /* extern "C" */

INLINE bool operator==(const vec2f &a, const vec2f &b)
{
    return vec2f_eq(a, b);
}

INLINE bool operator!=(const vec2f &a, const vec2f &b)
{
    return !vec2f_eq(a, b);
}

INLINE vec2f operator+(const vec2f v)
{
    return v;
}

INLINE vec2f operator-(const vec2f v)
{
    return vec2f_inv(v);
}

INLINE vec2f operator+(const vec2f a, const vec2f b)
{
    return vec2f_add(a, b);
}

INLINE vec2f operator-(const vec2f a, const vec2f b)
{
    return vec2f_sub(a, b);
}

INLINE vec2f operator+(const vec2f v, const float s)
{
    return vec2f_adds(v, s);
}

INLINE vec2f operator-(const vec2f v, const float s)
{
    return vec2f_subs(v, s);
}

INLINE vec2f operator+(const float s, const vec2f v)
{
    return vec2f_adds(v, s);
}

INLINE vec2f operator-(const float s, const vec2f v)
{
    return vec2f_adds(v, -s);
}

INLINE vec2f operator+=(vec2f &a, const vec2f b)
{
    return a = a + b;
}

INLINE vec2f operator-=(vec2f &a, const vec2f b)
{
    return a = a - b;
}

INLINE vec2f operator+=(vec2f &a, const float b)
{
    return a = a + b;
}

INLINE vec2f operator-=(vec2f &a, const float b)
{
    return a = a - b;
}

INLINE vec2f operator*(const vec2f a, const vec2f b)
{
    return vec2f_mul(a, b);
}

INLINE vec2f operator/(const vec2f a, const vec2f b)
{
    return vec2f_div(a, b);
}

INLINE vec2f operator%(const vec2f a, const vec2f b)
{
    return vec2f_mod(a, b);
}

INLINE vec2f operator*(const vec2f v, const float s)
{
    return vec2f_muls(v, s);
}

INLINE vec2f operator/(const vec2f v, const float s)
{
    return vec2f_divs(v, s);
}

INLINE vec2f operator%(const vec2f v, const float s)
{
    return vec2f_mods(v, s);
}

INLINE vec2f operator*(const float s, const vec2f v)
{
    return vec2f_muls(v, s);
}

INLINE vec2f operator/(const float s, const vec2f v)
{
    return vec2f(s, s) / v;
}

INLINE vec2f operator%(const float s, const vec2f v)
{
    return vec2f(s, s) % v;
}

INLINE float dot(const vec2f a, const vec2f b)
{
    return vec2f_dot(a, b);
}

} /* namespace vm */
#endif

#endif
