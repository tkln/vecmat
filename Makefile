# Copyright (c) 2019 Aapo Vienamo
# SPDX-License-Identifier: CC0-1.0

CFLAGS+=-Wall -O2
CXXFLAGS+=$(CFLAGS)
LDFLAGS+=-lm

all: test testpp

test: test.c vec2i.h vec2f.h vec3f.h vec4f.h
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testpp: testpp.cc vec2i.h vec2f.h vec3f.h vec4f.h
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f test testpp
