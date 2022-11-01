#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Price                          // N la san 5, M la san 11
{
public:
	int perNightM;
	int perHourM;
	int perNightN;
	int perHourN;
	Price()
	{
		fGetPrice();
	}
	void UpdatePrice();
	void fSetPrice();
	void fGetPrice();
};
void Price::UpdatePrice()
{
	cout << "Cap nhat lai gia san\n";
	cout << "San 5 nguoi\n";
NHAPGIASAN5THEOGIO:
	try
	{
		cout << "Gia san theo moi gio: ";
		cin >> perHourN;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia san la so nha ban ~.~";
		}
		if (perHourN < 0)
			throw "Gia san phai la so duong ~.~";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia san ~.~\n";
		goto NHAPGIASAN5THEOGIO;
	}
NHAPGIAPSAN5THEODEM:
	try
	{
		cout << "Gia san theo moi dem ";
		cin >> perNightN;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia san la so ban ui ~.~";
		}
		if (perNightN < 0)
			throw "Gia san phai la so duong";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia\n";
		goto NHAPGIAPSAN5THEODEM;
	}
	cout << "Phong V.I.P\n";
NHAPGIASAN11THEOGIO:
	try
	{
		cout << "Gia san theo moi gio: ";
		cin >> perHourM;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia san la so ~.~";
		}
		if (perHourM < 0)
			throw "Gia san phai la so duong";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia san\n";
		goto NHAPGIASAN11THEOGIO;
	}
NHAPGIASAN11THEODEM:
	try
	{
		cout << "Gia san theo moi dem ";
		cin >> perNightM;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw "Phai nhap gia san la so ban ui ~.~";
		}
		if (perNightM < 0)
			throw "Gia san phai la so duong";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "Vui long nhap lai gia san\n";
		goto NHAPGIASAN11THEODEM;
	}
	fSetPrice();
}
void Price::fSetPrice()
{
	ofstream fileout;
	fileout.open("GIAPHONG.TXT", ios::out);
	fileout << this->perHourN << endl;
	fileout << this->perNightN << endl;
	fileout << this->perHourM << endl;
	fileout << this->perNightM << endl;
	fileout.close();
}
void Price::fGetPrice()
{
	ifstream filein;
	filein.open("GIAPHONG.TXT", ios::in);
	while (!filein.eof())
	{
		filein >> perHourN;
		filein >> perNightN;
		filein >> perHourM;
		filein >> perNightM;
	}
	filein.close();
}
