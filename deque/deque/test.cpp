#include <iostream>
#include<deque>
using namespace std;

void PrintDeque(const std::deque<int>& d)
{
	for (const auto& e : d)
		cout << e << " ";
	cout << endl;
}

void TestDeque1()
{
	// ����յ�˫�˶���
	std::deque<int> d1;

	// ��10��ֵΪ5��Ԫ�ع���˫�˶���
	std::deque<int> d2(10, 5); 
	PrintDeque(d2); //5 5 5 5 5 5 5 5 5 5

	// ����������乹��˫�˶���
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3); //1 2 3 4 5 6 7 8 9 0
	
	// ��d3��������d4
	std::deque<int> d4(d3);
	PrintDeque(d4); //1 2 3 4 5 6 7 8 9 0
}

void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));

	// ���������������ӡdeque�е�Ԫ��
	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " "; //1 2 3 4 5 6 7 8 9 0
	cout << endl;

	auto cit = d.cbegin();
	//*it = 100; ����������ʧ�ܣ�itΪconst����������ָ��ռ�Ԫ��ֵ�����޸�

	// ���÷�������������ӡdeque�е�Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " "; //0 9 8 7 6 5 4 3 2 1
	cout << endl;
}

void TestDeque3()
{
	// �б�ʽ��ʼ����C++11�﷨
	deque<int> d1{ 3,4,5 };

	// ��deque��β������5��ͷ������2������ӡ
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1); //2 3 4 5 6

	cout << d1.size() << endl; //5
	cout << d1.front() << endl; //2
	cout << d1.back() << endl; //6
	// ��deque��β������6��ͷ������0
	// ע�⣺�������������Ԫ�أ�emplace_back��push_back emplace_front��push_front��Ч����ͬ
	// ������Զ�������Ԫ��
	// emplace_back/emplace_front��Ч�ʸ��ߣ�����������ֱ����β������ͷ������Ԫ��
	// push_back/push_front��Ч�ʵͣ��ò���ʱ�Ƚ�Ԫ�ع���ã�Ȼ�󿽱���β����ͷ��
	d1.emplace_back(7); 
	d1.emplace_front(1);
	PrintDeque(d1); //1 2 3 4 5 6 7

	// ��deque��beginλ�ò���Ԫ��0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1); //0 1 2 3 4 5 6 7

	// ɾ��deque�ײ���β��Ԫ��
	d1.pop_front(); //ɾ��0
	d1.pop_back(); //ɾ��7
	d1.erase(d1.begin()); //ɾ��1
	PrintDeque(d1); //2 3 4 5 6

	// ��deque�е�Ԫ�����
	d1.clear();
	cout << d1.size() << endl; //0
}

// ��deque�е�Ԫ�ؽ�������Ч�ʵ���
// ��deque����ʱ����Ҫ��ζ�deque�е�Ԫ�ؽ��������������deque�е�Ԫ���������ʱЧ�ʱȽϵ�
// ��Ϊdeque�ײ�Ŀռ䲻���������Ҫ���������������ĳ�οռ��Ĭ�ϻ��ײ�ʱ
// ����Ҫ������һ�λ���ǰһ�οռ��λ�ã�����deque��Ч�ʱȽϵ��¡� 

#include <algorithm>

void TestDequeSort()
{
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d); //5 2 1 9 6 3 8 7 4 0

	// ���ñ�׼���е��㷨��deque�е�Ԫ�ؽ�����������
	sort(d.begin(), d.end());
	PrintDeque(d); //0 1 2 3 4 5 6 7 8 9
}

int main()
{
	TestDeque1();
	cout << endl;

	TestDeque2();
	cout << endl;

	TestDeque3();
	cout << endl;

	TestDequeSort();

	system("pause");
	return 0;
}