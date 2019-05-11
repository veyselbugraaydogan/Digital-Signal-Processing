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

	/* Bu fonksiyon verilen ger�el bir i�areti (inreal) ,
	ger�el (outreal) ve imaginer (outimag) k�s�mlar�na ayr��t�r�r. */

	// ��k�� verilecek diziler �nce 0 lan�r
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

	/*Bu fonksiyon daha �nce ayr��t�r�lm�� olan bir sinyalin 
	ger�el (inReal) ve imaginer (inImag) k�s�mlar�n� 
	tek bir ger�el sinyalde (outReal) sentezler.*/
	
	for (int i = 0; i < (size / 2) + 1; i++) {
		inReal[i] = inReal[i] / (size / 2);
		inImag[i] = -inImag[i] / (size / 2);
	}
	inReal[0] = inReal[0] / 2;
	inReal[(size/2)] = inReal[(size /2)] / 2;

	//��k�� dizisini s�f�rl�yoruz
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