#include<iostream>
#include<fstream>
#define N (100000+2)
using namespace std;
int iprice[N];
struct segTreeNode{
	int priceSum;
	int lazyTagAdd;
	int lazyTagSet;
};
segTreeNode node[3 * N];
void buildSegTree(int root, int start, int end);
void updateLazyTag(int root, int start, int end);
void updateSegTree(int root, int start, int end, int ustart, int uend, int add, int set);
int main()
{
	//	ifstream cin;
	//	cin.open("data.txt", std::ifstream::in);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		cin >> iprice[i];
	buildSegTree(1, 0, n);
	for (int i = 1; i <= m; i++)
	{
		int op, l, r, value;
		cin >> op >> l >> r >> value;
		if (op)
			updateSegTree(1, 0, n, l, r, 0, value);
		else
			updateSegTree(1, 0, n, l, r, value, 0);
		cout << node[1].priceSum << endl;

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
		node[root].priceSum = node[2 * root].priceSum + node[2 * root + 1].priceSum;
	}
	else
	{
		node[root].priceSum = iprice[start];
	}
}

void updateSegTree(int root, int start, int end, int ustart, int uend, int add, int set)
{
	updateLazyTag(root, start, end);
	if (start == ustart&&end == uend)
	{
		if (add)
		{
			node[root].lazyTagAdd = add;
			node[root].priceSum = node[root].priceSum + add*(end - start + 1);
		}
		else if (set)
		{
			node[root].lazyTagSet = set;
			node[root].priceSum = set*(end - start + 1);
		}
	}
	else
	{
		int mid = (start + end) / 2;
		if (uend <= mid)
			updateSegTree(2 * root, start, mid, ustart, uend, add, set);
		else if (ustart>mid)
			updateSegTree(2 * root + 1, mid + 1, end, ustart, uend, add, set);
		else
		{
			updateSegTree(2 * root, start, mid, ustart, mid, add, set);
			updateSegTree(2 * root + 1, mid + 1, end, mid + 1, uend, add, set);
		}
		node[root].priceSum = node[2 * root].priceSum + node[2 * root + 1].priceSum;
	}
}

void updateLazyTag(int root, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		if (node[root].lazyTagSet)
		{
			//updateLazyTag(root * 2, start, mid);
			//updateLazyTag(root * 2 + 1, mid + 1, end);
			node[root * 2].lazyTagSet = node[root].lazyTagSet;
			node[root * 2 + 1].lazyTagSet = node[root].lazyTagSet;
			node[root * 2].lazyTagAdd = 0;
			node[root * 2 + 1].lazyTagAdd = 0;
			node[root * 2].priceSum = node[root].lazyTagSet*(mid - start + 1);
			node[root * 2 + 1].priceSum = node[root].lazyTagSet*(end - mid);
			node[root].lazyTagSet = 0;
		}
		if (node[root].lazyTagAdd)
		{
			//updateLazyTag(root * 2, start, mid);
			//updateLazyTag(root * 2+1, mid+1,end);
			node[root * 2].lazyTagAdd += node[root].lazyTagAdd;
			node[root * 2 + 1].lazyTagAdd += node[root].lazyTagAdd;
			node[root * 2].priceSum += node[root].lazyTagAdd*(mid - start + 1);
			node[root * 2 + 1].priceSum += node[root].lazyTagAdd*(end - mid);
			node[root].lazyTagAdd = 0;
		}

	}
}