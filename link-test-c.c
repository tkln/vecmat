#include "vec2f.h"

struct vec2f do_stuff(struct vec2f a, struct vec2f b)
{
    return vec2f_sub(b, vec2f_muls(a, 2));
}
