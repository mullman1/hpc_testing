---
title:  Exercise Zero - Gettig Started
author: Prof. Dr. Ronald C. Moore 
        <ronald.moore@h-da.de>
date:   January 2019
...




Exercise Zero : Getting Started
===============================

The goal of this exercise is to get up and running. 

You should find here three programs and one make file.

To build all three programs, enter "make" on the command line.

To test all three programs, enter "make tests" on the command line.

If all is good, all three programs should run, using slurm -- the correct way to run programs on the Big Data Cluster. If you are testing these programs at home, you will probably want to change the Makefile to test without slurm (just comment out the lines you don't want, and uncomment the lines provided for you).

The next step is to modify these programs so that they run **much** longer than they do now.

You may need to change the Makefile as well -- particularly the test for the MPI program may need to be changed.

After you have your versions of the programs (and Makefile) up and running, start measuring their performance and write a lab report, as described in Moodle. 

Prof. R. C. Moore