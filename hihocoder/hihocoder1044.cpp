#include<cstdio>
#include<cstring>
#define N 1001
#define M 1024
using namespace std;
int count(const int &i);
inline int max(const int &x, const int &y);
int w[N];
int best[2][M];
int main()
{
	int n, m, q;
	memset(w, 0, sizeof(w));
	memset(best, 0, sizeof(best));
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
		for (int j = 0; j < (1 << (m - 1)); j++)
		{
			if (count(j) < q)
			{
				best[i%2][j / 2 + (1 << (m - 2))] = max(best[(i - 1)%2][j] + w[i], best[i%2][j / 2 + (1 << (m - 2))]);
				best[i%2][j / 2] = max(best[(i - 1)%2][j], best[i%2][j / 2]);

			}
			else
				best[i%2][j / 2] = max(best[(i - 1)%2][j], best[i%2][j / 2]);
		}	
	}
	int maxmum = 0;
	for (int j = 0; j < (1 << (m - 1)); j++)
	{
		if (maxmum < best[n%2][j])
			maxmum = best[n%2][j];
	}
	printf("%d\n", maxmum);
	return 0;
}

int count(const int &i)
{
	int cnt=0;
	int j = 1;
	while(j <= i)
	{
		if (j&i)
			cnt++;
		j=j << 1;
	}
	return cnt;
}
inline int max(const int &x, const int &y)
{
	return x > y ? x : y;
}
