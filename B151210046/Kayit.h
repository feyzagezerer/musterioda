#pragma once
#ifndef KAYÝT_H
#define KAYÝT_H
#include <iostream>
#include <string>
#include <fstream>
#include"Musteri.h"
#include "Oda.h"

using namespace std;
class Kayit
{
public:
	string dosya;

	int secim;
	void Menu()
	{
		cout << "Oda Kayýt Ýþlemleri" << endl;
		cout << "------------" << endl;
		cout << "1- Oda Kaydý Ekle\n2- Oda Kaydý Sil\n3- Oda Kayýtlarýný Listele\n99- Üst Menü" << endl;
		cout << "Seçiminiz: ";
		cin >> secim;
	}

	void Calistir()
	{
		switch (secim)
		{
		case 1: KayitEkle(); break;
		case 2: KayitSil(); break;
		case 3:KayitlariniListele(); break;
		case 99: cout << "Üst menüye gönderemedim." << endl; break; //UstMenu(); break;
		default:
			cout << "Hatalý seçim. " << endl; break;
		}
	}
	Oda oda;
	Musteri musteri;
	int m;
	int o;
	void bilgiAl()
	{
		cout << "Hangi müþteriyi kayýt yaptýrmak istiyorsunuz(no)? " << endl;
		musteri.MusterileriListele();
		cin >> m;
		cout << "\nHangi odaya kaydetmek istiyorsunuz? "<<endl;
		oda.OdalariListele();
		cin >> o;
	}
	void KayitEkle()
	{
		bilgiAl();
		ofstream dosyaYaz;
		dosyaYaz.open(dosya, ios::app); //dosyayý açtýk
		dosyaYaz << m << "\t";
		dosyaYaz << o << "\n";
		dosyaYaz.close();
	}
	void KayitSil()
	{
		int silinecek;
		cout << "Silmek istediðiniz kayda ait müþteri numarasýný giriniz: ";
		cin >> silinecek;
		ifstream dosya;
		ofstream gecici;
		dosya.open("OdaKayýtlarý.txt");
		gecici.open("gecici.txt");
	}
	void bilgiYaz()
	{
		cout << "Müþterinin Numarasý     Oda Numarasý" << endl;

		cout << m << "     " << o;
	}
	void KayitlariniListele()
	{
		ifstream dosyaOku;
		dosyaOku.open(dosya, ios::in);
		while (!dosyaOku.eof())
		{
			dosyaOku >> m;
			dosyaOku >> o;
			bilgiYaz();
		}
		dosyaOku.close();
	}
public:
	Kayit()
	{
		secim = 0;

		dosya = "OdaKayýtlarý.txt";
	}
	void Islem()
	{

		while (secim != 99)
		{
			system("cls");
			Menu();
			Calistir();

			system("pause");
		}
	}
};
#endif // KAYÝT_H