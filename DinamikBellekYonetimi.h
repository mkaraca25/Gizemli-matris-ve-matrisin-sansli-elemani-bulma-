

#ifndef DinamikBellekYonetimi_H  //ifndef, define ve endif  öniþlemci direktifleri Polinom Sýnýfý tanýmýnýn projenin 
#define DinamikBellekYonetimi_H //birden fazla dosyasý içerisinde kullanýmýnýn nesne kodu (object code) bünyesinde tekrarýný engeller.
#include <climits>             //sayýsal sýnýflar

class DinamikBellekYonetimi // Sýnýf adý
{
	public:  //public ve fonksiyonlarý
		bool GizemliMatrisMi(int**, int, int);
		int SansliMatrisElemanlarininSayisi(int**, int, int);
	private: //private ve fonksiyonlarý
		bool ButunElemanlariFarkliMi(int**, int, int); // Matrisin bütün elemanlarýnýn farklý olup olmadýðýný döner
		int SatirTopla(int**, int, int);		// Matrisin istenilen satýrýnýn toplamýný döner
		int SutunTopla(int**, int, int);		// Matrisin istenilen sütununun toplamýný döner
		int KosegenTopla(int**, int, int);	// Matrisin istenilen köþegeninin toplamýný döner
		void SatirMinMax(int**, int, int, int*, int*);	// Matrisin istenilen satýrýnýn max ve min deðerleri indexlerini bulur, pointer ile geçirilen deðiþkenlere yazar
		void SutunMinMax(int**, int, int, int*, int*);	// Matrisin istenilen sütununun max ve min deðerleri indexlerini bulur, pointer ile geçirilen deðiþkenlere yazar
};
#endif
