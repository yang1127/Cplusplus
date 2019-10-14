#include<iostream>
using namespace std;

//加命名空间及作用域限定符
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

//使用using将命名空间中成员引入
//using N::b;
//
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//使用using namespace 命名空间名称引入
//using namespace N;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	Add(10, 20);
//	return 0;
//}


//缺省参数
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	TestFunc();   // 没有传参时，使用参数的默认值
//	TestFunc(10); // 传参时，使用指定的实参 
//}

//全缺省:所有参数都带默认值
//void TestFunc(int a = 1, int b = 2, int c = 3)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}


//半缺省参数:只能右从左
void TestFunc(int a, int b = 10, int c = 20) //半缺省参数必须从右往左依次来给出
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main()
{
	//全缺省
	//TestFunc();
	//TestFunc(10);
	//TestFunc(10, 20);
	//TestFunc(10, 20, 30);

	//半缺省
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);

	system("pause");
	return 0;
}