#include<cstdio>
#define N 1000000
using namespace std;
void swap(int &x, int &y);
int binarySearch(int begin, int end, int k);
int a[N];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d\n", binarySearch(0, n - 1, k));
	return 0;
}

int binarySearch(int begin, int end,int k)
{
	if (begin <= end)
	{
		int j = begin;
		int temp = a[end];
		for (int i = begin; i < end; i++)
		{
			if (a[i] < temp)
			{

				swap(a[j], a[i]);
				j++;
			}
		}
		swap(a[j], a[end]);
		if (k == a[j])
			return j+1;
		else if (k < a[j])
			return binarySearch(begin, j - 1, k);
		else
			return binarySearch(j+1, end, k);
	}
	else
		return -1;
}

inline void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}