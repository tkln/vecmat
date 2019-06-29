/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_MAT2F_H
#define VECMAT_MAT2F_H

#include <stdbool.h>

#include "vecmat-compiler.h"
#include "vec2f.h"

#ifdef __cplusplus
namespace vm {
#endif

struct mat2f;
static VECMAT_INLINE struct mat2f mat2f_init_cols(struct vec2f c0,
                                                  struct vec2f c1);
static VECMAT_INLINE struct mat2f mat2f_init_rows(struct vec2f r0,
                                                  struct vec2f r1);
static VECMAT_INLINE struct mat2f mat2f_init(float v00, float v01,
                                             float v10, float v11);
static VECMAT_INLINE bool mat2f_eq(const struct mat2f a, const struct mat2f b);
static VECMAT_INLINE struct mat2f mat2f_add(const struct mat2f a,
                                            const struct mat2f b);
static VECMAT_INLINE struct mat2f mat2f_sub(const struct mat2f a,
                                            const struct mat2f b);
static VECMAT_INLINE struct mat2f mat2f_muls(const struct mat2f m,
                                             const float s);
static VECMAT_INLINE struct vec2f mat2f_mulv(const struct mat2f m,
                                             const struct vec2f v);
static VECMAT_INLINE struct mat2f mat2f_mul(const struct mat2f a,
                                            const struct mat2f b);
static VECMAT_INLINE struct mat2f mat2f_divs(const struct mat2f m,
                                             const float s);
static VECMAT_INLINE struct mat2f mat2f_einv(const struct mat2f m);
static VECMAT_INLINE struct mat2f mat2f_transpose(const struct mat2f m);

VECMAT_ALIGN_WARN_SUPPRESS
struct VECMAT_ALIGN mat2f {
    union {
        float v[2][sizeof(struct vec2f) / sizeof(float)];
        struct vec2f col[2];
    };

#ifdef __cplusplus
    VECMAT_INLINE mat2f()
    {
    }

    VECMAT_INLINE mat2f(float v00, float v01,
                        float v10, float v11) :
        v{{v00, v10},
          {v01, v11}}
    {
    }

