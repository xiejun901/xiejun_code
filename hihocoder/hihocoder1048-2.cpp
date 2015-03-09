#include<cstdio>
#include<cstring>
using namespace std;
#define N 1002
#define M 5+2
int a[2048];
int getbit(const int &x, const int &k);
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	//	n = 2;
	//	m = 4;
	int mm = (1 << (2 * m)) - 1;
	//memset(a, 1, sizeof(a));
	for (int j = 1; j <= m; j++)
	for (int k = 0; k <= mm; k++)
		a[k] = 1;
	a[(1 << (2 * m)) - 1] = 1;
	for (int i = n; i > 0; i--)
	{
		for (int j = m; j > 0; j--)
		{
			for (int k = mm; k >= 0; k--)
			{
				if (j < m && getbit(k, j) == 1)
				{
					a[k] = a[k];
				}
				else if (j == m && getbit(k, j) == 1)
				{
					a[k] = a[k >> m];
				}
				else if (getbit(k, j) == 0 && (j == m || getbit(k, j + 1) == 1) && (i == n || getbit(k, j + m) == 1))
				{
					a[k] = 0;
				}
				else if (getbit(k, j) == 0 && (j < m && getbit(k, j + 1) == 0) && (i == n || getbit(k, j + m) == 1))
				{
					a[k] = a[k + (1 << (j - 1)) + (1 << (j + 1 - 1))];
				}
				else if (getbit(k, j) == 0 && (j == m || getbit(k, j + 1) == 1) && (i < n&&getbit(k, j + m) == 0))
				{
					a[k] = a[k + (1 << (j - 1)) + (1 << (j + m - 1))];
				}
				else if (getbit(k, j) == 0 && (j<m&&getbit(k, j + 1) == 0) && (i<n&&getbit(k, j + m) == 0))
				{
					a[k] = a[k + (1 << (j - 1)) + (1 << (j + 1 - 1))] + a[k + (1 << (j - 1)) + (1 << (j + m - 1))];
					a[k] = a[k] % 1000000007;
				}
			}
		}
	}
	printf("%d\n", a[0]);
	return 0;

}

inline int getbit(const int &x, const int &k)
{
	return (x >> (k - 1)) & 1;
}