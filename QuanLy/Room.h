#pragma once
#include <string>
#include "Price.h"
using namespace std;
class Room
{
	private:
		Price price;
	public:
		string id;
		int state;


	int GetPricePerHour()
	{
		price.fGetPrice();
		if (id[0] == 'M' && id[1] == '1')
			return price.perHourMHang1;
		else if ((id[0] == 'M' && id[1] == '2'))
		{
			return price.perHourMHang2;
		}
		else if ((id[0] == 'N' && id[1] == '1'))
		{
			return price.perHourNHang1;
		}
		return price.perHourNHang2;
	}

};
