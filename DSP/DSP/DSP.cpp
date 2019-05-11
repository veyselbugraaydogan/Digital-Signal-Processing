// DSP.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "pch.h"
#include <iostream>
#include "Isaret.h"
#include "DiscreteFourierTransformer.h"

using namespace std;

void printArray(double*, int);

void fillArrayRandom(double*, int);

void fillArray(double*, int);

int main()
{	

	const int signalSize = 64;
	const int decomposedSignalsSize = (signalSize / 2) + 1;

	double sinyal[signalSize] ;

	double outputReal[decomposedSignalsSize];
	double outputIm[decomposedSignalsSize];



	DiscreteFourierTransformer dft;


	fillArrayRandom(sinyal, signalSize); // İndis değerleri + 1 i değişkenlere atıyor

	cout << "Sinyalin decompose edilmeden onceki hali" << endl;

	printArray(sinyal, signalSize);

	dft.decompose(sinyal, outputReal, outputIm, signalSize);

	fillArray(sinyal, signalSize); // 0 atıyor

	dft.synthesize(outputReal, outputIm, sinyal, signalSize);

	cout << "Sinyalin decompose edilip tekrer sentezlendikten sonraki hali" << endl;

	printArray(sinyal, signalSize);


}


void printArray(double* array,int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void fillArrayRandom(double* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = i+1;
	}
}

void fillArray(double* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}


// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
