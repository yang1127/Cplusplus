#include "date.h"

/*bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;

	else if (_year == d._year)
	{
		if (_month < d._month)
			return true;

		else if (_month == d._month)
		{
			if (_day < d._day)
				return true;
		}
	}

	return false;
}

bool Date::operator>(const Date& d)
{
	if ((!(*this < d)) && (!(*this == d)))
		return true;

	return false;

	//return !(*this <= d)£»
}

bool Date::operator<=(const Date& d)
{
	if ((*this < d) || (*this == d))
		return true;

	return false;

	//return *this < d || *this == d;
}

bool Date::operator>=(const Date& d)
{
	if ((*this > d) || (*this == d))
		return true;

	return false;

	//return !(*this < 0);
}

bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month < d._month && _day < d._day)
		return true;

	return false;

	//return _year == d._year && _month < d._month && _day < d._day;
}

bool Date::operator!=(const Date& d)
{
	if (!(*this == d))
		return true;

	return false;

	//return !(*this == d)£»
}
*/


int main()
{
	Date d1(2019, 8, 2);
	d1.Print();

	//Date d2(2019, 8, 3);
	//d2.Print();
	//Date d3(2100, 2, 29); //²âÊÔ·Ç·¨
	//d3.Print();

	//+
	//Date d4 = d1 + 10;
	//d4.Print();
	//(d1 + 10).Print();


	//-
	Date d5 = d1 - 10;
	d5.Print();
	(d1 - 10).Print();

	/*cout << d1.operator<(d2) << endl;
	cout << d1.operator>(d2) << endl;
	cout << d1.operator<=(d2) << endl;
	cout << d1.operator>=(d2) << endl;
	cout << d1.operator==(d2) << endl;
	cout << d1.operator!=(d2) << endl;
	*/

	system("pause");
	return 0;
}