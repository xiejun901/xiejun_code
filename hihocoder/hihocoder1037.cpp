#include<iostream>
using namespace std;
int a[210];
int b[210];
int max(int x, int y);
int main()
{
	int layer;
	cin >> layer;
	for (int i = 1; i <= layer; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> a[j];
		for (int j = i; j >= 1; j--)
			b[j] = max(b[j], b[j - 1]) + a[j];
	}
	int sum = 0;
	for (int i = 0; i <= layer; i++)
		sum = max(sum, b[i]);
	cout << sum << endl;
	return 0;
}

int max(int x, int y)
{
	return (x > y ? x : y);
}
