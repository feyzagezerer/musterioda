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
		cout << "Oda ��lemleri" << endl;
		cout << "------------" << endl;
		cout << "1- Oda Ekle\n2- Oda Sil\n3- Odalar� Listele\n99- �st Men�" << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
	}
	void Calistir()
	{
		switch (secim)
		{
		case 1: OdaEkle(); break;
		case 2: OdaSil(); break;
		case 3: OdalariListele(); break;
		case 99: cout << "�st men�ye g�nderemedim."; break;
		default:
			cout << "Hatal� se�im. " << endl; break;

		}
	}

	int odaNo;
	int ucret;
	void BilgiAlOda()
	{

		cout << "Odan�n numaras�n� giriniz: " << endl;
		cin >> odaNo;
		cout << "Odan�n �cretini giriniz: " << endl;
		cin >> ucret;

	}
	void OdaEkle()
	{
		BilgiAlOda();

		ofstream dosyaYaz;
		dosyaYaz.open(dosya, ios::app); //dosyay� a�t�k
		dosyaYaz << odaNo << "\t";
		dosyaYaz << ucret << "\n";
		dosyaYaz.close();

	}
	void OdaSil()
	{
		int silinecek;
		cout << "Silmek istedi�iniz odan�n numaras�n� giriniz: ";
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
		cout << "Odan�n Numaras�   Odan�n �creti" << endl;
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