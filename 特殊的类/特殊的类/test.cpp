#include <iostream>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static Singleton inst;
		return inst;
	}
private:
	Singleton()
	{}

	//Singleton(const Singleton&) = delete; //(1)只声明不定义
	Singleton(const Singleton&); //(2) C++11 做成删除函数
};

int main()
{
	Singleton::GetInstance();

	//Singleton s2;
	//Singleton s3;

	system("pause");
	return 0;
}