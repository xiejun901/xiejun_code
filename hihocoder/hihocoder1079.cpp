#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#define N 5+1
using namespace std;
pair<int, int> intervalOrigin[N];
pair<int, int> intervalNew[N];
int inputPoint[2 * N];
map<int, int> map1;
int node[3 * N];
int answer[N];
void updateSegTree(int root, int start, int end, int ustart, int uend, int value);
void traverSegTree(int root, int start, int end);
int main()
{
	int n = 5;
	//intervalOrigin[1] = make_pair(4, 10);
	//intervalOrigin[2] = make_pair(0, 2);
	//intervalOrigin[3] = make_pair(1, 6);
	//intervalOrigin[4] = make_pair(5, 9);
	//intervalOrigin[5] = make_pair(3, 4);
	int l;
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &intervalOrigin[i].first, &intervalOrigin[i].second);

		inputPoint[2 * i - 1] = intervalOrigin[i].first;
		inputPoint[2 * i] = intervalOrigin[i].second;
	}
	sort(inputPoint + 1, inputPoint + 2 * n + 1);
	int j = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (map1[inputPoint[i]] == 0)
			map1[inputPoint[i]] = ++j;
	}
	for (int i = 1; i <= n; i++)
	{
		intervalNew[i].first = map1[intervalOrigin[i].first];
		intervalNew[i].second = map1[intervalOrigin[i].second];
		updateSegTree(1, 1, j, intervalNew[i].first, intervalNew[i].second, i);
	}
	//printf("%d\n", temp);
	traverSegTree(1, 1, j);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += answer[i];
	printf("%d\n",sum);
	return 0;
}

void updateSegTree(int root, int start, int end, int ustart, int uend,int value)
{
	if (start == ustart&&end == uend)
		node[root] = value;
	else
	{
		int mid = (start + end) / 2;
		if (node[root])
		{
			node[2 * root] = node[root];
			node[2 * root + 1] = node[root];
			node[root] = 0;
		}
		if (uend <= mid)
			updateSegTree(2 * root, start, mid, ustart, uend, value);
		else if (ustart>=mid)
			updateSegTree(2 * root+1, mid, end, ustart, uend, value);
		else
		{
			updateSegTree(2 * root, start, mid, ustart, mid, value);
			updateSegTree(2 * root + 1, mid, end, mid, uend, value);
		}
	}
}
void traverSegTree(int root,int start,int end)
{
		if (node[root])
		{
			answer[node[root]] = 1;
		}
		else
		{
			if (end - start > 1)
			{
				int mid = (start + end) / 2;
				traverSegTree(2 * root, start, mid);
				traverSegTree(2 * root + 1, mid, end);
			}
		}
}
