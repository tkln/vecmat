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
namespace vm {
extern "C" {
#endif /* __cplusplus */

struct vec2i;
static VECMAT_INLINE bool vec2i_eq(const struct vec2i a, const struct vec2i b);
static VECMAT_INLINE struct vec2i vec2i_inv(const struct vec2i v);
static VECMAT_INLINE struct vec2i vec2i_add(const struct vec2i a,
                                            const struct vec2i b);
static VECMAT_INLINE struct vec2i vec2i_sub(const struct vec2i a,
                                            const struct vec2i b);
static VECMAT_INLINE struct vec2i vec2i_adds(const struct vec2i a,
                                             const int s);
static VECMAT_INLINE struct vec2i vec2i_subs(const struct vec2i a,
                                             const int s);
static VECMAT_INLINE struct vec2i vec2i_mul(const struct vec2i a,
                                            const struct vec2i b);
static VECMAT_INLINE struct vec2i vec2i_div(const struct vec2i a,
                                            const struct vec2i b);
static VECMAT_INLINE struct vec2i vec2i_muls(const struct vec2i v, const int s);
static VECMAT_INLINE struct vec2i vec2i_divs(const struct vec2i v, const int s);

struct VECMAT_ALIGN vec2i {
    int x, y;
#ifdef __cplusplus
    VECMAT_INLINE vec2i()
    {
    }

    VECMAT_INLINE vec2i(int x, int y) : x(x), y(y)
    {
    }
#endif /* __cplusplus */
};

static const struct vec2i vec2i_zeros = { 0, 0 };
static const struct vec2i vec2i_ones = { 1, 1 };

static VECMAT_INLINE struct vec2i vec2i_init(int x, int y)
{
    return (struct vec2i) { x, y };
}

static VECMAT_INLINE struct vec2i vec2i_inits(int s)
{
    return (struct vec2i) { s, s };
}

static VECMAT_INLINE struct vec2i vec2i_inv(const struct vec2i v)
{
    return (struct vec2i) { -v.x, -v.y };
}

static VECMAT_INLINE bool vec2i_eq(const struct vec2i a, const struct vec2i b)
{
    return (a.x == b.x) && (a.y == b.y);
}

static VECMAT_INLINE struct vec2i vec2i_add(const struct vec2i a,
                                            const struct vec2i b)
{
    return (struct vec2i) {
        a.x + b.x,
        a.y + b.y,
    };
}

static VECMAT_INLINE struct vec2i vec2i_add3(const struct vec2i a,
                                             const struct vec2i b,
                                             const struct vec2i c)
{
    return (struct vec2i) {
        a.x + b.x + c.x,
        a.y + b.y + c.y,
    };
}

static VECMAT_INLINE struct vec2i vec2i_sub(const struct vec2i a,
                                            const struct vec2i b)
{
    return (struct vec2i) {
        a.x - b.x,
        a.y - b.y,
    };
}

static VECMAT_INLINE struct vec2i vec2i_adds(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x + s,
        v.y + s,
    };
}

static VECMAT_INLINE struct vec2i vec2i_subs(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x - s,
        v.y - s,
    };
}

static VECMAT_INLINE struct vec2i vec2i_mul(const struct vec2i a,
                                            const struct vec2i b)
{
    return (struct vec2i) {
        a.x * b.x,
        a.y * b.y,
    };
}

static VECMAT_INLINE struct vec2i vec2i_div(const struct vec2i a,
                                            const struct vec2i b)
{
    return (struct vec2i) {
        a.x / b.x,
        a.y / b.y,
    };
}

static VECMAT_INLINE struct vec2i vec2i_mod(const struct vec2i a,
                                            const struct vec2i b)
{
    return (struct vec2i) {
        a.x % b.x,
        a.y % b.y,
    };
}

static VECMAT_INLINE struct vec2i vec2i_muls(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x * s,
        v.y * s,
    };
}

static VECMAT_INLINE struct vec2i vec2i_divs(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x / s,
        v.y / s,
    };
}

static VECMAT_INLINE struct vec2i vec2i_mods(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x % s,
        v.y % s,
    };
}

static VECMAT_INLINE int vec2i_dot(const struct vec2i a, const struct vec2i b)
{
    struct vec2i c = vec2i_mul(a, b);
    return c.x + c.y;
}

static VECMAT_INLINE int vec2i_norm2(const struct vec2i a)
{
    return vec2i_dot(a, a);
}

#ifdef __cplusplus
} /* extern "C" */

VECMAT_INLINE bool operator==(const vec2i a, const vec2i b)
{
    return vec2i_eq(a, b);
}

VECMAT_INLINE bool operator!=(const vec2i a, const vec2i b)
{
    return !vec2i_eq(a, b);
}

VECMAT_INLINE vec2i operator+(const vec2i v)
{
    return v;
}

VECMAT_INLINE vec2i operator-(const vec2i v)
{
    return vec2i_inv(v);
}

VECMAT_INLINE vec2i operator+(const vec2i a, const vec2i b)
{
    return vec2i_add(a, b);
}

VECMAT_INLINE vec2i operator-(const vec2i a, const vec2i b)
{
    return vec2i_sub(a, b);
}

VECMAT_INLINE vec2i operator+(const vec2i v, const float s)
{
    return vec2i_adds(v, s);
}

VECMAT_INLINE vec2i operator-(const vec2i v, const float s)
{
    return vec2i_subs(v, s);
}

VECMAT_INLINE vec2i operator+(const float s, const vec2i v)
{
    return vec2i_adds(v, s);
}

VECMAT_INLINE vec2i operator-(const float s, const vec2i v)
{
    return vec2i_adds(v, -s);
}

VECMAT_INLINE vec2i operator+=(vec2i &a, const vec2i b)
{
    return a = a + b;
}

VECMAT_INLINE vec2i operator-=(vec2i &a, const vec2i b)
{
    return a = a - b;
}

VECMAT_INLINE vec2i operator+=(vec2i &a, const int b)
{
    return a = a + b;
}

VECMAT_INLINE vec2i operator-=(vec2i &a, const int b)
{
    return a = a - b;
}

VECMAT_INLINE vec2i operator*(const vec2i a, const vec2i b)
{
    return vec2i_mul(a, b);
}

VECMAT_INLINE vec2i operator/(const vec2i a, const vec2i b)
{
    return vec2i_div(a, b);
}

VECMAT_INLINE vec2i operator%(const vec2i a, const vec2i b)
{
    return vec2i_mod(a, b);
}

VECMAT_INLINE vec2i operator*(const vec2i v, const float s)
{
    return vec2i_muls(v, s);
}

VECMAT_INLINE vec2i operator/(const vec2i v, const float s)
{
    return vec2i_divs(v, s);
}

VECMAT_INLINE vec2i operator%(const vec2i v, const float s)
{
    return vec2i_mods(v, s);
}

VECMAT_INLINE vec2i operator*(const float s, const vec2i v)
{
    return vec2i_muls(v, s);
}

VECMAT_INLINE vec2i operator/(const float s, const vec2i v)
{
    return vec2i(s, s) / v;
}

VECMAT_INLINE vec2i operator%(const float s, const vec2i v)
{
    return vec2i(s, s) % v;
}

VECMAT_INLINE int dot(const vec2i a, const vec2i b)
{
    return vec2i_dot(a, b);
}

} /* namespace vm */
#endif

#endif
