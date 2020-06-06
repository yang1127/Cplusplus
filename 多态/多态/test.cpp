#include <iostream>
using namespace std;

/*
class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};

class Student : public Person {
public:
	//ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���
	//��ȻҲ���Թ�����д(��Ϊ�̳к������麯�����̳������������������ɱ����麯������),
	//���Ǹ���д�����Ǻܹ淶������������ʹ��*
	//void BuyTicket() { cout << "��Ʊ-���" << endl; }

	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);
	return 0;
}*//*class A {};
class B : public A {};

class Person {
public:
	virtual A* f() { return new A; }
};

class Student : public Person {
public:
	virtual B* f() { return new B; }
};
*/

/*
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};

// ֻ��������Student������������д��Person�����������������delete���������������
//���ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�����������

int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}*//*class Car
{
public:
	virtual void Drive() = 0;
};

class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-����" << endl;
	}
};

class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-�ٿ�" << endl;
	}
};

void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}

int main()
{
	Test();
	system("pause");
	return 0;
}
*/

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};int main()
{
	cout << sizeof(Base) << endl; //8
	system("pause");
	return 0;
}
*/


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2() //�麯��Func2
	{

		cout << "Base::Func2()" << endl;
	}
	void Func3() //��ͨ����Func3
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base //������Deriveȥ�̳�Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	Base b;
	Derive d;
	system("pause");
	return 0;
}