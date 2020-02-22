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

	RBTreeNode(const T& data) //���캯��
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(BLACK) //������ɫ�����ԣ����ڻ��ɫ
	{}
};

//template<class K, class V>
template<class K, class T, class KeyOfValue> //�������ʲô�ɵڶ�������T�������ģ��ȿ��Դ�map���ֿ���set

class RBTree
{
	//typedef RBTreeNode<pair<K, V>> Node;
	typedef RBTreeNode<T> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	//pair<Node*, bool> Insert(const pair<K, V>& kv) //������ -> �������Ĺ������
	pair<Node*, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data); //Ϊ�ղ����½ڵ�
			return make_pair(_root, true);
		}

		KeyOfValue kov;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{   //�º���ȡ��T�е�K���бȽ�
			if (kov(cur->_data) < kov(data)) //���ڳ�����
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_data) > kov(data)) //С�ڳ�����
			{
				parent = cur;
				cur = cur->_left;
			}
			else //���ʱ����ʾ���У�����ʧ��
			{
				return make_pair(_root, false);
			}
		}

		cur = new Node(data);
		//����
		if (kov(parent->_data) < kov(data)) //���ڸ��ڵ�
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else  //С�ڸ��ڵ�
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//�仯
		while (parent && parent->_col == RED)//���1�и���
		{
			// �ؼ�������
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left) //����������������
			{
				Node* uncle = grandfather->_right;
				// ���1
				if (uncle && uncle->_col == RED) //���������Ϊ��ɫ
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// �������ϸ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2 + ���3 ���岻���ڻ��ߴ�����Ϊ��
				{
					//     g
					//   p
					// c
					// ��ת
					if (cur == parent->_left)
					{
						// �ҵ���
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p
						//     c
						// ����˫��
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					// ����ѭ��
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left; //�������ҡ���������
				// ���1
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// �������ϸ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2 + ���3 uncle�����ڻ��ߴ�����Ϊ��
				{
					//     g
					//        p
					//           c
					// ��ת
					if (cur == parent->_right)
					{
						// ����
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p
						//     c
						// ����˫��
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					// ����ѭ��
					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(cur, true);
	}

	void RotateL(Node* parent) //����
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
		//��ת������
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (_root == parent) //ԭparentΪ��������parentParent
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else  //�ж�ԭparent��parentParent��������������������
		{
			if (parentParent->_left == parent) 
			{
				parentParent->_left = subR; //���ӵ���ת���subR
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent; //���ӵ���ת���subR
		}
	}

	void RotateR(Node* parent) //����
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

	void RotateLR(Node* parent) //������ ���ﲻͬ��AVL������Ҫ����ƽ������
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)  //������ת
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

	void InOrder() //������� �����
	{
		_InOrder(_root);
		cout << endl;
	}

	//���
	typedef Node* PNode;
	bool IsValidRBTree()
	{
		PNode pRoot = _root;
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_col)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;

			pCur = pCur->_left;
		}

		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_col)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		PNode pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && RED == pRoot->_col)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
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