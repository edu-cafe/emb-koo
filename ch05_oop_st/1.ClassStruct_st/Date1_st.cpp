#include <iostream>
using namespace std;

class Date
{
	int day, month, year;
public:
	Date() {}
	Date(int d=1, int m=1, int y=2000) : day(d), month(m), year(y) {}
	void set(int d, int m, int y)
	{ 
		day = d; month =m; year = y; 
	}
	bool cmp(const Date&);
	void print();
};

bool Date::cmp(const Date& d)
{ 
	return (year == d.year && month == d.month && day  == d.day ) ?
		true : false; 
}
void Date::print()
{ 
	cout << "(" << day << "," << month << "," << year << ")" << endl;
}

Date my_birthday(2,9,1989);

int main(void)
{
	..........
	
	
	
	
	return 0;
}

