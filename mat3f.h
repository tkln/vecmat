/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_MAT3F_H
#define VECMAT_MAT3F_H

#include <stdbool.h>

#include "vecmat-compiler.h"
#include "vec3f.h"
#include "mat2f.h"

#ifdef __cplusplus
namespace vm {
#endif

struct mat3f;
static VECMAT_INLINE struct mat3f mat3f_init_cols(struct vec3f c0,
                                                  struct vec3f c1,
                                                  struct vec3f c2);
static VECMAT_INLINE struct mat3f mat3f_init_rows(struct vec3f r0,
                                                  struct vec3f r1,
                                                  struct vec3f r2);
static VECMAT_INLINE struct mat3f mat3f_init(float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22);
static VECMAT_INLINE bool mat3f_eq(const struct mat3f a, const struct mat3f b);
static VECMAT_INLINE struct mat3f mat3f_add(const struct mat3f a,
                                            const struct mat3f b);
static VECMAT_INLINE struct mat3f mat3f_sub(const struct mat3f a,
                                            const struct mat3f b);
static VECMAT_INLINE struct mat3f mat3f_muls(const struct mat3f m,
                                             const float s);
static VECMAT_INLINE struct vec3f mat3f_mulv(const struct mat3f m,
                                             const struct vec3f v);
static VECMAT_INLINE struct mat3f mat3f_mul(const struct mat3f a,
                                            const struct mat3f b);
static VECMAT_INLINE struct mat3f mat3f_einv(const struct mat3f m);
static VECMAT_INLINE struct mat3f mat3f_divs(const struct mat3f m,
                                             const float s);
static VECMAT_INLINE struct mat3f mat3f_transpose(const struct mat3f m);
static VECMAT_INLINE float mat3f_det(const struct mat3f m);

VECMAT_ALIGN_WARN_SUPPRESS
struct VECMAT_ALIGN mat3f {
    union {
        float v[3][sizeof(struct vec3f) / sizeof(float)];
        struct vec3f col[3];
    };

#ifdef __cplusplus
    VECMAT_INLINE mat3f()
    {
    }

    VECMAT_INLINE mat3f(float v00, float v01, float v02,
                        float v10, float v11, float v12,
                        float v20, float v21, float v22) :
        v{{v00, v10, v20},
          {v01, v11, v21},
          {v02, v12, v22}}
    {
    }

