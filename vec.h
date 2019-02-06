#ifndef VECMAT_VEC_H
#define VECMAT_VEC_H

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


struct vec2f {
    float x, y;
};

static const struct vec2f vec2f_ones = { 1.0f, 1.0f };

static INLINE struct vec2f vec2f_inv(const struct vec2f v)
{
    return (struct vec2f) { -v.x, -v.y };
}


struct vec3f {
    float x, y, z;
};

static const struct vec3f vec3f_ones = { 1.0f, 1.0f, 1.0f };

static INLINE struct vec3f vec3f_inv(const struct vec3f v)
{
    return (struct vec3f) { -v.x, -v.y, -v.z };
}


struct vec4f {
    float x, y, z, w;
};

static const struct vec4f vec4f_ones = { 1.0f, 1.0f, 1.0f, 1.0f };

static INLINE struct vec4f vec4f_inv(const struct vec4f v)
{
    return (struct vec4f) { -v.x, -v.y, -v.z, -v.w };
}

#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
