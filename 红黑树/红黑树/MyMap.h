#pragma once
#include "RBTree.h"

namespace xiaoyang
{
	template<class K, class V>
	class map
	{
	public:
		void Insert(const pair<K, V>& kv)
		{
			_t.Insert(kv);
		}
	private:
		struct MapKeyOfValue  
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;   //取出里面的K
			}
		};

		RBTree<K, pair<K, V>, MapKeyOfValue> _t;
	};

	void test_map()
	{
		map<int, int> m;
		m.Insert(make_pair(1, 1));

	}
}