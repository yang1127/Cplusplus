#include<iostream>

using namespace std;

//template<typename T>  
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	double d1 = 2.0;
//	double d2 = 3.0;
//	Swap(d1, d2);
//	cout << "d1为:"<< d1 << " " << "d2为:" << d2 << endl; // 3 2
//
//	system("pause");
//	return 0;
//}

//template<class T> T 
//Add(const T& left, const T& right) 
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	Add(a1, (int)d1); //强制转换
//	cout << "a1为:" << a1 << " " << "d1为:" << d1 << endl; // 10 10 
//	
//	Add<int>(a1, d1); //显示实例化
//	cout << "a1为:" << a1 << " " << "d1为:" << d1 << endl; // 10 10 
//
//	system("pause");
//	return 0;
//}

//函数模板特化
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//
//	return false;
//}////类模板特化
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<>
//class Data<int, int>
//{
//public:
//	Data() { cout << "Data<int, int>" << endl; }
//};
//
//int main()
//{
//	Data<int, char> d1; //Data<T1, T2>
//	Data<int, int> d2;  //Data<int, int>
//
//	system("pause");
//	return 0;
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int, int>
{
public:
	Data() { cout << "Data<int, int>" << endl; }
};

//偏特化<->半特化
template<class T1>
class Data<T1, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
};

//偏特化：两个参数偏特化为指针类型
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};

//偏特化：两个参数偏特化为引用类型
template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};

int main()
{
	Data<int, char> d1;  //半Data<int, char>
	Data<int, int> d2;   //全Data<int, int>
	Data<char, char> d3; //半Data<int, char>
	Data<char, int> d4;  //原Data<T1, T2>
	Data<char*, int*> d5;     //半Data<T1*, T2*>
	Data<char*, double*> d6;  //半Data<T1*, T2*>
	Data<char&, int&> d7;     //半Data<T1*, T2*>
	Data<char&, double&> d8;  //半Data<T1*, T2*>

	system("pause");
	return 0;
}

