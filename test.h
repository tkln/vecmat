#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>

#ifndef TEST_END
static int test_exit_on_failure = 0;
#define TEST_END if (test_exit_on_failure) exit(EXIT_FAILURE);
#endif

#define ASSERT(v_)                                                      \
    do {                                                                \
        if (v_)                                                         \
            break;                                                      \
        fprintf(stderr, "%s, %d: Assertion failed: %s\n", __FUNCTION__, \
                __LINE__, #v_);                                         \
        TEST_END                                                        \
    } while (0);

#define ASSERT_EQ(a_, b_)                                           \
    do {                                                            \
        if ((a_) == (b_))                                           \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s == %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_NOTEQ(a_, b_)                                        \
    do {                                                            \
        if ((a_) != (b_))                                           \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s != %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_FEEQ(a_, b_, e_)                                     \
    do {                                                            \
        if (abs((a_) - (b_)) < (e_))                                \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s == %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_FENOTEQ(a_, b_, e_)                                  \
    do {                                                            \
        if (!(abs((a_) - (b_)) < (e_)))                             \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s != %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_STREQ(a_, b_)                                        \
    do {                                                            \
        if (!strcmp((a_), (b_)))                                    \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s == %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_STRNOTEQ(a_, b_)                                     \
    do {                                                            \
        if (strcmp((a_), (b_)))                                     \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s != %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_MEMEQ(a_, b_, sz_)                                   \
    do {                                                            \
        if (!memcmp((a_), (b_), (sz_)))                             \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s == %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);

#define ASSERT_MEMNOTEQ(a_, b_)                                     \
    do {                                                            \
        if (memcmp((a_), (b_), (sz_)))                              \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed: %s != %s\n",     \
                __FUNCTION__, __LINE__, #a_, #b_);                  \
        TEST_END                                                    \
    } while (0);


#define ASSERTM(v_, msg_, ...)                                      \
    do {                                                            \
        if (v_)                                                     \
            break;                                                  \
        fprintf(stderr, "%s, %d: Assertion failed %s: " msg_ "\n",  \
                __FUNCTION__, __LINE__, #v_, __VA_ARGS__);          \
        TEST_END                                                    \
    } while (0);

#define ASSERTM_EQ(a_, b_, msg_, ...)                                       \
    do {                                                                    \
        if ((a_) == (b_))                                                   \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s == %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_NOTEQ(a_, b_, msg_, ...)                                    \
    do {                                                                    \
        if ((a_) != (b_))                                                   \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s != %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_FEEQ(a_, b_, e_, msg_, ...)                                 \
    do {                                                                    \
        if (abs((a_) - (b_)) < (e_))                                        \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s == %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_FENOTEQ(a_, b_, e_, msg_, ...)                              \
    do {                                                                    \
        if (!(abs((a_) - (b_)) < (e_)))                                     \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s != %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_STREQ(a_, b_, msg_, ...)                                    \
    do {                                                                    \
        if (!strcmp((a_), (b_)))                                            \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s == %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_STRNOTEQ(a_, b_, msg_, ...)                                 \
    do {                                                                    \
        if (strcmp((a_), (b_)))                                             \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s != %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_MEMEQ(a_, b_, msg_, ...)                                    \
    do {                                                                    \
        if (!strcmp((a_), (b_)))                                            \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s == %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#define ASSERTM_MEMNOTEQ(a_, b_, msg_, ...)                                 \
    do {                                                                    \
        if (strcmp((a_), (b_)))                                             \
            break;                                                          \
        fprintf(stderr, "%s, %d: Assertion failed %s != %s: " msg_ "\n",    \
                __FUNCTION__, __LINE__, #a_, #b_, __VA_ARGS__);             \
        TEST_END                                                            \
    } while (0);

#endif
