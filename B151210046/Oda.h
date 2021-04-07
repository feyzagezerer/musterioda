#pragma once
#ifndef ODA_H
#define ODA_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Oda
{
public:
	string dosya;
	int secim;
	void Menu()
	{
		cout << "Oda Ýþlemleri" << endl;
		cout << "------------" << endl;
		cout << "1- Oda Ekle\n2- Oda Sil\n3- Odalarý Listele\n99- Üst Menü" << endl;
		cout << "Seçiminiz: ";
		cin >> secim;
	}
	void Calistir()
	{
		switch (secim)
		{
		case 1: OdaEkle(); break;
		case 2: OdaSil(); break;
		case 3: OdalariListele(); break;
		case 99: cout << "Üst menüye gönderemedim."; break;
		default:
			cout << "Hatalý seçim. " << endl; break;

		}
	}

	int odaNo;
	int ucret;
	void BilgiAlOda()
	{

		cout << "Odanýn numarasýný giriniz: " << endl;
		cin >> odaNo;
		cout << "Odanýn ücretini giriniz: " << endl;
		cin >> ucret;

	}
	void OdaEkle()
	{
		BilgiAlOda();

		ofstream dosyaYaz;
		dosyaYaz.open(dosya, ios::app); //dosyayý açtýk
		dosyaYaz << odaNo << "\t";
		dosyaYaz << ucret << "\n";
		dosyaYaz.close();

	}
	void OdaSil()
	{
		int silinecek;
		cout << "Silmek istediðiniz odanýn numarasýný giriniz: ";
		cin >> silinecek;
		ifstream dosya;
		ofstream gecici;
		dosya.open("Odalar.txt");
		gecici.open("gecici.txt");
		/*	while (!dosya.eof())
		{
		if (silinecek != odaNo)
		{
		fstream dosyaYaz;
		dosyaYaz.open(dosya, ios::app);
		dosyaYaz << odaNo << "\t";
		dosyaYaz << ucret << "\n";
		dosyaYaz.close();
		}
		}
		dosya.close();
		gecici.close();
		remove("Odalar.txt");
		rename("gecici.txt", "Odalar.txt");*/
	}
	void odaBilgiYaz()
	{
		cout << odaNo;
		cout << "   " << ucret << endl;
	}
	void OdalariListele()
	{

		ifstream dosyaOku;
		dosyaOku.open(dosya, ios::in);
		cout << "Odanýn Numarasý   Odanýn Ücreti" << endl;
		while (!dosyaOku.eof())
		{
			dosyaOku >> odaNo;
			dosyaOku >> ucret;
			odaBilgiYaz();
		}
		dosyaOku.close();
	}

public:
	Oda()
	{
		secim = 0;
		dosya = "Odalar.txt";
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



#endif // !ODA_H