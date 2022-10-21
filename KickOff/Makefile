# This Makefile is brutally simple, not very sophisticated,
# and not at all up to my normal standards...
# ...Be grateful, dear reader!
# (Signed, Prof. R. Moore, h_da, fbi )

# --------------------------------------------------------------------------

# Choose a C++ and a C Compiler!
# Ether gnu compiler chain (gcc):
# C++ = g++
# CC = gcc
# Or clang / LLVM:
# C++ = clang++
# CC = clang
# Or whatever is the default on your system:
C++ = c++
CC = cc

# Depending on your OS and local installation of clang, openmp, MPI, etc.,
# you MIGHT need to uncomment one or more of the following lines:
# CPPFLAGS += -std=c++11 -I/user/local/include/
# LDFLAGS  += -std=c++11 -L/user/local/lib/
#         The next two lines are only needed for Mac OS (if at all):
# CPPFLAGS += -I/opt/homebrew/opt/llvm/include/
# LDFLAGS  += -L/opt/homebrew/opt/llvm/lib/

# This should work on all OS's (
CPPFLAGS +=  --std=c++17 -O3
LDFLAGS  +=  --std=c++17 -O3

# This makefile makes the following programs
TARGETS = mpi-pi mpi-pi++ cpp11-pi openMP-pi 

all: $(TARGETS)

clean:
	-rm -f *.o $(TARGETS)

# NOTE : It is possible to tell mpicc which c (or c++) compiler to use, 
# but the method depends on whether you are using OpenMPI or MPICH.
# For MPICH, use 
#	mpicc -cc="$(CC)" -O3 ... 
# For OpenMPI, see "man mpicc" (environment variables, toward the bottom of the page)

# Help with Makefile "automatic variables":
# (https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables)
# ---------------------------------------------
# $@ = The filename representing the target.
# $< = The filename of the first prerequisite.
# $(*F) = The stem of the filename of the target (i.e. without .o, .cpp...)
# $^ = The names of all the prerequisites, with spaces between them.

mpi-pi.o: mpi-pi.c
	mpicc -O3 -c $<

mpi-pi: mpi-pi.o
	mpicc -O3 -o $@ $^
	
mpi-pi++.o: mpi-pi++.cpp	
	mpic++ $(CPPFLAGS) -c $<

mpi-pi++: mpi-pi++.o
	mpic++ $(LDFLAGS) -o $@ $^
	
cpp11-pi.o: cpp11-pi.cpp
	$(C++) $(CPPFLAGS) -pthread -c $<

cpp11-pi: cpp11-pi.o
	$(C++) $(LDFLAGS) -pthread -o $@ $^

openMP-pi.o: openMP-pi.cpp
	$(C++) $(CPPFLAGS) -fopenmp -c $<

openMP-pi: openMP-pi.o
	$(C++) $(LDFLAGS) -fopenmp -o $@ $^

NUM_THREADS = 16

tests: all
###  Use these tests if you have both slurm and OpenMPI (i.e. at the GSI!)
# 	echo "\nRunning cpp11-pi with slurm...";
# 	srun --bcast=${PWD}/cpp11-pi -T 4 ./cpp11-pi 4
# 	echo "\nRunning openMP-pi with slurm...";
# 	srun --bcast=${PWD}/openMP-pi -T 4 ./openMP-pi 4
# 	echo "\nRunning mpi-pi with salloc mpiexec...";
# 	salloc -N 4 -n 4 mpiexec --mca btl tcp,self ./mpi-pi
# 	echo "\nRunning mpi-pi++ with salloc mpiexec...";
# 	salloc -N 4 -n 4 mpiexec --mca btl tcp,self ./mpi-pi++

### If you are using mpich without slurm (perhaps on your own notebook?)
# use these tests instead:
	echo "\nRunning cpp11-pi without slurm...";
	./cpp11-pi 4
	echo "\nRunning openMP-pi without slurm...";
	./openMP-pi 4
	echo "\nRunning mpi-pi++ without slurm...";
	mpiexec --mca btl tcp,self -n 4 ./mpi-pi++
	echo "\nRunning mpi-pi without slurm...";
	mpiexec --mca btl tcp,self -n 4 ./mpi-pi

# Note on "--mca btl tcp,self" (with mpiexec)
# See https://www.open-mpi.org/faq/?category=tcp
# Note on "mpiexec" vs. "mpirun" 
# See https://stackoverflow.com/questions/25287981/mpiexec-vs-mpirun