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
	while (it != s.end())  //走中序遍历
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

	//确定找到要删除的数后再删除，找不到则输出找不到
	auto pos = s.find(5); // O(logN)  自己的find   /*基本上使用这种方法
	if (pos != s.end())
	{
		s.erase(pos);  //erase可以删除迭代器、值
	}
	else
	{
		cout << "找不到" << endl;
	}
}

//map  key/value 
void test_map_set2()  // map底层存pair <-> value type
{
	//字典
	map<string, string> dict;
	dict.insert(pair<string, string>("insert", "插入")); //pair为模板
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(pair<string, string>("right", "右边"));
	dict.insert(pair<string, string>("node", "节点"));
	dict.insert(pair<string, string>("tree", "树"));
	//dict["sort"] = "排序";

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
	cout << str << ":" << "非法词汇" << endl;
	}
	}*/


	//统计次数
	//（法一）
	string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap; //统计次数
	for (auto& e : strs)
	{
		//1.若在 ++次数  2.若不在insert pair<水果, l>

		//map<string, int>::iterator ret = countMap.find(e);
		auto ret = countMap.find(e);
		if (ret != countMap.end())
		{
			//(*ret).second++;
			ret->second++;
		}
		else
		{
			// 调用构造函数创建匿名对象
			//countMap.insert(pair<map<string, int>(e, 1));
	
			countMap.insert(pair<string, int>(e, 1));

			//make_pair
			// template<class K, class V>
			/*inline pair<K, V> make_pair(const K& k, const V& v) //make_pair 函数模板
			{
				return pair<K, V>(k, v);
			}*/
			//countMap.insert(make_pair(e, 1));
		}
	}

    //法二

	////make_pair
    //template<class K, class V>
	///*inline pair<K, V> make_pair(const K& k, const V& v) //make_pair 函数模板
	//{
	//	return pair<K, V>(k, v);
	//}*/
	//countMap.insert(make_pair(e, 1));

	//operator[]:可插入、可修改，返回value的值
	/*V& operator[](const K& k)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V())); //value的缺省值
		return ret.first->second;
	}*/

	//string strs[] = { "苹果", "苹果","苹果","西瓜", "草莓", "草莓", "西瓜", "草莓" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{

	//  pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
	//	if (ret.second == false) // second-->bool
	//	{
	//		ret.first->second++; // ret-->pair  first-->iterator + ->second --> value 次数
	//	}
	//}

	string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap; //统计次数
	for (auto& e : strs)
	{
		countMap[e]++;
	}

	countMap["香蕉"];
	countMap["香蕉"] = 5;

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

	multiset<int> ms; //multi：可以冗余，multimap无[]
	ms.insert(3);
	ms.insert(2);
	ms.insert(1);
	ms.insert(2);
	ms.insert(4);

}



//笔试题
#include <vector>
//方法一
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.统计出水果出现次数
	map<string, int> countMap; 
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 2.找出大家最喜欢吃的水果

	
}

void test_map_set()
{
	vector<string> v = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓", "西瓜", "榴莲", "榴莲", "火龙果", "火龙果", "火龙果" };
	GetFavoriteFruit(v, 3);
}

//方法二：优先级队列
#include<queue>

void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.统计出水果出现次数
	map<string, int> countMap;
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 2.找出大家最喜欢吃的水果
	//最大的前k个，创建成一个小堆
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

//方法三
#include <functional>
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.统计出水果出现次数
	map<string, int> countMap;
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 2.找出大家最喜欢吃的水果
	//map是排序+key去重
	multimap<int, string, greater<int>> sortMap;
	for (auto& e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	//或者不用仿函数，反向迭代器倒着
}