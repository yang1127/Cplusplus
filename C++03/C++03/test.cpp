#include<iostream>
using namespace std;

////C�����У��ṹ����ֻ�ܶ����������C++�У��ṹ���ڲ������Զ��������Ҳ���Զ��庯��
////�ṹ��Ķ��壬��C++�и�ϲ����class������
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
//	s.SetStudentInfo("xiaoyang", "Ů", 21);
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
//// ������Ҫָ��PrintPersonInfo������Person������� 
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}

////�����Ͷ���ȫ����������
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
////��������.h�У���Ķ������.cpp��
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
	int _year; // ��
	int _month; // ��
	int _day; // �� 
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

