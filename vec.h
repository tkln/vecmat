/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef VECMAT_VEC_H
#define VECMAT_VEC_H

#include <stdbool.h>
#include <math.h>

#include "vecmat-compiler.h"

#ifdef __cplusplus
extern "C" {
namespace vm {
#endif /* __cplusplus */

struct vec2i {
    int x, y;
};

static const struct vec2i vec2i_ones = { 1, 1 };

static INLINE struct vec2i vec2i_inv(const struct vec2i v)
{
    return (struct vec2i) { -v.x, -v.y };
}

static INLINE bool vec2i_eq(const struct vec2i a, const struct vec2i b)
{
    return (a.x == b.x) && (a.y == b.y);
}

static INLINE struct vec2i vec2i_add(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x + b.x,
        a.y + b.y,
    };
}

static INLINE struct vec2i vec2i_sub(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x - b.x,
        a.y - b.y,
    };
}

static INLINE struct vec2i vec2i_adds(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x + s,
        v.y + s,
    };
}

static INLINE struct vec2i vec2i_subs(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x - s,
        v.y - s,
    };
}

static INLINE struct vec2i vec2i_mul(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x * b.x,
        a.y * b.y,
    };
}

static INLINE struct vec2i vec2i_div(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x / b.x,
        a.y / b.y,
    };
}

static INLINE struct vec2i vec2i_mod(const struct vec2i a, const struct vec2i b)
{
    return (struct vec2i) {
        a.x % b.x,
        a.y % b.y,
    };
}

static INLINE struct vec2i vec2i_muls(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x * s,
        v.y * s,
    };
}

static INLINE struct vec2i vec2i_divs(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x / s,
        v.y / s,
    };
}

static INLINE struct vec2i vec2i_mods(const struct vec2i v, const int s)
{
    return (struct vec2i) {
        v.x % s,
        v.y % s,
    };
}

static INLINE int vec2i_dot(const struct vec2i a, const struct vec2i b)
{
    struct vec2i c = vec2i_mul(a, b);
    return c.x + c.y;
}


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


struct vec3f {
    float x, y, z;
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


struct vec4f {
    float x, y, z, w;
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


#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
