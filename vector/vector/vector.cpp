#include <iostream>
#include <vector>

using namespace std;

void test1()
{
	vector<int> v1; //类型 设置为int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (size_t i = 0; i < v1.size(); ++i) //遍历
	{
		cout << v1[i] << " "; //vector 与数组相同
	}
	cout << endl;

	vector<int>::iterator it1 = v1.begin(); //使用迭代器遍历
	while (it1 != v1.end())  //begin 返回第一个数据的位置、end返回最后一个数据的下一个位置
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : v1) //使用范围for经行遍历、本质还是依赖于迭代器
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(10, int());//构造并初始化n个val

	vector<int> v3(v1.begin(), v1.end()); //迭代器进行初始化构造
	vector<int> v4(++v1.begin(), --v1.end()); //不要v1的第一个、最后一个数据

	// 使用const迭代器进行遍历打印
	vector<int>::const_iterator it2 = v1.cbegin();
	while (it2 != v1.cend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	// 使用迭代器进行修改
	it1 = v1.begin();
	while (it1 != v1.end())
	{
		*it1 *= 2;
		++it1;
	}

	// 使用反向迭代器进行遍历再打印
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;  //10 8 6 4 2 上面修改扩大二倍，再反向遍历输出
}


//template<class T>
//void func()
//{
//	cout << T() << endl;
//}

int main()
{
	test1();

	cout << int() << endl; //vector<int> v2(10, int()); //0
	//func(); //不能调用
	//func<int>();//void func()

	system("pause");
	return 0;
}