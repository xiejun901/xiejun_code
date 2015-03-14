#include<iostream>
#include<cstdio>
#define N 101
#define M 101
using namespace std;
struct TreeSide{
	int to;
	int next;
};
struct TreeNode{
	int lastSideNumber;
	int value;
};
TreeSide side[N];
TreeNode node[N];
int n, m;
int best[N][M];
void dfs(int index);
int max(int x, int y);
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &node[i].value);
	}
	for (int i = 1; i <= n - 1; i++)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		side[i].to = to;
		side[i].next = node[from].lastSideNumber;
		node[from].lastSideNumber = i;
	}
	dfs(1);
	printf("%d\n", best[1][m]);
	return 0;
}

void dfs(int index)
{
	int p = node[index].lastSideNumber;
	if (p)
	{
		while (p)
		{
			dfs(side[p].to);
			p = side[p].next;
		}
		//	printf("%d,", index);
		p = node[index].lastSideNumber;
		for (int i = 2; i <= m; i++)
			best[index][i] = 0;
		best[index][0] = 0;
		best[index][1] = node[index].value;
		while (p)
		{
			for (int i = m; i >= 2; i--)
			{
				for (int j = 1; j <= i; j++)
				{
					best[index][i] = max(best[index][i], best[side[p].to][i - j] + best[index][j]);
				}
			}
			p = side[p].next;
		}
	}
	else
	{
		//	printf("%d,", index);
		best[index][0] = 0;
		best[index][1] = node[index].value;
		for (int i = 2; i <= m; i++)
			best[index][i] = 0;
	}
}

int max(int x, int y)
{
	return x > y ? x : y;
}