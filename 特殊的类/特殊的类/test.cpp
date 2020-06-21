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

	//Singleton(const Singleton&) = delete; //(1)ֻ����������
	Singleton(const Singleton&); //(2) C++11 ����ɾ������
};

int main()
{
	Singleton::GetInstance();

	//Singleton s2;
	//Singleton s3;

	system("pause");
	return 0;
}