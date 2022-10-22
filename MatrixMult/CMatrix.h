// file...: CMatrix.h
// desc...: minimalistic helper class to hold matrix information 
// oct-2010 | a.knirsch@fbi.h-da.de

#ifndef CMATRIX_H_
#define CMATRIX_H_

#include <assert.h>

// some helper
void printError(const char* progname, const char* error = NULL);


class CMatrix {
public:
	
	// create matrix from given file
	CMatrix(const char* filename);
	
	// create empty matrix with given size
	CMatrix(unsigned int w, unsigned int h);
	
	// destructor
	~CMatrix();
	
	// size of matrix (amount of values)
	unsigned int size() { return height * width; }
	
	// print matrix to stdout
	void print();
	
	// Row selector -
	// With this, you can use matrix[row][col] 
	// Note that we only need to overload the first square brackets,
	// and that we do this "inline" (here in the header) to speed it up.
	double * operator[]( unsigned int rowNumber )  {
    	assert( rowNumber < height );
    	return container + (rowNumber * width );
	}


	// Remainder is public for simplification
	// You might want to consider making everything below here private...
	unsigned int height;
	unsigned int width;
	
	// We COULD declare the matrix as double[ height ][ width ] (dynamically)
	// but we do it the HARD way to make it very clear that all the doubles are
	// stored as one big contiguous block of memory (!).
	// This means however that we have to overload the first (row) square brackets
	// (see above).
	
	double* container;
};


#endif // CMATRIX_H_

