/****************************************************************************
**							SAKARYA �N�VERS�TES�
**				    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**					   B�LG�SAYAR M�HEND�SL��� B�L�M�
**				         PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI.......: PROJE 1
**				��RENC� ADI.........: FEYZA GEZERER
**				��RENC� NUMARASI....: B151210046
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
	cout << "Otel ��lemleri" << endl;
	cout << "------------" << endl;
	cout << "1- Oda ��lemleri\n2- M��teri ��lemleri\n3- Oda Kay�t ��lemleri\n99- ��k��" << endl;
	cout << "Se�iminiz: ";
	cin >> secim;
	Kayit kayit;
	Oda oda;
	Musteri musteri;
	switch (secim)
	{
	case 1: oda.Islem(); break;
	case 2:  musteri.Islem(); break;
	case 3:  kayit.Islem();  break;
	case 99: cout << "��k�� yapt�n�z."; break;
	default:
		cout << "Hatal� se�im. " << endl; break;
	}
}