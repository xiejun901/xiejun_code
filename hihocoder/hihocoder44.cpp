#include<vector>
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(101);
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int sum = a[0];
	for (int i = 1;i < n;i++)
	{
		sum ^= a[i];
	}
	if (sum == 0)
		cout << "Bob" << endl;
	else
		cout << "Alice" << endl;
	return 0;
}