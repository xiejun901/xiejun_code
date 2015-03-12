//这个程序要报TLE！！！！！！！！
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
int check(pair<int, int> *p, int n, int r, int key);
int main()
{
	pair<int, int> p[N];
	int n, r, t;
	scanf("%d", &t);
	while (t--)
	{
		int max = 0;
		scanf("%d%d", &n, &r);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &p[i].first, &p[i].second);
			if (p[i].second > max)
				max = p[i].second;
		}
		sort(p + 1, p + n + 1);
		int low = 1;
		int high = max;
		int mid = (low + high) / 2;
		while (low < high)
		{
			int temp = check(p, n, r, mid);
			//int temp = check(p, n, r, 88);
			if (temp)
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
			mid = (low + high) >> 1;
		}
		//cout << low << endl;
		printf("%d\n", low);
	}

	return 0;
}
int check(pair<int, int> *p, int n, int r, int key)
{
	int a[N];
	for (int i = 1; i <= n; i++)
		a[i] = (p + i)->second;
	for (int i = 1; i < n; i++)
	{
		if (a[i]>key)
		{
			int j = i + 1;
			int resi = a[i] - key;
			a[i] = key;
			while (resi>0 && (((p + j)->first - (p + i)->first) <= r) && j <= n)
			{

				a[j] = a[j] + (resi < key ? resi : key);
				resi = resi - key;
				j++;
			}
			if (resi > 0)
			{
				return 0;
			}
		}
		else if (a[i] < key)
		{
			int j = i + 1;
			int resi = key - a[i];
			while (resi>0 && (((p + j)->first - (p + i)->first) <= r) && j <= n)
			{
				int temp = a[j];
				a[i] = a[i] + (resi < a[j] ? resi : a[j]);
				a[j] = a[j] - (resi < a[j] ? resi : a[j]);
				resi = resi - temp;
				j++;
			}
			if (j>n&&a[n] <= key)
				return 1;
		}
	}
	if (a[n] <= key)
		return 1;
	else
		return 0;

}