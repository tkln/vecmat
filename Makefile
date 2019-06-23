# Copyright (c) 2019 Aapo Vienamo
# SPDX-License-Identifier: CC0-1.0

CFLAGS+=-Wall -O2
CXXFLAGS+=$(CFLAGS)
LDFLAGS+=-lm

HEADERS=vecmat-compiler.h vec2f.h vec3f.h vec4f.h vec2i.h
LINK_TEST_OBJS=link-test-c.o link-test-cpp.o

all: test testpp link-test

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
	rm -f test testpp link-test $(LINK_TEST_OBJS)
