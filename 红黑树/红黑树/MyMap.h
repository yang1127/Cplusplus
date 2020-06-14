#pragma once
#include "RBTree.h"

namespace xiaoyang
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;   //ȡ�������K
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> Insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void test_map()
	{
		map<int, int> m;
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(2, 1));
		m.Insert(make_pair(5, 1));
		m.Insert(make_pair(6, 1));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << ":" << (*it).second << endl;
			cout << it->first << ":" << it->second << endl; //��һ������operator*���ڶ�������ֵ

			++it;
		}

		m[10]; //����
		m[5] = 5; //�޸�
		m[8] = 8; //���롢���޸�

		for (auto& e : m)
		{
			cout << e.first << ":" << e.second << endl;
		}

	}
}