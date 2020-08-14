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
//	//Singleton(const Singleton&) = delete; //(1)只声明不定义
//	Singleton(const Singleton&); //(2) C++11 做成删除函数
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
// 只能在堆上
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj() //设置成静态成员函数
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

private:
	HeapOnly() //构造函数私有
	{
		cout << "HeapOnly()" << endl;
	}

	// C++98 只声明不实现+声明成私有
	//HeapOnly(const HeapOnly& hp);

	// C++11
	//拷贝构造封锁 -> 不创建对象，防止漏洞
	HeapOnly(const HeapOnly& hp) = delete;
};

int main()
{
	//HeapOnly hp1;				// 栈
	//static HeapOnly hp2;		// 数据段
	//HeapOnly* p = new HeapOnly; // 堆

	HeapOnly* p1 = HeapOnly::GetHeapObj();

	return 0;
}
*/

/*
//只在栈上
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
	// 定制专属的operator new和delete，但是不实现，就没办法new了
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{
	StackOnly so1;
	//StackOnly* p2 = new StackOnly; // operator new + 构造函数

	return 0;
}
*/
/*
// C++98 
//不能被继承，私有在子类不可见 + 子类的构造函数必须调用父类的构造函数
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

class Inherit : public NonInherit  // 借助子类构造函数来设定
{};

//C++11方法
//final关键字，final修饰类，表示该类不能被继承

class A  final   // 最终类，不能被继承
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
 //饿汉 -> 一上来就要吃，也就是一开始(main函数之前)就创建对象
class Singleton
{
public:
	static Singleton& GetInstance()
	{
		return _sInst;
	}

private:
	// 构造函数私有化
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton _sInst;
};

// 对象在静态区
Singleton Singleton::_sInst; // main函数之前就创建初始化这个实例对象

int main()
{
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;

	// 多线程来调用Singleton::GetInstance()，有没有线程安全的问题？
	// 没有线程安全的问题，因为实例对象的创建在main函数之前

	return 0;
}
*/

/*
// 懒汉 -》 拖延症，最后一刻（第一次调用GetInstance时）才去创建对象

#include <vector>
#include <thread>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		// 双检查解锁的效率问题
		if (_spInst == nullptr)
		{
			_spInst = new Singleton;

		}

		return *_spInst;
	}

private:
	// 构造函数私有化
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
};

Singleton* Singleton::_spInst = nullptr; // main函数之前就创建初始化指针

int main()
{
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;

	return 0;
}

//考虑线程安全
#include <vector>
#include <thread>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		// 双检查解锁的效率问题
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

	// 一般没必要释放对象，进程结束以后会释放
	// 但是可以提供主动释放的接口
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
	// 构造函数私有化
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
	static mutex _smtx;
};

Singleton* Singleton::_spInst = nullptr; // main函数之前就创建初始化指针
mutex Singleton::_smtx;

int main()
{
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;

	 //多线程来调用Singleton::GetInstance()，有没有线程安全的问题？
	 
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

	// 隐式类型转换
	double d = i;
	printf("%d, %.2f\n", i, d);
	int* p = &i;

	// 显示的强制类型转换
	int address = (int)p;

	printf("%x, %d\n", p, address);
}*/

/*
int main()
{
	int i = 1;

	double d = static_cast<double>(i); // 相近类型，相关类型-》意义类似的类型之间的转换
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// 显示的强制类型转换
	int address = reinterpret_cast<int>(p); // 不想关类型的转换

	volatile const int a = 2;
	int* p1 = const_cast<int*>(&a);  // 去掉const属性的转换
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
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	//A* pa = new A;
	//B* pb = new B;
	// 父指针 = 子指针  这个直接就支持的切片，可以不算转换
	//pa = pb;

	// 子指针 = 父指针 这里是需要转换，且一般这样的转换时不合适的，特殊情况下才需要
	// B* p = (B*)pa;  // 这样的转换时不安全

	// dynamic_cast可以用来识别父类指针是指向父类对象还是子类对象
	//A* pa = new A;
	A* pa = new B;
	B* p = dynamic_cast<B*>(pa); // 这样转才是安全，如果pa是指针B类型(子类)的对象的，就可以成功
	cout << p << endl;           //                 如果pa是指针A类型(子类)的对象的，失败，返回NULL

	return 0;
}
