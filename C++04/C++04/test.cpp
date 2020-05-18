#include<iostream>
 
using namespace std;

//���캯��
//class Date
//{
//public:
//	// 1.�޲ι��캯��
//	Date()
//	{}
//
//	// 2.���ι��캯��
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
//	Date d1; // �����޲ι��캯��
//	Date d2(2019, 11, 19); // ���ô��εĹ��캯��
//
//	Date d3(); // ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺���������������d3�������ú����޲Σ�����һ���������͵Ķ���
//}
//
//int main()
//{
//	TestDate();
//
//	system("pause");
//	return 0;
//}

////�������캯��
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
//	Date d2(d1); //�������캯��
//	return 0;
//}

////���������
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
//	bool operator==(const Date& x) //this�����������
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
////ȫ��:
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
//	//ȫ��
//	//cout << operator == (d1, d2) << endl; //1
//	//cout << operator == (d1, d3) << endl; //0
//
//	cout << d1.operator == (d2) << endl;
//
//	return 0;
//}

//��ֵ���������
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
		if (this != &d) //d1 �� d3�ĵ�ַ���ж��£������ھͲ��ý��룬���Ч��
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
	d1.Print(); //2019-11-20������,�ٵ���һ�ο�������

	system("pause");
	return 0;
}
