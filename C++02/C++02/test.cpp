#include <iostream>
using namespace std;

//void swap(int& x1, int& x2)
//{
//	int x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
////�꺯��������ɶ��Ժ�ά���ԱȽϲ���ܵ���
//#define add(a, b)((a)+(b))
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//    swap(a, b);
//	cout << a <<" " << b << endl;
//
//	int tmp = add(1, 2) * 3; //���꺯��
//	cout << tmp << endl;
//
//	system("pause");
//	return 0;
//}

////����inline���Զ��Ż�
////ע�⣺inline�����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ��Ҳ���
//inline void swap(int& x1, int& x2)
//{
//	int x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 1; 
//	int b = 2;
//	swap(a, b);
//	cout << a << " " << b << endl;
//
//	system("pause");
//	return 0;
//}

//auto
//int TestAuto()
//{ 
//	return 10;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl; //����������typeid().name() int
//	cout << typeid(c).name() << endl; //char
//	cout << typeid(d).name() << endl; //int
//
//	system("pause");
//	return 0;
//}

//int main() 
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl; //int* 
//	cout << typeid(b).name() << endl; //int* 
//	cout << typeid(c).name() << endl; //int
//
//
//	system("pause");
//	return 0;
//}

////��Χfor
//int main() 
//{
//	int array[] = { 1, 2, 3, 4, 5 }; 
//	for (auto& e : array)
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " "; //2 4 6 8 10
//
//	system("pause");
//	return 0;
//}

//nullptr
//NULL-nullptr