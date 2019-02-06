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


struct vec2f {
    float x, y;
};

static const struct vec2f vec2f_ones = { 1.0f, 1.0f };


struct vec3f {
    float x, y, z;
};

static const struct vec3f vec3f_ones = { 1.0f, 1.0f, 1.0f };


struct vec4f {
    float x, y, z, w;
};

static const struct vec4f vec4f_ones = { 1.0f, 1.0f, 1.0f, 1.0f };

#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
