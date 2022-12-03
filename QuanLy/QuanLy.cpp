#include <string>
#include "windows.h" 
#include "RoomList.h"
#include "CustomerList.h"
#include "TradeList.h"
#include "ServiceList.h"
#include "Trade.h"
void Menu(TradeList* tradeList);
void Start();
void SetColor(int color);
void banner();
void Option(int option, TradeList*& tradeList);
Picture* scan = new Picture();
string idtest;

int main()
{
	banner();
	Start();
	return 0;
}
void Start()
{
	system("pause");
	system("cls");
	TradeList* tradeList = new TradeList();
	
	Menu(tradeList);
	SetColor(13);
	int option;
	do
	{
	NHAPLAILUACHON:
		try
		{
			cout << "Nhap lua chon cua ban: ";
			cin.seekg(1);
			cin >> option;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Vui long nhap so!!!";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai lua chon!!!\n";
			goto NHAPLAILUACHON;
		}
		Option(option, tradeList);
	} while (option != 0);
}
void Menu(TradeList* tradeList)
{
	cout << "\n";
	SetColor(126);
	cout << right << setw(2) << " " << "^^^^^^^^^^^^^^^^^^^^" << right << setw(6) << "" << "^^^^^^^^^^^^^^^^^^^ QUAN LY SAN BANH ^^^^^^^^^^^^^^^^^" << endl;
	cout << right << setw(3) << "+" << "      Member      +" << right << setw(6) << "" << "*" << right << setw(53) << "*" << endl;
	cout << right << setw(2) << " " << "+------------------+" << right << setw(6) << "" << "*\t[1] Dat san" << right << setw(39) << "*" << setw(4) << " " << "+++++++++++++++++++++++++++++++++++++" << endl;
	cout << right << setw(3) << "+" << " Tran Quang Thoi  +" << right << setw(6) << "" << "*\t[2] Tra san" << right << setw(39) << "*" << setw(4) << " " << "+" << "\t Gia san 5  loai 1(N):" << tradeList->price->perHourNHang1<<"VND" << right << setw(3) << "+" << endl;
	cout << right << setw(3) << "+" << " Huynh Bao Toan   +" << right << setw(6) << "" << "*\t[3] Tim kiem khach hang" << right << setw(27) << "*" << right << setw(5) << "+" << "\t Gia san 5  loai 2(N):" << tradeList->price->perHourNHang1 << "VND" << right << setw(3) << "+" << endl;
	cout << right << setw(3) << "+" << " Cao Ngoc Quy     +" << right << setw(6) << "" << "*\t[4] Tim kiem khach hang dang thue san" << right << setw(13) << "*" << setw(5) << "+" << "\t Gia san 11 loai 1(M):" << tradeList->price->perHourMHang1 << "VND" << right << setw(3) << "+" << endl;
	cout << right << setw(2) << " " << "++++++++++++++++++++" << right << setw(6) << "" << "*\t[5] Danh sach khach hang" << right << setw(26) << "*" << setw(4) << " " << "+" "\t Gia san 11 loai 2(M):"<< tradeList->price->perHourMHang2 << "VND" << right << setw(4) << "+" << endl;
	cout << right << setw(28) << "" << "*\t[6] Danh sach khach hang dang thue san" << right << setw(12) << "*" << setw(4) << " " << "+++++++++++++++++++++++++++++++++++++" << endl;
	cout << right << setw(28) << "" << "*\t[7] Danh sach lich su giao dich" << right << setw(19) << "*" << setw(22) << " " << "+" << endl;
	cout << right << setw(28) << "" << "*\t[8] Danh sach san" << right << setw(33) << "*" << setw(20) << " " << "+   +" << endl;
	cout << right << setw(28) << "" << "*\t[9] Danh sach cac san con trong" << right << setw(19) << "*" << setw(18) << " " << "+       +" << endl;
	cout << right << setw(28) << "" << "*\t[10] Cap nhat them san" << right << setw(28) << "*" << setw(16) << " " << "+           +" << endl;
	cout << right << setw(28) << "" << "*\t[11] Cap nhat lai gia san" << right << setw(25) << "*" << setw(4) << " " << "====================================" << endl;
	cout << right << setw(28) << "" << "*\t[12] Cap nhat trang thai san sau khi bao tri" << right << setw(6) << "*" << setw(4) << " " << "||||||||||||||||||||||||||||||||||||" << endl;
	cout << right << setw(28) << "" << "*\t[13] So luong san cua san banh" << right << setw(20) << "*" << setw(4) << " " << "====================================" << endl;
	cout << right << setw(28) << "" << "*\t[14] Doanh thu trong ngay" << right << setw(25) << "*" << endl;
	cout << right << setw(28) << "" << "*\t[15] Danh sach cac dich vu" << right << setw(24) << "*" << endl;
	cout << right << setw(28) << "" << "*\t[16] Dat dich vu" << right << setw(34) << "*" << endl;
	cout << right << setw(28) << "" << "*\t[0] Exit" << right << setw(42) << "*" << endl;
	cout << right << setw(28) << "" << "*" << right << setw(53) << "*" << endl;
	cout << right << setw(28) << "" << "* * * * * * * * * * * * * * *  * * * * * * * * * * * * " << endl;

}
void Option(int option, TradeList*& tradeList)
{
	system("cls");
	Menu(tradeList);
	SetColor(7);
	switch (option)
	{
	case 1:
		tradeList->BooKSan();
		system("pause");
		system("cls");
		Menu(tradeList);
		break;
	case 2:
		tradeList->CheckSan();
		break;
	case 3:
		tradeList->customerList->searchName();
		break;
	case 4:
		tradeList->searchName();
		break;
	case 5:
		tradeList->customerList->printListk();
		break;
	case 6:
		tradeList->printTrade();
		break;
	case 7:
		tradeList->printHistoryList();
		break;
	case 8:
		tradeList->roomList->PrintRoomList();
		break;
	case 9:
		tradeList->roomList->PrintEmptyRoomList();
		break;
	case 10:
		tradeList->roomList->UpdateMaxRoom();
		break;
	case 11:
		tradeList->price->UpdatePrice();
		system("cls");
		Menu(tradeList);
		break;
	case 12:
		tradeList->roomList->UpdateRoomA();
		break;
	case 13:
		cout << "Tong so san hien tai cua san banh la: " << tradeList->roomList->GetMaxRoom() << endl;
		break;
	case 14:
		tradeList->EarnToday();
		break;
	case 15:
		tradeList->serviceList->PrintServiceList();
		break;
	case 16:
		tradeList->DatDichVu(idtest);
		break;
	case 0:
		tradeList->DetroyTradeList();
		cout << "Da thoat chuong trinh!! Cam on quy khach da su dung dich vu cua chung toi!!" << endl;
		system("pause");
		break;
	default:
		cout << "Vui long nhap cac so tu 0->17" << endl;
		break;
	}
}
void SetColor(int color)
{
	WORD wColor;

	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info))
	{
		wColor = (screen_buffer_info.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hConsoleOutput, wColor);
	}
}
void banner()
{
	SetColor(3);
	cout << "\n" << right << setw(30) << "" << "TRUONG DAI HOC SU PHAM KY THUAT TP.HCM\n";
	cout << right << setw(35) << "" << "KHOA DAO TAO CHAT LUONG CAO\n\n\n";
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(42) << "" << "DO AN CUOI KY\n";
	cout << right << setw(30) << "" << "Mon hoc: Cau truc du lieu va giai thuat\n";
	cout << right << setw(36) << "" << "Hoc ky 1 Nam hoc 2022-2023\n";
	cout << right << setw(45) << "" << "Giang Vien: PGS.TS. Hoang Van Dung\n\n\n\n";
	SetColor(3);
	cout << right << setw(45) << "" << "QUAN LY SAN BANH\n";
	cout << right << setw(50) << "" << "Danh sach thanh vien thuc hien\n";
	cout << right << setw(25) << "" << "+=====================================================+" << endl;
	cout << right << setw(26) << "|" << " Ma so SV |" << left << setw(25) << " Ho va ten" << "| Ty le dong gop |" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " 20110xxx |" << left << setw(25) << " Huynh Bao Toan" << left << setw(17) << "| 33.33%" << "|" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " 20161377 |" << left << setw(25) << " Tran Quang Thoi" << left << setw(17) << "| 33.33%" << "|" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " 20110xxx |" << left << setw(25) << " Cao Ngoc Quy" << left << setw(17) << "| 33.33%" << "|" << endl;
	cout << right << setw(25) << "" << "+=====================================================+" << endl;
	cout << right << setw(25) << "" << "\n\n";
	cout << right << setw(25) << "" << "\tWELLCOME TO OUR SOCCER FIELD\n\n\n";
	SetColor(154);
	/*scan->inputPicture();*/
}
