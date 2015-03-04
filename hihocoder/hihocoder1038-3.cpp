#include<iostream>
using namespace std;
#define N 500+1
#define M 100000+1
int need[N];
int value[N];
int best[M];
int max(int a, int b);
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> need[i] >> value[i];
	}
	for (int i = 0; i <= m; i++)
		best[i] = 0;
	for (int i = 1; i <=n; i++)
	{
		int j = m;
		while(j >= 0 && j >= need[i])
		{
			best[j] = max(best[j - need[i]] + value[i], best[j]);
			--j;
		}
	}
	cout << best[m] << endl;
	return 0;
}

int max(int a, int b)
{
	return a>b ? a : b;
}