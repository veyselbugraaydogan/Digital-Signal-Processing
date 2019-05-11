#pragma once
#include <iostream>

class Isaret
{
public:
	Isaret();
	Isaret(double* dizi,int baslangicT,int bitisT);
	double getValueByTime(int t);
	void setArrayWithZero(double* arr, int size);
	~Isaret();

private:
	double* degerler;
	int baslangicT, bitisT;
	float binSize;
};

