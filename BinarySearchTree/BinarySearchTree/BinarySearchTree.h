#pragma once

#include<iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		: _pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	PNode Find(const T& data)
	{
		PNode pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_pLeft)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; // Ԫ���Ѿ������д���
			else
				return false;
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}

	bool Erase(const T& data)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot)
			return false;
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data���ڶ��������������޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ��
		if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
			if (nullptr == pCur->_pLeft)
			{
				if (pParent->_pLeft == pCur)
				{
					pParent->_pLeft = nullptr;
				}
				else if (pParent->_pRight == pCur)
				{
					pParent->_pRight = nullptr;
				}

				pCur->_data = -1;
				delete pCur;
				pCur = nullptr;

			}
			else
			{
				PNode dNode = pCur;
				PNode tmp = pCur->_pLeft;
				swap(tmp->_data, pCur->_data);
				pCur = tmp;
				tmp = dNode;
				tmp->_pLeft = nullptr;
				delete pCur;
				pCur = nullptr;
			}
		}
		else if (nullptr != pCur->_pRight && nullptr == pCur->_pLeft)
		{
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
			pParent->_pLeft = pCur->_pRight;
			pCur->_data = -1;
			delete pCur->_pRight;
			pCur->_pRight = nullptr;
			delete pCur;
			pCur = nullptr;
		}
		else
		{
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������
		/*	������С�Ľڵ�*/
			// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
			PNode leftmax = _pRoot->_pLeft;
			PNode rightmin = _pRoot->_pRight;
			if (_pRoot->_data < pCur->_data)
			{
				while (rightmin)
				{
					if (rightmin->_pLeft)
					{
						rightmin = rightmin->_pLeft;
					}
					else
						break;
				}
				swap(pCur->_data, rightmin->_data);
				PNode pTmd = pCur;
				pCur = rightmin;
				rightmin = pTmd;
				rightmin->_pLeft = nullptr;
			}
			else
			{
				while (leftmax)
				{
					if (leftmax->_pRight)
					{
						leftmax = leftmax->_pRight;
					}
					else
						break;

				}
				swap(pCur->_data, leftmax->_data);
				PNode pTmd = pCur;
				pCur = leftmax;
				leftmax = pTmd;
				leftmax->_pRight = nullptr;
			}
			pCur->_data = -1;
			delete pCur;
			pCur = nullptr;
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}

private:
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	void _Destroy(PNode& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			pRoot = nullptr;
		}
	}
private:
	PNode _pRoot;
};