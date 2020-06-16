#pragma once
#include <vector>

//namespace CLOSE_HASH
//{
//	enum State //存入位置的状态
//	{
//		EXITS,  //存在
//		EMPTY,  //空
//		DELETE, //删除
//	};
//
//	template<class T>
//	struct HashData
//	{
//		T _data;
//		State _state; // 状态
//	};
//
//	template<class K, class V>
//	class HashTable
//	{
//		typedef HashData<pair<K, V>> HashData;
//	public:
//		//pair<HashData*, bool> Insert(const pair<K, V>& kv)
//		//{
//		//	// 考虑容量的问题
//		//	if (_dataNum == _tables.size()) //已满
//		//	{
//		//		size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2; //增容以后映射关系会发生变化，也不能在原表上处理
//		//		vector<HashData> newtables; //新开一个表
//		//		newtables.resize(newSize);  //开空间
//
//		//		// 将原表的数据重新映射到新表
//		//		for (size_t i = 0; i < _tables.size(); ++i)
//		//		{
//		//			if (_tables[i]._state == EXITS)
//		//			{
//
//		//				size_t index = _tables[i]._data.first % newtables.size(); //新表的位置，放入新表还会冲突，再算位置是否冲突
//		//				while (newtables[index]._state == EXITS) 
//		//				{
//		//					++index;
//		//					if (index == _tables.size())
//		//					{
//		//						index = 0;
//		//					}
//		//				}
//
//		//				newtables[index]._data = _tables[i]._data;
//		//				newtables[index]._state = EXITS;
//		//			}
//		//		}
//
//		//		_tables.swap(newtables); //将原表与新表的数据交换
//		//	}
//
//		//	//插入
//		//	size_t index = kv.first % _tables.size(); // % 使用vector时， % size、实际大小
//		//	// 线性探测
//		//	while (_tables[index]._state == EXITS) //存入位置有数值存在
//		//	{
//		//		++index;  //往后探测下一个位置
//		//		if (index == _tables.size()) //探测到最后往回绕
//		//		{
//		//			index = 0;  //置到开始
//		//		}
//		//	}
//
//		//	_tables[index]._data = kv; //存入数值
//		//	_tables[index]._state = EXITS; //将存入的位置状态置为存在
//		//	++_dataNum; //size++
//
//		//	return make_pair(&_tables[index], true);
//		//}
//
//		//pair<HashData*, bool> Insert(const pair<K, V>& kv)
//		//{
//		//	// 考虑容量的问题 ->改进
//		//	if (_dataNum == _tables.size())
//		//	{
//		//		size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//		//		HashTable<K, V> newht;  //创建新的哈希表对象
//		//		newht._tables.resize(newSize);
//
//		//		// 将原表的数据重新计算位置，映射到新表
//		//		for (size_t i = 0; i < _tables.size(); ++i)
//		//		{
//		//			if (_tables[i]._state == EXITS)
//		//			{
//		//				newht.Insert(_tables[i]._data);  //插入到新表，调用insert去解决冲突问题
//		//			}
//		//		}
//
//		//		_tables.swap(newht._tables); //交换原、旧表数据
//		//	}
//
//		//	size_t index = kv.first % _tables.size();
//		//	// 线性探测
//		//	while (_tables[index]._state == EXITS)
//		//	{
//		//		if (_tables[index]._data.first == kv.first)
//		//		{
//		//			return make_pair(&_tables[index], false);  //已有，插入失败
//		//		}
//
//		//		++index;
//		//		if (index == _tables.size())
//		//		{
//		//			index = 0;
//		//		}
//		//	}
//
//		//	_tables[index]._data = kv;
//		//	_tables[index]._state = EXITS;
//		//	++_dataNum;
//
//		//	return make_pair(&_tables[index], true);
//		//}
//
//		//HashData* Find(const K& key)  //查找
//		//{
//		//	size_t index = key % _tables.size(); //key % 表大小
//		//	while (_tables[index]._state != EMPTY)  //不为空、继续：存在或者删除的情况
//		//	{
//		//		if (_tables[index]._state == EXITS
//		//			&& _tables[index]._data.first == key)
//		//		{
//		//			return &_tables[index]; //找到
//		//		}
//		//		else
//		//		{
//		//			++index;
//		//			if (index == _tables.size()) //找到最后，再置回到头
//		//			{
//		//				index = 0;
//		//			}
//		//		}
//		//	}
//
//		//	return nullptr;  //没有
//		//}
//
//		pair<HashData*, bool> Insert(const pair<K, V>& kv)
//		{
//			//控制负载因子在0.7
//			if (_tables.size() == 0 || _dataNum * 10 / _tables.size() == 7) //整形
//			// 考虑容量的问题 ->改进
//			//if (_dataNum == _tables.size())
//			{
//				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//				HashTable<K, V> newht;  //创建新的哈希表对象
//				newht._tables.resize(newSize);
//
//				// 将原表的数据重新计算位置，映射到新表
//				for (size_t i = 0; i < _tables.size(); ++i)
//				{
//					if (_tables[i]._state == EXITS)
//					{
//						newht.Insert(_tables[i]._data);  //插入到新表，调用insert去解决冲突问题
//					}
//				}
//
//				_tables.swap(newht._tables); //交换原、旧表数据
//			}
//
//			size_t start = kv.first % _tables.size();
//			size_t index = start; //从起始位置开始找
//			size_t i = 1;
//			// 二次探测 、优化
//			while (_tables[index]._state == EXITS)
//			{
//				if (_tables[index]._data.first == kv.first)
//				{
//					return make_pair(&_tables[index], false);  //已有，插入失败
//				}
//
//				index = start + i * i; // + 1^2....
//				index %= _tables.size(); //超了表大小 取%
//				++i;
//
//			}
//
//			_tables[index]._data = kv;
//			_tables[index]._state = EXITS;
//			++_dataNum;
//
//			return make_pair(&_tables[index], true);
//		}
//
//		HashData* Find(const K& key)  //查找
//		{
//			size_t start = kv.first % _tables.size();
//			size_t index = start;
//			size_t i = 1;
//			while (_tables[index]._state != EMPTY)  //不为空、继续：存在或者删除的情况
//			{
//				if (_tables[index]._state == EXITS
//					&& _tables[index]._data.first == key)
//				{
//					return &_tables[index]; //找到
//				}
//				else
//				{
//					index = start + i * i; // + 1^2....
//					index %= _tables.size(); //超了表大小 取%
//					++i;
//				}
//			}
//
//			return nullptr;  //没有
//		}
//
//		void Erase(const K& key)  //删除
//		{
//			HashData* ret = Find(key);  //调find，找到该值，删除
//			if (ret)
//			{
//				ret->_state = DELETE; //删除只需置状态
//			}
//		}
//
//		V& operator[](const K& key) // operator[] 修改
//		{
//			pair<HashData*, bool> ret = Insert(make_pair(key, V())); //调用insert
//			return ret.first->_data.second;  //_data.second  value
//		}
//
//	private:
//		/*	HashData* _tables;
//			size_t _size;
//			size_t _capacity;*/
//
//		vector<HashData> _tables; //使用vector去替换上述定义
//		size_t           _dataNum = 0;  // 有效的数据个数,给缺省值
//	};
//
//	void Test()
//	{
//		HashTable<int, int> ht;
//		ht.Insert(make_pair(1, 1));
//		ht.Insert(make_pair(3, 1));
//		ht.Insert(make_pair(5, 1));
//		ht.Insert(make_pair(7, 1));
//		ht.Insert(make_pair(9, 1));
//		ht.Insert(make_pair(11, 1));
//		ht.Insert(make_pair(13, 1));
//		ht.Insert(make_pair(15, 1));
//		ht.Insert(make_pair(17, 1));
//		ht.Insert(make_pair(19, 1));
//		ht.Insert(make_pair(21, 1));
//		ht.Insert(make_pair(23, 1));
//		ht.Insert(make_pair(25, 1));
//
//		ht[27]; //插入
//		ht[27] = 27; // 修改
//		ht[29] = 29; // 插入+修改
//	}
//}


