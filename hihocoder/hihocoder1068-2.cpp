#include<cstdio>
#define N 1000000+1
using namespace std;
int segTree[3*N];
int weight[N];
void buildSegTree(int index, int start, int last);
int min(int x, int y);
int serchSegTree(int index, int start, int last, int startsearch, int lastsearch);
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
		int li, ri;
		scanf("%d%d", &li, &ri);
		printf("%d\n", serchSegTree(1, 1, n, li, ri));
	}
	return 0;

}

void buildSegTree(int index, int start, int last)
{
	if (start < last)
	{
		int mid = (start + last) / 2;
		buildSegTree(2 * index, start, mid);
		buildSegTree(2 * index+1, mid + 1, last);
		segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
	}
	else
	{
		segTree[index] = weight[start];
	}
}
int serchSegTree(int index, int start, int last, int startsearch, int lastsearch)
{
	int mid = (start + last) / 2;
	if (start == startsearch&&last == lastsearch)
		return segTree[index];
	if (lastsearch <= mid)
		return serchSegTree(2*index,start, mid, startsearch, lastsearch);
	else if (startsearch > mid)
		return serchSegTree(2*index+1,mid + 1, last, startsearch, lastsearch);
	else
		return min(serchSegTree(2*index,start, mid, startsearch, mid), serchSegTree(2*index+1,mid + 1, last, mid + 1, lastsearch));

}
inline int min(int x, int y)
{
	return x < y ? x : y;
}