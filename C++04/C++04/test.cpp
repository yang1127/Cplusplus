#include<iostream>
 
using namespace std;

//构造函数
//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{}
//
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1; // 调用无参构造函数
//	Date d2(2019, 11, 19); // 调用带参的构造函数
//
//	Date d3(); // 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明，声明了d3函数，该函数无参，返回一个日期类型的对象。
//}
//
//int main()
//{
//	TestDate();
//
//	system("pause");
//	return 0;
//}

////拷贝构造函数
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1;
//	Date d2(d1); //拷贝构造函数
//	return 0;
//}

////运算符重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator==(const Date& x) //this做了左操作数
//	{
//		return _year == x._year
//			&& _month == x._month
//			&& _day == x._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////全局:
////bool operator==(const Date& x1, const Date& x2)
////{
////	return x1._year == x2._year
////	&& x1._month == x2._month
////	&& x1._day == x2._day;
////}
//
//int main()
//{
//	Date d1(2019, 11, 19);
//	Date d2(d1);
//	Date d3(2019, 11, 20);
//
//	//全局
//	//cout << operator == (d1, d2) << endl; //1
//	//cout << operator == (d1, d3) << endl; //0
//
//	cout << d1.operator == (d2) << endl;
//
//	return 0;
//}

//赋值运算符重载
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//d1 = d3
	Date& operator=(const Date& d)
	{
		if (this != &d) //d1 与 d3的地址先判断下，不等于就不用进入，提高效率
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 11, 19);
	Date d2(d1);
	Date d3(2019, 11, 20);

	d1 = d3;
	d1.Print(); //2019-11-20加引用,少调用一次拷贝构造

	system("pause");
	return 0;
}
