/*
 * Copyright (c) 2019 Aapo Vienamo
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdlib.h>

#include "vec2i.h"
#include "vec2f.h"
#include "vec3f.h"
#include "vec4f.h"

#include "test.h"

void test_vec2i(void)
{
    struct vec2i a = vec2i_ones;
    struct vec2i b = vec2i_init(1, 2);
    struct vec2i c;

    ASSERTM_EQ(a.x, 1, "got: %d", a.x);
    ASSERTM_EQ(a.y, 1, "got: %d", a.y);

    a = vec2i_inv(a);

    ASSERTM_EQ(a.x, -1, "got: %d", a.x);
    ASSERTM_EQ(a.y, -1, "got: %d", a.y);

    ASSERT(vec2i_eq(vec2i_init(-1, -1), a));
    ASSERT(!vec2i_eq(a, b));

    ASSERTM(vec2i_eq(c = vec2i_add(b, a), vec2i_init(0, 1)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_sub(b, a), vec2i_init(2, 3)),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_adds(b, 1), vec2i_init(2, 3)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_subs(b, 1), vec2i_init(0, 1)),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_mul(b, a), vec2i_init(-1, -2)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_mul(b, b), vec2i_init(1, 4)),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_div(b, b), vec2i_ones), "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_div(b, a), vec2i_inv(b)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_div(a, b), vec2i_init(-1, -0)),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_mod(b, b), vec2i_init(0, 0)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_mod(a, b), vec2i_init(-0, -1)),
            "got %d, %d", c.x, c.y);

    ASSERTM(vec2i_eq(c = vec2i_muls(b, 2), vec2i_init(2, 4)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_divs(b, 2), vec2i_init(0, 1)),
            "got %d, %d", c.x, c.y);
    ASSERTM(vec2i_eq(c = vec2i_mods(b, 2), vec2i_init(1, 0)),
            "got %d, %d", c.x, c.y);

    ASSERT_EQ(vec2i_dot(b, b), 5);

    ASSERT_EQ(vec2i_norm2(b), 5);
}

void test_vec2f(void)
{
    struct vec2f a = vec2f_ones;
    struct vec2f b = vec2f_init(1.0f, 2.0f);
    struct vec2f c;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);

    a = vec2f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);

    ASSERT(vec2f_eq(vec2f_init(-1.0f, -1.0f), a));
    ASSERT(!vec2f_eq(a, b));

    ASSERTM(vec2f_eq(c = vec2f_add(b, a), vec2f_init(0.0f, 1.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_sub(b, a), vec2f_init(2.0f, 3.0f)),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_add(b, a), vec2f_init(0.0f, 1.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_sub(b, a), vec2f_init(2.0f, 3.0f)),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_adds(b, 1), vec2f_init(2.0f, 3.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_subs(b, 1), vec2f_init(0.0f, 1.0f)),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_mul(b, a), vec2f_init(-1.0f, -2.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_mul(b, b), vec2f_init(1.0f, 4.0f)),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_div(b, b), vec2f_ones), "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_div(b, a), vec2f_inv(b)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_div(a, b), vec2f_init(-1.0f, -0.5f)),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_mod(b, b), vec2f_init(0.0f, 0.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_mod(a, b), vec2f_init(-0.0f, -1.0f)),
            "got %f, %f", c.x, c.y);

    ASSERTM(vec2f_eq(c = vec2f_muls(b, 2), vec2f_init(2.0f, 4.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_divs(b, 2), vec2f_init(0.5f, 1.0f)),
            "got %f, %f", c.x, c.y);
    ASSERTM(vec2f_eq(c = vec2f_mods(b, 2), vec2f_init(1.0f, 0.0f)),
            "got %f, %f", c.x, c.y);

    ASSERT_EQ(vec2f_dot(b, b), 5.0f);

    ASSERT_EQ(vec2f_norm2(b), 5.0f);
    ASSERT_EQ(vec2f_norm(b), sqrtf(5.0f));
    ASSERTM(vec2f_eq(c = vec2f_normalized(vec2f_init(2.0f, 4.0f)),
                     vec2f_init(1.0 / sqrtf(5.0f), 2.0f / sqrtf(5.0f))),
            "got %f, %f", c.x, c.y);
}

void test_vec3f(void)
{
    struct vec3f a = vec3f_ones;
    struct vec3f b = vec3f_init(1.0f, 2.0f, 3.0f);
    struct vec3f c;

    ASSERTM_EQ(a.x, 1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, 1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, 1.0f, "got: %f", a.z);

    a = vec3f_inv(a);

    ASSERTM_EQ(a.x, -1.0f, "got: %f", a.x);
    ASSERTM_EQ(a.y, -1.0f, "got: %f", a.y);
    ASSERTM_EQ(a.z, -1.0f, "got: %f", a.z);

    ASSERT(vec3f_eq(vec3f_init(-1.0f, -1.0f, -1.0f), a));
    ASSERT(!vec3f_eq(a, b));

    ASSERTM(vec3f_eq(c = vec3f_add(b, a),
                     vec3f_init(0.0f, 1.0f, 2.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_sub(b, a), vec3f_init(2.0f, 3.0f, 4.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_adds(b, 1), vec3f_init(2.0f, 3.0f, 4.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_subs(b, 1), vec3f_init(0.0f, 1.0f, 2.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_mul(b, a), vec3f_init(-1.0f, -2.0f, -3.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_mul(b, b), vec3f_init(1.0f, 4.0f, 9.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_div(b, b), vec3f_ones),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_div(b, a), vec3f_inv(b)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_div(a, b),
                     vec3f_init(-1.0f, -1.0f / 2.0f, -1.0f / 3.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_mod(b, b), vec3f_init(0.0f, 0.0f, 0.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_mod(a, b), vec3f_init(-0.0f, -1.0f, -1.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_muls(b, 2), vec3f_init(2.0f, 4.0f, 6.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_divs(b, 2),
                     vec3f_init(0.5f, 1.0f, 3.0f / 2.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
    ASSERTM(vec3f_eq(c = vec3f_mods(b, 2), vec3f_init(1.0f, 0.0f, 1.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERT_EQ(vec3f_dot(b, b), 14.0f);

    ASSERT_EQ(vec3f_norm2(b), 14.0f);
    ASSERT_EQ(vec3f_norm(b), sqrtf(14.0f));

    ASSERTM(vec3f_eq(c = vec3f_normalized(vec3f_init(2, 4, 8)),
                     vec3f_init(1.0f / sqrtf(21.0f),
                                2.0f / sqrtf(21.0),
                                4.0f / sqrtf(21.0))),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_cross(vec3f_init(1.0f, 0.0f, 0.0f),
                                     vec3f_init(0.0f, 1.0f, 0.0f)),
                     vec3f_init(0.0f, 0.0f, 1.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);

    ASSERTM(vec3f_eq(c = vec3f_cross(vec3f_init(1.0f, 2.0f, 3.0f),
                                     vec3f_init(4.0f, 5.0f, 6.0f)),
                     vec3f_init(-3.0f, 6.0f, -3.0f)),
            "got %f, %f, %f", c.x, c.y, c.z);
}

void test_vec4f(void)
{
    struct vec4f a = vec4f_ones;
    struct vec4f b = vec4f_init(1.0f, 2.0f, 3.0f, 4.0f);
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

    ASSERT(vec4f_eq(vec4f_init(-1.0f, -1.0f, -1.0f, -1.0f), a));
    ASSERT(!vec4f_eq(a, b));

    ASSERTM(vec4f_eq(c = vec4f_add(b, a),
                     vec4f_init(0.0f, 1.0f, 2.0f, 3.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_sub(b, a),
                     vec4f_init(2.0f, 3.0f, 4.0f, 5.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_add(b, a),
                     vec4f_init(0.0f, 1.0f, 2.0f, 3.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_sub(b, a),
                     vec4f_init(2.0f, 3.0f, 4.0f, 5.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_adds(b, 1),
                     vec4f_init(2.0f, 3.0f, 4.0f, 5.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_subs(b, 1),
                     vec4f_init(0.0f, 1.0f, 2.0f, 3.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_mul(b, a),
                     vec4f_init(-1.0f, -2.0f, -3.0f, -4.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_mul(b, b),
                     vec4f_init(1.0f, 4.0f, 9.0f, 16.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_div(b, b), vec4f_ones),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_div(b, a), vec4f_inv(b)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_div(a, b),
                     vec4f_init(-1.0f, -1.0f / 2.0f,
                                -1.0f / 3.0f, -1.0f / 4.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_mod(b, b),
                     vec4f_init(0.0f, 0.0f, 0.0f, 0.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_mod(a, b),
                     vec4f_init(-0.0f, -1.0f, -1.0f, -1.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERTM(vec4f_eq(c = vec4f_muls(b, 2),
                     vec4f_init(2.0f, 4.0f, 6.0f, 8.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_divs(b, 2),
                     vec4f_init(0.5f, 1.0f, 3.0f / 2.0f, 2.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);
    ASSERTM(vec4f_eq(c = vec4f_mods(b, 2),
                     vec4f_init(1.0f, 0.0f, 1.0f, 0.0f)),
            "got %f, %f, %f, %f", c.x, c.y, c.z, c.w);

    ASSERT_EQ(vec4f_dot(b, b), 30.0f);

    ASSERT_EQ(vec4f_norm2(b), 30.0f);
    ASSERT_EQ(vec4f_norm(b), sqrtf(30.0f));
    ASSERTM(vec4f_eq(c = vec4f_normalized(vec4f_init(2, 4, 8, 16)),
                     vec4f_init(1.0f / sqrtf(85.0f),
                                2.0f / sqrtf(85.0),
                                4.0f / sqrtf(85.0),
                                8.0f / sqrtf(85.0))),
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
