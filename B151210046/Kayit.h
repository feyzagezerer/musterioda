#pragma once
#ifndef KAY�T_H
#define KAY�T_H
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
		cout << "Oda Kay�t ��lemleri" << endl;
		cout << "------------" << endl;
		cout << "1- Oda Kayd� Ekle\n2- Oda Kayd� Sil\n3- Oda Kay�tlar�n� Listele\n99- �st Men�" << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
	}

	void Calistir()
	{
		switch (secim)
		{
		case 1: KayitEkle(); break;
		case 2: KayitSil(); break;
		case 3:KayitlariniListele(); break;
		case 99: cout << "�st men�ye g�nderemedim." << endl; break; //UstMenu(); break;
		default:
			cout << "Hatal� se�im. " << endl; break;
		}
	}
	Oda oda;
	Musteri musteri;
	int m;
	int o;
	void bilgiAl()
	{
		cout << "Hangi m��teriyi kay�t yapt�rmak istiyorsunuz(no)? " << endl;
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
		dosyaYaz.open(dosya, ios::app); //dosyay� a�t�k
		dosyaYaz << m << "\t";
		dosyaYaz << o << "\n";
		dosyaYaz.close();
	}
	void KayitSil()
	{
		int silinecek;
		cout << "Silmek istedi�iniz kayda ait m��teri numaras�n� giriniz: ";
		cin >> silinecek;
		ifstream dosya;
		ofstream gecici;
		dosya.open("OdaKay�tlar�.txt");
		gecici.open("gecici.txt");
	}
	void bilgiYaz()
	{
		cout << "M��terinin Numaras�     Oda Numaras�" << endl;

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

		dosya = "OdaKay�tlar�.txt";
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
#endif // KAY�T_H