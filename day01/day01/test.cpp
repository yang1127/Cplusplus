#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(3 * n);
		int sum = 0;
		for (int i = 0; i < 3 * n£» i++)
		{
			cin >> a[i];
		}

		sort(arr.begin(), arr.end());
		for (int i = n; i <= 3 * n - 2; i = i + 2)
		{
			sum = sum + a[i];
		}

		cout << sum << endl;
	}
}