# This Makefile is brutally simple, not very sophisticated,
# and not at all up to my normal standards...
# ...Be grateful, dear reader!
# (Signed, Prof. R. Moore, h_da, fbi )

# --------------------------------------------------------------------------
all: dumbSort gensort valsort

gensort: gensort-1.5/gensort 
	cp gensort-1.5/gensort .

valsort: gensort-1.5/valsort 
	cp gensort-1.5/valsort .

gensort-1.5/gensort gensort-1.5/valsort:
	+cd gensort-1.5 && make

dumbSort: dumbSort.cpp gray_sort_record.h
	c++ -std=c++11 -Wall -o dumbSort dumbSort.cpp

clean:
	-rm -f *.o mpi-pi dumbSort gensort valsort
	+cd gensort-1.5 && make clean
	


