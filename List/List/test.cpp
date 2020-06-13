#include <iostream>
#include <list>
using namespace std;

/*
int main()
{
	list<int> l1; // ����յ�l1
	list<int> l2(4, 100); // l2�з�4��ֵΪ100��Ԫ��
	list<int> l3(l2.begin(), l2.end()); // ��l2��[begin(), end()������ҿ������乹��l3
	list<int> l4(l3); // ��l3��������l4

	// ������Ϊ���������乹��l5
	int array[] = { 16,2,77,29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));

	// �õ�������ʽ��ӡl5�е�Ԫ��
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

	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " "; //1 2 3 4 5 6 7 8 9 0
	cout << endl;

	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " "; //0 9 8 7 6 5 4 3 2 1
	cout << endl;

	// cosnt�����������
	auto cit = l.cbegin();
	cout << typeid(cit).name() << endl; //class std::_List_const_iterator<class  std::_List_val<struct std::_List_simple_types<int> > >
	//*cit = 10; ���д������ʧ�ܣ���ΪcitΪconst_iterator���͵ĵ�����

	system("pause");
	return 0;
}
*/

/*
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// ��ӡlist����Ч�ڵ�ĸ���
	cout << l.size() << endl; //10

	// ���list�Ƿ�Ϊ��
	if (l.empty())
		cout << "�յ�list" << endl;
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

	// ��list�е�һ���ڵ������һ���ڵ��е�ֵ��Ϊ10
	l1.front() = 10;
	l1.back() = 10;
	for (auto& e : l1)
		cout << e << " "; //10 2 3 4 5 6 7 8 9 10
	cout << endl;

	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	//int& a = l2.front(); ��Ϊl2��const���͵�list���������front()Ϊconst��������
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
	// ��list��β������4��ͷ������0
	L.push_back(4);
	L.push_front(0);
	PrintList(L); //0 1 2 3 4
	// ɾ��listβ���ڵ��ͷ���ڵ�
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

	// ��ȡ�����еڶ����ڵ�
	auto pos = ++L.begin();
	cout << *pos << endl; //2

	// ��posǰ����ֵΪ4��Ԫ��
	L.insert(pos, 4);
	PrintList(L); //1 4 2 3

	// ��posǰ����5��ֵΪ5��Ԫ��
	L.insert(pos, 5, 5);
	PrintList(L); //1 4 5 5 5 5 5 2 3

	// ��posǰ����[v.begin(), v.end)�����е�Ԫ��
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L); //1 4 5 5 5 5 5 7 8 9 2 3

	// ɾ��posλ���ϵ�Ԫ��
	L.erase(pos);
	PrintList(L); //1 4 5 5 5 5 5 7 8 9 3

	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
	L.erase(L.begin(), L.end());
	PrintList(L);  //
}

// resize/swap/clear
void TestList4()
{
	// ������������list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(l1); //1 2 3

	// ��l1��Ԫ�ظ������ӵ�10���������Ԫ����Ĭ��ֵ���
	// ע�⣺���list�з��õ����������ͣ�Ĭ��ֵΪ0, ���list�з����Զ�������Ԫ�أ�����ȱʡ���캯��
	l1.resize(10);
	PrintList(l1); //1 2 3 0 0 0 0 0 0 0

	// ��l1�е�Ԫ�����ӵ�20���������Ԫ����4�����
	l1.resize(20, 4);
	PrintList(l1); //1 2 3 0 0 0 0 0 0 0 4 4 4 4 4 4 4 4 4 4

	// ��l1�е�Ԫ�ؼ��ٵ�5��
	l1.resize(5);
	PrintList(l1); //1 2 3 0 0

	// ��vector�е�Ԫ��������list
	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());
	PrintList(l2); //4 5 6

	// ����l1��l2�е�Ԫ��
	l1.swap(l2);
	PrintList(l1); //4 5 6
	PrintList(l2); //1 2 3 0 0

	// ��l2�е�Ԫ�����
	l2.clear();
	cout << l2.size() << endl; //0
}
*/
