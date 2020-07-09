
#include "DinamikBellekYonetimi.h"  //DinamikBellekYonetimi kütüphanem

//////////////////////////////// Public Fonksiyonlar ////////////////////////

bool DinamikBellekYonetimi::GizemliMatrisMi(int** matris, int satir, int sutun) 
{
	// Kare Matris mi diye kontrol et
	if(satir != sutun)
		return false;
	
	// bütün elemanlarý farklý mý diye kontrol et
	if(not ButunElemanlariFarkliMi(matris, satir, sutun))
		return false;
	// bütün elemanlarýn 1 ve n^2 arasýnda olduðunu kontrol et
	for(int i = 0; i < satir; i++)
	{
		int minIndex, maxIndex;
		SatirMinMax(matris, sutun, i, &minIndex, &maxIndex);
		if(matris[i][minIndex] < 1 || matris[i][maxIndex] > satir*satir)
			return false;
	}
	
	int M = satir*(satir*satir + 1) / 2;//projede verilen fonksiyon 
	
	// Bütün satýrlarýn toplamýnýn M'e eþit olup olmadýðýný kontrol et
	for(int i = 0; i < satir; i++)
	{
		if (SatirTopla(matris, sutun, i) != M)
			return false;
	}

	// Bütün sutunlarin toplamýnýn M'e eþit olup olmadýðýný kontrol et
	for(int i = 0; i < sutun; i++)
	{
		if (SutunTopla(matris, satir, i) != M)
			return false;
	}

	// Bütün kosegenlerin toplamýnýn M'e eþit olup olmadýðýný kontrol et
	for(int i = 0; i < 2; i++)
	{
		if (KosegenTopla(matris, satir, i) != M)
			return false;
	}
	
	// Bütün bu kontrollerden geçebildiyse matris bir gizemli matristir	
	return true;
}

int DinamikBellekYonetimi::SansliMatrisElemanlarininSayisi(int** matris, int satir, int sutun)
{
	
	// Kare Matris mi diye kontrol et
	if(satir != sutun)
		return 0;
		
	// bütün elemanlarý farklý mý diye kontrol et
	if(not ButunElemanlariFarkliMi(matris, satir, sutun))
		return 0; 
		
	int sansliMatrisElemanlari = 0;
	
	/*
	Her satýrdaki minimum elemaný bul. Eðer o eleman bulunduðu sütundaki maximum elemansa
	sanslý matris elemanlarý sayýsýný bir arttýr.
	*/
	for(int i = 0; i<satir; i++)
	{
		int satirMinIndex, satirMaxIndex;
		int sutunMinIndex, sutunMaxIndex;
		SatirMinMax(matris, sutun, i, &satirMinIndex, &satirMaxIndex);
		SutunMinMax(matris, satir, satirMinIndex, &sutunMinIndex, &sutunMaxIndex);
		if(sutunMaxIndex == i)
			sansliMatrisElemanlari++;
	}
	
	return sansliMatrisElemanlari;
	
}

///////////////////////////////// Private Fonksiyonlar /////////////////////////////////

bool DinamikBellekYonetimi::ButunElemanlariFarkliMi(int** matris, int satir, int sutun)
{
/*
	Bu fonksiyon matristeki her elemaný, öncesinde kalan elemanlarla karþýlaþtýrarak 
	matrisin bütün elemanlarýnýn birbirinden farklý olup olmadýðýný bulur
*/
	
    int i, j;

    for(i = 1; i < satir*sutun; i++) {
        for(j = 0; j < i; j++) {
            if (matris[i / sutun][i % sutun] == matris[j / sutun][j % sutun]) return false;
        }
    }

    return true; 
}

int DinamikBellekYonetimi::SatirTopla(int** matris, int sutunUzunlugu, int istenilenSatir) //satýrlarý toplama 
{
	int toplam = 0;
    for(int i = 0; i < sutunUzunlugu; i++) {
        toplam += matris[istenilenSatir][i];
    }
    return toplam; 
}

int DinamikBellekYonetimi::SutunTopla(int** matris, int satirUzunlugu, int istenilenSutun) //sutünlarý toplama
{
	int toplam = 0;
    for(int i = 0; i < satirUzunlugu; i++) {
        toplam += matris[i][istenilenSutun];
    }
    return toplam; 
}

int DinamikBellekYonetimi::KosegenTopla(int** matris, int satirUzunlugu, int istenilenKosegen) //köþegenleri toplama
{
	int toplam = 0;
    if(istenilenKosegen == 0)
    {
    	for(int i = 0; i<satirUzunlugu; i++)
    	{
    		toplam += matris[i][i];
		}
	}
	else
	{
    	for(int i = 0; i<satirUzunlugu; i++)
    	{
    		toplam += matris[i][satirUzunlugu - 1 - i];
		}	
	}
    return toplam; 
}

void DinamikBellekYonetimi::SatirMinMax(int** matris, int sutunUzunlugu, int istenilenSatir, int* minIndex, int* maxIndex) // satýrlarýn min max durumu
{

	int min = INT_MAX;
	int max = INT_MIN;
	
	for(int i=0; i < sutunUzunlugu; i++)
	{
		if(matris[istenilenSatir][i] < min)
		{
			min = matris[istenilenSatir][i];
			*minIndex = i;
		}
		if(matris[istenilenSatir][i] > max)
		{
			max = matris[istenilenSatir][i];
			*maxIndex = i;
		}
	}
}

void DinamikBellekYonetimi::SutunMinMax(int** matris, int satirUzunlugu, int istenilenSutun, int* minIndex, int* maxIndex) // sutünlarýn min max durumu
{
	int min = INT_MAX;
	int max = INT_MIN;
	
	for(int i=0; i < satirUzunlugu; i++)
	{
		if(matris[i][istenilenSutun] < min)
		{
			min = matris[i][istenilenSutun];
			*minIndex = i;
		}
		if(matris[i][istenilenSutun] > max)
		{
			max = matris[i][istenilenSutun];
			*maxIndex = i;
		}
	} 
}


