# This Makefile is brutally simple, not very sophisticated,
# and not at all up to my normal standards...
# ...Be grateful, dear reader!
# (Signed, Prof. R. Moore, h_da, fbi )

# --------------------------------------------------------------------------

# Choose a C++ and a C Compiler!
# Ether gnu compiler chain (gcc):
# C++ = g++8 
# CC = gcc8
# Or clang / LLVM:
C++ = c++
CC = cc

all: mpi-pi cpp11-pi openMP-pi

clean:
	-rm -f *.o mpi-pi cpp11-pi openMP-pi

mpi-pi.o: mpi-pi.c
	mpicc -cc="$(CC)" -O3 -c $<

mpi-pi: mpi-pi.o
	mpicc -cc="$(CC)" -O3 -o mpi-pi mpi-pi.o


cpp11-pi.o: cpp11-pi.cpp
	$(C++) -std=c++11 -O3 -pthread -c $<

cpp11-pi: cpp11-pi.o
	$(C++) -std=c++11 -O3 -o cpp11-pi cpp11-pi.o -pthread

openMP-pi.o: openMP-pi.cpp
	$(C++) -std=c++11 -I/usr/local/include -O3 -fopenmp -c $<

openMP-pi: openMP-pi.o
	$(C++) -std=c++11 -L/usr/local/lib -fopenmp -O3 -o openMP-pi openMP-pi.o

tests: all
#  Use these tests if you have both slurm and mpich (i.e. on the BDC!)
	echo -e "\nRunning cpp11-pi with slurm...";
	salloc -c 16 ./cpp11-pi 16
	echo -e "\nRunning openMP-pi... with slurm...";
	srun -T 16 ./openMP-pi 16
	echo -e "\nRunning mpi-pi...";
	salloc -N 4 -n 16 mpiexec --prepend-rank  ./mpi-pi
# If you are using mpich without slurm (perhaps on your own notebook?)
# use these tests instead:
	# echo -e "\nRunning cpp11-pi without slurm...";
	# ./cpp11-pi 4
	# echo -e "\nRunning openMP-pi without slurm...";
	# ./openMP-pi 4
	# echo -e "\nRunning mpi-pi without slurm...";
	# mpiexec -n 4 --prepend-rank ./mpi-pi
