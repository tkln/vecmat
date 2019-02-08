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

using namespace vm;

void test_vec2i(void)
{
    vec2i a = vec2i(1, 2);
    ASSERT_EQ(a.x, 1);
    ASSERT_EQ(a.y, 2);

    ASSERT(a == vec2i(1, 2));
    ASSERT(a != vec2i(2, 2));

    ASSERT(+a == a);
    ASSERT_EQ(-a, vec2i(-1, -2));
    ASSERT_EQ(vec2i(1, 1) + vec2i(1, 2), vec2i(2, 3));
    ASSERT_EQ(vec2i(1, 1) - vec2i(1, 2), vec2i(0, -1));
    ASSERT_EQ(vec2i(1, 2) + 1, vec2i(2, 3));
    ASSERT_EQ(vec2i(1, 2) - 1, vec2i(0, 1));
    ASSERT_EQ(1 + vec2i(1, 2), vec2i(2, 3));
    ASSERT_EQ(1 - vec2i(1, 2), vec2i(0, 1));

    ASSERT_EQ(a * a, vec2i(1, 4));
    ASSERT_EQ(a * 2, vec2i(2, 4));
    ASSERT_EQ(2 * a, vec2i(2, 4));
    ASSERT_EQ(a / a, vec2i(1, 1));
    ASSERT_EQ(a / 2, vec2i(0, 1));
    ASSERT_EQ(2 / a, vec2i(2, 1));
    ASSERT_EQ(a % a, vec2i(0, 0));
    ASSERT_EQ(a % 2, vec2i(1, 0));
    ASSERT_EQ(2 % a, vec2i(0, 0));

    ASSERT_EQ(dot(a, a), 5);
}

void test_vec2f(void)
{
    vec2f a = vec2f(1.0f, 2.0f);
    ASSERT_EQ(a.x, 1.0f);
    ASSERT_EQ(a.y, 2.0f);

    ASSERT(a == vec2f(1.0f, 2.0f));
    ASSERT(a != vec2f(2.0f, 2.0f));

    ASSERT(+a == a);
    ASSERT_EQ(-a, vec2f(-1.0f, -2.0f));
    ASSERT_EQ(vec2f(1.0f, 1.0f) + a, vec2f(2.0f, 3.0f));
    ASSERT_EQ(vec2f(1.0f, 1.0f) - a, vec2f(0.0f, -1.0f));
    ASSERT_EQ(a + 1.0f, vec2f(2.0f, 3.0f));
    ASSERT_EQ(a - 1.0f, vec2f(0.0f, 1.0f));
    ASSERT_EQ(1.0f + a, vec2f(2.0f, 3.0f));
    ASSERT_EQ(1.0f - a, vec2f(0.0f, 1.0f));

    ASSERT_EQ(a * a, vec2f(1.0f, 4.0f));
    ASSERT_EQ(a * 2.0f, vec2f(2.0f, 4.0f));
    ASSERT_EQ(2.0f * a, vec2f(2.0f, 4.0f));
    ASSERT_EQ(a / a, vec2f(1.0f, 1.0f));
    ASSERT_EQ(a / 2.0f, vec2f(0.5f, 1.0f));
    ASSERT_EQ(2.0f / a, vec2f(2.0f, 1.0f));
    ASSERT_EQ(a % a, vec2f(0.0f, 0.0f));
    ASSERT_EQ(a % 2.0f, vec2f(1.0f, 0.0f));
    ASSERT_EQ(2.0f % a, vec2f(0.0f, 0.0f));

    ASSERT_EQ(dot(a, a), 5.0f);
}

