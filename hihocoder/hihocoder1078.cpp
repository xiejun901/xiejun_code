#include<cstdio>
#define N (100000+1)
using namespace std;
class SegTreeNode{
public:
	SegTreeNode() :lazyTag(0),price(0),totalPrice(0){};
	bool lazyTag;
	int price;
	int totalPrice;
};
SegTreeNode node[3 * N];
int iPrice[N];
void changeSegTree(int root, int start, int end, int changeStart, int changeEnd, int price);
void buildSegTree(int root, int start, int end);
int querySegTree(int root, int start, int end, int qstart, int qend);
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &iPrice[i]);
	buildSegTree(1, 1, n);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int op;
		scanf("%d", &op);
		if (op)
		{
			int cstart, cend,price;
			scanf("%d%d%d", &cstart, &cend, &price);
			changeSegTree(1, 1, n, cstart, cend, price);
		}
		else
		{
			int qstart, qend;
			scanf("%d%d", &qstart, &qend);
			printf("%d\n",querySegTree(1, 1, n, qstart, qend));
		}
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
		node[root].totalPrice = node[2 * root].totalPrice + node[2 * root + 1].totalPrice;
	}
	else
	{
		node[root].totalPrice = iPrice[start];
	}
}

void changeSegTree(int root, int start, int end, int changeStart, int changeEnd,int price)
{
	if (start == changeStart&&end == changeEnd)
	{
		node[root].lazyTag = true;
		node[root].price = price;
		node[root].totalPrice = (end - start + 1)*price;
	}
	else
	{
		int mid = (start + end) / 2;
		if (node[root].lazyTag)
		{
			node[2 * root].lazyTag = true;
			node[2 * root].price = node[root].price;
			node[2 * root].totalPrice = (mid - start + 1)*node[root].price;
			node[2 * root+1].lazyTag = true;
			node[2 * root+1].price = node[root].price;
			node[2 * root + 1].totalPrice = (end - mid)*node[root].price;
			node[root].lazyTag = false;
		}
		if (changeEnd <= mid)
		{
			changeSegTree(2 * root, start, mid, changeStart, changeEnd, price);
		}
		else if (changeStart > mid)
		{
			changeSegTree(2 * root + 1, mid + 1, end, changeStart, changeEnd, price);
		}
		else
		{
			changeSegTree(2 * root, start, mid, changeStart, mid, price);
			changeSegTree(2 * root + 1, mid + 1, end, mid+1, changeEnd, price);
		}
		node[root].totalPrice = node[2 * root].totalPrice + node[2 * root + 1].totalPrice;
	}
}

int querySegTree(int root, int start, int end, int qstart, int qend)
{
	if (start == qstart&&end == qend)
		return node[root].totalPrice;
	else
	{
		int mid = (start + end) / 2;
		if (node[root].lazyTag)
		{
			node[2 * root].lazyTag = true;
			node[2 * root].price = node[root].price;
			node[2 * root].totalPrice = (mid - start + 1)*node[root].price;
			node[2 * root + 1].lazyTag = true;
			node[2 * root + 1].price = node[root].price;
			node[2 * root + 1].totalPrice = (end - mid)*node[root].price;
			node[root].lazyTag = false;
		}
		if (qend <= mid)
		{
			return querySegTree(2*root, start, mid, qstart, qend);
		}
		else if (qstart > mid)
		{
			return querySegTree(2 * root + 1, mid + 1,end, qstart, qend);
		}
		else
		{
			return querySegTree(2 * root, start, mid, qstart, mid) + querySegTree(2 * root + 1, mid + 1, end, mid + 1, qend);
		}
	}
}