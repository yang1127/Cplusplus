#include<iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	int _bf; // 平衡因子

	AVLTreeNode(const pair<K, V>& kv) //pair kv
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)  //平衡因子默认给1
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	V& operator[](const K& key) //operator[]调用insert
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second; //有返回，没有插入再返回
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv) //插入
	{
		if (_root == nullptr)
		{
			_root = new Node(kv); //_root == nullptr，第一个节点进入
			return make_pair(_root, true);//节点插入成功
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first < kv.first) //大于朝右子树走
			{
				parent = cur; //先把 parent = cur保存到parent，再去找cur的左或右
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) //小于朝左子树找
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		cur = new Node(kv); //找到cur的位置后，再来链接cur，三岔链
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

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right) //插入的cur是在父节点右边，平衡因子+1
				parent->_bf += 1;
			else
				parent->_bf -= 1;  //插入的cur是在父节点左边，平衡因子-1

			//1.如果parent->bf ==1 / -1,说明parent为根的子树的高度也变了，继续往上更新
			if (parent->_bf == 1 || parent->_bf == -1) //abs(parent->_bf == 1) abs:绝对值
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			//2.如果parent ->bf ==0,说明parent为所在的子树原来的高度是1/-1，现在把矮的那边给填上，parent所在的子树高度不变，停止更新
			else if (parent->_bf == 0)
			{
				break;
			}
			//3.如果parent ->bf ==2 /-2,说明parent为根的子树已经不平衡，需要旋转处理
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理
				if (parent->_bf == -2 && cur->_bf == -1)   //右单旋
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1) //左单旋
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
		Node* subR = parent->_right; //subR:parent的右孩子
		Node* subRL = subR->_left;   //subRL:parent右孩子的左孩子

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
		Node* subL = parent->_left; //subL:parent的左孩子
		Node* subLR = subL->_right;  //subLR:parent左孩子的右孩子
       
		//三岔链交换
		parent->_left = subLR; 
		if (subLR)  //subLR不为空时，为空不需要改
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parentParent = parent->_parent; //parent节点是否有parent节点，先保存parent->_parent
		parent->_parent = subL;

		if (_root == parent) //parent为根，则没有parentParent
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