#include<iostream>
#define N 100+2
using namespace std;
int main()
{
	int t, n, m;
	cin >> t;
	int a[N];
	while (t--)
	{
		int max = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		a[0] = 0;
		a[n+1] = 101;
		if (m >= n)
		{
			cout << 100 << endl;
			continue;
		}
		for (int i = 1; i <=n+1; i++)
		{
			if (i + m - 1>n)
				break;
			if ((a[i + m] - a[i - 1] - 1) > max)
				max = a[i + m] - a[i - 1] - 1;
		}
		cout << max << endl;
	}
	return 0;
}