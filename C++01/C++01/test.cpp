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
//void TestFunc(int a, int b = 10, int c = 20) //半缺省参数必须从右往左依次来给出
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//全缺省
//	//TestFunc();
//	//TestFunc(10);
//	//TestFunc(10, 20);
//	//TestFunc(10, 20, 30);
//
//	//半缺省
//	TestFunc(10);
//	TestFunc(10, 20);
//	TestFunc(10, 20, 30);
//
//	system("pause");
//	return 0;
//}

////函数重载：必须在相同的作用域，相同名字的函数，参数列表不同
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
////参数列表不同：参数个数、参数类型次序不同、参数类型不同
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
///*无法重载：重载与返回值类型是否相同没有关系
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
///*无法重载：作用域不同
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
//	//编译器编译时，会对实参类型进行推演，自动调用
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//
//	system("pause");
//	return 0;
//}

//c语言函数名字修饰规则：编译器只是在函数名字前增加_
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

//引用
//void Test() 
//{
//	int a = 10;
//	int& ra = a; //定义引用类型
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
//	//指针和引用赋值时：权限缩小可以、放大不行
//	const int& r1 = 1;
//
//	int a = 2;  
//	const int& r2 = a;//引用变量可以、引用常量使用const引用；const引用可以引用常量、可以引用变量
//
//	const int b = 3;
//	//int& r3 = b; //不能，引用，b只读
//	int c = b;//可以、普通赋值
//
//	//int* d1 = b;//不能，指针，只读
//	const int* d2 = &b;//可以，不能修改传给也不能修改
//	int* d3 = &a;//可以
//	const int* d4 = &a;//可以 
//
//	double e = 1.1;
//	//int& f = e;//不能，中间引入了临时变量int f = e，再传给int& f
//	const int& f = e;//可以
//
//
//	system("pause");
//	return 0;
//}

////做参数
//void Swap(int& left, int& right) 
//{ 
//	int temp = left;
//	left = right;
//	right = temp;
//}

////做返回值
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

