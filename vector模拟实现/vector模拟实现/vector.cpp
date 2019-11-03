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

void test2()
{
	//size_t v;
	//std::vector<int> space;
	////space.reserve(100); //capacity����
	////space.resize(100); //capacity��sizeͬ���ӡ���ȱʡֵ
	//space.resize(100, 5);//��ʼ��
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
	//v.reserve(10); //10 ֻ�����ռ䲻�����ռ�
	//v.reserve(20); //20
	//v.reserve(10); //20

	v.resize(10); //size 10��capacity10
	v.resize(20); //20��20
	v.resize(10); //10��20
}

void test3()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//�����������ָ�룩

	// ʹ��find����3����λ�õ�iterator��find�㷨���ֳ����Ͳ�����븴��
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//auto pos = find(v.begin(), v.end(), 3);

	//��posλ��֮ǰ����30
	v.insert(pos, 30);////���������ܻ�ʧЧ�����ݵ���posʧЧ

	vector<int>::iterator it = v.begin();
	//while (it != v.end()) //������ӡ
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	pos = find(v.begin(), v.end(), 3); //���ӣ��Ҳ���posλ�ã�Ұָ��
	// ɾ��posλ�õ�����
	v.erase(pos);

	it = v.begin();
	while (it != v.end()) //������ӡ
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
	// ͨ��[]��д��0��λ�á�
	v[0] = 10;
	cout << v[0] << endl; //10

	// ͨ��[i]�ķ�ʽ����vector
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
		cout << v[i] << " "; //�գ��Ѿ���ֵ����swapv
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
	//func(); //���ܵ���
	//func<int>();//void func()

	//test2();
	//test3();
	test4();

	system("pause");
	return 0;
}