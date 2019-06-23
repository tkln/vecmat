#ifndef LINK_TEST_C_H
#define LINK_TEST_C_H

#include "vec2f.h"

#ifdef __cplusplus
using vm::vec2f;
extern "C" {
#endif

struct vec2f do_stuff(struct vec2f a, struct vec2f b);

#ifdef __cplusplus
};
#endif

#endif
