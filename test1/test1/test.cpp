////输出字符串

#include <iostream>
#include <string>

//
//using namespace std;
//
//int main()
//{
//	string s;
//	while (cin >> s) //输入字符串
//	{
//		int arr[256] = { 0 }; //将字符串中字符下标全初始化为0
//		for (auto e : s) //遍历字符串
//		{
//			if (arr[e] == 0) //若字符下标为0时进入
//			{
//				cout << e; //输出该字符
//				arr[e] = 1;//将输出的字符置为1
//			}
//		}
//		cout << endl; //若字符下标为1时不进入
//	}
//	return 0;
//}

////找元素
//class Finder 
//{
//public:
//	int findElement(vector<int> a, int n, int x) 
//	{
//		int left = 0, right = n - 1;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2; //先找新序列的中间元素
//
//			if (a[mid] == x) //如果中间元素恰好为要查询的元素，则直接返回中间元素
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
