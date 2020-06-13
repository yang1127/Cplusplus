#include <iostream>
#include <list>
using namespace std;

/*
int main()
{
	list<int> l1; // 构造空的l1
	list<int> l2(4, 100); // l2中放4个值为100的元素
	list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3
	list<int> l4(l3); // 用l3拷贝构造l4

	// 以数组为迭代器区间构造l5
	int array[] = { 16,2,77,29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));

	// 用迭代器方式打印l5中的元素
	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		cout << *it << " "; //16 2 77 29
	cout << endl;

	//C++11
	for (auto& e : l5)
		cout << e << " "; //16 2 77 29
	cout << endl;

	system("pause");
	return 0;
}
*/

/*
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	// 使用正向迭代器正向list中的元素
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " "; //1 2 3 4 5 6 7 8 9 0
	cout << endl;

	// 使用反向迭代器逆向打印list中的元素
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " "; //0 9 8 7 6 5 4 3 2 1
	cout << endl;

	// cosnt的正向迭代器
	auto cit = l.cbegin();
	cout << typeid(cit).name() << endl; //class std::_List_const_iterator<class  std::_List_val<struct std::_List_simple_types<int> > >
	//*cit = 10; 此行代码编译失败，因为cit为const_iterator类型的迭代器

	system("pause");
	return 0;
}
*/

/*
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// 打印list中有效节点的个数
	cout << l.size() << endl; //10

	// 检测list是否为空
	if (l.empty())
		cout << "空的list" << endl;
	else
	{
		for (const auto& e : l)
			cout << e << " "; //1 2 3 4 5 6 7 8 9 0
		cout << endl;
	}

	system("pause");
	return 0;
}
*/

/*
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : l1)
		cout << e << " "; //1 2 3 4 5 6 7 8 9 0
	cout << endl;

	// 将list中第一个节点与最后一个节点中的值改为10
	l1.front() = 10;
	l1.back() = 10;
	for (auto& e : l1)
		cout << e << " "; //10 2 3 4 5 6 7 8 9 10
	cout << endl;

	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	//int& a = l2.front(); 因为l2是const类型的list对象，因此其front()为const引用类型
	const int& ca = l2.front();

	system("pause");
	return 0;
}
*/

/*
void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}

// push_back/pop_back/push_front/pop_front
void TestList1()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	// 在list的尾部插入4，头部插入0
	L.push_back(4);
	L.push_front(0);
	PrintList(L); //0 1 2 3 4
	// 删除list尾部节点和头部节点
	L.pop_back();
	L.pop_front();
	PrintList(L); //1 2 3
}

//emplace_back / emplace_front / emplace
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestList2()
{

	list<Date> l;
	Date d(2018, 10, 20);
	l.push_back(d);
	l.emplace_back(2018, 10, 21);
	l.emplace_front(2018, 10, 19);
}

// insert /erase
void TestList3()
{
	int array1[] = { 1, 2, 3 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));

	// 获取链表中第二个节点
	auto pos = ++L.begin();
	cout << *pos << endl; //2

	// 在pos前插入值为4的元素
	L.insert(pos, 4);
	PrintList(L); //1 4 2 3

	// 在pos前插入5个值为5的元素
	L.insert(pos, 5, 5);
	PrintList(L); //1 4 5 5 5 5 5 2 3

	// 在pos前插入[v.begin(), v.end)区间中的元素
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L); //1 4 5 5 5 5 5 7 8 9 2 3

	// 删除pos位置上的元素
	L.erase(pos);
	PrintList(L); //1 4 5 5 5 5 5 7 8 9 3

	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
	L.erase(L.begin(), L.end());
	PrintList(L);  //
}

// resize/swap/clear
void TestList4()
{
	// 用数组来构造list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(l1); //1 2 3

	// 将l1中元素个数增加到10个，多出的元素用默认值填充
	// 注意：如果list中放置的是内置类型，默认值为0, 如果list中放置自定义类型元素，调用缺省构造函数
	l1.resize(10);
	PrintList(l1); //1 2 3 0 0 0 0 0 0 0

	// 将l1中的元素增加到20个，多出的元素用4来填充
	l1.resize(20, 4);
	PrintList(l1); //1 2 3 0 0 0 0 0 0 0 4 4 4 4 4 4 4 4 4 4

	// 将l1中的元素减少到5个
	l1.resize(5);
	PrintList(l1); //1 2 3 0 0

	// 用vector中的元素来构造list
	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());
	PrintList(l2); //4 5 6

	// 交换l1和l2中的元素
	l1.swap(l2);
	PrintList(l1); //4 5 6
	PrintList(l2); //1 2 3 0 0

	// 将l2中的元素清空
	l2.clear();
	cout << l2.size() << endl; //0
}
*/
