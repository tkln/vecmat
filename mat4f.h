/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_MAT4F_H
#define VECMAT_MAT4F_H

#include <stdbool.h>

#include "vecmat-compiler.h"
#include "vec4f.h"
#include "mat3f.h"

#ifdef __cplusplus
namespace vm {
#endif

struct mat4f;
static VECMAT_INLINE struct mat4f mat4f_init_cols(struct vec4f c0,
                                                  struct vec4f c1,
                                                  struct vec4f c2,
                                                  struct vec4f c3);
static VECMAT_INLINE struct mat4f mat4f_init_rows(struct vec4f r0,
                                                  struct vec4f r1,
                                                  struct vec4f r2,
                                                  struct vec4f r3);
static VECMAT_INLINE struct mat4f
mat4f_init(float v00, float v01, float v02, float v03,
           float v10, float v11, float v12, float v13,
           float v20, float v21, float v22, float v23,
           float v30, float v31, float v32, float v33);
static VECMAT_INLINE bool mat4f_eq(const struct mat4f a, const struct mat4f b);
static VECMAT_INLINE struct mat4f mat4f_add(const struct mat4f a,
                                            const struct mat4f b);
static VECMAT_INLINE struct mat4f mat4f_sub(const struct mat4f a,
                                            const struct mat4f b);
static VECMAT_INLINE struct mat4f mat4f_muls(const struct mat4f m,
                                             const float s);
static VECMAT_INLINE struct vec4f mat4f_mulv(const struct mat4f m,
                                             const struct vec4f v);
static VECMAT_INLINE struct mat4f mat4f_mul(const struct mat4f a,
                                            const struct mat4f b);
static VECMAT_INLINE struct mat4f mat4f_divs(const struct mat4f m,
                                             const float s);
static VECMAT_INLINE struct mat4f mat4f_einv(const struct mat4f m);
static VECMAT_INLINE struct mat4f mat4f_transpose(const struct mat4f m);

VECMAT_ALIGN_WARN_SUPPRESS
struct VECMAT_ALIGN mat4f {
    union {
        float v[4][sizeof(struct vec4f) / sizeof(float)];
        struct vec4f col[4];
    };

#ifdef __cplusplus
    VECMAT_INLINE mat4f()
    {
    }

    VECMAT_INLINE mat4f(float v00, float v01, float v02, float v03,
                        float v10, float v11, float v12, float v13,
                        float v20, float v21, float v22, float v23,
                        float v30, float v31, float v32, float v33) :
        v{{v00, v10, v20, v30},
          {v01, v11, v21, v31},
          {v02, v12, v22, v32},
          {v03, v13, v23, v33}}
    {
    }

