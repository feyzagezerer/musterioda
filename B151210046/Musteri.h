#pragma once
#ifndef MUSTER�_H
#define MUSTER�_H

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
		cout << "M��teri ��lemleri" << endl;
		cout << "------------" << endl;
		cout << "1- M��teri Ekle\n2- M��teri Sil\n3- M��terileri Listele\n99- �st Men�" << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
	}
	void Calistir()
	{
		switch (secim)
		{
		case 1: MusteriEkle(); break;
		case 2: MusteriSil(); break;
		case 3: MusterileriListele(); break;
		case 99: cout << "�st men�ye g�nderemedim." << endl; break;//UstMenu(); break;
		default:
			cout << "Hatal� se�im. " << endl; break;

		}
	}

	string musteriNo;
	string musteriTc;
	string musteriAd;
	string musteriSoyad;

	void musteriBilgiAl()
	{

		cout << "M��teri numaras�n� giriniz: " << endl;
		cin >> musteriNo;
		cout << "M��terinin ad�n� giriniz: " << endl;
		cin >> musteriAd;
		cout << "M��terinin soyad�n� giriniz: " << endl;
		cin >> musteriSoyad;
		cout << "M��terinin TC kimlik numaras�n� giriniz: " << endl;
		cin >> musteriTc;
	}

	void MusteriEkle()
	{
		musteriBilgiAl();

		ofstream dosyaYaz;
		dosyaYaz.open(dosya, ios::app); //dosyay� a�t�k
		dosyaYaz << musteriNo << "\t";
		dosyaYaz << musteriAd << "\t";
		dosyaYaz << musteriSoyad << "\t";
		dosyaYaz << musteriTc << "\n";
		dosyaYaz.close();

	}

	void MusteriSil()
	{
		int silinecek;
		cout << "Silmek istedi�iniz m��terinin numaras�n� giriniz: ";
		cin >> silinecek;
		ifstream dosya;
		ofstream gecici;
		dosya.open("M��teriler.txt");
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
		cout << "M��terinin Numaras�   M��terinin Ad�   M��terinin Soyad�   M��terinin TC Kimlik Numaras�" << endl;
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

		dosya = "M��teriler.txt";
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


#endif //MUSTER�_H