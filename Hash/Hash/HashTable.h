#pragma once
#include <vector>

//namespace CLOSE_HASH
//{
//	enum State //����λ�õ�״̬
//	{
//		EXITS,  //����
//		EMPTY,  //��
//		DELETE, //ɾ��
//	};
//
//	template<class T>
//	struct HashData
//	{
//		T _data;
//		State _state; // ״̬
//	};
//
//	template<class K, class V>
//	class HashTable
//	{
//		typedef HashData<pair<K, V>> HashData;
//	public:
//		//pair<HashData*, bool> Insert(const pair<K, V>& kv)
//		//{
//		//	// ��������������
//		//	if (_dataNum == _tables.size()) //����
//		//	{
//		//		size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2; //�����Ժ�ӳ���ϵ�ᷢ���仯��Ҳ������ԭ���ϴ���
//		//		vector<HashData> newtables; //�¿�һ����
//		//		newtables.resize(newSize);  //���ռ�
//
//		//		// ��ԭ�����������ӳ�䵽�±�
//		//		for (size_t i = 0; i < _tables.size(); ++i)
//		//		{
//		//			if (_tables[i]._state == EXITS)
//		//			{
//
//		//				size_t index = _tables[i]._data.first % newtables.size(); //�±��λ�ã������±����ͻ������λ���Ƿ��ͻ
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
//		//		_tables.swap(newtables); //��ԭ�����±�����ݽ���
//		//	}
//
//		//	//����
//		//	size_t index = kv.first % _tables.size(); // % ʹ��vectorʱ�� % size��ʵ�ʴ�С
//		//	// ����̽��
//		//	while (_tables[index]._state == EXITS) //����λ������ֵ����
//		//	{
//		//		++index;  //����̽����һ��λ��
//		//		if (index == _tables.size()) //̽�⵽���������
//		//		{
//		//			index = 0;  //�õ���ʼ
//		//		}
//		//	}
//
//		//	_tables[index]._data = kv; //������ֵ
//		//	_tables[index]._state = EXITS; //�������λ��״̬��Ϊ����
//		//	++_dataNum; //size++
//
//		//	return make_pair(&_tables[index], true);
//		//}
//
//		//pair<HashData*, bool> Insert(const pair<K, V>& kv)
//		//{
//		//	// �������������� ->�Ľ�
//		//	if (_dataNum == _tables.size())
//		//	{
//		//		size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//		//		HashTable<K, V> newht;  //�����µĹ�ϣ�����
//		//		newht._tables.resize(newSize);
//
//		//		// ��ԭ����������¼���λ�ã�ӳ�䵽�±�
//		//		for (size_t i = 0; i < _tables.size(); ++i)
//		//		{
//		//			if (_tables[i]._state == EXITS)
//		//			{
//		//				newht.Insert(_tables[i]._data);  //���뵽�±�����insertȥ�����ͻ����
//		//			}
//		//		}
//
//		//		_tables.swap(newht._tables); //����ԭ���ɱ�����
//		//	}
//
//		//	size_t index = kv.first % _tables.size();
//		//	// ����̽��
//		//	while (_tables[index]._state == EXITS)
//		//	{
//		//		if (_tables[index]._data.first == kv.first)
//		//		{
//		//			return make_pair(&_tables[index], false);  //���У�����ʧ��
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
//		//HashData* Find(const K& key)  //����
//		//{
//		//	size_t index = key % _tables.size(); //key % ���С
//		//	while (_tables[index]._state != EMPTY)  //��Ϊ�ա����������ڻ���ɾ�������
//		//	{
//		//		if (_tables[index]._state == EXITS
//		//			&& _tables[index]._data.first == key)
//		//		{
//		//			return &_tables[index]; //�ҵ�
//		//		}
//		//		else
//		//		{
//		//			++index;
//		//			if (index == _tables.size()) //�ҵ�������ûص�ͷ
//		//			{
//		//				index = 0;
//		//			}
//		//		}
//		//	}
//
//		//	return nullptr;  //û��
//		//}
//
//		pair<HashData*, bool> Insert(const pair<K, V>& kv)
//		{
//			//���Ƹ���������0.7
//			if (_tables.size() == 0 || _dataNum * 10 / _tables.size() == 7) //����
//			// �������������� ->�Ľ�
//			//if (_dataNum == _tables.size())
//			{
//				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//				HashTable<K, V> newht;  //�����µĹ�ϣ�����
//				newht._tables.resize(newSize);
//
//				// ��ԭ����������¼���λ�ã�ӳ�䵽�±�
//				for (size_t i = 0; i < _tables.size(); ++i)
//				{
//					if (_tables[i]._state == EXITS)
//					{
//						newht.Insert(_tables[i]._data);  //���뵽�±�����insertȥ�����ͻ����
//					}
//				}
//
//				_tables.swap(newht._tables); //����ԭ���ɱ�����
//			}
//
//			size_t start = kv.first % _tables.size();
//			size_t index = start; //����ʼλ�ÿ�ʼ��
//			size_t i = 1;
//			// ����̽�� ���Ż�
//			while (_tables[index]._state == EXITS)
//			{
//				if (_tables[index]._data.first == kv.first)
//				{
//					return make_pair(&_tables[index], false);  //���У�����ʧ��
//				}
//
//				index = start + i * i; // + 1^2....
//				index %= _tables.size(); //���˱��С ȡ%
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
//		HashData* Find(const K& key)  //����
//		{
//			size_t start = kv.first % _tables.size();
//			size_t index = start;
//			size_t i = 1;
//			while (_tables[index]._state != EMPTY)  //��Ϊ�ա����������ڻ���ɾ�������
//			{
//				if (_tables[index]._state == EXITS
//					&& _tables[index]._data.first == key)
//				{
//					return &_tables[index]; //�ҵ�
//				}
//				else
//				{
//					index = start + i * i; // + 1^2....
//					index %= _tables.size(); //���˱��С ȡ%
//					++i;
//				}
//			}
//
//			return nullptr;  //û��
//		}
//
//		void Erase(const K& key)  //ɾ��
//		{
//			HashData* ret = Find(key);  //��find���ҵ���ֵ��ɾ��
//			if (ret)
//			{
//				ret->_state = DELETE; //ɾ��ֻ����״̬
//			}
//		}
//
//		V& operator[](const K& key) // operator[] �޸�
//		{
//			pair<HashData*, bool> ret = Insert(make_pair(key, V())); //����insert
//			return ret.first->_data.second;  //_data.second  value
//		}
//
//	private:
//		/*	HashData* _tables;
//			size_t _size;
//			size_t _capacity;*/
//
//		vector<HashData> _tables; //ʹ��vectorȥ�滻��������
//		size_t           _dataNum = 0;  // ��Ч�����ݸ���,��ȱʡֵ
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
//		ht[27]; //����
//		ht[27] = 27; // �޸�
//		ht[29] = 29; // ����+�޸�
//	}
//}


