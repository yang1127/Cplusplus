#include<iostream>
using namespace std;

////C语言中，结构体中只能定义变量，在C++中，结构体内不仅可以定义变量，也可以定义函数
////结构体的定义，在C++中更喜欢用class来代替
//struct Student
//{
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//int main()
//{
//	Student s;
//	s.SetStudentInfo("xiaoyang", "女", 21);
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int  _age;
//};
//
//// 这里需要指定PrintPersonInfo是属于Person这个类域 
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}

////声明和定义全部在类体内
//class person
//{
//public:
//	void show();
//
//private:
//	char* _name;
//	char* _sex;
//	int _age;
//};
//
////声明放在.h中，类的定义放在.cpp中
//#include "person.h"
//
//void person::show()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}

//class A 
//{
//public:
//    void PrintA() 
//	{ 
//	    cout << _a << endl;
//	}
//private: 
//	char _a; 
//}; 
//
//int main() 
//{
//	cout << sizeof(A) << endl; //1 
//	A a;
//	cout << sizeof(a) << endl; //1 
//	system("pause"); 
//	return 0;
//}

class Date
{
public:
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year; // 年
	int _month; // 月
	int _day; // 日 
};

int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();

	system("pause");
	return 0;
}

