#include<cstdio>
#define N 1000000+1
#define M 20//2^20=1048576
using namespace std;
int weight[N];
int preCal[N][M];
int log2(int x);
int min(int x, int y);
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &weight[i]);
	int m = log2(n);
	for (int i = 1; i <= n; i++)
	{
		preCal[i][0] = weight[i];
	}
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i + (1 << (j - 1)) <= n; i++)
		{
			preCal[i][j] = min(preCal[i][j-1], preCal[i+(1<<(j-1))][j-1]);
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int li, ri;
		scanf("%d%d", &li,&ri);
		int nl = ri - li + 1;
		int ml = log2(nl);
		printf("%d\n", min(preCal[li][ml], preCal[ri - (1<<ml)+1][ml]));
	}
	return 0;

}
//不超过x的2^i;如x=1024，返回10，x=1024，返回9;
inline int log2(int x)
{
	int i = 20;
	while ((((1 << i)&x) == 0)&&i>=0)
		--i;
	return i;
}

inline int min(int x, int y)
{
	return x < y ? x : y;
}