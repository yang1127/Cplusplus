//#include <iostream>
//#include <vector>
//#include <algorithm> //sort
//using namespace std;
//
//int main()
//{
//	int n; //����n������
//	while (cin >> n)
//	{
//		vector<int> arr(3 * n); //�����СΪ 3 * n�����ܶ�Ա
//		int sum = 0; //long long int
//		for (int i = 0; i < 3 * n; i++) //��������
//		{
//			cin >> arr[i];
//		}
//
//		sort(arr.begin(), arr.end()); //������Ԫ�ؽ�������������ķ�ʽ����
//		for (int i = n; i <= 3 * n - 2; i = i + 2) //�����ˮƽֵ���ڸö���ĵڶ���ˮƽֵ
//		{                                          //��ÿ i+2 ��λ��Ϊһ��ˮƽֵ��- 2��i��2��λ�ÿ�ʼ
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
	getline(cin, s1); //�����һ���ַ���
	getline(cin, s2); //����ڶ����ַ���
	char arr[256] = { 0 }; //��ʼ������Ԫ��Ϊ0
	for (int i = 0; i < s2.size(); ++i) //����s2
	{
		arr[s2[i]]++; //��s2�е��ַ��±���Ϊ1    
	}
	string tmp; //����������ַ���
	for (int i = 0; i < s1.size(); ++i)//����s1
	{
		if (arr[s1[i]] == 0) //�±�Ϊ0ʱ
		{
			tmp = tmp + s1[i];
		}
	}
	cout << tmp << endl;

	system("pause");
	return 0;
}