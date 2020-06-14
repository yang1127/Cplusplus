#pragma once

#include "RBTree.h"

namespace xiaoyang
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)  //K&  const不能给非const
			{
				return k; //取出里面的K
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
		void Insert(const K& k)
		{
			_t.Insert(k);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		s.Insert(1);
		s.Insert(2);
		s.Insert(5);
		s.Insert(8);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << endl;
			++it;
		}

		for (auto& e : s)
		{
			cout << e << endl;
		}
	}
}