#include<iostream>
using namespace std;
#define N 500+1
#define M 100000+1
int need[N];
int value[N];
int best[2][M];
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
		best[0][i] = 0;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j < need[i])
				best[i%2][j] = best[(i - 1)%2][j];
			else
				best[i % 2][j] = max(best[(i - 1) % 2][j - need[i]] + value[i], best[(i - 1) % 2][j]);
		}
	}
	cout << best[n%2][m] << endl;
	return 0;
}

int max(int a, int b)
{
	return a>b ? a : b;
}