    VECMAT_INLINE mat2f(vec2f r0, vec2f r1)
    {
        *this = mat2f_init_rows(r0, r1);
    }
#endif
};

static const struct mat2f mat2f_zeros = VECMAT_INIT({0.0f, 0.0f},
                                                    {0.0f, 0.0f});

static const struct mat2f mat2f_ones = VECMAT_INIT({1.0f, 1.0f},
                                                   {1.0f, 1.0f});

static const struct mat2f mat2f_identity = VECMAT_INIT({1.0f, 0.0f},
                                                       {0.0f, 1.0f});

static VECMAT_INLINE struct mat2f mat2f_init_cols(struct vec2f c0,
                                                  struct vec2f c1)
{
    struct mat2f m;
    m.col[0] = c0;
    m.col[1] = c1;
    return m;
}

static VECMAT_INLINE struct mat2f mat2f_init_rows(struct vec2f r0,
                                                  struct vec2f r1)
{
    return mat2f_init_cols(vec2f_init(r0.x, r1.x),
                           vec2f_init(r0.y, r1.y));
}

/* Row major notation */
static VECMAT_INLINE struct mat2f mat2f_init(float v00, float v01,
                                             float v10, float v11)
{
    return mat2f_init_cols(vec2f_init(v00, v10),
                           vec2f_init(v01, v11));
}

static VECMAT_INLINE bool mat2f_eq(const struct mat2f a, const struct mat2f b)
{
    return vec2f_eq(a.col[0], b.col[0]) && vec2f_eq(a.col[1], b.col[1]);
}

static VECMAT_INLINE struct mat2f mat2f_add(const struct mat2f a,
                                            const struct mat2f b)
{
    return mat2f_init_cols(vec2f_add(a.col[0], b.col[0]),
                           vec2f_add(a.col[1], b.col[1]));
}

static VECMAT_INLINE struct mat2f mat2f_sub(const struct mat2f a,
                                            const struct mat2f b)
{
    return mat2f_init_cols(vec2f_sub(a.col[0], b.col[0]),
                           vec2f_sub(a.col[1], b.col[1]));
}

static VECMAT_INLINE struct mat2f mat2f_einv(const struct mat2f m)
{
    return mat2f_init_cols(vec2f_muls(m.col[0], -1.0f),
                           vec2f_muls(m.col[1], -1.0f));
}

static VECMAT_INLINE struct mat2f mat2f_adds(const struct mat2f a,
                                             const float s)
{
    return mat2f_init_cols(vec2f_adds(a.col[0], s),
                           vec2f_adds(a.col[1], s));
}

static VECMAT_INLINE struct mat2f mat2f_subs(const struct mat2f a,
                                             const float s)
{
    return mat2f_init_cols(vec2f_subs(a.col[0], s),
                           vec2f_subs(a.col[1], s));
}

static VECMAT_INLINE struct mat2f mat2f_muls(const struct mat2f m,
                                             const float s)
{
    return mat2f_init_cols(vec2f_muls(m.col[0], s), vec2f_muls(m.col[1], s));
}

static VECMAT_INLINE struct vec2f mat2f_mulv(const struct mat2f m,
                                             const struct vec2f v)
{
    return vec2f_add(vec2f_muls(m.col[0], v.x), vec2f_muls(m.col[1], v.y));
}

static VECMAT_INLINE struct mat2f mat2f_mul(const struct mat2f a,
                                            const struct mat2f b)
{
    return mat2f_init_cols(mat2f_mulv(a, b.col[0]), mat2f_mulv(a, b.col[1]));
}

static VECMAT_INLINE struct mat2f mat2f_divs(const struct mat2f m,
                                             const float s)
{
    return mat2f_init_cols(vec2f_divs(m.col[0], s),
                           vec2f_divs(m.col[1], s));
}

static VECMAT_INLINE struct mat2f mat2f_transpose(const struct mat2f m)
{
    return mat2f_init(m.v[0][0], m.v[0][1],
                      m.v[1][0], m.v[1][1]);
}

static VECMAT_INLINE float mat2f_det(const struct mat2f m)
{
    return m.v[0][0] * m.v[1][1] - m.v[0][1] * m.v[1][0];
}

#ifdef __cplusplus

VECMAT_INLINE bool operator==(const mat2f a, const mat2f b)
{
    return mat2f_eq(a, b);
}

VECMAT_INLINE bool operator!=(const mat2f a, const mat2f b)
{
    return !mat2f_eq(a, b);
}

VECMAT_INLINE mat2f operator+(const mat2f v)
{
    return v;
}

VECMAT_INLINE mat2f operator-(const mat2f v)
{
    return mat2f_einv(v);
}

VECMAT_INLINE mat2f operator+(const mat2f a, const mat2f b)
{
    return mat2f_add(a, b);
}

VECMAT_INLINE mat2f operator-(const mat2f a, const mat2f b)
{
    return mat2f_sub(a, b);
}

VECMAT_INLINE mat2f operator+(const mat2f v, const float s)
{
    return mat2f_adds(v, s);
}

VECMAT_INLINE mat2f operator-(const mat2f v, const float s)
{
    return mat2f_subs(v, s);
}

VECMAT_INLINE mat2f operator+(const float s, const mat2f v)
{
    return mat2f_adds(v, s);
}

VECMAT_INLINE mat2f operator-(const float s, const mat2f v)
{
    return mat2f_subs(v, s);
}

VECMAT_INLINE mat2f operator+=(mat2f &a, const mat2f b)
{
    return a = a + b;
}

VECMAT_INLINE mat2f operator-=(mat2f &a, const mat2f b)
{
    return a = a - b;
}

VECMAT_INLINE mat2f operator+=(mat2f &a, const float b)
{
    return a = a + b;
}

VECMAT_INLINE mat2f operator-=(mat2f &a, const float b)
{
    return a = a - b;
}

VECMAT_INLINE mat2f operator*(const mat2f a, const mat2f b)
{
    return mat2f_mul(a, b);
}

VECMAT_INLINE vec2f operator*(const mat2f m, const vec2f v)
{
    return mat2f_mulv(m, v);
}

} /* namespace vm */
#endif /* __cplusplus */ 

#endif
