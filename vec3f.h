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
#endif /* __cplusplus */

struct vec3f;
static VECMAT_INLINE bool vec3f_eq(const struct vec3f a, const struct vec3f b);
static VECMAT_INLINE struct vec3f vec3f_inv(const struct vec3f v);
static VECMAT_INLINE struct vec3f vec3f_add(const struct vec3f a,
                                            const struct vec3f b);
static VECMAT_INLINE struct vec3f vec3f_sub(const struct vec3f a,
                                            const struct vec3f b);
static VECMAT_INLINE struct vec3f vec3f_adds(const struct vec3f a,
                                             const float s);
static VECMAT_INLINE struct vec3f vec3f_subs(const struct vec3f a,
                                             const float s);
static VECMAT_INLINE struct vec3f vec3f_mul(const struct vec3f a,
                                            const struct vec3f b);
static VECMAT_INLINE struct vec3f vec3f_div(const struct vec3f a,
                                            const struct vec3f b);
static VECMAT_INLINE struct vec3f vec3f_muls(const struct vec3f v,
                                             const float s);
static VECMAT_INLINE struct vec3f vec3f_divs(const struct vec3f v,
                                             const float s);
static VECMAT_INLINE struct vec3f vec3f_cross(const struct vec3f a,
                                              const struct vec3f b);
static VECMAT_INLINE struct vec3f vec3f_normalized(const struct vec3f v);
static VECMAT_INLINE float vec3f_norm2(const struct vec3f v);
static VECMAT_INLINE float vec3f_norm(const struct vec3f v);

VECMAT_ALIGN_WARN_SUPPRESS
struct VECMAT_ALIGN vec3f {
    union {
        struct {
            float x, y, z;
        };
    };
#ifdef __cplusplus
    VECMAT_INLINE vec3f()
    {
    }

