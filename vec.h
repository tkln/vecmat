#ifndef VECMAT_VEC_H
#define VECMAT_VEC_H

#ifdef __cplusplus
extern "C" {
namespace vm {
#endif /* __cplusplus */

struct vec2i {
    int x, y;
};

struct vec2f {
    float x, y;
};

struct vec3f {
    float x, y, z;
};

struct vec4f {
    float x, y, z, w;
};

#ifdef __cplusplus
} /* namespace vm */
} /* extern "C" */
#endif

#endif
