#include<iostream>
#include<algorithm>
#define N 100010
using namespace std;
pair<int,int> p1[N], p2[N];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		int c, v;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			
			cin >> p1[i].first >> p1[i].second;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> p2[i].first >> p2[i].second;
		}
		sort(p1, p1+n);
		sort(p2, p2+m);
		long long sum = 0, cnt = 0;
		int j = 0;
		for (int i = 0; i<n; i++)
		{
			while (j<m && (p1[i].first) >(p2[j].first))
			{
				cnt = cnt + p2[j].second;
				j++;
			}
			sum = sum + p1[i].second*cnt;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
