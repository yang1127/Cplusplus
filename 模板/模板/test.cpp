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
//	cout << "d1Ϊ:"<< d1 << " " << "d2Ϊ:" << d2 << endl; // 3 2
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
//	Add(a1, (int)d1); //ǿ��ת��
//	cout << "a1Ϊ:" << a1 << " " << "d1Ϊ:" << d1 << endl; // 10 10 
//	
//	Add<int>(a1, d1); //��ʾʵ����
//	cout << "a1Ϊ:" << a1 << " " << "d1Ϊ:" << d1 << endl; // 10 10 
//
//	system("pause");
//	return 0;
//}

//����ģ���ػ�
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//
//	return false;
//}////��ģ���ػ�
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

//ȫ�ػ�
template<>
class Data<int, int>
{
public:
	Data() { cout << "Data<int, int>" << endl; }
};

//ƫ�ػ�<->���ػ�
template<class T1>
class Data<T1, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
};

//ƫ�ػ�����������ƫ�ػ�Ϊָ������
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};

//ƫ�ػ�����������ƫ�ػ�Ϊ��������
template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};

int main()
{
	Data<int, char> d1;  //��Data<int, char>
	Data<int, int> d2;   //ȫData<int, int>
	Data<char, char> d3; //��Data<int, char>
	Data<char, int> d4;  //ԭData<T1, T2>
	Data<char*, int*> d5;     //��Data<T1*, T2*>
	Data<char*, double*> d6;  //��Data<T1*, T2*>
	Data<char&, int&> d7;     //��Data<T1*, T2*>
	Data<char&, double&> d8;  //��Data<T1*, T2*>

	system("pause");
	return 0;
}

