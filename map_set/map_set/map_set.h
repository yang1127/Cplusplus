#include <map>
#include <set>
#include <string>

void test_map_set1()
{
	set<int> s;  //set底层为二叉搜索树
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(1);
	s.insert(9);

	//遍历:
	set<int>::iterator it = s.begin(); //set不允许修改
	while (it != s.end())  //走中序
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin(); //反向
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

	//s.erase(5); //删除节点   有5则删除，没有5则不处理

	// auto pos = std::find(s.begin(), s.end(), 5); // O(N) 算法中的find、效率低

	//确定后再删除
	auto pos = s.find(5); // O(logN)  自己的find
	if (pos != s.end())
	{
		s.erase(pos);
	}
	else
	{
		cout << "找不到" << endl;
	}
}

void test_map_set2()  // map底层存pair <-> value type
{
	//map<string, string> dict;
	//dict.insert(pair<string, string>("insert", "插入"));
	//dict.insert(pair<string, string>("left", "左边"));
	//dict.insert(pair<string, string>("right", "右边"));
	//dict.insert(pair<string, string>("node", "节点"));
	//dict.insert(pair<string, string>("tree", "树"));
	//dict["sort"] = "排序";

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
	cout << str << ":" << "非法词汇" << endl;
	}
	}*/

	//string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	//map<string, int> countMap; //统计次数
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
	//		// 调用构造函数创建匿名对象
	//		//countMap.insert(pair<map<string, int>(e, 1));
	//
	//		// template<class K, class V>
	//		/*inline pair<K, V> make_pair(const K& k, const V& v) //make_pair 函数模板
	//		{
	//			return pair<K, V>(k, v);
	//		}*/
	//
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}

	//operator[]:可插入、可修改
	/*V& operator[](const K& k)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V())); //value的缺省值
		return ret.first->second;
	}*/

	string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap; //统计次数
	for (auto& e : strs) 
	{
		countMap[e]++;  
	}
	
	countMap["香蕉"];  
	countMap["香蕉"] = 5;


	//string strs[] = { "苹果", "苹果","苹果","西瓜", "草莓", "草莓", "西瓜", "草莓" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{

	//    pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
	//	if (ret.second == false) // second-->bool
	//	{
	//		ret.first->second++; // ret-->pair  first-->iterator + ->second --> value 次数
	//	}
	//}
}

void test_map_set3()
{
	map<string, string> dict; //map可修改，set不能修改
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(make_pair("insert", "插入")); //make_pair:函数模板，返回一个pair对象，自动推出K、V类型


	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(make_pair("left", "左边"));

	dict.insert(pair<string, string>("right", "右边"));
	dict.insert(make_pair("right", "右边"));

	dict.insert(pair<string, string>("node", "节点"));
	dict.insert(make_pair("node", "节点"));

	dict.insert(pair<string, string>("tree", "树"));
	dict.insert(make_pair("tree", "树"));

    dict["left"] = "左边"; //查找（没有则插入） + 修改
	
	dict["string"] = "字符串";
}

void test_map_set4()
{
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(2);  //已有 则插入失败
	s.insert(4);

	multiset<int> ms;
	ms.insert(3);
	ms.insert(2);
	ms.insert(1);
	ms.insert(2);
	ms.insert(4);

}