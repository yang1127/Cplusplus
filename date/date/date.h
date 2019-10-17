#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //每个月天数
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //判断每年2月的情况、四年一闰，百年不闰，四百年一闰
		{
			return 29; //闰年情况
		}
		else
		{
			return monthDays[month];
		}
	}

	Date(int year = 1900, int month = 1, int day = 1)  //初始化日期1900-1-1、构造函数
	{
		_year = year;
		_month = month;
		_day = day;

		if (year >= 1900 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month)) //判断日期是否合理、改成||直接输出日期不合理
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期不合理" << endl;
		}
	}

	~Date() //析构函数
	{
		cout << "~Date()" << endl;
	}

	void Print() //打印
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	Date(const Date &d) //拷贝<->引用
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//d1 this、d2 d
	Date& operator = (const Date& d) //运算符重载，出了作用域还在用引用
	{
		if (this != &d) //d->传地址
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	bool operator<(const Date& d)//判断日期大小,d1 < d2 、d1传给this、d2传给d1 以下复用
	{
		if (_year < d._year) //先比较年
		{
			return true;
		}
		else if (_year == d._year) //年相等比较月
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month < d._month)//月相等比较日
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}

		return false;
	}

	//使用复用、先写出其中两个、再复用
	bool operator>(const Date& d)
	{
		return !(*this <= d); // >不是<=
	}

	bool operator<=(const Date& d) //d1 <= d2 
	{
		return *this < d || *this == d; //复用 < 和 ==
	}

	bool operator>=(const Date& d) //d1 >= d2 
	{
		return !(*this < d);
	}

	bool operator==(const Date& d) //年、月、日相等
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
	//	Date ret = *this; //拷贝一个和d一样的值
	//	ret._day += day;
	//	while (ret._day > GetMonthDay(ret._year, ret._month))  //当日期不合理时进入循环，当前月满了，往下进，直到日期合理  !!!进位
	//	{
	//		ret._day -= GetMonthDay(ret._year, ret._month);
	//		if (ret._month == 12) //月满进年
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
	//Date operator+=(int day) //自己改变
	//{
 //       _day += day; 
	//	while (_day > GetMonthDay(_year, _month))  //当日期不合理时进入循环，当前月满了，往下进，直到日期合理  !!!进位
	//	{
	//		_day -= GetMonthDay(_year, _month);
	//		if (_month == 12) //月满进年
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
	//	//*this = *this + day; //复用Date operator+(int day)会产生两次构造、一次赋值
	//	//return *this;
	//}
*/

	//先实现+=，+复用+=
	Date operator+=(int day)
	{
		_day += day; 
		while (_day > GetMonthDay(_year, _month))  //当日期不合理时进入循环，当前月满了，往下进，直到日期合理  !!!进位
		{
			_day -= GetMonthDay(_year, _month);
			if (_month == 12) //月满进年
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
		Date ret(*this); //复用Date operator+=(int day)
		ret += day;
		return ret;
	}

	//先实现-=，-复用-=
	Date operator-=(int day) //考虑day = -100，负天数时，*this -= -day
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
		Date ret(*this); //拷贝构造、复用Date operator+=(int day)
		ret -= day;
		return ret;
	}

	//思路：可用算两个日期与默认年份的差值，这两个差值再做差值，即为两个日期相差的天数

	//本用法思路：小的日期++，加到和大的日期相等，加了多少次即为相差的天数
	int operator-(const Date& d) //两日期之间相隔天数
	{
		Date max = *this;//默认让第一个为大，第二个为小
		Date min = d;
		int flag = 1;//第一个大，第二个小

		if (*this < d) //如果第一个小于第二个，交换
		{
			max = d;
			min = *this;
			flag = -1;//第一个小，第二个大
		}

		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}

		return n * flag;
	}

	// ++d d.operator++(&d)返回++之前的，前置高效
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// d++ d.operator++(&d, 0) 用一个参数来区分前置++、后置++，构成重载，返回++之后的
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