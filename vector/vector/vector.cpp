#include <iostream>
#include <vector>

using namespace std;

void test1()
{
	vector<int> v1; //���� ����Ϊint
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (size_t i = 0; i < v1.size(); ++i) //����
	{
		cout << v1[i] << " "; //vector ��������ͬ
	}
	cout << endl;

	vector<int>::iterator it1 = v1.begin(); //ʹ�õ���������
	while (it1 != v1.end())  //begin ���ص�һ�����ݵ�λ�á�end�������һ�����ݵ���һ��λ��
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : v1) //ʹ�÷�Χfor���б��������ʻ��������ڵ�����
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(10, int());//���첢��ʼ��n��val

	vector<int> v3(v1.begin(), v1.end()); //���������г�ʼ������
	vector<int> v4(++v1.begin(), --v1.end()); //��Ҫv1�ĵ�һ�������һ������

	// ʹ��const���������б�����ӡ
	vector<int>::const_iterator it2 = v1.cbegin();
	while (it2 != v1.cend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	// ʹ�õ����������޸�
	it1 = v1.begin();
	while (it1 != v1.end())
	{
		*it1 *= 2;
		++it1;
	}

	// ʹ�÷�����������б����ٴ�ӡ
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;  //10 8 6 4 2 �����޸�����������ٷ���������
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
	//func(); //���ܵ���
	//func<int>();//void func()

	system("pause");
	return 0;
}