void test_vec3f(void)
{
    vec3f a = vec3f(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(a.x, 1.0f);
    ASSERT_EQ(a.y, 2.0f);
    ASSERT_EQ(a.z, 3.0f);

    ASSERT(a == vec3f(1.0f, 2.0f, 3.0f));
    ASSERT(a != vec3f(2.0f, 2.0f, 2.0f));

    ASSERT_EQ(+a, a);
    ASSERT_EQ(-a, vec3f(-1.0f, -2.0f, -3.0f));
    ASSERT_EQ(vec3f(1.0f, 1.0f, 1.0f) + a, vec3f(2.0f, 3.0f, 4.0f));
    ASSERT_EQ(vec3f(1.0f, 1.0f, 1.0f) - a, vec3f(0.0f, -1.0f, -2.0f));
    ASSERT_EQ(a + 1.0f, vec3f(2.0f, 3.0f, 4.0f));
    ASSERT_EQ(a - 1.0f, vec3f(0.0f, 1.0f, 2.0f));
    ASSERT_EQ(1.0f + a, vec3f(2.0f, 3.0f, 4.0f));
    ASSERT_EQ(1.0f - a, vec3f(0.0f, 1.0f, 2.0f));

    ASSERT_EQ(a * a, vec3f(1.0f, 4.0f, 9.0f));
    ASSERT_EQ(a * 2.0f, vec3f(2.0f, 4.0f, 6.0f));
    ASSERT_EQ(2.0f * a, vec3f(2.0f, 4.0f, 6.0f));
    ASSERT_EQ(a / a, vec3f(1.0f, 1.0f, 1.0f));
    ASSERT_EQ(a / 2.0f, vec3f(0.5f, 1.0f, 1.5f));
    ASSERT_EQ(2.0f / a, vec3f(2.0f, 1.0f, 2.0f / 3.0f));
    ASSERT_EQ(a % a, vec3f(0.0f, 0.0f, 0.0f));
    ASSERT_EQ(a % 2.0f, vec3f(1.0f, 0.0f, 1.0f));
    ASSERT_EQ(2.0f % a, vec3f(0.0f, 0.0f, 2.0f));

    ASSERT_EQ(dot(a, a), 14.0f);
}

void test_vec4f(void)
{
    vec4f a = vec4f(1.0f, 2.0f, 3.0f, 4.0f);
    ASSERT_EQ(a.x, 1.0f);
    ASSERT_EQ(a.y, 2.0f);
    ASSERT_EQ(a.z, 3.0f);
    ASSERT_EQ(a.w, 4.0f);

    ASSERT(a == vec4f(1.0f, 2.0f, 3.0f, 4.0f));
    ASSERT(a != vec4f(2.0f, 2.0f, 2.0f, 2.0f));

    ASSERT(+a == a);
    ASSERT_EQ(-a, vec4f(-1.0f, -2.0f, -3.0f, -4.0f));
    ASSERT_EQ(vec4f(1.0f, 1.0f, 1.0f, 1.0f) + a, vec4f(2.0f, 3.0f, 4.0f, 5.0f));
    ASSERT_EQ(vec4f(1.0f, 1.0f, 1.0f, 1.0f) - a, vec4f(0.0f, -1.0f, -2.0f, -3.0f));
    ASSERT_EQ(a + 1.0f, vec4f(2.0f, 3.0f, 4.0f, 5.0f));
    ASSERT_EQ(a - 1.0f, vec4f(0.0f, 1.0f, 2.0f, 3.0f));
    ASSERT_EQ(1.0f + a, vec4f(2.0f, 3.0f, 4.0f, 5.0f));
    ASSERT_EQ(1.0f - a, vec4f(0.0f, 1.0f, 2.0f, 3.0f));

    ASSERT_EQ(a * a, vec4f(1.0f, 4.0f, 9.0f, 16.0f));
    ASSERT_EQ(a * 2.0f, vec4f(2.0f, 4.0f, 6.0f, 8.0f));
    ASSERT_EQ(2.0f * a, vec4f(2.0f, 4.0f, 6.0f, 8.0f));
    ASSERT_EQ(a / a, vec4f(1.0f, 1.0f, 1.0f, 1.0f));
    ASSERT_EQ(a / 2.0f, vec4f(0.5f, 1.0f, 1.5f, 2.0f));
    ASSERT_EQ(2.0f / a, vec4f(2.0f, 1.0f, 2.0f / 3.0f, 0.5f));
    ASSERT_EQ(a % a, vec4f(0.0f, 0.0f, 0.0f, 0.0f));
    ASSERT_EQ(a % 2.0f, vec4f(1.0f, 0.0f, 1.0f, 0.0f));
    ASSERT_EQ(2.0f % a, vec4f(0.0f, 0.0f, 2.0f, 2.0f));

    ASSERT_EQ(dot(a, a), 30.0f);
}

int main(int argc, char **argv)
{
    test_vec2i();
    test_vec2f();
    test_vec3f();
    test_vec4f();

    return EXIT_SUCCESS;
}
