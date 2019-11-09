//#include <iostream>
//#include <vector>
//#include <algorithm> //sort
//using namespace std;
//
//int main()
//{
//	int n; //输入n个队伍
//	while (cin >> n)
//	{
//		vector<int> arr(3 * n); //数组大小为 3 * n，即总队员
//		int sum = 0; //long long int
//		for (int i = 0; i < 3 * n; i++) //遍历数组
//		{
//			cin >> arr[i];
//		}
//
//		sort(arr.begin(), arr.end()); //将数组元素进行排序，以升序的方式排序
//		for (int i = n; i <= 3 * n - 2; i = i + 2) //队伍的水平值等于该队伍的第二高水平值
//		{                                          //即每 i+2 的位置为一次水平值，- 2：i从2的位置开始
//			sum = sum + arr[i];
//		}
//
//		cout << sum << endl;
//	}
//}

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1;
	string s2;
	getline(cin, s1); //输入第一个字符串
	getline(cin, s2); //输入第二个字符串
	char arr[256] = { 0 }; //初始化数组元素为0
	for (int i = 0; i < s2.size(); ++i) //遍历s2
	{
		arr[s2[i]]++; //将s2中的字符下标标记为1    
	}
	string tmp; //最终输出的字符串
	for (int i = 0; i < s1.size(); ++i)//遍历s1
	{
		if (arr[s1[i]] == 0) //下标为0时
		{
			tmp = tmp + s1[i];
		}
	}
	cout << tmp << endl;

	system("pause");
	return 0;
}