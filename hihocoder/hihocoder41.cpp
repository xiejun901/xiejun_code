#include<iostream>
#include<vector>
using namespace std;
const long long mod = 19999997;
vector<vector<long long>> matrixMul(const vector<vector<long long>> &a, const vector<vector<long long>> &b)
{
	vector<vector<long long>> vec;
	for (int i = 0; i < a.size(); i++)
	{
		vector<long long> temp;
		for (int j = 0; j < b[i].size(); j++)
		{
			int sum = 0;
			for (int k = 0; k < b.size(); k++)
			{
				sum = (sum + a[i][k] * b[k][j]%mod)%mod;
			}
			temp.push_back(sum);
		}
		vec.push_back(temp);
	}
	return vec;
}

int main()
{
	vector<vector<long long>> a{ vector<long long>{0, 1}, vector<long long>{1, 1} };
	vector<vector<long long>> aPow2Pow[32];
	aPow2Pow[0]=a;
	for (int i = 1; i <= 31; i++)
		aPow2Pow[i] = matrixMul(aPow2Pow[i - 1], aPow2Pow[i - 1]);
	int n;
	cin >> n;
	vector<vector<long long>> product{ vector<long long>{1, 0}, vector<long long>{0, 1} };
	for (int i = 0; i <= 31; i++)
	{
		if (n&(1 << i))
			product = matrixMul(product, aPow2Pow[i]);
	}
	cout << product[1][1] << endl;
	return 0;
}