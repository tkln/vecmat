#ifndef LINK_TEST_C_H
#define LINK_TEST_C_H

#include "vec2f.h"

#ifdef __cplusplus
extern "C" {
struct vm::vec2f do_stuff(struct vm::vec2f a, struct vm::vec2f b);
};
#else
struct vec2f do_stuff(struct vec2f a, struct vec2f b);
#endif

#endif
