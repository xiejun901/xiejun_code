#include<cstdio>
using namespace std;
#define N 1000001
int n, k;
int value[N];
void swap(int &x, int &y);
int findk(int low, int high);
int findk2(int low, int high);
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &value[i]);
	};
	printf("%d\n", findk2(1, n));
	return 0;
	
}

int findk(int low, int high)
{
	if (low < high)
	{
		int i = low;
		int j = low;
		while (i < high)
		{
			if (value[i] < value[high])
			{
				swap(value[i], value[j]);
				j++;
			}
			i++;
		}
		swap(value[j], value[i]);
		if (j == k)
			return value[j];
		else if (j > k)
			return findk(low, j - 1);
		else
			return findk(j + 1, high);
	}
	else
	{
		if (k == low)
			return value[low];
		else
			return -1;
	}

}
int findk2(int low, int high)
{
	while (low < high)
	{
		int i = low;
		int j = low;
		while (i < high)
		{
			if (value[i] < value[high])
			{
				swap(value[i], value[j]);
				j++;
			}
			i++;
		}
		swap(value[j], value[i]);
		if (j == k)
			return value[j];
		else if (j > k)
			high = j - 1;
		else
			low = j + 1;
	}
	if (k == low)
		return value[low];
	else
		return -1;
}

inline void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}