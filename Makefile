CFLAGS+=-Wall -O2
CXXFLAGS+=$(CFLAGS)

all: test testpp

test: test.c
testpp: testpp.cc

.PHONY: clean
clean:
	rm -f test testpp
