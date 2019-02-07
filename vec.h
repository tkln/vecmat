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


#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
