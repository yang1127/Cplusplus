//#include<iostream>
//using namespace std;
//
//class A {
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}

////�����ַ���
////s1  abcdefg��s2 bcd
//// aefg
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	getline(cin, s1); //����s1�ַ���
//	getline(cin, s2); //����s2�ַ���
//	for (int i = 0; i < s1.size(); i++)
//	{
//		if (s2.find(s1[i]) == -1)
//			cout << s1[i];
//	}
//	return 0;
//}

//��������
//3 -1 2 1
//3

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int NUMmax = v[0];
	int SUMNUMmax = v[0];

	for (int i = 1; i < n; i++)
	{
		NUMmax = (NUMmax >= 0 ? NUMmax + v[i] : v[i]);

		if (NUMmax > SUMNUMmax)
			SUMNUMmax = NUMmax;
		else
			SUMNUMmax = SUMNUMmax;
	}
	cout << SUMNUMmax << endl;

	system("pause");
	return 0;
}
