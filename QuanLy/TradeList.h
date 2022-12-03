#pragma once

#include "Trade.h"
#include "CustomerList.h"
#include <string>
#include "ServiceList.h"

class TradeList
{
public:
	CustomerList* customerList;
	RoomList* roomList;
	Price* price;
	ServiceList* serviceList;
	Trade* trade;

	class TradeNode {
	public:
		Trade data;
		TradeNode* next;
		TradeNode(Trade data)
		{
			this->data = data;
			this->next = nullptr;
		}
	};
	TradeNode* head;
	TradeList()
	{
		customerList = new CustomerList();
		roomList = new RoomList();
		serviceList = new ServiceList();
		price = new Price();
		head = nullptr;
		fInput();

	}


	void EarnToday()
	{
		int sum = 0;
		Trade trade;
		int price;
		ifstream filein;
		bool k = false;
		Date date;
		date.AutoSetDate();
		filein.open("LICHSUGIAODICH.TXT", ios::in);
		if (filein.fail())
		{
			return;
		}
		while (!filein.eof())
		{
			trade = fTrade(filein, k);
			k = true;
			trade.customer = customerList->ReturnById(trade.customer.id);
			filein.seekg(1, 1);
			trade.dateOut.fDateTime(filein);
			filein.seekg(1, 1);
			filein >> price;
			if (date.SumDate() == trade.dateOut.SumDate())
			{
				sum += price;
			}
		}
		filein.close();
		cout << "Doanh thu ngay ";
		date.printDate();
		cout << " " << sum << "VND" << endl;
	}
	void printHistoryList()
	{
		Trade trade;
		int price;
		ifstream filein;
		bool k = false;
		filein.open("LICHSUGIAODICH.TXT", ios::in);
		if (filein.fail())
		{
			return;
		}
		memset(t, '_', 176);
		cout << t << endl;
		cout << "|" << left << setw(15) << "   CMND/CCCD" << "|" << left << setw(20) << "\t\tHo va Ten";
		cout << "|" << left << setw(16) << "  So Dien Thoai" << "|" << left << setw(12) << " Ngay Sinh" << "|" <<
			left << setw(9) << "Gioi Tinh" << "|" << left << setw(14) << "\t Dia chi" << "|" <<
			left << setw(26) << "    Ngay dat san" << "|" << left << setw(26) << "    Ngay tra san" << "|" << left << setw(11) << " Gia tien" << "|" << endl;
		memset(t, '=', 176);
		cout << t << endl;
		while (!filein.eof())
		{
			trade = fTrade(filein, k);
			k = true;
			trade.customer = customerList->ReturnById(trade.customer.id);
			filein.seekg(1, 1);
			trade.dateOut.fDateTime(filein);
			filein.seekg(1, 1);
			filein >> price;


			trade.customer.printACustomer();
			trade.dateIn.printDateTime();
			trade.dateOut.printDateTime();
			cout << " " << left << setw(10) << price << "|" << endl;
			memset(t, '-', 176);
			cout << t << endl;
		}
		memset(t, NULL, MAX);
		filein.close();

	}
	void fOutputHistory(Trade trade)
	{
		ofstream fileout;
		ifstream filein;
		filein.open("LICHSUGIAODICH.TXT", ios::in);
		fileout.open("LICHSUGIAODICH.TXT", ios::app);
		if (!filein.fail())
		{
			fileout << '\n';
		}

		fileout << trade.id << ";" << trade.customer.id << ";" << trade.room.id << ";";
		trade.dateIn.fOuputDateTime(fileout, trade.dateIn);
		fileout << ";";
		trade.dateOut.fOuputDateTime(fileout, trade.dateOut);
		fileout << ";" << trade.GetPrice();

		filein.close();
		fileout.close();
	}
	void printTrade()
	{
		TradeNode* temp = head;
		printform();
		while (temp != nullptr)
		{
			cout << left << setw(10) << "" << "| " << left << setw(14) << temp->data.id << "| ";
			cout << left << setw(9) << temp->data.room.id;
			temp->data.customer.printACustomer();
			cout << endl;
			memset(t, '-', 135);
			cout << left << setw(10) << "" << t << endl;
			temp = temp->next;
		}
		memset(t, NULL, MAX);
	}
	void fOutput()
	{
		TradeNode* temp = head;
		if (head == nullptr)
		{
			int t = remove("DANHSACHGIAODICH.TXT");
			return;
		}
		ofstream fileout;
		fileout.open("DANHSACHGIAODICH.TXT", ios::out);
		while (temp->next != nullptr)
		{
			temp->data.fOutput(fileout);
			fileout << '\n';
			temp = temp->next;
		}
		temp->data.fOutput(fileout);
		fileout.close();
	}
	Trade fTrade(ifstream& filein, bool k)
	{
		Trade trade;
		if (k)
		{
			string temp;
			getline(filein, temp, '\n');// loai bo ki tu xuong hang
		}
		getline(filein, trade.id, ';');
		getline(filein, trade.customer.id, ';');
		getline(filein, trade.room.id, ';');
		trade.dateIn.fDateTime(filein);
		return trade;
	}
	void fInput()
	{
		bool k = false;
		Trade trade;
		ifstream filein;
		filein.open("DANHSACHGIAODICH.TXT", ios::in);
		if (filein.fail())
		{
			return;
		}

		while (!filein.eof())
		{
			trade = fTrade(filein, k);
			k = true;
			trade.customer = customerList->ReturnById(trade.customer.id);
			trade.InitDateOut();
			AddLast(trade);
		}
		filein.close();
	}
	string SearchByIDR(string idR)
	{
		TradeNode* temp = head;
		while (temp != nullptr)
		{
			if (temp->data.room.id.compare(idR) == 0)
				return temp->data.id;
			temp = temp->next;
		}
		return "";
	}

