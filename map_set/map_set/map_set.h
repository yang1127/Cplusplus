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
	while (it != s.end())  //������
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

	//ȷ������ɾ��
	auto pos = s.find(5); // O(logN)  �Լ���find
	if (pos != s.end())
	{
		s.erase(pos);
	}
	else
	{
		cout << "�Ҳ���" << endl;
	}
}

void test_map_set2()  // map�ײ��pair <-> value type
{
	//map<string, string> dict;
	//dict.insert(pair<string, string>("insert", "����"));
	//dict.insert(pair<string, string>("left", "���"));
	//dict.insert(pair<string, string>("right", "�ұ�"));
	//dict.insert(pair<string, string>("node", "�ڵ�"));
	//dict.insert(pair<string, string>("tree", "��"));
	//dict["sort"] = "����";

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

	//string strs[] = { "ƻ��", "����", "��ݮ", "��ݮ", "����", "��ݮ" };
	//map<string, int> countMap; //ͳ�ƴ���
	//for (auto& e : strs)
	//{
	////	map<string, int>::iterator ret = countMap.find(e);
	//	auto ret = countMap.find(e);
	//	if (ret != countMap.end())
	//	{
	//		//(*ret).second++;
	//		ret->second++;
	//	}
	//	else
	//	{
	//		// ���ù��캯��������������
	//		//countMap.insert(pair<map<string, int>(e, 1));
	//
	//		// template<class K, class V>
	//		/*inline pair<K, V> make_pair(const K& k, const V& v) //make_pair ����ģ��
	//		{
	//			return pair<K, V>(k, v);
	//		}*/
	//
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}

	//operator[]:�ɲ��롢���޸�
	/*V& operator[](const K& k)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V())); //value��ȱʡֵ
		return ret.first->second;
	}*/

	string strs[] = { "ƻ��", "����", "��ݮ", "��ݮ", "����", "��ݮ" };
	map<string, int> countMap; //ͳ�ƴ���
	for (auto& e : strs) 
	{
		countMap[e]++;  
	}
	
	countMap["�㽶"];  
	countMap["�㽶"] = 5;


	//string strs[] = { "ƻ��", "ƻ��","ƻ��","����", "��ݮ", "��ݮ", "����", "��ݮ" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{

	//    pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
	//	if (ret.second == false) // second-->bool
	//	{
	//		ret.first->second++; // ret-->pair  first-->iterator + ->second --> value ����
	//	}
	//}
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

	multiset<int> ms;
	ms.insert(3);
	ms.insert(2);
	ms.insert(1);
	ms.insert(2);
	ms.insert(4);

}