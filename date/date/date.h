#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //ÿ��������
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //�ж�ÿ��2�µ����������һ�򣬰��겻���İ���һ��
		{
			return 29; //�������
		}
		else
		{
			return monthDays[month];
		}
	}

	Date(int year = 1900, int month = 1, int day = 1)  //��ʼ������1900-1-1�����캯��
	{
		_year = year;
		_month = month;
		_day = day;

		if (year >= 1900 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month)) //�ж������Ƿ�����ĳ�||ֱ��������ڲ�����
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "���ڲ�����" << endl;
		}
	}

	~Date() //��������
	{
		cout << "~Date()" << endl;
	}

	void Print() //��ӡ
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	Date(const Date &d) //����<->����
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//d1 this��d2 d
	Date& operator = (const Date& d) //��������أ�������������������
	{
		if (this != &d) //d->����ַ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	bool operator<(const Date& d)//�ж����ڴ�С,d1 < d2 ��d1����this��d2����d1 ���¸���
	{
		if (_year < d._year) //�ȱȽ���
		{
			return true;
		}
		else if (_year == d._year) //����ȱȽ���
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month < d._month)//����ȱȽ���
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}

		return false;
	}

	//ʹ�ø��á���д�������������ٸ���
	bool operator>(const Date& d)
	{
		return !(*this <= d); // >����<=
	}

	bool operator<=(const Date& d) //d1 <= d2 
	{
		return *this < d || *this == d; //���� < �� ==
	}

	bool operator>=(const Date& d) //d1 >= d2 
	{
		return !(*this < d);
	}

	bool operator==(const Date& d) //�ꡢ�¡������
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

/*
	//// d + 100
	//Date operator+(int day)
	//{
	//	Date ret = *this; //����һ����dһ����ֵ
	//	ret._day += day;
	//	while (ret._day > GetMonthDay(ret._year, ret._month))  //�����ڲ�����ʱ����ѭ������ǰ�����ˣ����½���ֱ�����ں���  !!!��λ
	//	{
	//		ret._day -= GetMonthDay(ret._year, ret._month);
	//		if (ret._month == 12) //��������
	//		{
	//			ret._month++;
	//			_month = 1;
	//		}
	//		else
	//		{
	//			return _month++;
	//		}
	//	}
	//	return ret;
	//}

	////d1 += 100
	//Date operator+=(int day) //�Լ��ı�
	//{
 //       _day += day; 
	//	while (_day > GetMonthDay(_year, _month))  //�����ڲ�����ʱ����ѭ������ǰ�����ˣ����½���ֱ�����ں���  !!!��λ
	//	{
	//		_day -= GetMonthDay(_year, _month);
	//		if (_month == 12) //��������
	//		{
	//			_month++;
	//			_month = 1;
	//		}
	//		else
	//		{
	//			return _month++;
	//		}
	//	}
	//	return _day;
	//	
	//	//*this = *this + day; //����Date operator+(int day)��������ι��졢һ�θ�ֵ
	//	//return *this;
	//}
*/

	//��ʵ��+=��+����+=
	Date operator+=(int day)
	{
		_day += day; 
		while (_day > GetMonthDay(_year, _month))  //�����ڲ�����ʱ����ѭ������ǰ�����ˣ����½���ֱ�����ں���  !!!��λ
		{
			_day -= GetMonthDay(_year, _month);
			if (_month == 12) //��������
			{
				_month++;
				_month = 1;
			}
			else
			{
				return _month++;
			}
		}
		return _day;
	}

	Date operator+(int day)
	{
		Date ret(*this); //����Date operator+=(int day)
		ret += day;
		return ret;
	}

	//��ʵ��-=��-����-=
	Date operator-=(int day) //����day = -100��������ʱ��*this -= -day
	{
		_day -= day;
		if (day < 1)
		{
			if (_month == 1)
			{
				--_year;
				_month = 12;
			}
			else
			{
				--_month;
			}
			_day += GetMonthDay(_year, _month);
		}

		return _day;
	}

	Date operator-(int day)
	{
		Date ret(*this); //�������졢����Date operator+=(int day)
		ret -= day;
		return ret;
	}

	//˼·������������������Ĭ����ݵĲ�ֵ����������ֵ������ֵ����Ϊ����������������

	//���÷�˼·��С������++���ӵ��ʹ��������ȣ����˶��ٴμ�Ϊ��������
	int operator-(const Date& d) //������֮���������
	{
		Date max = *this;//Ĭ���õ�һ��Ϊ�󣬵ڶ���ΪС
		Date min = d;
		int flag = 1;//��һ���󣬵ڶ���С

		if (*this < d) //�����һ��С�ڵڶ���������
		{
			max = d;
			min = *this;
			flag = -1;//��һ��С���ڶ�����
		}

		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}

		return n * flag;
	}

	// ++d d.operator++(&d)����++֮ǰ�ģ�ǰ�ø�Ч
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// d++ d.operator++(&d, 0) ��һ������������ǰ��++������++���������أ�����++֮���
	Date operator++(int)
	{

		Date tmp = *this;
		*this += 1;
		return tmp;
	}

private:
	int _year;
	int _month;
	int _day;
};