//��ɢ��
namespace BUCKET_HASH
{
	template<class T>
	struct HashNode  //����
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	template<class K>
	struct _Hash  //Ĭ�ϣ��������Σ�����Ҫ����
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	// sort��string��ͬ�ַ�
	// bacd bcad
	// abc aad  ��ĸ���������
	// ����Ч���������ܶ���ַ�������ĸ��һ����ӳ��ת����������ֵ�Ͳ�һ����
	template<>
	struct _Hash<string> //string
	{
		size_t operator()(const string& key)
		{
			//return key[0];
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); ++i) //�ַ���ͬ
			{
				hash = hash * 131 + key[i]; //��ϣ�ַ����㷨
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

	// ǰ������
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	// ������
	template<class K, class T, class KeyOfT, class Hash>
	struct HashTableIterator
	{
		typedef HashNode<T> Node;
		Node* _node;
		HashTable<K, T, KeyOfT, Hash>* _ht; //��ϣ��
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
			if (_node->_next) //��ǰͰû������
			{
				_node = _node->_next;
			}
			else
			{
				//��ǰͰ�Ѿ�����
				KeyOfT kot;
				size_t index = _ht->HashFunc(kot(_node->_data), _ht->_tables.size());
				//��һ��Ͱ
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
				_node = nullptr; //û���ҵ��ÿ�
			}
			return *this;
		}

		bool operator!=(const Self& s) //�������Ƚ� -> �Ƿ���ͬһ���ڵ�
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

		//��Ԫ -> ����˽�г�Ա�޷�����
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
					return iterator(bucket, this);//��ָ�롢��ϣ��
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator, bool> Insert(const T& data) //T��map->pair set->k
		//pair<Node*, bool> Insert(const pair<K, V>& kv)
		{
			KeyOfT kot;

			// �������ӿ��Ƶ�1 -> ƽ������ÿ��Ͱ��1-2������
			if (_dataNum == _tables.size()) //����������
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtables;  
				newtables.resize(newsize, nullptr);

				// �ɱ�����ݽڵ�ȡ���������������±��е�λ��
				for (size_t i = 0; i < _tables.size(); ++i)  //�����ɱ�
				{
					Node* cur = _tables[i]; //�ӵ�һ��λ��ȡ
					while (cur)
					{
						Node* next = cur->_next;  //��ǰ���棬�����Ҳ���
					
						// ͷ�嵽�±�  
						//size_t index = cur->_data.first % newtables.size();  //�±��λ��
						//size_t index = HashFunc(cur->_data.first, newtables.size());
						size_t index = HashFunc(kot(cur->_data), newtables.size());
						cur->_next = newtables[index];
						newtables[index] = cur;

						cur = next;
					}
					_tables[i] = nullptr; //�ÿ�
				}

				_tables.swap(newtables); //������ֵ
			}

			size_t index = HashFunc(kot(data), _tables.size());
			//size_t index = HashFunc(kv.first, _tables.size());
			//size_t index = kv.first % _tables.size();
			// ����key�Ƿ���ڣ������򲻲��루multi�汾���������飬ֱ�ӽ�������Ĳ��룩
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_data) == kot(data))
				{
					return make_pair(iterator(cur, this), false);
				}

				cur = cur->_next;
			}

			// ͷ�� β��Ҫȥ��β���������Ӷ������֪��˭��β -> ��¼β
			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_dataNum;

			return make_pair(iterator(newnode, this), true);
		}

		// O(��ʽͰ�ĳ���)
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

		// ��key����ȡģ����ӳ��λ��
		size_t HashFunc(const K& key, size_t size)
		{
			Hash hash; // ��ϣ�º���:��keyת������
			return hash(key) % size;
		}

	private:
		vector<Node*> _tables;  //vector ��ڵ�ָ��
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
	//	dict.Insert(make_pair("sort", "����"));
	//	dict.Insert(make_pair("string", "�ַ���"));
	//	dict.Insert(make_pair("left", "���"));

	//	/*	_HashString hash;
	//	cout << hash("abc") << endl;
	//	cout << hash("aad") << endl;
	//	cout << hash("abcd") << endl;
	//	cout << hash("bcad") << endl;*/
	//}
}