#pragma once

#include "HashTable.h"

namespace xiaoyang
{
	template<class K, class V, class Hash = BUCKET_HASH::_Hash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename BUCKET_HASH::HashTable<K, pair<K, V>, MapKeyOfT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[] (const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		BUCKET_HASH::HashTable<K, pair<K, V>, MapKeyOfT, Hash> _ht;
	};

	void test_unordered_map()
	{
		unordered_map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(6, 1));
		m.insert(make_pair(2, 1));
		m.insert(make_pair(8, 1));


		unordered_map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ": " << it->second << endl;
			++it;
		}
		cout << endl;

		m[8] = 81;
		m[1] = 11;

		for (auto& e : m)
		{
			cout << e.first << ": " << e.second << endl;
		}
		cout << endl;

		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "≈≈–Ú"));
	}
}