    VECMAT_INLINE mat4f(vec4f r0, vec4f r1, vec4f r2, vec4f r3)
    {
        *this = mat4f_init_rows(r0, r1, r2, r3);
    }
#endif
};

static const struct mat4f mat4f_zeros = VECMAT_INIT({0.0f, 0.0f, 0.0f, 0.0f},
                                                    {0.0f, 0.0f, 0.0f, 0.0f},
                                                    {0.0f, 0.0f, 0.0f, 0.0f},
                                                    {0.0f, 0.0f, 0.0f, 0.0f});

static const struct mat4f mat4f_ones = VECMAT_INIT({1.0f, 1.0f, 1.0f, 1.0f},
                                                   {1.0f, 1.0f, 1.0f, 1.0f},
                                                   {1.0f, 1.0f, 1.0f, 1.0f},
                                                   {1.0f, 1.0f, 1.0f, 1.0f});

static const struct mat4f mat4f_identity =
    VECMAT_INIT({1.0f, 0.0f, 0.0f, 0.0f},
                {0.0f, 1.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 1.0f, 0.0f},
                {0.0f, 0.0f, 0.0f, 1.0f});

static VECMAT_INLINE struct mat4f mat4f_init_cols(struct vec4f c0,
                                                  struct vec4f c1,
                                                  struct vec4f c2,
                                                  struct vec4f c3)
{
    struct mat4f m;
    m.col[0] = c0;
    m.col[1] = c1;
    m.col[2] = c2;
    m.col[3] = c3;
    return m;
}

static VECMAT_INLINE struct mat4f mat4f_init_rows(struct vec4f r0,
                                                  struct vec4f r1,
                                                  struct vec4f r2,
                                                  struct vec4f r3)
{
    return mat4f_init_cols(vec4f_init(r0.x, r1.x, r2.x, r3.x),
                           vec4f_init(r0.y, r1.y, r2.y, r3.y),
                           vec4f_init(r0.z, r1.z, r2.z, r3.z),
                           vec4f_init(r0.w, r1.w, r2.w, r3.w));
}

/* Row major notation */
static VECMAT_INLINE struct mat4f
mat4f_init(float v00, float v01, float v02, float v03,
           float v10, float v11, float v12, float v13,
           float v20, float v21, float v22, float v23,
           float v30, float v31, float v32, float v33)
{
    return mat4f_init_cols(vec4f_init(v00, v10, v20, v30),
                           vec4f_init(v01, v11, v21, v31),
                           vec4f_init(v02, v12, v22, v32),
                           vec4f_init(v03, v13, v23, v33));
}

static VECMAT_INLINE bool mat4f_eq(const struct mat4f a, const struct mat4f b)
{
    return vec4f_eq(a.col[0], b.col[0]) && vec4f_eq(a.col[1], b.col[1]) &&
           vec4f_eq(a.col[2], b.col[2]) && vec4f_eq(a.col[3], b.col[3]);
}

static VECMAT_INLINE struct mat4f mat4f_add(const struct mat4f a,
                                            const struct mat4f b)
{
    return mat4f_init_cols(vec4f_add(a.col[0], b.col[0]),
                           vec4f_add(a.col[1], b.col[1]),
                           vec4f_add(a.col[2], b.col[2]),
                           vec4f_add(a.col[3], b.col[3]));
}

static VECMAT_INLINE struct mat4f mat4f_sub(const struct mat4f a,
                                            const struct mat4f b)
{
    return mat4f_init_cols(vec4f_sub(a.col[0], b.col[0]),
                           vec4f_sub(a.col[1], b.col[1]),
                           vec4f_sub(a.col[2], b.col[2]),
                           vec4f_sub(a.col[3], b.col[3]));
}

static VECMAT_INLINE struct mat4f mat4f_einv(const struct mat4f m)
{
    return mat4f_init_cols(vec4f_muls(m.col[0], -1.0f),
                           vec4f_muls(m.col[1], -1.0f),
                           vec4f_muls(m.col[2], -1.0f),
                           vec4f_muls(m.col[3], -1.0f));
}

static VECMAT_INLINE struct mat4f mat4f_adds(const struct mat4f a,
                                             const float s)
{
    return mat4f_init_cols(vec4f_adds(a.col[0], s),
                           vec4f_adds(a.col[1], s),
                           vec4f_adds(a.col[2], s),
                           vec4f_adds(a.col[3], s));
}

static VECMAT_INLINE struct mat4f mat4f_subs(const struct mat4f a,
                                             const float s)
{
    return mat4f_init_cols(vec4f_subs(a.col[0], s),
                           vec4f_subs(a.col[1], s),
                           vec4f_subs(a.col[2], s),
                           vec4f_subs(a.col[3], s));
}

static VECMAT_INLINE struct mat4f mat4f_muls(const struct mat4f m,
                                             const float s)
{
    return mat4f_init_cols(vec4f_muls(m.col[0], s), vec4f_muls(m.col[1], s),
                           vec4f_muls(m.col[2], s), vec4f_muls(m.col[3], s));
}

static VECMAT_INLINE struct vec4f mat4f_mulv(const struct mat4f m,
                                             const struct vec4f v)
{
    return vec4f_add(vec4f_add(vec4f_muls(m.col[0], v.x),
                               vec4f_muls(m.col[1], v.y)),
                     vec4f_add(vec4f_muls(m.col[2], v.z),
                               vec4f_muls(m.col[3], v.w)));
}

static VECMAT_INLINE struct mat4f mat4f_mul(const struct mat4f a,
                                            const struct mat4f b)
{
    return mat4f_init_cols(mat4f_mulv(a, b.col[0]), mat4f_mulv(a, b.col[1]),
                           mat4f_mulv(a, b.col[2]), mat4f_mulv(a, b.col[3]));
}

static VECMAT_INLINE struct mat4f mat4f_divs(const struct mat4f m,
                                             const float s)
{
    return mat4f_init_cols(vec4f_divs(m.col[0], s),
                           vec4f_divs(m.col[1], s),
                           vec4f_divs(m.col[2], s),
                           vec4f_divs(m.col[3], s));
}

static VECMAT_INLINE struct mat4f mat4f_transpose(const struct mat4f m)
{
    return mat4f_init(m.v[0][0], m.v[0][1], m.v[0][2], m.v[0][3],
                      m.v[1][0], m.v[1][1], m.v[1][2], m.v[1][3],
                      m.v[2][0], m.v[2][1], m.v[2][2], m.v[2][3],
                      m.v[3][0], m.v[3][1], m.v[3][2], m.v[3][3]);
}

static VECMAT_INLINE float mat4f_det(const struct mat3f m)
{
    struct mat3f a = mat3f_init(m.v[1][1], m.v[1][2], m.v[1][3],
                                m.v[2][1], m.v[2][2], m.v[2][3],
                                m.v[3][1], m.v[3][2], m.v[3][3]);
    struct mat3f b = mat3f_init(m.v[1][0], m.v[1][2], m.v[1][3],
                                m.v[2][0], m.v[2][2], m.v[2][3],
                                m.v[3][0], m.v[3][2], m.v[3][3]);
    struct mat3f c = mat3f_init(m.v[1][0], m.v[1][1], m.v[1][3],
                                m.v[2][0], m.v[2][1], m.v[2][3],
                                m.v[3][0], m.v[3][1], m.v[3][3]);
    struct mat3f d = mat3f_init(m.v[1][0], m.v[1][1], m.v[1][2],
                                m.v[2][0], m.v[2][1], m.v[2][2],
                                m.v[3][0], m.v[3][1], m.v[3][2]);
    return m.v[0][0] * mat3f_det(a) - m.v[0][1] * mat3f_det(b) +
           m.v[0][2] * mat3f_det(c) - m.v[0][3] * mat3f_det(d);
}

#ifdef __cplusplus

VECMAT_INLINE bool operator==(const mat4f a, const mat4f b)
{
    return mat4f_eq(a, b);
}

VECMAT_INLINE bool operator!=(const mat4f a, const mat4f b)
{
    return !mat4f_eq(a, b);
}

VECMAT_INLINE mat4f operator+(const mat4f v)
{
    return v;
}

VECMAT_INLINE mat4f operator-(const mat4f v)
{
    return mat4f_einv(v);
}

VECMAT_INLINE mat4f operator+(const mat4f a, const mat4f b)
{
    return mat4f_add(a, b);
}

VECMAT_INLINE mat4f operator-(const mat4f a, const mat4f b)
{
    return mat4f_sub(a, b);
}

VECMAT_INLINE mat4f operator+(const mat4f v, const float s)
{
    return mat4f_adds(v, s);
}

VECMAT_INLINE mat4f operator-(const mat4f v, const float s)
{
    return mat4f_subs(v, s);
}

VECMAT_INLINE mat4f operator+(const float s, const mat4f v)
{
    return mat4f_adds(v, s);
}

VECMAT_INLINE mat4f operator-(const float s, const mat4f v)
{
    return mat4f_subs(v, s);
}

VECMAT_INLINE mat4f operator+=(mat4f &a, const mat4f b)
{
    return a = a + b;
}

VECMAT_INLINE mat4f operator-=(mat4f &a, const mat4f b)
{
    return a = a - b;
}

VECMAT_INLINE mat4f operator+=(mat4f &a, const float b)
{
    return a = a + b;
}

VECMAT_INLINE mat4f operator-=(mat4f &a, const float b)
{
    return a = a - b;
}

VECMAT_INLINE mat4f operator*(const mat4f a, const mat4f b)
{
    return mat4f_mul(a, b);
}

VECMAT_INLINE vec4f operator*(const mat4f m, const vec4f v)
{
    return mat4f_mulv(m, v);
}

} /* namespace vm */
#endif /* __cplusplus */ 

#endif
