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
void TestFunc(int a, int b = 10, int c = 20) //��ȱʡ�������������������������
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main()
{
	//ȫȱʡ
	//TestFunc();
	//TestFunc(10);
	//TestFunc(10, 20);
	//TestFunc(10, 20, 30);

	//��ȱʡ
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);

	system("pause");
	return 0;
}