    VECMAT_INLINE vec3f(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    VECMAT_INLINE float norm2() const
    {
        return vec3f_norm2(*this);
    }

    VECMAT_INLINE float norm() const
    {
        return vec3f_norm(*this);
    }

    VECMAT_INLINE vec3f normalized() const
    {
        return vec3f_normalized(*this);
    }
#endif /* __cplusplus */
};

static const struct vec3f vec3f_zeros = VECMAT_INIT(0.0f, 0.0f, 0.0f);
static const struct vec3f vec3f_ones = VECMAT_INIT(1.0f, 1.0f, 1.0f);

static VECMAT_INLINE struct vec3f vec3f_init(float x, float y, float z)
{
    struct vec3f v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

static VECMAT_INLINE struct vec3f vec3f_inits(float s)
{
    return vec3f_init(s, s, s);
}

static VECMAT_INLINE bool vec3f_eq(const struct vec3f a, const struct vec3f b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

static VECMAT_INLINE struct vec3f vec3f_inv(const struct vec3f v)
{
    return vec3f_init(-v.x, -v.y, -v.z);
}

static VECMAT_INLINE struct vec3f vec3f_adds(const struct vec3f a,
                                             const float s)
{
    return vec3f_init(
        a.x + s,
        a.y + s,
        a.z + s
    );
}

static VECMAT_INLINE struct vec3f vec3f_ssub(const float s,
                                             const struct vec3f a)
{
    return vec3f_init(
        s - a.x,
        s - a.y,
        s - a.z
    );
}

static VECMAT_INLINE struct vec3f vec3f_subs(const struct vec3f a,
                                             const float s)
{
    return vec3f_init(
        a.x - s,
        a.y - s,
        a.z - s
    );
}

static VECMAT_INLINE struct vec3f vec3f_add(const struct vec3f a,
                                            const struct vec3f b)
{
    return vec3f_init(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    );
}

static VECMAT_INLINE struct vec3f vec3f_add3(const struct vec3f a,
                                             const struct vec3f b,
                                             const struct vec3f c)
{
    return vec3f_init(
        a.x + b.x + c.x,
        a.y + b.y + c.y,
        a.z + b.z + c.z
    );
}

static VECMAT_INLINE struct vec3f vec3f_sub(const struct vec3f a,
                                            const struct vec3f b)
{
    return vec3f_init(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    );
}

static VECMAT_INLINE struct vec3f vec3f_mul(const struct vec3f a,
                                            const struct vec3f b)
{
    return vec3f_init(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    );
}

static VECMAT_INLINE struct vec3f vec3f_div(const struct vec3f a,
                                            const struct vec3f b)
{
    return vec3f_init(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
    );
}

static VECMAT_INLINE struct vec3f vec3f_mod(const struct vec3f a,
                                            const struct vec3f b)
{
    return vec3f_init(
        fmodf(a.x, b.x),
        fmodf(a.y, b.y),
        fmodf(a.z, b.z)
    );
}

static VECMAT_INLINE struct vec3f vec3f_muls(const struct vec3f v,
                                             const float s)
{
    return vec3f_init(
        v.x * s,
        v.y * s,
        v.z * s
    );
}

static VECMAT_INLINE struct vec3f vec3f_divs(const struct vec3f v,
                                             const float s)
{
    return vec3f_init(
        v.x / s,
        v.y / s,
        v.z / s
    );
}

static VECMAT_INLINE struct vec3f vec3f_mods(const struct vec3f v,
                                             const float s)
{
    return vec3f_init(
        fmodf(v.x, s),
        fmodf(v.y, s),
        fmodf(v.z, s)
    );
}

static VECMAT_INLINE float vec3f_dot(const struct vec3f a, const struct vec3f b)
{
    struct vec3f c = vec3f_mul(a, b);
    return c.x + c.y + c.z;
}

static VECMAT_INLINE float vec3f_norm2(const struct vec3f v)
{
    return vec3f_dot(v, v);
}

static VECMAT_INLINE float vec3f_norm(const struct vec3f v)
{
    return sqrtf(vec3f_norm2(v));
}

static VECMAT_INLINE struct vec3f vec3f_normalized(const struct vec3f v)
{
    return vec3f_divs(v, vec3f_norm(v));
}

static VECMAT_INLINE struct vec3f vec3f_cross(const struct vec3f a,
                                              const struct vec3f b)
{
    return vec3f_init(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

#ifdef __cplusplus

VECMAT_INLINE bool operator==(const vec3f a, const vec3f b)
{
    return vec3f_eq(a, b);
}

VECMAT_INLINE bool operator!=(const vec3f a, const vec3f b)
{
    return !vec3f_eq(a, b);
}

VECMAT_INLINE vec3f operator+(const vec3f v)
{
    return v;
}

VECMAT_INLINE vec3f operator-(const vec3f v)
{
    return vec3f_inv(v);
}

VECMAT_INLINE vec3f operator+(const vec3f a, const vec3f b)
{
    return vec3f_add(a, b);
}

VECMAT_INLINE vec3f operator-(const vec3f a, const vec3f b)
{
    return vec3f_sub(a, b);
}

VECMAT_INLINE vec3f operator+(const vec3f v, const float s)
{
    return vec3f_adds(v, s);
}

VECMAT_INLINE vec3f operator-(const vec3f v, const float s)
{
    return vec3f_subs(v, s);
}

VECMAT_INLINE vec3f operator+(const float s, const vec3f v)
{
    return vec3f_adds(v, s);
}

VECMAT_INLINE vec3f operator-(const float s, const vec3f v)
{
    return vec3f_adds(v, -s);
}

VECMAT_INLINE vec3f operator+=(vec3f &a, const vec3f b)
{
    return a = a + b;
}

VECMAT_INLINE vec3f operator-=(vec3f &a, const vec3f b)
{
    return a = a - b;
}

VECMAT_INLINE vec3f operator+=(vec3f &a, const float b)
{
    return a = a + b;
}

VECMAT_INLINE vec3f operator-=(vec3f &a, const float b)
{
    return a = a - b;
}

VECMAT_INLINE vec3f operator*(const vec3f a, const vec3f b)
{
    return vec3f_mul(a, b);
}

VECMAT_INLINE vec3f operator/(const vec3f a, const vec3f b)
{
    return vec3f_div(a, b);
}

VECMAT_INLINE vec3f operator%(const vec3f a, const vec3f b)
{
    return vec3f_mod(a, b);
}

VECMAT_INLINE vec3f operator*(const vec3f v, const float s)
{
    return vec3f_muls(v, s);
}

VECMAT_INLINE vec3f operator/(const vec3f v, const float s)
{
    return vec3f_divs(v, s);
}

VECMAT_INLINE vec3f operator%(const vec3f v, const float s)
{
    return vec3f_mods(v, s);
}

VECMAT_INLINE vec3f operator*(const float s, const vec3f v)
{
    return vec3f_muls(v, s);
}

VECMAT_INLINE vec3f operator/(const float s, const vec3f v)
{
    return vec3f(s, s, s) / v;
}

VECMAT_INLINE vec3f operator%(const float s, const vec3f v)
{
    return vec3f(s, s, s) % v;
}

VECMAT_INLINE float dot(const vec3f a, const vec3f b)
{
    return vec3f_dot(a, b);
}

VECMAT_INLINE vec3f cross(const vec3f a, const vec3f b)
{
    return vec3f_cross(a, b);
}

} /* namespace vm */
#endif

#endif
