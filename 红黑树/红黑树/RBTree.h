#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& data) //构造函数
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(BLACK) //两个颜色都可以，后期会变色
	{}
};

//template<class K, class V>
template<class K, class T, class KeyOfValue> //红黑树存什么由第二个参数T所决定的，既可以存map、又可以set

class RBTree
{
	//typedef RBTreeNode<pair<K, V>> Node;
	typedef RBTreeNode<T> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	//pair<Node*, bool> Insert(const pair<K, V>& kv) //插入树 -> 搜索树的规则插入
	pair<Node*, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data); //为空插入新节点
			return make_pair(_root, true);
		}

		KeyOfValue kov;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{   //仿函数取出T中的K进行比较
			if (kov(cur->_data) < kov(data)) //大于朝右走
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_data) > kov(data)) //小于朝左走
			{
				parent = cur;
				cur = cur->_left;
			}
			else //相等时，表示已有，插入失败
			{
				return make_pair(_root, false);
			}
		}

		cur = new Node(data);
		//链接
		if (kov(parent->_data) < kov(data)) //大于父节点
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else  //小于父节点
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//变化
		while (parent && parent->_col == RED)//情况1有更新
		{
			// 关键看叔叔
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left) //父亲在左、叔叔在右
			{
				Node* uncle = grandfather->_right;
				// 情况1
				if (uncle && uncle->_col == RED) //叔叔存在且为红色
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// 继续往上更新
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2 + 情况3 叔叔不存在或者存在且为黑
				{
					//     g
					//   p
					// c
					// 旋转
					if (cur == parent->_left)
					{
						// 右单旋
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p
						//     c
						// 左右双旋
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					// 跳出循环
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left; //父亲在右、叔叔在左
				// 情况1
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// 继续往上更新
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2 + 情况3 uncle不存在或者存在且为黑
				{
					//     g
					//        p
					//           c
					// 旋转
					if (cur == parent->_right)
					{
						// 左单旋
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p
						//     c
						// 左右双旋
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					// 跳出循环
					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(cur, true);
	}

	void RotateL(Node* parent) //左旋
	{
		//   p
		//    subR   
		//   subRL		
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		// parentParent
		//    subR
		//  p
		//  subRL	 
		//旋转后链接
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (_root == parent) //原parent为根，则无parentParent
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else  //判断原parent在parentParent的左子树，还是右子树
		{
			if (parentParent->_left == parent) 
			{
				parentParent->_left = subR; //链接到旋转后的subR
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent; //链接到旋转后的subR
		}
	}

	void RotateR(Node* parent) //右旋
	{
		//    p
        //subL   
        //  subLR	
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		//  subL 
        //      p
        //    subLR
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
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
	}

	void RotateLR(Node* parent) //左右旋 这里不同于AVL，不需要考虑平衡因子
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)  //右左旋转
	{
		RotateR(parent->_right);
		RotateL(parent);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_data.first << " ";
		_InOrder(root->_right);
	}

	void InOrder() //中序遍历 左根右
	{
		_InOrder(_root);
		cout << endl;
	}

	//检查
	typedef Node* PNode;
	bool IsValidRBTree()
	{
		PNode pRoot = _root;
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;

			pCur = pCur->_left;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == pRoot->_col)
			k++;

		// 检测当前节点与其双亲是否都为红色
		PNode pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && RED == pRoot->_col)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

private:
	Node* _root;
};

//void TestRBTree()
//{
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
// 	}
//	cout << t.IsValidRBTree() << endl;
//}