################################################################
## SIMPLE MAKEFILE TO BUILD WITH MPICH                        ##
################################################################
# oct-2010 - a.knirsch@fbi.h-da.de                             #
# April-2013 - ronald.moore@h-da.de  (added make test)         #
# Oct-2021 - Removed MPI stuff
################################################################

# Set CXX to be clang++ or g++ or mpic++ -- compare kickoff makefile.
# CXX	= c++  
CXX = clang++
# CXX = g++

CFLAGS	= -O3 --std=c++17
PROGS	= matrix_sequential matrix_generator
OBJS	= matrix_sequential.o matrix_generator.o CMatrix.o
TESTFILES = matrix-A-10x10.txt matrix-B-10x10.txt

CFLAGS	+= -I/usr/local/include/
LDFLAGS += -L/usr/local/lib/

all: $(PROGS) $(TESTFILES)

#      "Variables", die hier benutzt werden:
#      Vgl. http://www.makelinux.net/make3/make3-CHP-2-SECT-2.html
# $@ = The filename representing the target.
# $< = The filename of the first prerequisite.
# $* = The stem of the filename of the target (i.e. without .o, .cpp...)
# $^ = The names of all the prerequisites, with spaces between them.

$(PROGS): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@  $@.o  CMatrix.o


%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

$(TESTFILES): matrix_generator
	./matrix_generator 10 10 >$@

clean:
	-rm -rf $(PROGS) *~ *.o ._*

distclean: clean
	-rm -rf $(TESTFILES)

test:  $(PROGS) $(TESTFILES)
	echo "Calling matrix_sequential..."
	./matrix_sequential $(TESTFILES)
# Or, usiong slurm...
#	srun ./matrix_sequential $(TESTFILES)

