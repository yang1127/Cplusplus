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

		Node* newnode = new Node(kv);
		cur = newnode;
		cur->_bf = 0; //�ҵ�cur��λ�ú���������cur��������
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
				else if (parent->_bf == -2 && cur->_bf == 1) //������
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) //������
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
		else //��subL��parentParent���������ӡ������Һ�������
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

	//void RotateLR(Node* parent)  //ƽ������û�п����ܵ�
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
		int bf = subLR->_bf; // subLR->_bf ����ڵ���ƽ������ֵ�����������-1��0��1 

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
		int bf = subRL->_bf; //�������

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

	int  Height(Node* root)  //�����ĸ߶ȣ�����˼�룺���Ҹ�
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		//�ݹ�:������������... -> ���
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1; //��������������+1
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr) //����ҲΪƽ����
			return true;

		int leftHeight = Height(root->_left);   //�������ĸ߶�
		int rightHeight = Height(root->_right); //�������ĸ߶�

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << root->_kv.first << ":ƽ�������쳣" << endl;
			return false;
		}

		return abs(leftHeight - rightHeight) < 2    //����ֵС��2������  ���ݹ鿴�����Ƿ�����
			       && _IsBalance(root->_left)
			       && _IsBalance(root->_right);     //root==nullptrʱ��ֹ
	}

	bool IsBalance() //���ú������_root˽������
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