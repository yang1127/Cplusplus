#include <map>
#include <set>
#include <string>

void test_map_set1()
{
	set<int> s;  //set�ײ�Ϊ����������
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(1);
	s.insert(9);

	//����:
	set<int>::iterator it = s.begin(); //set�������޸�
	while (it != s.end())  //���������
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin(); //����
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//s.erase(5); //ɾ���ڵ�   ��5��ɾ����û��5�򲻴���

	// auto pos = std::find(s.begin(), s.end(), 5); // O(N) �㷨�е�find��Ч�ʵ�

	//ȷ���ҵ�Ҫɾ����������ɾ�����Ҳ���������Ҳ���
	auto pos = s.find(5); // O(logN)  �Լ���find   /*������ʹ�����ַ���
	if (pos != s.end())
	{
		s.erase(pos);  //erase����ɾ����������ֵ
	}
	else
	{
		cout << "�Ҳ���" << endl;
	}
}

//map  key/value 
void test_map_set2()  // map�ײ��pair <-> value type
{
	//�ֵ�
	map<string, string> dict;
	dict.insert(pair<string, string>("insert", "����")); //pairΪģ��
	dict.insert(pair<string, string>("left", "���"));
	dict.insert(pair<string, string>("right", "�ұ�"));
	dict.insert(pair<string, string>("node", "�ڵ�"));
	dict.insert(pair<string, string>("tree", "��"));
	//dict["sort"] = "����";

	map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
	   //piar<key, value> operator*()
		cout << (*dit).first << ":" << (*dit).second << endl;
		++dit;
	}
	cout << endl;

	/*string str;
	while (cin >> str)
	{
	auto ret = dict.find(str);
	if (ret != dict.end())
	{
	cout << str << ":" << (*ret).second << endl;  //second-->value
	}
	else
	{
	cout << str << ":" << "�Ƿ��ʻ�" << endl;
	}
	}*/


	//ͳ�ƴ���
	//����һ��
	string strs[] = { "ƻ��", "����", "��ݮ", "��ݮ", "����", "��ݮ" };
	map<string, int> countMap; //ͳ�ƴ���
	for (auto& e : strs)
	{
		//1.���� ++����  2.������insert pair<ˮ��, l>

		//map<string, int>::iterator ret = countMap.find(e);
		auto ret = countMap.find(e);
		if (ret != countMap.end())
		{
			//(*ret).second++;
			ret->second++;
		}
		else
		{
			// ���ù��캯��������������
			//countMap.insert(pair<map<string, int>(e, 1));
	
			countMap.insert(pair<string, int>(e, 1));

			//make_pair
			// template<class K, class V>
			/*inline pair<K, V> make_pair(const K& k, const V& v) //make_pair ����ģ��
			{
				return pair<K, V>(k, v);
			}*/
			//countMap.insert(make_pair(e, 1));
		}
	}

    //����

	////make_pair
    //template<class K, class V>
	///*inline pair<K, V> make_pair(const K& k, const V& v) //make_pair ����ģ��
	//{
	//	return pair<K, V>(k, v);
	//}*/
	//countMap.insert(make_pair(e, 1));

	//operator[]:�ɲ��롢���޸ģ�����value��ֵ
	/*V& operator[](const K& k)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V())); //value��ȱʡֵ
		return ret.first->second;
	}*/

	//string strs[] = { "ƻ��", "ƻ��","ƻ��","����", "��ݮ", "��ݮ", "����", "��ݮ" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{

	//  pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
	//	if (ret.second == false) // second-->bool
	//	{
	//		ret.first->second++; // ret-->pair  first-->iterator + ->second --> value ����
	//	}
	//}

	string strs[] = { "ƻ��", "����", "��ݮ", "��ݮ", "����", "��ݮ" };
	map<string, int> countMap; //ͳ�ƴ���
	for (auto& e : strs)
	{
		countMap[e]++;
	}

	countMap["�㽶"];
	countMap["�㽶"] = 5;

}

void test_map_set3()
{
	map<string, string> dict; //map���޸ģ�set�����޸�
	dict.insert(pair<string, string>("insert", "����"));
	dict.insert(make_pair("insert", "����")); //make_pair:����ģ�壬����һ��pair�����Զ��Ƴ�K��V����


	dict.insert(pair<string, string>("left", "���"));
	dict.insert(make_pair("left", "���"));

	dict.insert(pair<string, string>("right", "�ұ�"));
	dict.insert(make_pair("right", "�ұ�"));

	dict.insert(pair<string, string>("node", "�ڵ�"));
	dict.insert(make_pair("node", "�ڵ�"));

	dict.insert(pair<string, string>("tree", "��"));
	dict.insert(make_pair("tree", "��"));

    dict["left"] = "���"; //���ң�û������룩 + �޸�
	
	dict["string"] = "�ַ���";
}

void test_map_set4()
{
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(2);  //���� �����ʧ��
	s.insert(4);

	multiset<int> ms; //multi���������࣬multimap��[]
	ms.insert(3);
	ms.insert(2);
	ms.insert(1);
	ms.insert(2);
	ms.insert(4);

}



//������
#include <vector>
//����һ
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.ͳ�Ƴ�ˮ�����ִ���
	map<string, int> countMap; 
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 2.�ҳ������ϲ���Ե�ˮ��

	
}

void test_map_set()
{
	vector<string> v = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ", "����", "����", "����", "������", "������", "������" };
	GetFavoriteFruit(v, 3);
}

//�����������ȼ�����
#include<queue>

void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.ͳ�Ƴ�ˮ�����ִ���
	map<string, int> countMap;
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 2.�ҳ������ϲ���Ե�ˮ��
	//����ǰk����������һ��С��
	priority_queue<pair<string, int>, vector<pair<string, int>>, CountCompare> pq; pq;
	size_t i = 0;
	for (auto&e : countMap)
	{
		if (i < k)
		{
			pq.push(e);
			++i;
		}
		else
		{
			//O(logk)*N
			if (e.second > pq.top().second)
			{
				pq.pop();
				pq.push(e);
			}
		}
	}
}

//������
#include <functional>
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.ͳ�Ƴ�ˮ�����ִ���
	map<string, int> countMap;
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 2.�ҳ������ϲ���Ե�ˮ��
	//map������+keyȥ��
	multimap<int, string, greater<int>> sortMap;
	for (auto& e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	//���߲��÷º������������������
}