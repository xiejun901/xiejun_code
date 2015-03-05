#include<iostream>
#include<cstring>
using namespace std;
#define N 500+1
#define M 100000+1
int max(int a, int b);
int best[M];
int main()
{
	int need[N], value[N];

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> need[i] >> value[i];
	memset(best, 0, sizeof(best));
	for (int i = 1; i <= n; i++)
	{
		for (int j = need[i]; j <= m; j++)
		{
			if (best[j-need[i]]+value[i]>best[j])
					best[j] =best[j - need[i]] + value[i];
				//best[i][j] = max(best[i - 1][j], best[i - 1][j - need[i]]+value[i]);
		}
	}
	cout << best[m] << endl;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}