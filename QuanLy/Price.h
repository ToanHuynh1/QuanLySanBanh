#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Price                          // N la san 5, M la san 11
{
public:
	int perHourMHang1;
	int perHourNHang1;
	int perHourMHang2;
	int perHourNHang2;
	Price()
	{
		fGetPrice();
	}


	void  UpdatePrice()
	{
		cout << "Cap nhat lai gia san\n";
		cout << "San 5 nguoi hang 1\n";
	NHAPGIASAN5THEOGIOHANG1:
		try
		{
			cout << "Gia san theo moi gio: ";
			cin >> perHourNHang1;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Phai nhap gia san la so nha ban";
			}
			if (perHourNHang1 < 0)
				throw "Gia san phai la so duong";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai gia san \n";
			goto NHAPGIASAN5THEOGIOHANG1;
		}

		cout << "San 11 hang 1\n";
	NHAPGIASAN11THEOGIOHANG1:
		try
		{
			cout << "Gia san theo moi gio: ";
			cin >> perHourMHang1;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Phai nhap gia san la so";
			}
			if (perHourMHang1 < 0)
				throw "Gia san phai la so duong";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai gia san\n";
			goto NHAPGIASAN11THEOGIOHANG1;
		}

		cout << "San 5 hang 2\n";
	NHAPGIASAN5THEOGIOHANG2:
		try
		{
			cout << "Gia san theo moi gio: ";
			cin >> perHourNHang2;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Phai nhap gia san la so";
			}
			if (perHourNHang2 < 0)
				throw "Gia san phai la so duong";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai gia san\n";
			goto NHAPGIASAN5THEOGIOHANG2;
		}
		cout << "San 5 hang 2\n";
	NHAPGIASAN11THEOGIOHANG2:
		try
		{
			cout << "Gia san theo moi gio: ";
			cin >> perHourMHang2;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Phai nhap gia san la so";
			}
			if (perHourMHang2 < 0)
				throw "Gia san phai la so duong";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai gia san\n";
			goto NHAPGIASAN5THEOGIOHANG2;
		}

		fSetPrice();
	}
	void  fSetPrice()
	{
		ofstream fileout;
		fileout.open("GIASAN.TXT", ios::out);
		fileout << this->perHourNHang1 << endl;
		fileout << this->perHourMHang1 << endl;
		fileout << this->perHourNHang2 << endl;
		fileout << this->perHourMHang2 << endl;
		fileout.close();
	}
	void  fGetPrice()
	{
		ifstream filein;
		filein.open("GIASAN.TXT", ios::in);
		while (!filein.eof())
		{
			filein >> perHourNHang1;
			filein >> perHourMHang1;
			filein >> perHourNHang2;
			filein >> perHourMHang2;
		}
		filein.close();
	}

};
