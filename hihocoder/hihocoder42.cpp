#include<iostream>
#include<vector>
using namespace std;
const long long mod = 12357;
vector<vector<long long>> matrixMul(const vector<vector<long long>> &a, const vector<vector<long long>> &b)
{
	vector<vector<long long>> vec;
	for (size_t i = 0; i < a.size(); i++)
	{
		vector<long long> temp;
		for (size_t j = 0; j < b[i].size(); j++)
		{
			int sum = 0;
			for (size_t k = 0; k < b.size(); k++)
			{
				sum = (sum + a[i][k] * b[k][j] % mod) % mod;
			}
			temp.push_back(sum);
		}
		vec.push_back(temp);
	}
	return vec;
}

vector<long long> vectorMul(const vector<long long> &a, const vector<vector<long long>> &b)
{
	vector<long long> ret;
	for (size_t i = 0; i < b[0].size(); i++)
	{
		long long sum = 0;
		for (size_t j = 0; j < a.size(); j++)
			sum += ((a[j] * b[j][i])%mod);
		ret.push_back(sum);
	}
	return ret;
}

void generateIdentityMatirx(vector<vector<long long>> &m,int n)
{
	for (int i = 0; i < n; i++)
	{
		vector<long long> temp;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				temp.push_back(1);
			else
			{
				temp.push_back(0);
			}
		}
		m.push_back(temp);
	}
}
vector<vector<long long>> matrixPow(const vector<vector<long long>> &m, int n)
{
	vector<vector<long long>> ans[32];
	ans[0] = m;
	int i = 1;
	while (i < 32)
	{
		ans[i] = matrixMul(ans[i - 1], ans[i - 1]);
		++i;
	}
	vector<vector<long long>> pro;
	generateIdentityMatirx(pro,m.size());
	i = 0;
	while (n >> i)
	{
		if (n&(1 << i))
		{
			pro = matrixMul(pro, ans[i]);
		}
		++i;
	}
	return pro;
}

int main()
{
	//vector<long long> f{ 0, 0, 1, 1, 1, 0 };
	//vector<vector<long long>> m{ vector<long long>{0, 0, 0, 1, 0, 0},
	//							 vector<long long>{0, 0, 0, 0, 1, 0},
	//							 vector<long long>{0, 0, 0, 0, 0, 1},
	//							 vector<long long>{1, 0, 0, 0, 0, 1},
	//							 vector<long long>{0, 1, 0, 0, 0, 1},
	//							 vector<long long>{0, 0, 1, 1, 1, 0} };
	//vector<long long> f{ 0,1,1,0 };
	//vector<vector<long long>> m{ vector<long long>{0,0,1,0},
	//							 vector<long long>{0,0,0,1},
	//							 vector<long long>{1,0,0,2},
	//							 vector<long long>{0,1,1,0} };
	//vector<long long> f{ 0, 1 };
	//vector<vector<long long>> m{ vector<long long>{0, 1},
	//	vector<long long>{1,1}};
	vector<long long> f{0,0,0,0,0,0,0,1};
	vector<vector<long long>> m{ vector<long long>{0,0,0,0,0,0,0,1},
								 vector<long long>{0,0,0,0,0,0,1,0},
								 vector<long long>{0,0,0,0,0,1,0,0},
								 vector<long long>{0,0,0,0,1,0,0,1},
								 vector<long long>{0,0,0,1,0,0,0,0},
								 vector<long long>{0,0,1,0,0,0,0,0},
								 vector<long long>{0,1,0,0,0,0,0,1},
								 vector<long long>{1,0,0,1,0,0,1,0} };
	int task;
	cin >> task; 
	while (task--)
	{
		int n;
		cin >> n;
		vector<long long>ff = vectorMul(f, matrixPow(m, n));
		cout << ff[7] << endl;
	}
	return 0;
}