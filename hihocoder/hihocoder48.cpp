#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int modn = 142857;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> degree(n + 1, 0);
	vector<int> virus(n + 1, 0);
	vector<vector<int>> graph(n + 1,vector<int>());
	for (int i = 1;i <= k;++i)
	{
		int ai;
		cin >> ai;
		virus[ai] = 1;
	}
	for (int i = 1;i <= m;++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		degree[v]++;
	}
	queue<int> q;
	for (int i = 1;i <= n;++i)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (auto u : graph[v])
		{
			virus[u] = (virus[u] + virus[v])%modn;
			if (--degree[u] == 0)
				q.push(u);
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;++i)
		ans = (ans + virus[i])%modn;
	cout << ans << endl;
	return 0;
}