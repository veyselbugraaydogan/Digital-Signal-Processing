#pragma once

// Shared definitions
#include <cmath>
#include <vector>
#include <iostream>

#define PI  3.14159265

using std::size_t;
using std::vector;


/*
 * Computes the discrete Fourier transform (DFT) of the given complex vector.
 * All the array arguments must have the same length.
 */
#include <complex>
using std::complex;
using std::exp;
using std::cos;
using std::sin;

class DiscreteFourierTransformer
{
public:
	DiscreteFourierTransformer();
	~DiscreteFourierTransformer();
	void decompose(const double* inreal ,double* outreal,
		double* outimag,int size);
	void synthesize(double* inReal,
		double* inImag,double* outReal, int size);
};
