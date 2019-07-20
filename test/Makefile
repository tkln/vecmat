# Copyright (c) 2019 Aapo Vienamo
# SPDX-License-Identifier: CC0-1.0

VECMAT_PATH=../include/vecmat/
CFLAGS+=-Wall -O2 -I$(VECMAT_PATH)
CXXFLAGS+=$(CFLAGS)
LDFLAGS+=-lm

HEADERS=$(addprefix $(VECMAT_PATH), vecmat-compiler.h vec2f.h vec3f.h vec4f.h \
									vec2i.h)
LINK_TEST_OBJS=link-test-c.o link-test-cpp.o

all: test testpp11 testpp98 link-test

test: test.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testpp11: testpp.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -std=c++11 $< -o $@ $(LDFLAGS)

testpp98: testpp.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -std=c++98 $< -o $@ $(LDFLAGS)

link-test-c.o: link-test-c.c $(HEADERS)
link-test-cpp.o: link-test-cpp.cc $(HEADERS)

link-test: $(LINK_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f test testpp11 testpp98 link-test $(LINK_TEST_OBJS)
