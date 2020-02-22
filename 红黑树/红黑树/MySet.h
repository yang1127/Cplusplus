#pragma once

#include "RBTree.h"

namespace xiaoyang
{
	template<class K>
	class set
	{
	public:
		void Insert(const K& k)
		{
			_t.Insert(k);
		}
	private:
		struct SetKeyOfValue
		{
			const K& operator()(const K& k)  //K&  const���ܸ���const
			{
				return k; //ȡ�������K
			}
		};

		RBTree<K, K, SetKeyOfValue> _t;
	};

	void test_set()
	{
		set<int> s;
		s.Insert(1);
	}
}