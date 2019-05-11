#include "pch.h"
#include "DiscreteFourierTransformer.h"


DiscreteFourierTransformer::DiscreteFourierTransformer()
{

}


DiscreteFourierTransformer::~DiscreteFourierTransformer()
{

}


void DiscreteFourierTransformer::decompose(const double* inreal,
	double* outreal, double* outimag,int size) {

	/* Bu fonksiyon verilen gerçel bir iþareti (inreal) ,
	gerçel (outreal) ve imaginer (outimag) kýsýmlarýna ayrýþtýrýr. */

	// Çýkýþ verilecek diziler önce 0 lanýr
	for (int i = 0; i < (size / 2) + 1; i++) {

		outimag[i] = 0;
		outreal[i] = 0;
	}

	
	for (int k = 0; k <(size/2)+1; k++) {

		for (int i = 0; i < size ; i++) {

			outreal[k] = outreal[k] + inreal[i] * cos(2 * PI*i*k/size);
			outimag[k] = outimag[k] - inreal[i] * sin(2 * PI*i*k/size);

		}

	}


}

void DiscreteFourierTransformer::synthesize(double* inReal,
	double* inImag, double* outReal, int size) {

	/*Bu fonksiyon daha önce ayrýþtýrýlmýþ olan bir sinyalin 
	gerçel (inReal) ve imaginer (inImag) kýsýmlarýný 
	tek bir gerçel sinyalde (outReal) sentezler.*/
	
	for (int i = 0; i < (size / 2) + 1; i++) {
		inReal[i] = inReal[i] / (size / 2);
		inImag[i] = -inImag[i] / (size / 2);
	}
	inReal[0] = inReal[0] / 2;
	inReal[(size/2)] = inReal[(size /2)] / 2;

	//Çýkýþ dizisini sýfýrlýyoruz
	for (int i = 0; i < size; i++) {
		outReal[i] = 0;
	}

	for (int i = 0; i < size ; i++) {

		for (int k = 0; k < (size / 2) + 1; k++) {
			outReal[i] = outReal[i] + inReal[k] * cos(2 * PI*i*k/size);
			outReal[i] = outReal[i] + inImag[k] * sin(2 * PI*i*k/ size);
		}
	}
}