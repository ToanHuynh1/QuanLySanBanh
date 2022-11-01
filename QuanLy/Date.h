#pragma once
#include <time.h>
class Date
{
public:
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;
	void AutoSetDate();
	void printDateTime();
	void printDate();
	bool IsLeapYear();
	int DateInMonth();
	bool IsTrueDate();
	bool IsTrueTime();
	void fDateTime(ifstream& filein);//true
	void fDate(ifstream& filein);
	void fOuputDateTime(ofstream& fileout, Date date);
	bool isEqualDate(Date date);
	void fOuputDate(ofstream& fileout, Date date);
	int SumDate();

};
int Date::SumDate() {
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}
bool Date::isEqualDate(Date date)
{
	if (date.day == day && date.month == month && date.year == year)
		return true;
	return false;
}
void Date::fOuputDateTime(ofstream& fileout, Date date)
{
	fileout << date.hour << ":" << date.minute << ":" << date.second << ";"
		<< date.day << "/" << date.month << "/" << date.year;

}
void Date::fOuputDate(ofstream& fileout, Date date)
{
	fileout << date.day << "/" << date.month << "/" << date.year;
}
void Date::fDate(ifstream& filein)//true
{
	filein >> day;
	filein.seekg(1, 1);
	filein >> month;
	filein.seekg(1, 1);
	filein >> year;
}
void Date::fDateTime(ifstream& filein)//true
{
	filein >> hour;
	filein.seekg(1, 1);
	filein >> minute;
	filein.seekg(1, 1);
	filein >> second;
	filein.seekg(1, 1);
	filein >> day;
	filein.seekg(1, 1);
	filein >> month;
	filein.seekg(1, 1);
	filein >> year;
}
bool Date::IsLeapYear()
{
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
		return true;
	return false;
}
int Date::DateInMonth()
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		if (month == 2)
			if (IsLeapYear())
				return 29;
			else
				return 28;
		else
			return 31;
}
bool Date::IsTrueDate()
{
	if (day > 0 && day <= DateInMonth() && month > 0 && month <= 12 && year > 0)
		return  true;
	return false;
}
bool Date::IsTrueTime()
{
	return (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60);
}
void Date::printDateTime()//true
{
	string temp = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second)
		+ " " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	cout << " " << left << setw(25) << temp << "|";
}
void Date::printDate()
{
	string temp = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	cout << left << setw(11) << temp << "| ";
}
void Date::AutoSetDate()
{
	struct tm currentTime;
	time_t now = time(0);
	localtime_s(&currentTime,&now);
	day = currentTime.tm_mday;
	month = 1 + currentTime.tm_mon;
	year = 1900 + currentTime.tm_year;
	hour = currentTime.tm_hour;
	minute = currentTime.tm_min;
	second = currentTime.tm_sec;
}