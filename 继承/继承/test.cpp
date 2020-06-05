#include <iostream>
#include <string>
using namespace std;

/*
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};

// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分
//Student和Teacher复用了Person的成员
class Student : public Person
{
protected:
		int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};

int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}
*/

/*
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};

class Student : public Person
{
public:
	int _No; // 学号
};

int Test()
{
	Student sobj;
	//子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//基类对象不能赋值给派生类对象
	sobj = pobj;

	// 基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
}
*/

/*
// Student的_num和Person的_num构成隐藏关系
class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 学号:" << _num << endl; //999
		cout << " 身份证号:" << Person::_num << endl; //111
	}
protected:
	int _num = 999; // 学号
};

int main()
{
	Student s1;
	s1.Print();
	system("pause");
	return 0;
};
*/

/*
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏/重定义
class A
{
public:
	void fun()
	{
		cout << "func()" << endl; 
	}
};

class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl; //
	}
};

//编译通过
int main()
{
	B b;
	b.fun(10);
	//b.fun(); //不会调用，隐藏 //可A::cout << "func()" << endl; 
	system("pause");
	return 0;
};
*/


class Person //基类
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};

class Student : public Person //派生类
{
public:
	//派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	//派生类的拷贝构造函数必须调用基类的拷贝构造完成基类的拷贝初始化
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	//派生类的operator=必须要调用基类的operator=完成基类的赋值
	Student& operator = (const Student& s) //与基类构成隐藏
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	//派生类对象析构清理先调用派生类析构再调基类的析构
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};

int main()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
	system("pause");
	return 0;
}