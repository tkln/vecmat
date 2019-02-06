#include <stdlib.h>

#include "vec.h"

#include "test.h"

void test_vec2i(void)
{
    struct vec2i a = vec2i_ones;

    ASSERTM_EQ(a.x, 1, "got: %d", a.x);
    ASSERTM_EQ(a.y, 1, "got: %d", a.y);
}

void test_vec2f(void)
{
    struct vec2f a = vec2f_ones;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
}

void test_vec3f(void)
{
    struct vec3f a = vec3f_ones;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, 1.0f, "got: %f", a.z);
}

void test_vec4f(void)
{
    struct vec4f a = vec4f_ones;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, 1.0f, "got: %f", a.z);
    ASSERTM_EQ(a.w, 1.0f, "got: %f", a.w);
}

int main(int argc, char **argv)
{
    test_vec2i();
    test_vec2f();
    test_vec3f();
    test_vec4f();

    return EXIT_SUCCESS;
}
