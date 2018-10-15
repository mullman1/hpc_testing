# This Makefile is brutally simple, not very sophisticated,
# and not at all up to my normal standards...
# ...Be grateful, dear reader!
# (Signed, Prof. R. Moore, h_da, fbi )

# --------------------------------------------------------------------------
all: mpi-pi cpp11-pi openMP-pi

clean:
	-rm -f *.o mpi-pi cpp11-pi openMP-pi

mpi-pi.o: mpi-pi.c
	mpicc -c $<

mpi-pi: mpi-pi.o
	mpicc -o mpi-pi mpi-pi.o


cpp11-pi.o: cpp11-pi.cpp
	c++ -std=c++11 -pthread -c $<

cpp11-pi: cpp11-pi.o
	c++ -std=c++11 -o cpp11-pi cpp11-pi.o -pthread

openMP-pi.o: openMP-pi.cpp
	c++ -std=c++11 -I/usr/local/include -fopenmp -c $<

openMP-pi: openMP-pi.o
	c++ -std=c++11 -L/usr/local/lib -fopenmp -o openMP-pi openMP-pi.o

tests: all
#  Use these tests if you have both slurm and mpich (i.e. on the BDC!)
	echo -e "\nRunning cpp11-pi with slurm...";
	srun ./cpp11-pi 4
	echo -e "\nRunning openMP-pi... with slurm...";
	salloc -n 4 ./openMP-pi 4
	echo -e "\nRunning mpi-pi...";
	salloc -N 4 -n 4 mpiexec --prepend-rank  ./mpi-pi
# If you are using mpich without slurm (perhaps on your own notebook?)
# use these tests instead:
	# echo -e "\nRunning cpp11-pi without slurm...";
	# ./cpp11-pi 4
	# echo -e "\nRunning openMP-pi without slurm...";
	# ./openMP-pi 4
	# echo -e "\nRunning mpi-pi without slurm...";
	# mpiexec -n 4 --prepend-rank ./mpi-pi
