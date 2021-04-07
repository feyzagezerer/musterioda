/****************************************************************************
**							SAKARYA ÜNÝVERSÝTESÝ
**				    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**					   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				         PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI.......: PROJE 1
**				ÖÐRENCÝ ADI.........: FEYZA GEZERER
**				ÖÐRENCÝ NUMARASI....: B151210046
**				DERS GRUBU..........: 2-C
****************************************************************************/
#include <iostream>
#include <string>
#include "Oda.h"
#include "Musteri.h"
#include "Kayit.h"
using namespace std;

int main()
{
	//setlocale(LC_ALL, ("Turkish"));
	int secim;
	cout << "Otel Ýþlemleri" << endl;
	cout << "------------" << endl;
	cout << "1- Oda Ýþlemleri\n2- Müþteri Ýþlemleri\n3- Oda Kayýt Ýþlemleri\n99- Çýkýþ" << endl;
	cout << "Seçiminiz: ";
	cin >> secim;
	Kayit kayit;
	Oda oda;
	Musteri musteri;
	switch (secim)
	{
	case 1: oda.Islem(); break;
	case 2:  musteri.Islem(); break;
	case 3:  kayit.Islem();  break;
	case 99: cout << "Çýkýþ yaptýnýz."; break;
	default:
		cout << "Hatalý seçim. " << endl; break;
	}
}