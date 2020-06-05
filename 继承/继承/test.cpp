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
	string _name = "peter"; // ����
	int _age = 18; // ����
};

// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ����
//Student��Teacher������Person�ĳ�Ա
class Student : public Person
{
protected:
		int _stuid; // ѧ��
};

class Teacher : public Person
{
protected:
	int _jobid; // ����
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
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};

class Student : public Person
{
public:
	int _No; // ѧ��
};

int Test()
{
	Student sobj;
	//���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//��������ܸ�ֵ�����������
	sobj = pobj;

	// �����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sobj
	Student* ps1 = (Student*)pp; // �������ת��ʱ���Ե�
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	ps2->_No = 10;
}
*/

/*
// Student��_num��Person��_num�������ع�ϵ
class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111; // ���֤��
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ѧ��:" << _num << endl; //999
		cout << " ���֤��:" << Person::_num << endl; //111
	}
protected:
	int _num = 999; // ѧ��
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
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹�������/�ض���
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

//����ͨ��
int main()
{
	B b;
	b.fun(10);
	//b.fun(); //������ã����� //��A::cout << "func()" << endl; 
	system("pause");
	return 0;
};
*/


class Person //����
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
	string _name; // ����
};

class Student : public Person //������
{
public:
	//������Ĺ��캯��������û���Ĺ��캯����ʼ���������һ���ֳ�Ա
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	//������Ŀ������캯��������û���Ŀ���������ɻ���Ŀ�����ʼ��
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	//�������operator=����Ҫ���û����operator=��ɻ���ĸ�ֵ
	Student& operator = (const Student& s) //����๹������
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	//������������������ȵ��������������ٵ����������
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
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