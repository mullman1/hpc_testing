Exercise 3 -- Matrix Multiplication
===================================

This directory contains a Makefile and three programs:
1. matrix_generator -- creates matrix files with random numbers. Output is written to standard out.
1. matrix_sequential -- multiplies two matrix files (in the format created by matrix_generator
1. matrix_parallel -- an MPI program that reads in two matrix files, forgets to multiply them,
and then writes out a blank result matrix.

### Building the Programs

Enter "make" at the command line.

Enter "make test" to test all three programs (on very small matrices).

Enter "make clean" or "make distclean" to clean up.

### File Format


The file format is very simple.
The first line in each file contains the size of the matrix, i.e.

    numRows numColums

e.g.

    20 30

After that, each row contains one row of the matrix. The matrices hold floating point numbers, and all data is in text.

### Exercise

Write a better matrix multiplication program using MPI.

In other words, do *not* use shared memory; assume a distributed memory
and use message passing communication between processes (not threads, but processes).

In your design, analysis and lab report, think about space as well as time.
In other words, the goal is not *only* to be as fast as possible,
it is also to multiply *very large* matrices.

###Acknowledgements and Apologies

This code is very old.
(Working with legacy code is part of being a computer scientist!).

It has been written over the years by Prof. Moore and Dr. Andreas Kirsch,
who has supervised the lab several times over the years (but no longer
works at the FbI/h_da (unfortunately)).

Prof. R. Moore <ronald.moore@h-da.de> now takes full responsibility for
maintaining the code you have received
(you are of course responsible for your copy of the code once you have received it).
