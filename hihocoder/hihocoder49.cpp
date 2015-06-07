#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<int> degree(n + 1, 0);
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		++degree[u];
		++degree[v];
	}
	vector<int> is_visit(n + 1, 0);
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		is_visit[k] = 1;
		for (auto vi : graph[k])
		{
			if (is_visit[vi] == 0)
				q.push(vi);
		}
	}
	int odd_nums = 0;
	bool is_connect = true;
	for (int i = 1;i <= n;++i)
	{
		if (degree[i] % 2)
			odd_nums++;
		if (is_visit[i] == 0)
		{
			is_connect = false;
			break;
		}
	}
	if ((odd_nums <= 2) && is_connect)
		cout << "Full" << endl;
	else
		cout << "Part" << endl;
	return 0;
}