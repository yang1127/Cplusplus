////����ַ���

#include <iostream>
#include <string>

//
//using namespace std;
//
//int main()
//{
//	string s;
//	while (cin >> s) //�����ַ���
//	{
//		int arr[256] = { 0 }; //���ַ������ַ��±�ȫ��ʼ��Ϊ0
//		for (auto e : s) //�����ַ���
//		{
//			if (arr[e] == 0) //���ַ��±�Ϊ0ʱ����
//			{
//				cout << e; //������ַ�
//				arr[e] = 1;//��������ַ���Ϊ1
//			}
//		}
//		cout << endl; //���ַ��±�Ϊ1ʱ������
//	}
//	return 0;
//}

////��Ԫ��
//class Finder 
//{
//public:
//	int findElement(vector<int> a, int n, int x) 
//	{
//		int left = 0, right = n - 1;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2; //���������е��м�Ԫ��
//
//			if (a[mid] == x) //����м�Ԫ��ǡ��ΪҪ��ѯ��Ԫ�أ���ֱ�ӷ����м�Ԫ��
//				return mid;
//
//			// [left, mid][mid,right]
//			if (a[left] < a[mid]) 
//			{
//				if (a[left] <= x && x < a[mid]) 
//					right = mid - 1;
//				else
//					left = mid + 1;
//			}
//			else
//			{
//				if (a[mid] < x && x <= a[right])
//					left = mid + 1;
//				else
//					right = mid - 1;
//			}
//		}
//
//		return -1;
//	}
//};
