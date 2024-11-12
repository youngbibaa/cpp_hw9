#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date() {}
	Date(int day, int month, int year) : day{ day }, month{ month }, year{ year } {}

	void increaseByOne() {
		day++;
	}

	Date& operator++() 
	{ 
		++day; 
		return *this; 
	}
	Date& operator--()
	{
		--day;
		return *this;
	}

	friend bool operator==(const Date& date1, const Date& date2)
	{
		return date1.day == date2.day && date1.month == date2.month && date1.year == date2.year;
	}

	friend bool operator!=(const Date& date1, const Date& date2) 
	{ 
		return !(date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
	}

	friend bool operator<(const Date& date1, const Date& date2)
	{
		if (date1.year < date2.year) return true;
		if (date1.year > date2.year) return false;
		if (date1.month < date2.month) return true;
		if (date1.month > date2.month) return false;
		return date1.day < date2.day;
	}

	friend bool operator>(const Date& date1, const Date& date2)
	{
		return date2 < date1; 
	}

	friend ostream& operator<< (ostream& output, const Date& date)
	{ 
		output << date.day << "/" << date.month << "/" << date.year;
		return output; 
	}

	friend istream& operator>> (istream& input, Date& date) 
	{ 
		input >> date.day;
		input.ignore(1);    
		input >> date.month;
		input.ignore(1);
		input >> date.year;
		return input; 
	}

	Date& operator=(const Date& date) 
	{
		if (this == &date)
			return *this;

		day = date.day;
		month = date.month;
		year = date.year;

		return *this;
	}

	Date& operator+=(int days)
	{
		day += days;

		while (day > 30) { 
			day -= 30;
			month++;
			if (month > 12) {
				month = 1;
				year++;
			}
		}
		return *this;
	}

	Date& operator-=(int days)
	{
		day -= days;

		while (day <= 0) {
			day += 30;
			month--;
			if (month <= 0) {
				month = 12;
				year--;
			}
		}
		return *this;
	}

	void operator()(int newDay, int newMonth, int newYear)
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}


};

int main()
{
	Date date1(15, 8, 2025);
	Date date2(1, 1, 2023);

	cout << "Начальная дата date1: " << date1 << endl;
	cout << "Начальная дата date2: " << date2 << endl;

	date1 += 20;
	cout << "date1 после += 20 дней: " << date1 << endl;

	date1 -= 25;
	cout << "date1 после -= 25 дней: " << date1 << endl;

	date1(10, 10, 2022);
	cout << "date1 после установки новой даты с помощью (): " << date1 << endl;

	++date1;
	cout << "date1 после ++: " << date1 << endl;

	--date1;
	cout << "date1 после --: " << date1 << endl;

	date1.increaseByOne();
	cout << "date1 после increaseByOne: " << date1 << endl;

	cout << "Равна ли date1 date2? " << (date1 == date2 ? "Да" : "Нет") << endl;
	cout << "Не равна ли date1 date2? " << (date1 != date2 ? "Да" : "Нет") << endl;
	cout << "Меньше ли date1, чем date2? " << (date1 < date2 ? "Да" : "Нет") << endl;
	cout << "Больше ли date1, чем date2? " << (date1 > date2 ? "Да" : "Нет") << endl;

	return 0;
}

