#include "pch.h"
#include "Isaret.h"


Isaret::Isaret()
{
}

Isaret::Isaret(double* dizi,int baslangicT,int bitisT)
{
	degerler = dizi;
	this->baslangicT = baslangicT;
	this->bitisT = bitisT;
}

void Isaret::setArrayWithZero(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

Isaret::~Isaret()
{
}


double Isaret::getValueByTime(int t) {
	if (t<baslangicT || t>bitisT) {
		//std::cout <<"a"<<t <<baslangicT<<bitisT<<std:: endl;
		return 0;
	}
	else {
		return degerler[(t-baslangicT)];
	}
}