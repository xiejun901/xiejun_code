#include<iostream>
#include<cstdio>
using namespace std;
#define N (1000000+1)
int weight[N];
int segTreeNode[3 * N];
void buildSegTree(int root, int start, int end);
void changeWeight(int root, int start, int end, int index, int value);
int querySegTree(int root, int start, int end, int qstart, int qend);
inline int min(int x, int y);
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &weight[i]);
	}
	buildSegTree(1, 1, n);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int op,l, r;
		scanf("%d%d%d",&op, &l, &r);
		if (op == 0)
			printf("%d\n", querySegTree(1, 1, n, l, r));
		else
			changeWeight(1, 1, n, l, r);
	}
	return 0;

}

void buildSegTree(int root, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		buildSegTree(2 * root, start, mid);
		buildSegTree(2 * root + 1, mid + 1, end);
		segTreeNode[root] = min(segTreeNode[2 * root], segTreeNode[2 * root + 1]);
	}
	else
	{
		segTreeNode[root] = weight[start];
	}
}
void changeWeight(int root, int start, int end, int index, int value)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		if (index <= mid)
			changeWeight(2 * root, start, mid, index, value);
		else
			changeWeight(2 * root + 1, mid + 1, end, index, value);
		segTreeNode[root] = min(segTreeNode[2 * root], segTreeNode[2 * root + 1]);
	}
	else
	{
	//	weight[index] = value;
		segTreeNode[root] = value;
	}
}
int querySegTree(int root, int start, int end, int qstart, int qend)
{
	if (qstart == start&&qend == end)
		return segTreeNode[root];
	int mid = (start + end) / 2;
	if (qend <= mid)
		return querySegTree(2 * root, start, mid, qstart, qend);
	else if (qstart > mid)
		return querySegTree(2 * root + 1, mid + 1, end, qstart, qend);
	else
		return min(querySegTree(2 * root, start, mid, qstart, mid), querySegTree(2 * root + 1, mid + 1, end, mid + 1, qend));

}
inline int min(int x, int y)
{
	return x < y ? x : y;
}