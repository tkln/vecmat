#include <stdlib.h>

#include "vec.h"

#include "test.h"

void test_vec2i(void)
{
    struct vec2i a = vec2i_ones;
    struct vec2i b = { 1, 2 };

    ASSERTM_EQ(a.x, 1, "got: %d", a.x);
    ASSERTM_EQ(a.y, 1, "got: %d", a.y);

    a = vec2i_inv(a);

    ASSERTM_EQ(a.x, -1, "got: %d", a.x);
    ASSERTM_EQ(a.y, -1, "got: %d", a.y);

    ASSERT(vec2i_eq((struct vec2i) { -1, -1 }, a));
    ASSERT(!vec2i_eq(a, b));
}

void test_vec2f(void)
{
    struct vec2f a = vec2f_ones;
    struct vec2f b = { 1.0f, 2.0f };

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);

    a = vec2f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);

    ASSERT(vec2f_eq((struct vec2f) { -1.0f, -1.0f }, a));
    ASSERT(!vec2f_eq(a, b));
}

void test_vec3f(void)
{
    struct vec3f a = vec3f_ones;
    struct vec3f b = { 1.0f, 2.0f, 3.0f };

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, 1.0f, "got: %f", a.z);

    a = vec3f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, -1.0f, "got: %f", a.z);

    ASSERT(vec3f_eq((struct vec3f) { -1.0f, -1.0f, -1.0f }, a));
    ASSERT(!vec3f_eq(a, b));
}

void test_vec4f(void)
{
    struct vec4f a = vec4f_ones;
    struct vec4f b = { 1.0f, 2.0f, 3.0f, 4.0f };

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, 1.0f, "got: %f", a.z);
    ASSERTM_EQ(a.w, 1.0f, "got: %f", a.w);

    a = vec4f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, -1.0f, "got: %f", a.z);
    ASSERTM_EQ(a.w, -1.0f, "got: %f", a.w);

    ASSERT(vec4f_eq((struct vec4f) { -1.0f, -1.0f, -1.0f, -1.0f }, a));
    ASSERT(!vec4f_eq(a, b));
}

int main(int argc, char **argv)
{
    test_vec2i();
    test_vec2f();
    test_vec3f();
    test_vec4f();

    return EXIT_SUCCESS;
}
