#include<iostream>
#include<fstream>
#define N 100000
using namespace std;
long long total;
void merge(int start, int mid, int end);
void mergeSort(int start, int end);
int a[N];
int main()
{
	//ifstream cin("data.txt");
	int n;
	//= {5, 6, 7, 8, 9,0, 1, 2, 3, 4 };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mergeSort(0, n - 1);
	//merge(a, 0, 4, 9);
	cout << total << endl;
	//	cin.close();
	return 0;
}
void mergeSort(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}
void merge(int start, int mid, int end)
{
	int left[N];
	int right[N];
	int leftLength = mid - start + 1;
	int rightLength = end - mid;
	int i, j, k;
	for (i = 0; i < leftLength; i++)
		left[i] = a[start + i];
	for (j = 0; j < rightLength; j++)
		right[j] = a[mid + j + 1];
	i = 0;
	j = 0;
	k = start;
	while (i<leftLength&&j<rightLength)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			total = total + j;
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	if (i == leftLength)
	{
		while (j < rightLength)
		{
			a[k] = right[j];
			k++;
			j++;
		}
	}
	else
	{
		while (i < leftLength)
		{
			a[k] = left[i];
			total = total + j;
			k++;
			i++;
		}
	}
}
