#include"BinarySearchTree.h"

int main()
{
	BSTree<int> b;
	b.Insert(5);
	b.Insert(3);
	b.Insert(7);
	b.Insert(1);
	b.Insert(4);
	b.Insert(6);
	b.Insert(8);
	b.Insert(0);
	b.Insert(2);
	b.Insert(9);
	cout << "�������������:";
	b.InOrder();
	cout << endl;
	b.Erase(7);
	b.Erase(2);
	b.Erase(8);
	cout << "ɾ������������:";
	b.InOrder();
	cout << endl;
}
