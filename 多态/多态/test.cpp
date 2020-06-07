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
}
*/

/*
class A {};
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
}
*/

/*
class Car
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
};


int main()
{
	cout << sizeof(Base) << endl; //8
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
*/

/*
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

//int main()
//{
//	Base b;
//	Derive d;
//	//int* vftptr = (int*)(*((int*)&b));
//	//printf("vftptr:%p\n", vftptr); //vftptr:00099B34
//
//	//static int s = 0;
//	//printf("static:%p\n", &s); //static:0009C324
//
//	//const char* ptr = "hello";
//	//printf("������:%p\n", ptr); //������:00099B58
//	//printf("������ַ(�����):%p\n", &Base::func1); //������ַ(�����):0009153C
//	system("pause");
//	return 0;
//}

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	// ˼·��ȡ��b��d�����ͷ4bytes����������ָ�룬�麯��������һ�����麯��ָ���
	//ָ�����飬���������������һ��nullptr
	// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ�룻
	// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ�룻
	// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����飻
	// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
	// 5.�����ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������û��
	//��nullptr������Խ�磬���Ǳ����������⡣
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);

	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	system("pause");
	return 0;
}*/class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);
	system("pause");
	return 0;
}