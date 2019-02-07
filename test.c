#include <stdlib.h>

#include "vec.h"

#include "test.h"

void test_vec2i(void)
{
    struct vec2i a = vec2i_ones;
    struct vec2i b = { 1, 2 };
    struct vec2i c;

    ASSERTM_EQ(a.x, 1, "got: %d", a.x);
    ASSERTM_EQ(a.y, 1, "got: %d", a.y);

    a = vec2i_inv(a);

    ASSERTM_EQ(a.x, -1, "got: %d", a.x);
    ASSERTM_EQ(a.y, -1, "got: %d", a.y);

    ASSERT(vec2i_eq((struct vec2i) { -1, -1 }, a));
    ASSERT(!vec2i_eq(a, b));

    ASSERTM(vec2i_eq(c = vec2i_add(b, a), (struct vec2i) {0, 1}),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_sub(b, a), (struct vec2i) {2, 3}),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_mul(b, a), (struct vec2i) {-1, -2}),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_mul(b, b), (struct vec2i) {1, 4}),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_div(b, b), vec2i_ones), "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_div(b, a), vec2i_inv(b)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_div(a, b), (struct vec2i) {-1, -0}),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_mod(b, b), (struct vec2i) {0, 0}),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_mod(a, b), (struct vec2i) {-0, -1}),
            "got %d, %d", c.x, c.y);
}

void test_vec2f(void)
{
    struct vec2f a = vec2f_ones;
    struct vec2f b = { 1.0f, 2.0f };
    struct vec2f c;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);

    a = vec2f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);

    ASSERT(vec2f_eq((struct vec2f) { -1.0f, -1.0f }, a));
    ASSERT(!vec2f_eq(a, b));

    ASSERTM(vec2f_eq(c = vec2f_add(b, a), (struct vec2f) {0.0f, 1.0f}),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_sub(b, a), (struct vec2f) {2.0f, 3.0f}),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_add(b, a), (struct vec2f) {0.0f, 1.0f}),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_sub(b, a), (struct vec2f) {2.0f, 3.0f}),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_mul(b, a), (struct vec2f) {-1.0f, -2.0f}),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_mul(b, b), (struct vec2f) {1.0f, 4.0f}),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_div(b, b), vec2f_ones), "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_div(b, a), vec2f_inv(b)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_div(a, b), (struct vec2f) {-1.0f, -0.5f}),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_mod(b, b), (struct vec2f) {0.0f, 0.0f}),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_mod(a, b), (struct vec2f) {-0.0f, -1.0f}),
            "got %f, %f", c.x, c.y);
}

void test_vec3f(void)
{
    struct vec3f a = vec3f_ones;
    struct vec3f b = { 1.0f, 2.0f, 3.0f };
    struct vec3f c;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, 1.0f, "got: %f", a.z);

    a = vec3f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, -1.0f, "got: %f", a.z);

    ASSERT(vec3f_eq((struct vec3f) { -1.0f, -1.0f, -1.0f }, a));
    ASSERT(!vec3f_eq(a, b));

    ASSERTM(vec3f_eq(c = vec3f_add(b, a),
                     (struct vec3f) {0.0f, 1.0f, 2.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_sub(b, a), (struct vec3f) {2.0f, 3.0f, 4.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_mul(b, a), (struct vec3f) {-1.0f, -2.0f, -3.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_mul(b, b), (struct vec3f) {1.0f, 4.0f, 9.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_div(b, b), vec3f_ones),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_div(b, a), vec3f_inv(b)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_div(a, b),
                     (struct vec3f) {-1.0f, -1.0f / 2.0f, -1.0f / 3.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_mod(b, b), (struct vec3f) {0.0f, 0.0f, 0.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_mod(a, b), (struct vec3f) {-0.0f, -1.0f, -1.0f}),
            "got %f, %f, %f", c.x, c.y, c.z);
}

void test_vec4f(void)
{
    struct vec4f a = vec4f_ones;
    struct vec4f b = { 1.0f, 2.0f, 3.0f, 4.0f };
    struct vec4f c;

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

    ASSERTM(vec4f_eq(c = vec4f_add(b, a),
                     (struct vec4f) {0.0f, 1.0f, 2.0f, 3.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_sub(b, a),
                     (struct vec4f) {2.0f, 3.0f, 4.0f, 5.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_add(b, a),
                     (struct vec4f) {0.0f, 1.0f, 2.0f, 3.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_sub(b, a),
                     (struct vec4f) {2.0f, 3.0f, 4.0f, 5.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_mul(b, a),
                     (struct vec4f) {-1.0f, -2.0f, -3.0f, -4.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_mul(b, b),
                     (struct vec4f) {1.0f, 4.0f, 9.0f, 16.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_div(b, b), vec4f_ones),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_div(b, a), vec4f_inv(b)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_div(a, b),
                     (struct vec4f) {-1.0f, -1.0f / 2.0f,
                                     -1.0f / 3.0f, -1.0f / 4.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_mod(b, b),
                     (struct vec4f) {0.0f, 0.0f, 0.0f, 0.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_mod(a, b),
                     (struct vec4f) {-0.0f, -1.0f, -1.0f, -1.0f}),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
}

int main(int argc, char **argv)
{
    test_vec2i();
    test_vec2f();
    test_vec3f();
    test_vec4f();

    return EXIT_SUCCESS;
}
