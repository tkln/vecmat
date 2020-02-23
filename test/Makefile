# Copyright (c) 2019 Aapo Vienamo
# SPDX-License-Identifier: CC0-1.0

VECMAT_PATH=../include/vecmat/
CFLAGS+=-Wall -O2 -I$(VECMAT_PATH)
CXXFLAGS+=$(CFLAGS)
LDFLAGS+=-lm

HEADERS=$(addprefix $(VECMAT_PATH), vecmat-compiler.h vec2f.h vec3f.h vec4f.h \
									vec2i.h)
LINK_TEST_OBJS=link-test-c.o link-test-cpp.o
TESTS=test testpp link-test

all: $(TESTS)

test: test.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testpp: testpp.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

link-test-c.o: link-test-c.c $(HEADERS)
link-test-cpp.o: link-test-cpp.cc $(HEADERS)

link-test: $(LINK_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TESTS) $(LINK_TEST_OBJS)
