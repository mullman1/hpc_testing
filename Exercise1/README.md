# Exercise One : Sorting

The goal of this exercise is to investigate ways to do sorting in parallel, using threads. 

We will be sorting 100 byte records taken from files. This idea was taken from the "Sort Benchmark" hosted at http://sortbenchmark.org/ -- see that web page for much more information.

There are three tools here:
1. **gensort** -- a tool for generating data to be sorted. You should use this unchanged (unless you have *very* good reasons for changing it). The original version of this program is available at http://www.ordinal.com/gensort.html 
2. **valsort** -- a tool for validating sorted output. This tool should also not be changed and comes from the same source as gensort.
3. **dumbsort** -- a non-parallel (single-threaded), very simple sorting program that takes input created by gensort and creates output which can be validated by valsort. This code was written by Prof. R. C. Moore (ronald.moore@h-da.de) for the P%DC course.

Your job is to create a parallel, multi-threaded sort program. You may start with the code from the dumbsort program if you like, or you might want to start from scratch. This is up to you. 

After you have your own program up and running, start measuring its performance and write a lab report, as described in Moodle. 

Prof. R. C. Moore