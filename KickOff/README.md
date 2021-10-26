---
title:  Exercise Zero - Gettig Started
author: Prof. Dr. Ronald C. Moore 
        <ronald.moore@h-da.de>
date:   Oct 2021
...




Exercise Zero : Getting Started
===============================

The goal of this exercise is to get up and running. 

You should find here three programs and one make file.

Before building (or testing) the three programs provided, _please_ read the Makefile. 
This file has many comments -- and many of these are lines that have been "commented out",
that represent alternatives. 
You will _probably_ want to choose different alternatives for _your_ machine, 
and you should _definitely_ choose different alternatives when testing on the Big Data Cluster 
(in order to use SLURM).

Once you have reviewed the Makefile:

  *  To build all three programs, enter "make" on the command line.
  *  To test all three programs, enter "make tests" on the command line.

The programs are provided in a state which runs very quickly. 
This is good for establishing whether they run correctly. 
This is _not_ good for benchmarking performance!

The next step is to modify these programs so that they run **much** longer than they do now.

You may need to change the Makefile as well -- particularly the test for the MPI program may need to be changed.

After you have your versions of the programs (and Makefile) up and running, start measuring their performance and write a lab report, as described in Moodle. 

Prof. R. C. Moore