    VECMAT_INLINE mat3f(vec3f r0, vec3f r1, vec3f r2)
    {
        *this = mat3f_init_rows(r0, r1, r2);
    }
#endif
};

static const struct mat3f mat3f_zeros = VECMAT_INIT({0.0f, 0.0f, 0.0f},
                                                    {0.0f, 0.0f, 0.0f},
                                                    {0.0f, 0.0f, 0.0f});

static const struct mat3f mat3f_ones = VECMAT_INIT({1.0f, 1.0f, 1.0f},
                                                   {1.0f, 1.0f, 1.0f},
                                                   {1.0f, 1.0f, 1.0f});

static const struct mat3f mat3f_identity = VECMAT_INIT({1.0f, 0.0f, 0.0f},
                                                       {0.0f, 1.0f, 0.0f},
                                                       {0.0f, 0.0f, 1.0f});

static VECMAT_INLINE struct mat3f mat3f_init_cols(struct vec3f c0,
                                                  struct vec3f c1,
                                                  struct vec3f c2)
{
    struct mat3f m;
    m.col[0] = c0;
    m.col[1] = c1;
    m.col[2] = c2;
    return m;
}

static VECMAT_INLINE struct mat3f mat3f_init_rows(struct vec3f r0,
                                                  struct vec3f r1,
                                                  struct vec3f r2)
{
    return mat3f_init_cols(vec3f_init(r0.x, r1.x, r2.x),
                           vec3f_init(r0.y, r1.y, r2.y),
                           vec3f_init(r0.z, r1.z, r2.z));
}

/* Row major notation */
static VECMAT_INLINE struct mat3f mat3f_init(float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22)
{
    return mat3f_init_cols(vec3f_init(v00, v10, v20),
                           vec3f_init(v01, v11, v21),
                           vec3f_init(v02, v12, v22));
}

static VECMAT_INLINE bool mat3f_eq(const struct mat3f a, const struct mat3f b)
{
    return vec3f_eq(a.col[0], b.col[0]) && vec3f_eq(a.col[1], b.col[1]) &&
           vec3f_eq(a.col[2], b.col[2]);
}

static VECMAT_INLINE struct mat3f mat3f_add(const struct mat3f a,
                                            const struct mat3f b)
{
    return mat3f_init_cols(vec3f_add(a.col[0], b.col[0]),
                           vec3f_add(a.col[1], b.col[1]),
                           vec3f_add(a.col[2], b.col[2]));
}

static VECMAT_INLINE struct mat3f mat3f_sub(const struct mat3f a,
                                            const struct mat3f b)
{
    return mat3f_init_cols(vec3f_sub(a.col[0], b.col[0]),
                           vec3f_sub(a.col[1], b.col[1]),
                           vec3f_sub(a.col[2], b.col[2]));
}

static VECMAT_INLINE struct mat3f mat3f_einv(const struct mat3f m)
{
    return mat3f_init_cols(vec3f_muls(m.col[0], -1.0f),
                           vec3f_muls(m.col[1], -1.0f),
                           vec3f_muls(m.col[2], -1.0f));
}

static VECMAT_INLINE struct mat3f mat3f_adds(const struct mat3f a,
                                             const float s)
{
    return mat3f_init_cols(vec3f_adds(a.col[0], s),
                           vec3f_adds(a.col[1], s),
                           vec3f_adds(a.col[2], s));
}

static VECMAT_INLINE struct mat3f mat3f_subs(const struct mat3f a,
                                             const float s)
{
    return mat3f_init_cols(vec3f_subs(a.col[0], s),
                           vec3f_subs(a.col[1], s),
                           vec3f_subs(a.col[2], s));
}

static VECMAT_INLINE struct mat3f mat3f_muls(const struct mat3f m,
                                             const float s)
{
    return mat3f_init_cols(vec3f_muls(m.col[0], s), vec3f_muls(m.col[1], s),
                           vec3f_muls(m.col[2], s));
}

static VECMAT_INLINE struct vec3f mat3f_mulv(const struct mat3f m,
                                             const struct vec3f v)
{
    return vec3f_add3(vec3f_muls(m.col[0], v.x), vec3f_muls(m.col[1], v.y),
                      vec3f_muls(m.col[2], v.z));
}

static VECMAT_INLINE struct mat3f mat3f_mul(const struct mat3f a,
                                            const struct mat3f b)
{
    return mat3f_init_cols(mat3f_mulv(a, b.col[0]), mat3f_mulv(a, b.col[1]),
                           mat3f_mulv(a, b.col[2]));
}

static VECMAT_INLINE struct mat3f mat3f_divs(const struct mat3f m,
                                             const float s)
{
    return mat3f_init_cols(vec3f_divs(m.col[0], s),
                           vec3f_divs(m.col[1], s),
                           vec3f_divs(m.col[2], s));
}

static VECMAT_INLINE struct mat3f mat3f_transpose(const struct mat3f m)
{
    return mat3f_init(m.v[0][0], m.v[0][1], m.v[0][2],
                      m.v[1][0], m.v[1][1], m.v[1][2],
                      m.v[2][0], m.v[2][1], m.v[2][2]);
}

static VECMAT_INLINE float mat3f_det(const struct mat3f m)
{
    struct mat2f a = mat2f_init(m.v[1][1], m.v[1][2], m.v[2][1], m.v[2][2]);
    struct mat2f b = mat2f_init(m.v[1][0], m.v[1][2], m.v[2][0], m.v[2][2]);
    struct mat2f c = mat2f_init(m.v[1][0], m.v[1][1], m.v[2][0], m.v[2][1]);
    return m.v[0][0] * mat2f_det(a) - m.v[0][1] * mat2f_det(b) +
           m.v[0][2] * mat2f_det(c);
}

#ifdef __cplusplus

VECMAT_INLINE bool operator==(const mat3f a, const mat3f b)
{
    return mat3f_eq(a, b);
}

VECMAT_INLINE bool operator!=(const mat3f a, const mat3f b)
{
    return !mat3f_eq(a, b);
}

VECMAT_INLINE mat3f operator+(const mat3f v)
{
    return v;
}

VECMAT_INLINE mat3f operator-(const mat3f v)
{
    return mat3f_einv(v);
}

VECMAT_INLINE mat3f operator+(const mat3f a, const mat3f b)
{
    return mat3f_add(a, b);
}

VECMAT_INLINE mat3f operator-(const mat3f a, const mat3f b)
{
    return mat3f_sub(a, b);
}

VECMAT_INLINE mat3f operator+(const mat3f v, const float s)
{
    return mat3f_adds(v, s);
}

VECMAT_INLINE mat3f operator-(const mat3f v, const float s)
{
    return mat3f_subs(v, s);
}

VECMAT_INLINE mat3f operator+(const float s, const mat3f v)
{
    return mat3f_adds(v, s);
}

VECMAT_INLINE mat3f operator-(const float s, const mat3f v)
{
    return mat3f_subs(v, s);
}

VECMAT_INLINE mat3f operator+=(mat3f &a, const mat3f b)
{
    return a = a + b;
}

VECMAT_INLINE mat3f operator-=(mat3f &a, const mat3f b)
{
    return a = a - b;
}

VECMAT_INLINE mat3f operator+=(mat3f &a, const float b)
{
    return a = a + b;
}

VECMAT_INLINE mat3f operator-=(mat3f &a, const float b)
{
    return a = a - b;
}

VECMAT_INLINE mat3f operator*(const mat3f a, const mat3f b)
{
    return mat3f_mul(a, b);
}

VECMAT_INLINE vec3f operator*(const mat3f m, const vec3f v)
{
    return mat3f_mulv(m, v);
}

} /* namespace vm */
#endif /* __cplusplus */ 

#endif
