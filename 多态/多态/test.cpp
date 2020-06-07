#include <iostream>
using namespace std;

/*
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	//注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字
	//虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),
	//但是该种写法不是很规范，不建议这样使用*
	//void BuyTicket() { cout << "买票-半价" << endl; }

	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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

// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数
//才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数

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
		cout << "Benz-舒适" << endl;
	}
};

class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
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
	virtual void Func2() //虚函数Func2
	{

		cout << "Base::Func2()" << endl;
	}
	void Func3() //普通函数Func3
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base //派生类Derive去继承Base
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
//	//printf("常量区:%p\n", ptr); //常量区:00099B58
//	//printf("函数地址(代码段):%p\n", &Base::func1); //函数地址(代码段):0009153C
//	system("pause");
//	return 0;
//}

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	// 思路：取出b、d对象的头4bytes，就是虚表的指针，虚函数表本质是一个存虚函数指针的
	//指针数组，这个数组最后面放了一个nullptr
	// 1.先取b的地址，强转成一个int*的指针；
	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针；
	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组；
	// 4.虚表指针传递给PrintVTable进行打印虚表；
	// 5.这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有
	//放nullptr，导致越界，这是编译器的问题。
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
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
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