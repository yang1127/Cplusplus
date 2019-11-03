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

void test2()
{
	//size_t v;
	//std::vector<int> space;
	////space.reserve(100); //capacity增加
	////space.resize(100); //capacity、size同增加、给缺省值
	//space.resize(100, 5);//初始化
	//v = space.capacity();
	//std::cout << "making space grow:\n";
	//for (int i = 0; i < 100; ++i) {
	//	space.push_back(i);
	//	if (v != space.capacity()) {
	//		v = space.capacity();
	//		std::cout << "capacity changed: " << v << '\n';
	//	}
	//}

	vector<int> v;
	//v.reserve(10); //10 只能增空间不会缩空间
	//v.reserve(20); //20
	//v.reserve(10); //20

	v.resize(10); //size 10、capacity10
	v.resize(20); //20、20
	v.resize(10); //10、20
}

void test3()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//构造迭代器（指针）

	// 使用find查找3所在位置的iterator，find算法体现出泛型层面代码复用
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//auto pos = find(v.begin(), v.end(), 3);

	//在pos位置之前插入30
	v.insert(pos, 30);////迭代器可能会失效，增容导致pos失效

	vector<int>::iterator it = v.begin();
	//while (it != v.end()) //遍历打印
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	pos = find(v.begin(), v.end(), 3); //不加，找不到pos位置，野指针
	// 删除pos位置的数据
	v.erase(pos);

	it = v.begin();
	while (it != v.end()) //遍历打印
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test4()
{
	//vector<int> v1(5, 10);
	//vector<int> v2(10, 5);

	//swap(v1, v2);
	//v1.swap(v2);

	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 通过[]读写第0个位置。
	v[0] = 10;
	cout << v[0] << endl; //10

	// 通过[i]的方式遍历vector
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " "; //10 2 3 4
	}
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);

	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " "; //空，已经把值给了swapv
	}
	cout << endl;

	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " "; //10 2 3 4
	}
	cout << endl;

}

int main()
{
	//test1();

	//cout << int() << endl; //vector<int> v2(10, int()); //0
	//func(); //不能调用
	//func<int>();//void func()

	//test2();
	//test3();
	test4();

	system("pause");
	return 0;
}