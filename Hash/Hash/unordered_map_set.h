#include <unordered_map>
#include <unordered_set>

#include <map>
#include <set>
#include <string>
#include <time.h>

//�÷���map��set����һ��
void test_unordered_set()
{
	//����
	unordered_set<int> us; 
	us.insert(4);
	us.insert(1);
	us.insert(3);
	us.insert(2);

	set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(3);
	s.insert(2);

	//unordered_set<int>::iterator usit = us.begin(); //������� 4 1 3 2
	auto usit = us.begin();
	while (usit != us.end())
	{
		cout << *usit << " ";
		++usit;
	}
	cout << endl;

	//set<int>::iterator st = s.begin();  //������� 1 2 3 4
	auto st = s.begin();
	while (st != s.end())
	{
		cout << *st << " ";
		++st;
	}
	cout << endl;

	//��֧���޸�


	//ɾ��
	auto us_pos = us.find(3); //�Ȳ��������
	if (us_pos != us.end())
	{
		us.erase(us_pos);  
	}

	for (auto e : us)  //4 1 3
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_unordered_map()
{
	unordered_map<string, string> dict;
	dict.insert(make_pair("insert", "����"));
	dict["sort"]; //����value��ȱʡֵ ����string��ȱʡֵ
	dict["sort"] = "����"; //�޸�
	dict["map"] = "ӳ��";  //����+�޸�

	//unordered_map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << " : " << it->second << endl;;
		++it;
	}
	cout << endl;
}

void test_op() //��������
{
	set<int> s;
	unordered_set<int> us;

	srand(time(0));
	const size_t n = 100000; 

	vector<int> v;
	v.reserve(n); //reserve:ֻ���ռ�
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert:" << end1 - begin1 << endl;

	size_t begin2 = clock();
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert:" << end2 - begin2 << endl;
}

