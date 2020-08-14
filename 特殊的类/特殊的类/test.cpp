#include <iostream>
using namespace std;

//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		static Singleton inst;
//		return inst;
//	}
//private:
//	Singleton()
//	{}
//
//	//Singleton(const Singleton&) = delete; //(1)ֻ����������
//	Singleton(const Singleton&); //(2) C++11 ����ɾ������
//};
//
//int main()
//{
//	Singleton::GetInstance();
//
//	//Singleton s2;
//	//Singleton s3;
//
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

/*
// ֻ���ڶ���
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj() //���óɾ�̬��Ա����
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

private:
	HeapOnly() //���캯��˽��
	{
		cout << "HeapOnly()" << endl;
	}

	// C++98 ֻ������ʵ��+������˽��
	//HeapOnly(const HeapOnly& hp);

	// C++11
	//����������� -> ���������󣬷�ֹ©��
	HeapOnly(const HeapOnly& hp) = delete;
};

int main()
{
	//HeapOnly hp1;				// ջ
	//static HeapOnly hp2;		// ���ݶ�
	//HeapOnly* p = new HeapOnly; // ��

	HeapOnly* p1 = HeapOnly::GetHeapObj();

	return 0;
}
*/

/*
//ֻ��ջ��
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};

int main()
{
	StackOnly so = StackOnly::CreateObject();
	
	return 0;
}
*/

/*
class StackOnly
{
public:
	StackOnly() {}
private:
	// ����ר����operator new��delete�����ǲ�ʵ�֣���û�취new��
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{
	StackOnly so1;
	//StackOnly* p2 = new StackOnly; // operator new + ���캯��

	return 0;
}
*/
/*
// C++98 
//���ܱ��̳У�˽�������಻�ɼ� + ����Ĺ��캯��������ø���Ĺ��캯��
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

class Inherit : public NonInherit  // �������๹�캯�����趨
{};

//C++11����
//final�ؼ��֣�final�����࣬��ʾ���಻�ܱ��̳�

class A  final   // �����࣬���ܱ��̳�
{
	// ....
};

class InheritA : public A
{
};

int main()
{
	Inherit ih;

	return 0;
}
*/

/*
 //���� -> һ������Ҫ�ԣ�Ҳ����һ��ʼ(main����֮ǰ)�ʹ�������
class Singleton
{
public:
	static Singleton& GetInstance()
	{
		return _sInst;
	}

private:
	// ���캯��˽�л�
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton _sInst;
};

// �����ھ�̬��
Singleton Singleton::_sInst; // main����֮ǰ�ʹ�����ʼ�����ʵ������

int main()
{
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;

	// ���߳�������Singleton::GetInstance()����û���̰߳�ȫ�����⣿
	// û���̰߳�ȫ�����⣬��Ϊʵ������Ĵ�����main����֮ǰ

	return 0;
}
*/

/*
// ���� -�� ����֢�����һ�̣���һ�ε���GetInstanceʱ����ȥ��������

#include <vector>
#include <thread>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		// ˫��������Ч������
		if (_spInst == nullptr)
		{
			_spInst = new Singleton;

		}

		return *_spInst;
	}

private:
	// ���캯��˽�л�
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
};

Singleton* Singleton::_spInst = nullptr; // main����֮ǰ�ʹ�����ʼ��ָ��

int main()
{
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;

	return 0;
}

//�����̰߳�ȫ
#include <vector>
#include <thread>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		// ˫��������Ч������
		if (_spInst == nullptr)
		{
			_smtx.lock();
			if (_spInst == nullptr)
			{
				_spInst = new Singleton;
			}
			_smtx.unlock();
		}

		return *_spInst;
	}

	// һ��û��Ҫ�ͷŶ��󣬽��̽����Ժ���ͷ�
	// ���ǿ����ṩ�����ͷŵĽӿ�
	static void DelInstace()
	{
		_smtx.lock();
		if (_spInst == nullptr)
		{
			delete _spInst;
			_spInst = nullptr;
		}
		_smtx.unlock();
	}

private:
	// ���캯��˽�л�
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
	static mutex _smtx;
};

Singleton* Singleton::_spInst = nullptr; // main����֮ǰ�ʹ�����ʼ��ָ��
mutex Singleton::_smtx;

int main()
{
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;

	 //���߳�������Singleton::GetInstance()����û���̰߳�ȫ�����⣿
	 
	//vector<thread> vthreads;
	//for (size_t i = 0; i < 4; ++i)
	//{
	//	vthreads.push_back(thread([]()
	//	{
	//		this_thread::sleep_for(std::chrono::seconds(1));
	//		for (size_t i = 0; i < 10; ++i)
	//		{
	//			cout << &Singleton::GetInstance() << endl;
	//		}
	//		}));
	//}

	//for (auto& e : vthreads)
	//{
	//	e.join();
	//}	

	return 0;
}
*/

/*
void Test()
{
	int i = 1;

	// ��ʽ����ת��
	double d = i;
	printf("%d, %.2f\n", i, d);
	int* p = &i;

	// ��ʾ��ǿ������ת��
	int address = (int)p;

	printf("%x, %d\n", p, address);
}*/

/*
int main()
{
	int i = 1;

	double d = static_cast<double>(i); // ������ͣ��������-���������Ƶ�����֮���ת��
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// ��ʾ��ǿ������ת��
	int address = reinterpret_cast<int>(p); // ��������͵�ת��

	volatile const int a = 2;
	int* p1 = const_cast<int*>(&a);  // ȥ��const���Ե�ת��
	*p1 = 3;
	cout << a << endl;

	return 0;
}
*/

class A
{
public:
	virtual void f() {}

	int _a;
};

class B : public A
{
	int _b;
};

void fun(A* pa)
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	//A* pa = new A;
	//B* pb = new B;
	// ��ָ�� = ��ָ��  ���ֱ�Ӿ�֧�ֵ���Ƭ�����Բ���ת��
	//pa = pb;

	// ��ָ�� = ��ָ�� ��������Ҫת������һ��������ת��ʱ�����ʵģ���������²���Ҫ
	// B* p = (B*)pa;  // ������ת��ʱ����ȫ

	// dynamic_cast��������ʶ����ָ����ָ����������������
	//A* pa = new A;
	A* pa = new B;
	B* p = dynamic_cast<B*>(pa); // ����ת���ǰ�ȫ�����pa��ָ��B����(����)�Ķ���ģ��Ϳ��Գɹ�
	cout << p << endl;           //                 ���pa��ָ��A����(����)�Ķ���ģ�ʧ�ܣ�����NULL

	return 0;
}
