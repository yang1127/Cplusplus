#include<iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	int _bf; // ƽ������

	AVLTreeNode(const pair<K, V>& kv) //pair kv
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)  //ƽ������Ĭ�ϸ�1
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	V& operator[](const K& key) //operator[]����insert
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second; //�з��أ�û�в����ٷ���
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv) //����
	{
		if (_root == nullptr)
		{
			_root = new Node(kv); //_root == nullptr����һ���ڵ����
			return make_pair(_root, true);//�ڵ����ɹ�
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first < kv.first) //���ڳ���������
			{
				parent = cur; //�Ȱ� parent = cur���浽parent����ȥ��cur�������
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) //С�ڳ���������
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		cur = new Node(kv); //�ҵ�cur��λ�ú���������cur��������
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//����ƽ������
		while (parent)
		{
			if (cur == parent->_right) //�����cur���ڸ��ڵ��ұߣ�ƽ������+1
				parent->_bf += 1;
			else
				parent->_bf -= 1;  //�����cur���ڸ��ڵ���ߣ�ƽ������-1

			//1.���parent->bf ==1 / -1,˵��parentΪ���������ĸ߶�Ҳ���ˣ��������ϸ���
			if (parent->_bf == 1 || parent->_bf == -1) //abs(parent->_bf == 1) abs:����ֵ
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			//2.���parent ->bf ==0,˵��parentΪ���ڵ�����ԭ���ĸ߶���1/-1�����ڰѰ����Ǳ߸����ϣ�parent���ڵ������߶Ȳ��䣬ֹͣ����
			else if (parent->_bf == 0)
			{
				break;
			}
			//3.���parent ->bf ==2 /-2,˵��parentΪ���������Ѿ���ƽ�⣬��Ҫ��ת����
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת����
				if (parent->_bf == -2 && cur->_bf == -1)   //�ҵ���
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1) //����
				{
					RotateL(parent);
				}
				else if ()
				{

				}

				break;
			}
		}

		return make_pair(cur, true);
	}


	void RotateL(Node* parent)
	{
		Node* subR = parent->_right; //subR:parent���Һ���
		Node* subRL = subR->_left;   //subRL:parent�Һ��ӵ�����

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left; //subL:parent������
		Node* subLR = subL->_right;  //subLR:parent���ӵ��Һ���
       
		//����������
		parent->_left = subLR; 
		if (subLR)  //subLR��Ϊ��ʱ��Ϊ�ղ���Ҫ��
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parentParent = parent->_parent; //parent�ڵ��Ƿ���parent�ڵ㣬�ȱ���parent->_parent
		parent->_parent = subL;

		if (_root == parent) //parentΪ������û��parentParent
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}

		parent->_bf = subL->_bf = 0;
	}


private:
	Node* _root = nullptr;
};

void TestAVLTree()
{
	AVLTree<int, double> t;
	t.Insert(make_pair(1, 1.1));
	t.Insert(make_pair(2, 2.2));
	t[3];
	t[3] = 3.3;
	t[9] = 9.9;
}