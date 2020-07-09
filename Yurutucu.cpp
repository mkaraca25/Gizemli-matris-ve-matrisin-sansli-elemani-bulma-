
#include <iostream> //cin cout
#include "DinamikBellekYonetimi.h"   //DinamikBellekYonetimi kütüphanem

using namespace std;
void matrisiYaz(int** matris, int satir, int sutun) //matrisi yazdýrma fonksiyonu
{
	for (int i = 0; i < satir; ++i) { 
	  for (int j = 0; j < sutun; ++j) {
	    cout << "\t" << matris[i][j];
	  }
	  cout << endl;
	}
}
void matrisiSil(int** matris, int satir)  //matrisi silme fonksiyonu
{
    // Her satýrý sil
    for(int i = 0; i < satir; ++i) {
        delete[] matris[i];   
    }
    // Pointer dizisini sil
    delete[] matris;
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL,"Turkish"); //Türkçe karakterlerin gözükmesi için
	
	// Test olarak kullanýlacak deðerler
	int gizemliMatrisDegerleri[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
	int sansliMatrisDegerleri[3][3] = {{3,7,8},{9,11,13},{15,16,17}};

	////////////////////////////// Dizi 1 ///////////////////////////////////////
	// kullanýcýdan matris boyutlarýný al
	int satir1,sutun1,satir2,sutun2; 
	cout << "1. dinamik integer dizinin boyutlarýný sütun,satýr þeklinde giriniz (Test için 3,3 giriniz): ";
	cin >> satir1;
	cin.ignore(1, ','); //deðerlerin arasýna , koyma iþlemi
	cin >> sutun1;
	
	// dinamik integer dizilerini oluþtur
	int **dinamikDizi1 = new int*[satir1]; // int pointerlara iþaret eden dinamik dizi
	for (int i = 0; i < satir1; ++i) 
	  dinamikDizi1[i] = new int[sutun1];
	  
	// Satir ve sutun sayýsý 3 için test deðerleri otomatik olarak atanýr. Diðer giriþler için matrisin
	// elemanlarý kullancýdan teker teker alýnýr
	if(satir1 == 3 && sutun1 == 3)
	{
		for (int i = 0; i < satir1; ++i) {   // her satýr için
		  for (int j = 0; j < sutun1; ++j) { // her sutun için
		    dinamikDizi1[i][j] = gizemliMatrisDegerleri[i][j];
		  }
		}
	}
	else
	{
		cout << "1. matrisin elemanlarýný giriniz. (Teker teker veya aralarýnda 1 boþluk býrakarak.): ";
		for (int i = 0; i < satir1; ++i) {   // her satýr için
		  for (int j = 0; j < sutun1; ++j) { // her sutun için
		    cin >> dinamikDizi1[i][j];
		  }
		}	
	}
	
	////////////////////////////// Dizi 2 ////////////////////////////////////////
	
	cout << "2. dinamik integer dizinin boyutlarýný sütun,satýr þeklinde giriniz (Test için 3,3 giriniz): ";
	cin >> satir2;
	cin.ignore(1, ',');
	cin >> sutun2;
	
	// dinamik integer dizilerini oluþtur
	int **dinamikDizi2 = new int*[satir2]; // int pointerlara iþaret eden dinamik dizi
	for (int i = 0; i < satir2; ++i) 
	  dinamikDizi2[i] = new int[sutun2];
	  
	// Satir ve sutun sayýsý 3 için test deðerleri otomatik olarak atanýr. Diðer giriþler için matrisin
	// elemanlarý kullancýdan teker teker alýnýr
	if(satir2 == 3 && sutun2 == 3)
	{
		for (int i = 0; i < satir2; ++i) {   // her satýr için
		  for (int j = 0; j < sutun2; ++j) { // her sutun için
		    dinamikDizi2[i][j] = sansliMatrisDegerleri[i][j];
		  }
		}
	}
	else
	{
		cout << "2. matrisin elemanlarýný giriniz. (Teker teker veya aralarýnda 1 boþluk býrakarak.): ";
		for (int i = 0; i < satir2; ++i) {   // her satýr için
		  for (int j = 0; j < sutun2; ++j) { // her sutun için
		    cin >> dinamikDizi2[i][j];
		  }
		}	
	}		
	
	// dinamik bellek yönetimi nesnesi oluþtur
	DinamikBellekYonetimi* dby = new DinamikBellekYonetimi();

	// Matrisleri ve sonuçlarý ekrana bas
		// 1. dinamik dizi gizemli matris mi diye kontrol et
	cout << endl << "1. Dinamik Dizi: " << endl;
	matrisiYaz(dinamikDizi1,satir1,sutun1);
	if(dby->GizemliMatrisMi(dinamikDizi1,satir1,sutun1))
		cout << endl << "1. Dinamik Dizi bir Gizemli Matristir.";
	else
		cout << endl << "1. Dinamik Dizi bir Gizemli Matris deðildir.";
		// 2. dinamik dizinin þanslý matris elemanlarýnýn sayýsýný hesapla
	cout << endl << endl << "2. Dinamik Dizi: " << endl;
	matrisiYaz(dinamikDizi2,satir2,sutun2);
	cout << endl << "2. Dinamik Dizinin Þanslý Elemanlarýnýn Sayýsý = " << dby->SansliMatrisElemanlarininSayisi(dinamikDizi2,satir2,sutun2) << endl;
	
	// dinamik dizileri sil
	matrisiSil(dinamikDizi1,satir1);
	matrisiSil(dinamikDizi2,satir2);
	return 0;
}

