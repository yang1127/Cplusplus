#include<iostream>
using namespace std;

//�������ռ估�������޶���
//namespace N
//{
//	int a = 10; int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}

//int main()
//{
//	printf("%d\n", N::a);
//	system("pause");
//	return 0;
//}

//ʹ��using�������ռ��г�Ա����
//using N::b;
//
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//ʹ��using namespace �����ռ���������
//using namespace N;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	Add(10, 20);
//	return 0;
//}


//ȱʡ����
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	TestFunc();   // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	TestFunc(10); // ����ʱ��ʹ��ָ����ʵ�� 
//}

//ȫȱʡ:���в�������Ĭ��ֵ
//void TestFunc(int a = 1, int b = 2, int c = 3)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}


//��ȱʡ����:ֻ���Ҵ���
//void TestFunc(int a, int b = 10, int c = 20) //��ȱʡ�������������������������
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//ȫȱʡ
//	//TestFunc();
//	//TestFunc(10);
//	//TestFunc(10, 20);
//	//TestFunc(10, 20, 30);
//
//	//��ȱʡ
//	TestFunc(10);
//	TestFunc(10, 20);
//	TestFunc(10, 20, 30);
//
//	system("pause");
//	return 0;
//}

////�������أ���������ͬ����������ͬ���ֵĺ����������б�ͬ
//int Add(int left, int right) 
//{ 
//	return left + right;
//}
//
//double Add(double left, double right) 
//{ 
//	return left + right;
//}
//
//long Add(long left, long right)
//{ 
//	return left + right;
//}
//
//
////�����б�ͬ�������������������ʹ���ͬ���������Ͳ�ͬ
//void TestF()
//{}
//
//void TestF(int a)
//{}
//
//void TestF(char a)
//{}
//
//void TestF(int a, double b)
//{}
//
//void TestF(double a, int b)
//{}
//
//
///*�޷����أ������뷵��ֵ�����Ƿ���ͬû�й�ϵ
//int Add(short left, short right) 
//{
//	return left + right;
//}
//
//short Add(short left, short right)
//{
//	return left + right;
//}
//*/
//
//
///*�޷����أ�������ͬ
//namespace N
//{
//	char Add(char left, char right)
//	{
//		return left + right;
//	}
//}*/
//
//int main() 
//{
//	//����������ʱ�����ʵ�����ͽ������ݣ��Զ�����
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//
//	system("pause");
//	return 0;
//}

//c���Ժ����������ι��򣺱�����ֻ���ں�������ǰ����_
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//int main() 
//{
//	Add(1, 2);
//	//Add(1.0, 2.0);
//
//	system("pause");
//	return 0; 
//}

//����
//void Test() 
//{
//	int a = 10;
//	int& ra = a; //������������
////
////	printf("%p\n", &a);
////	printf("%p\n", &ra);
////}
//

//int main()
//{
//	/*int a = 10;
//	int& b = a;
//	printf("%d ", b);*/
//
//	//ָ������ø�ֵʱ��Ȩ����С���ԡ��Ŵ���
//	const int& r1 = 1;
//
//	int a = 2;  
//	const int& r2 = a;//���ñ������ԡ����ó���ʹ��const���ã�const���ÿ������ó������������ñ���
//
//	const int b = 3;
//	//int& r3 = b; //���ܣ����ã�bֻ��
//	int c = b;//���ԡ���ͨ��ֵ
//
//	//int* d1 = b;//���ܣ�ָ�룬ֻ��
//	const int* d2 = &b;//���ԣ������޸Ĵ���Ҳ�����޸�
//	int* d3 = &a;//����
//	const int* d4 = &a;//���� 
//
//	double e = 1.1;
//	//int& f = e;//���ܣ��м���������ʱ����int f = e���ٴ���int& f
//	const int& f = e;//����
//
//
//	system("pause");
//	return 0;
//}

////������
//void Swap(int& left, int& right) 
//{ 
//	int temp = left;
//	left = right;
//	right = temp;
//}

////������ֵ
//int& Test(int& a) 
//{
//	a += 10; 
//	return a;
//}

//int& Add(int a, int b) 
//{ 
//	int c = a + b;
//	return c;
//}
//
//int main() 
//{ 
//	int& ret = Add(1, 2);
//	Add(3, 4); 
//	cout << "Add(1, 2) is :" << ret << endl; //7
//
//	system("pause");
//	return 0;
//}

