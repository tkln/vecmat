/*
 * Copyright (c) 2019-2020 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_VEC2I_H
#define VECMAT_VEC2I_H

#include <stdbool.h>
#include <math.h>

#include "vecmat-compiler.h"

#ifdef __cplusplus
namespace vm {
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

#ifdef __cplusplus
namespace c {
extern "C" {
#endif /* __cplusplus */

VECMAT_ALIGN_WARN_SUPPRESS
struct VECMAT_ALIGN vec2i {
    union {
        struct {
            int x, y;
        };
    };
};

#ifdef __cplusplus
} /* namespace c */
} /* extern "C" */

VECMAT_ALIGN_WARN_SUPPRESS
struct VECMAT_ALIGN vec2i: public c::vec2i {
    VECMAT_INLINE vec2i()
    {
    }

    VECMAT_INLINE vec2i(c::vec2i v) : c::vec2i{v}
    {
    }

    VECMAT_INLINE vec2i(int x, int y) : c::vec2i{x, y}
    {
    }
};
#endif /* __cplusplus */

static const struct vec2i vec2i_zeros = VECMAT_INIT(0, 0);
static const struct vec2i vec2i_ones = VECMAT_INIT(1, 1);

static VECMAT_INLINE struct vec2i vec2i_init(int x, int y)
{
    struct vec2i v;
    v.x = x;
    v.y = y;
    return v;
}

static VECMAT_INLINE struct vec2i vec2i_inits(int s)
{
    return vec2i_init(s, s);
}

static VECMAT_INLINE struct vec2i vec2i_inv(const struct vec2i v)
{
    return vec2i_init(-v.x, -v.y);
}

static VECMAT_INLINE bool vec2i_eq(const struct vec2i a, const struct vec2i b)
{
    return (a.x == b.x) && (a.y == b.y);
}

static VECMAT_INLINE struct vec2i vec2i_add(const struct vec2i a,
                                            const struct vec2i b)
{
    return vec2i_init(
        a.x + b.x,
        a.y + b.y
    );
}

static VECMAT_INLINE struct vec2i vec2i_add3(const struct vec2i a,
                                             const struct vec2i b,
                                             const struct vec2i c)
{
    return vec2i_init(
        a.x + b.x + c.x,
        a.y + b.y + c.y
    );
}

static VECMAT_INLINE struct vec2i vec2i_sub(const struct vec2i a,
                                            const struct vec2i b)
{
    return vec2i_init(
        a.x - b.x,
        a.y - b.y
    );
}

static VECMAT_INLINE struct vec2i vec2i_adds(const struct vec2i v, const int s)
{
    return vec2i_init(
        v.x + s,
        v.y + s
    );
}

static VECMAT_INLINE struct vec2i vec2i_subs(const struct vec2i v, const int s)
{
    return vec2i_init(
        v.x - s,
        v.y - s
    );
}

static VECMAT_INLINE struct vec2i vec2i_mul(const struct vec2i a,
                                            const struct vec2i b)
{
    return vec2i_init(
        a.x * b.x,
        a.y * b.y
    );
}

static VECMAT_INLINE struct vec2i vec2i_div(const struct vec2i a,
                                            const struct vec2i b)
{
    return vec2i_init(
        a.x / b.x,
        a.y / b.y
    );
}

static VECMAT_INLINE struct vec2i vec2i_mod(const struct vec2i a,
                                            const struct vec2i b)
{
    return vec2i_init(
        a.x % b.x,
        a.y % b.y
    );
}

static VECMAT_INLINE struct vec2i vec2i_muls(const struct vec2i v, const int s)
{
    return vec2i_init(
        v.x * s,
        v.y * s
    );
}

static VECMAT_INLINE struct vec2i vec2i_divs(const struct vec2i v, const int s)
{
    return vec2i_init(
        v.x / s,
        v.y / s
    );
}

static VECMAT_INLINE struct vec2i vec2i_mods(const struct vec2i v, const int s)
{
    return vec2i_init(
        v.x % s,
        v.y % s
    );
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

VECMAT_INLINE vec2i operator+(const vec2i v, const int s)
{
    return vec2i_adds(v, s);
}

VECMAT_INLINE vec2i operator-(const vec2i v, const int s)
{
    return vec2i_subs(v, s);
}

VECMAT_INLINE vec2i operator+(const int s, const vec2i v)
{
    return vec2i_adds(v, s);
}

VECMAT_INLINE vec2i operator-(const int s, const vec2i v)
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

VECMAT_INLINE vec2i operator*(const vec2i v, const int s)
{
    return vec2i_muls(v, s);
}

VECMAT_INLINE vec2i operator/(const vec2i v, const int s)
{
    return vec2i_divs(v, s);
}

VECMAT_INLINE vec2i operator%(const vec2i v, const int s)
{
    return vec2i_mods(v, s);
}

VECMAT_INLINE vec2i operator*(const int s, const vec2i v)
{
    return vec2i_muls(v, s);
}

VECMAT_INLINE vec2i operator/(const int s, const vec2i v)
{
    return vec2i(s, s) / v;
}

VECMAT_INLINE vec2i operator%(const int s, const vec2i v)
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
