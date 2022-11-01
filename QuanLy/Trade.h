#pragma once
#include <string>
#include "Date.h"
#include "CustomerList.h"
#include "RoomList.h"

class Trade
{
private:
	int price = 0;
public:
	string id;
	Room room;
	Customer customer;
	Date dateIn;
	Date dateOut;
	void InitDateOut();
	void CalPrice();
	int GetPrice();
	void fOutput(ofstream& fileout);
};
void Trade::fOutput(ofstream& fileout)
{
	fileout << id << ";" << customer.id << ";" << room.id << ";";
	dateIn.fOuputDateTime(fileout, dateIn);
}
void Trade::InitDateOut()
{
	dateOut.day = 0;
	dateOut.minute = 0;
	dateOut.year = 0;
	dateOut.hour = 0;
	dateOut.minute = 0;
	dateOut.second = 0;
}
int Trade::GetPrice()
{
	CalPrice();
	return price;
}
void Trade::CalPrice()//true
{
	int totalhour;
	dateOut.AutoSetDate();
	int gen = dateOut.SumDate() - dateIn.SumDate();
	if (gen == 0)
		totalhour = dateOut.hour - dateIn.hour;
	else
		totalhour = (gen - 1) * 24 + (dateOut.hour + (24 - dateIn.hour));
	if (totalhour == 0)
		price = room.GetPricePerHour();
	else if (totalhour < 5)
		price = totalhour * room.GetPricePerHour();
	else
		if (totalhour >= 5 && totalhour < 12)
			price = totalhour * room.GetPricePerNight();
		else
			price = (totalhour / 12) * room.GetPricePerNight() + (totalhour % 12) * room.GetPricePerHour();
}