	bool IsExistId(string id)
	{
		TradeNode* temp = head;
		while (temp != nullptr)
		{
			if (temp->data.id.compare(id) == 0)
				return true;
			temp = temp->next;
		}
		return false;
	}
	void DeleteByID(string id)
	{
		TradeNode* pDel = head;
		char d[87];
		if (pDel == nullptr) {
			cout << "Danh sach rong!!!";
		}
		else {
			TradeNode* pPre = nullptr;
			while (pDel != nullptr) {
				if (pDel->data.id.compare(id) == 0)
				{
					cout << "Tong gia san: " << pDel->data.GetPrice() << endl;
					fOutputHistory(pDel->data);
					printform();
					cout << left << setw(10) << "" << "| " << left << setw(14) << pDel->data.id << "| ";
					cout << left << setw(9) << pDel->data.room.id;
					pDel->data.customer.printACustomer();
					cout << endl;
					memset(t, '-', 136);
					cout << left << setw(10) << "" << t << endl;
					cout << left << setw(10) << "" << "|" << left << setw(15);
					cout << "Ngay dat san: ";
					pDel->data.dateIn.printDateTime();					
					cout << "Ngay tra san: ";
					pDel->data.dateOut.printDateTimek();
					cout << endl;
					memset(t, NULL, MAX);
					memset(t, '=', 136);
					cout << left << setw(10) << "" << t << endl;
					memset(t, NULL, MAX);
					break;
				}
				pPre = pDel;
				pDel = pDel->next;
			}
			if (pDel == nullptr) {
				cout << "Khong tim thay ma giao dich can xoa";
			}
			else {
				if (pDel == head) {
					head = head->next;
					pDel->next = nullptr;
					delete pDel;
					pDel = nullptr;
				}
				else if (pDel->next == nullptr) {
					pPre->next = nullptr;
					delete pDel;
					pDel = nullptr;
				}
				else {
					pPre->next = pDel->next;
					pDel->next = nullptr;
					delete pDel;
					pDel = nullptr;
				}
			}
		}
	}
	void searchName()
	{
		FullName fname;
		bool check = false;
	NHAPLAITEN:
		try
		{
			cout << "Nhap ten khach hang: ";
			cin >> fname.firstName;
			if (fname.CheckFirstName() == false)
				throw "Ten khong hop le!";
			transform(fname.firstName.begin(), fname.firstName.end(), fname.firstName.begin(), toupper);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap ten bang chu!" << endl;
			goto NHAPLAITEN;
		}
		TradeNode* temp = head;
		printform();
		while (temp != nullptr)
		{
			if (fname.firstName.compare(temp->data.customer.fullName.firstName) == 0)
			{
				check = true;
				cout << left << setw(10) << "" << "| " << left << setw(14) << temp->data.id << "| ";
				cout << left << setw(9) << temp->data.room.id;
				temp->data.customer.printACustomer();
				cout << endl;
				memset(t, '-', 135);
				cout << left << setw(11) << "" << t << endl;
			}
			temp = temp->next;
		}
		memset(t, NULL, MAX);
		if (!check)
			cout << "Hien khong co khach hang ten " << fname.firstName << endl;
	}
	void CheckSan()
	{

		string idR;
	NHAPMASAN:
		try
		{
			cout << "Nhap ma san muon tra:";
			cin >> idR;
			bool kt = idR[1] == '1' || idR[1] == '2';
			if (!(idR.length() == 4 && idR[0] == 'N' || idR[0] == 'M' && kt))
				throw "ID da sai\n";
			if (!roomList->IsExistRoom(idR))
				throw "ID san khong ton tai\n";
			if (!roomList->IsFullRoom(idR))
				throw "San nay khong co nguoi thue\n";
			roomList->UpdateState(idR, -1);
			DeleteByID(SearchByIDR(idR));
			fOutput();
		}
		catch (const char* msg)
		{
			cout << msg;
			cout << "Vui long nhap lai\n";
			goto NHAPMASAN;
		}

	}
	void BooKSan()
	{
		if (roomList->IsNoMoreEmptyRoom())
		{
			cout << "Hien tai san banh khong con san trong!\n";
			return;
		}
		char type;
		Customer customer = customerList->InputCustomer();
		Trade trade;
		trade.customer = customer;
		do
		{
			srand(time(0));
			trade.id = to_string(rand() % (9999999 - 1000000 + 1) + 1000000);
		} while (IsExistId(trade.id));

	NHAPLAILOAISAN:
		try
		{
			cout << "Nhap loai san: ";
			cin >> type;

			type = toupper(type);
			if (!(type == 'N' || type == 'M'))
			{
				cin.seekg(1);
				throw "Loai san phai la M hoac N";
			}
			if (!roomList->IsEmptyRoom(type))
			{
				string str = "San loai ";
				str.append(type == 'N' ? "SAN 5" : "SAN 11");
				str.append(" da het");
				throw str;
			}

			trade.room = roomList->GetFirstEmptyRoom(type);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai" << endl;
			goto NHAPLAILOAISAN;
		}
		catch (const string msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai" << endl;
			goto NHAPLAILOAISAN;
		}
		trade.dateIn.AutoSetDate();
		trade.InitDateOut();
		if (!customerList->IsExistId(trade.customer.id))
		{
			customerList->AddHead(customer);
			customerList->fOutputApp(customer);
		}
		roomList->UpdateState(trade.room.id, 1);
		roomList->fOutputRooms();
		this->AddLast(trade);
		this->fOutput();
	}
	void AddLast(Trade data)
	{
		TradeNode* node = new TradeNode(data);
		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			TradeNode* temp = this->head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = node;
		}
	}
	void DetroyTradeList()
	{
		this->roomList->DetroyRoomList();
		this->customerList->DetroyCustomerList();
		TradeNode* temp = this->head;
		while (this->head != nullptr)
		{
			this->head = temp->next;
			delete temp;
			temp = this->head;
		}
	}
	void printform()
	{
		memset(t, '_', 135);
		cout << left << setw(11) << "" << t << endl;
		cout << left << setw(10) << "" << "|" << left << setw(15) << " ID Giao Dich" << "|" << left << setw(10) <<
			" ID San" << "|" << left << setw(15) << "   CMND/CCCD" << "|" << left << setw(25) << "\t\tHo va Ten";
		cout << "|" << left << setw(16) << "  So Dien Thoai" << "|" << left << setw(12) << " Ngay Sinh" << "|" <<
			left << setw(9) << "Gioi Tinh" << "|" << left << setw(18) << " Dia chi" << "|" << endl;
		memset(t, '=', 135);
		cout << left << setw(11) << "" << t << endl;
	}

	void DatDichVu(string ID)
	{
		int tiendichvu;
	NHAPMASAN:
		try
		{
			cout << "Nhap ma muon dat dich vu:";
			cin >> ID;
			bool kt = ID[1] == '1' || ID[1] == '2';
			if (!(ID.length() == 4 && ID[0] == 'N' || ID[0] == 'M' && kt))
				throw "ID da sai\n";
			if (!roomList->IsExistRoom(ID))
				throw "ID san khong ton tai\n";
			if (!roomList->IsFullRoom(ID))
				throw "San nay khong co nguoi thue\n";
			serviceList->UpdateDatDichVu();

			ifstream filein;
			filein.open("FILEGIATIEN.TXT", ios::in);
	
			filein >> tiendichvu;
			filein.close();
			cout << tiendichvu << endl;

			ofstream fileout;
			fileout.open("IDSANTIENDICHVU.TXT", ios::out);
			fileout << ID << "," << tiendichvu << endl;
			fileout.close();
			cout << "|" << "Ma San" << "|" << "TienDichVu" << "|" << endl;
			cout << "|" << ID << "|" << tiendichvu << "|" << endl;
		}
		catch (const char* msg)
		{
			cout << msg;
			cout << "Vui long nhap lai\n";
			goto NHAPMASAN;
		}
	}

};

