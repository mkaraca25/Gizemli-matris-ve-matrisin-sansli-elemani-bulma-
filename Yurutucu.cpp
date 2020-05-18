#include <iostream> 
#include "DinamikBellekYonetimi.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL,"Turkish");//Türkçe karakterlerin gözükmesi için
	int satir,sutun,m;
	DinamikBellekYonetimi *nesnePtr=new DinamikBellekYonetimi; // Yeni bir pointer deklare ediyoruz.
	cin>>satir>>sutun;// Kullanýcýdan satýr ve sütun isteyip atama iþlemini yapýyoruz.
	int **matrisPtr=new int*[satir];
	Fonksiyon1(matrisPtr,satir,sutun)=m;
	for(int i=0;i=m;i++)//Tüm þartlarý saðlayýp geriye true döndürüyor ise
	{
		if(m==true)
		cout<<"Matris gizemli bir matristir.n";
		else if(m==false)
		cout<<"Matris gizemli bir matris deðildir.n";
          //Kare matris deðilse programý sonlandýr.
        else
		cout<<"Lütfen satýr ve sütun sayýsýný eþit giriniz.n ";//return false;
		
	    delete [] matrisPtr;// Oluþturduðumuz pointerleri silme iþlemi.
	    delete  nesnePtr;
	}
	return 0;
}

