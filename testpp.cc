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
}

void test_vec2f(void)
{
    vec2f a = vec2f(1.0f, 2.0f);
    ASSERT_EQ(a.x, 1.0f);
    ASSERT_EQ(a.y, 2.0f);
}

void test_vec3f(void)
{
    vec3f a = vec3f(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(a.x, 1.0f);
    ASSERT_EQ(a.y, 2.0f);
    ASSERT_EQ(a.z, 3.0f);
}

void test_vec4f(void)
{
    vec4f a = vec4f(1.0f, 2.0f, 3.0f, 4.0f);
    ASSERT_EQ(a.x, 1.0f);
    ASSERT_EQ(a.y, 2.0f);
    ASSERT_EQ(a.z, 3.0f);
    ASSERT_EQ(a.w, 4.0f);
}

int main(int argc, char **argv)
{
    test_vec2i();
    test_vec2f();
    test_vec3f();
    test_vec4f();

    return EXIT_SUCCESS;
}
