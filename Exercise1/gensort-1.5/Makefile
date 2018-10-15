# gensort and valsort Makefile
#
# Define USE_SUMP_PUMP as "1" to use the SUMP Pump library to make
# multithreaded versions of gensort and valsort.  Use any other value
# to make single-threaded versions.  SUMP Pump requires the pthread library.
#
USE_SUMP_PUMP=0
# use BITS=-m32 to force 32-bit build on a 64-bit platform
BITS=
CFLAGS=$(BITS) -O3 -Wall

all: gensort valsort

gensort: gensort.c rand16.o rand16.h
	cc -g $(CFLAGS) -o gensort gensort.c rand16.o -lz

valsort: valsort.c rand16.o rand16.h
	cc -g $(CFLAGS) -o valsort valsort.c rand16.o -lz

rand16.o: rand16.c rand16.h
	cc -g $(CFLAGS) -c rand16.c
