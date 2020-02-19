#include<iostream>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv; //pair -> std

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

		Node* newnode = new Node(kv);
		cur = newnode;
		cur->_bf = 0; //找到cur的位置后，再来链接cur，三岔链
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
				else if (parent->_bf == -2 && cur->_bf == 1) //左右旋
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) //右左旋
				{
					RotateRL(parent);
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
		else //看subL与parentParent的左孩子链接、还是右孩子链接
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

	//void RotateLR(Node* parent)  //平衡因子没有考虑周到
	//{
	//	RotateL(parent->_left);
	//	RotateR(parent);
	//}

	//void RotateRL(Node* parent)
	//{
	//	RotateR(parent->_right);
	//	RotateL(parent);
	//}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf; // subLR->_bf 插入节点后的平衡因子值，三种情况：-1、0、1 

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 0;
			subLR->_bf = 1;
		}
		else if (bf == 0)
		{
			subL->_bf = 0;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
	}


	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left; 
		int bf = subRL->_bf; //三种情况

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 0;
		}
	}

	int  Height(Node* root)  //求树的高度：后序思想：左右根
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		//递归:求子树的子树... -> 求根
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1; //左右子树中最大的+1
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr) //空树也为平衡树
			return true;

		int leftHeight = Height(root->_left);   //求左树的高度
		int rightHeight = Height(root->_right); //求右树的高度

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << root->_kv.first << ":平衡因子异常" << endl;
			return false;
		}

		return abs(leftHeight - rightHeight) < 2    //绝对值小于2，满足  层层递归看子树是否满足
			       && _IsBalance(root->_left)
			       && _IsBalance(root->_right);     //root==nullptr时终止
	}

	bool IsBalance() //调用函数解决_root私有问题
	{
		return _IsBalance(_root);
	}

private:
	Node* _root = nullptr;
};

void TestAVLTree()
{
	//AVLTree<int, double> t;
	//t.Insert(make_pair(1, 1.1));
	//t.Insert(make_pair(2, 2.2));
	//t[3] = 3.3;
	//t[5] = 5.5;
	//t[6] = 6.6;

	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	cout << t.IsBalance() << endl;
}