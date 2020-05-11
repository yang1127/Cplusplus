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
//}

////类模板特化
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
////全特化
//template<>
//class Data<int, int>
//{
//public:
//	Data() { cout << "Data<int, int>" << endl; }
//};
//
////偏特化<->半特化
//template<class T1>
//class Data<T1, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//};
//
////偏特化：两个参数偏特化为指针类型
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//
////偏特化：两个参数偏特化为引用类型
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//int main()
//{
//	Data<int, char> d1;  //半Data<int, char>
//	Data<int, int> d2;   //全Data<int, int>
//	Data<char, char> d3; //半Data<int, char>
//	Data<char, int> d4;  //原Data<T1, T2>
//	Data<char*, int*> d5;     //半Data<T1*, T2*>
//	Data<char*, double*> d6;  //半Data<T1*, T2*>
//	Data<char&, int&> d7;     //半Data<T1&, T2&>
//	Data<char&, double&> d8;  //半Data<T1&, T2&>
//
//	system("pause");
//	return 0;
//}

//template<class T, size_t N> //常量不可修改，可以给缺省值但必须从右往左缺省
//class array
//{
//public:
//	T& operator[](size_t pos)
//	{
//		return _arr[pos];
//	}
//
//private:
//	T _a[N];
//	size_t _size;
//};
//
//int main()
//{ 
//	array<int, 10> a1;  //10
//	array<int, 100> a2;  //100
//
//	system("pause");
//	return 0;
//}

////求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		int sum = n;
//		sum && (sum += Sum_Solution(n - 1));
//		return sum;
//	}
//};

//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//STL
// 代表内置类型
struct __true_type {};

// 代表自定义类型
struct __false_type {};

template <class type>
struct __type_traits
{
	typedef __false_type is_POD_type;
};

// 对所有内置类型进行特化
template<>
struct __type_traits<char>
{
	typedef __true_type is_POD_type;
};

template<>
struct __type_traits<signed char>
{
	typedef __true_type is_POD_type;
};

template<>
struct __type_traits<unsigned char>
{
	typedef __true_type is_POD_type;
};

template<>
struct __type_traits<int>
{
	typedef __true_type is_POD_type;
};

template<>
struct __type_traits<float>
{
	typedef __true_type is_POD_type;
};

template<>
struct __type_traits<double>
{
	typedef __true_type is_POD_type;
};

// 注意：在重载内置类型时，所有的内置类型都必须重载出来，包括有符号和无符号，比如：对于int类型，必须特化三个，int-- signed int -- unsigned int

// 在需要区分内置类型与自定义类型的位置，标准库通常都是通过__true_type与__false_type给出一对重载的函数，然后用一个通用函数对其进行封装

// 注意：第三个参数可以不提供名字，该参数最主要的作用就是让两个_copy函数形成重载
template<class T>
void _copy(T* dst, T* src, size_t n, __true_type)
{
	memcpy(dst, src, n * sizeof(T));
}

template<class T>
void _copy(T* dst, T* src, size_t n, __false_type)
{
	for (size_t i = 0; i < n; ++i)
		dst[i] = src[i];
}

template<class T>
void Copy(T* dst, T* src, size_t n)
{
	_copy(dst, src, n, __type_traits<T>::is_POD_type());
}