#pragma once
#ifndef MUSTERÝ_H
#define MUSTERÝ_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Musteri
{
public:

	int secim;
	string dosya;
	void Menu()
	{
		cout << "Müþteri Ýþlemleri" << endl;
		cout << "------------" << endl;
		cout << "1- Müþteri Ekle\n2- Müþteri Sil\n3- Müþterileri Listele\n99- Üst Menü" << endl;
		cout << "Seçiminiz: ";
		cin >> secim;
	}
	void Calistir()
	{
		switch (secim)
		{
		case 1: MusteriEkle(); break;
		case 2: MusteriSil(); break;
		case 3: MusterileriListele(); break;
		case 99: cout << "Üst menüye gönderemedim." << endl; break;//UstMenu(); break;
		default:
			cout << "Hatalý seçim. " << endl; break;

		}
	}

	string musteriNo;
	string musteriTc;
	string musteriAd;
	string musteriSoyad;

	void musteriBilgiAl()
	{

		cout << "Müþteri numarasýný giriniz: " << endl;
		cin >> musteriNo;
		cout << "Müþterinin adýný giriniz: " << endl;
		cin >> musteriAd;
		cout << "Müþterinin soyadýný giriniz: " << endl;
		cin >> musteriSoyad;
		cout << "Müþterinin TC kimlik numarasýný giriniz: " << endl;
		cin >> musteriTc;
	}

	void MusteriEkle()
	{
		musteriBilgiAl();

		ofstream dosyaYaz;
		dosyaYaz.open(dosya, ios::app); //dosyayý açtýk
		dosyaYaz << musteriNo << "\t";
		dosyaYaz << musteriAd << "\t";
		dosyaYaz << musteriSoyad << "\t";
		dosyaYaz << musteriTc << "\n";
		dosyaYaz.close();

	}

	void MusteriSil()
	{
		int silinecek;
		cout << "Silmek istediðiniz müþterinin numarasýný giriniz: ";
		cin >> silinecek;
		ifstream dosya;
		ofstream gecici;
		dosya.open("Müþteriler.txt");
		gecici.open("gecici.txt");
	}
	void musteriBilgiYaz()
	{
		cout << musteriNo;
		cout << "         " << musteriAd;
		cout << "          " << musteriSoyad;
		cout << "         " << musteriTc << endl;
	}
	void MusterileriListele()
	{
		ifstream dosyaOku;
		dosyaOku.open(dosya, ios::in);
		cout << "Müþterinin Numarasý   Müþterinin Adý   Müþterinin Soyadý   Müþterinin TC Kimlik Numarasý" << endl;
		while (!dosyaOku.eof())
		{
			dosyaOku >> musteriNo;
			dosyaOku >> musteriAd;
			dosyaOku >> musteriSoyad;
			dosyaOku >> musteriTc;
			musteriBilgiYaz();

		}
		dosyaOku.close();
	}
public:
	Musteri()
	{
		secim = 0;

		dosya = "Müþteriler.txt";
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


#endif //MUSTERÝ_H