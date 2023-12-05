/* -*- Mode: C++; c-basic-offset:4 ; -*- */
/*  This file is meant to demonstrate a simple (naive) as a simple
 *  C++ wrapper for the records sorted in the "Gray" sorting benchmark.
 * 
 *  The code is original, written by Prof. Dr. Ronald Moore, h_da,
 *  ronald.moore@h-da.de, but the ideas are all from 
 *  http://sortbenchmark.org/    and
 *  http://www.ordinal.com/gensort.html
 * 
 *  This code is provided with no license, is totally open,
 *  but comes with no warranty or guarantee for any purpose whatsoever.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <mpi.h>

#include "gray_sort_record.h"

double secondsSince(std::chrono::system_clock::time_point startTime)
{
    const double microsecs = 1000000.0;
    auto endTime = std::chrono::system_clock::now();
    auto microRunTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    return microRunTime.count() / microsecs;
}

void printTime(std::chrono::system_clock::time_point startTime)
{
    std::cout << "Wall Time used so far: "
              << std::setprecision(8)
              << secondsSince(startTime)
              << " seconds." << std::endl;
}

void parallelMergeSort(std::vector<graySortRecord> &records, int rank, int size)
{
    // Determine the chunk size for each process
    int chunkSize = records.size() / size;

    // Scatter data to all processes
    std::vector<graySortRecord> localRecords(chunkSize);
    MPI_Scatter(records.data(), chunkSize, MPI_BYTE, localRecords.data(), chunkSize, MPI_BYTE, 0, MPI_COMM_WORLD);

    // Local sort
    std::sort(localRecords.begin(), localRecords.end());

    // Gather sorted data back to the root process
    MPI_Gather(localRecords.data(), chunkSize, MPI_BYTE, records.data(), chunkSize, MPI_BYTE, 0, MPI_COMM_WORLD);

    // Perform parallel merge
    for (int step = 1; step < size; step *= 2)
    {
        if (rank % (2 * step) == 0)
        {
            int partner = rank + step;
            if (partner < size)
            {
                // Receive data from partner
                MPI_Recv(localRecords.data() + chunkSize, chunkSize, MPI_BYTE, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                // Merge locally
                std::inplace_merge(localRecords.begin(), localRecords.begin() + chunkSize, localRecords.end());

                // Send merged data back to partner
                MPI_Send(localRecords.data() + chunkSize, chunkSize, MPI_BYTE, partner, 0, MPI_COMM_WORLD);
            }
        }
        else if (rank % (2 * step) == step)
        {
            int partner = rank - step;
            // Send data to partner
            MPI_Send(localRecords.data(), chunkSize, MPI_BYTE, partner, 0, MPI_COMM_WORLD);

            // Receive merged data from partner
            MPI_Recv(localRecords.data(), chunkSize, MPI_BYTE, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "Parallel Sort Program starts..." << std::endl;

    // check command line usage
    if (3 != argc)
    {
        if (rank == 0)
        {
            std::cerr << "Usage: " << argv[0]
                      << " <input binary data file name> <output binary data file name>\n"
                      << "Example " << argv[0] << " foo.dat bar.dat\n";
        }
        MPI_Finalize();
        exit(-1);
    };

    // start stop watch...
    auto startTime = std::chrono::system_clock::now();

    // only the root process performs file I/O and data reading
    if (rank == 0)
    {
        // open input file for binary input
        std::ifstream inStream(argv[1], std::ios::in | std::ios::binary);
        if (!inStream.is_open())
        {
            std::cerr << "ERROR: Could not open input file named "
                      << argv[1] << std::endl;
            MPI_Finalize();
            exit(-2);
        }

        // read all of the records into a vector
        std::vector<graySortRecord> records;
        graySortRecord rec;
        long int numRecords = 0;
        while (inStream >> rec)
        {
            records.push_back(rec);
            ++numRecords;
        }
        std::cout << "Read " << numRecords << " from input file!\n";
        printTime(startTime);

        // close input file
        inStream.close();

        // Perform parallel merge sort
        parallelMergeSort(records, rank, size);

        // open output file for binary output
        std::ofstream outStream(argv[2], std::ios::out | std::ios::binary);
        if (!outStream.is_open())
        {
            std::cerr << "ERROR: Could not open output file named "
                      << argv[2] << std::endl;
            MPI_Finalize();
            exit(-2);
        }

        // write all of the records to output file
        for (graySortRecord r : records)
            outStream << r;

        // close output file
        outStream.close();
    }
    else
    {
        // Non-root processes perform parallel merge sort
        std::vector<graySortRecord> dummy;
        parallelMergeSort(dummy, rank, size);
    }

    // Stop stopwatch!
    if (rank == 0)
    {
        std::cout << "Parallel Sort Program finished!" << std::endl;
        printTime(startTime);
    }

    MPI_Finalize();
    return 0; // OK!!!
}