//开散列
namespace BUCKET_HASH
{
	template<class T>
	struct HashNode  //链表
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	template<class K>
	struct _Hash  //默认：例如整形，不需要处理
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	// sort、string不同字符
	// bacd bcad
	// abc aad  字母加起来相等
	// 期望效果：尽可能多个字符串的字母不一样，映射转换出的整形值就不一样？
	template<>
	struct _Hash<string> //string
	{
		size_t operator()(const string& key)
		{
			//return key[0];
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); ++i) //字符不同
			{
				hash = hash * 131 + key[i]; //哈希字符串算法
			}

			return hash;
		}
	};

	struct _HashString
	{
		size_t operator()(const string& key)
		{
			//return key[0];
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); ++i)
			{
				hash = hash * 131 + key[i];
			}

			return hash;
		}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	// 迭代器
	template<class K, class T, class KeyOfT, class Hash>
	struct HashTableIterator
	{
		typedef HashNode<T> Node;
		Node* _node;
		HashTable<K, T, KeyOfT, Hash>* _ht; //哈希表
		typedef HashTableIterator<K, T, KeyOfT, Hash> Self;

		HashTableIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* ht)
			:_node(node)
			, _ht(ht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self operator++()
		{
			if (_node->_next) //当前桶没有走完
			{
				_node = _node->_next;
			}
			else
			{
				//当前桶已经走完
				KeyOfT kot;
				size_t index = _ht->HashFunc(kot(_node->_data), _ht->_tables.size());
				//下一个桶
				++index;
				for (; index < _ht->_tables.size(); ++index)
				{
					Node* bucket = _ht->_tables[index];
					if (bucket)
					{
						_node = bucket;
						return *this;
					}
				}
				_node = nullptr; //没有找到置空
			}
			return *this;
		}

		bool operator!=(const Self& s) //迭代器比较 -> 是否在同一个节点
		{
			return _node != s._node;
		}
		
	};

	template<class K, class T, class KeyOfT, class Hash>
	//template<class K, class V, class Hash = _Hash<K>>
	class HashTable
	{
		//typedef HashNode<K> Node; // -> set
		//typedef HashNode<pair<K, V>> Node;  // -> map

		typedef HashNode<T> Node;

		//有元 -> 否则私有成员无法访问
		template<class K, class T, class KeyOfT, class Hash>
		friend struct HashTableIterator;
	public:
		typedef HashTableIterator<K, T, KeyOfT, Hash> iterator;
		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* bucket = _tables[i];
				if (bucket)
				{
					return iterator(bucket, this);//传指针、哈希表
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator, bool> Insert(const T& data) //T：map->pair set->k
		//pair<Node*, bool> Insert(const pair<K, V>& kv)
		{
			KeyOfT kot;

			// 负载因子控制到1 -> 平均下来每个桶挂1-2个数据
			if (_dataNum == _tables.size()) //已满，扩容
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtables;  
				newtables.resize(newsize, nullptr);

				// 旧表的数据节点取下来，重新算在新表中的位置
				for (size_t i = 0; i < _tables.size(); ++i)  //遍历旧表
				{
					Node* cur = _tables[i]; //从第一个位置取
					while (cur)
					{
						Node* next = cur->_next;  //提前保存，否则找不到
					
						// 头插到新表  
						//size_t index = cur->_data.first % newtables.size();  //新表的位置
						//size_t index = HashFunc(cur->_data.first, newtables.size());
						size_t index = HashFunc(kot(cur->_data), newtables.size());
						cur->_next = newtables[index];
						newtables[index] = cur;

						cur = next;
					}
					_tables[i] = nullptr; //置空
				}

				_tables.swap(newtables); //交换数值
			}

			size_t index = HashFunc(kot(data), _tables.size());
			//size_t index = HashFunc(kv.first, _tables.size());
			//size_t index = kv.first % _tables.size();
			// 查找key是否存在，存在则不插入（multi版本则不作冗余检查，直接进行下面的插入）
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_data) == kot(data))
				{
					return make_pair(iterator(cur, this), false);
				}

				cur = cur->_next;
			}

			// 头插 尾插要去找尾，而若链接多个并不知道谁是尾 -> 记录尾
			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_dataNum;

			return make_pair(iterator(newnode, this), true);
		}

		// O(链式桶的长度)
		Node* Find(const K& key)
		{
			//size_t index = key % _tables.size();
			size_t index = HashFunc(key, _tables.size());
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_data.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}

		void Erase(const K& key) 
		{
			//size_t index = key % _table.size();
			size_t index = HashFunc(key, _tables.size());
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_data.first == key) 
				{
					if (cur == _tables[index])//if (prev == nullptr)
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

		//void Erase(const K& key)
		//{
		//	HashData* ret = Find(key);
		//	if (ret)
		//	{
		//		ret->_state = DELETE;
		//	}
		//}

		// 将key进行取模计算映射位置
		size_t HashFunc(const K& key, size_t size)
		{
			Hash hash; // 哈希仿函数:将key转成整形
			return hash(key) % size;
		}

	private:
		vector<Node*> _tables;  //vector 存节点指针
		size_t       _dataNum = 0; 
	};

	//void TestHash()
	//{
	//	/*
	//	HashTable<int, int> ht;
	//	ht.Insert(make_pair(1, 1));
	//	ht.Insert(make_pair(3, 1));
	//	ht.Insert(make_pair(5, 1));
	//	ht.Insert(make_pair(7, 1));
	//	ht.Insert(make_pair(9, 1));
	//	ht.Insert(make_pair(11, 1));
	//	ht.Insert(make_pair(13, 1));
	//	ht.Insert(make_pair(15, 1));
	//	ht.Insert(make_pair(17, 1));
	//	ht.Insert(make_pair(19, 1));
	//	ht.Insert(make_pair(21, 1));
	//	ht.Insert(make_pair(23, 1));
	//	ht.Insert(make_pair(25, 1));

	//	ht.Erase(5);
	//	ht.Erase(25);
	//	*/

	//	HashTable<string, string, _HashString> dict;
	//	HashTable<string, string> dict;
	//	dict.Insert(make_pair("sort", "排序"));
	//	dict.Insert(make_pair("string", "字符串"));
	//	dict.Insert(make_pair("left", "左边"));

	//	/*	_HashString hash;
	//	cout << hash("abc") << endl;
	//	cout << hash("aad") << endl;
	//	cout << hash("abcd") << endl;
	//	cout << hash("bcad") << endl;*/
	//}
}