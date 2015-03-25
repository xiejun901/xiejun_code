#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 10000+1
#define M 100000+1
using namespace std;
struct graphSide{
	int to;
	int weight;
};
vector<graphSide> node[N];
int n, m, k, t;
int bfs(int root, int value);
int main()
{
	//cin >> n >> m >> k >> t;
	scanf("%d%d%d%d", &n, &m, &k, &t);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
	//	cin >> u >> v >> w;
		scanf("%d%d%d", &u, &v, &w);
		graphSide side;
		side.to = v;
		side.weight = w;
		node[u].push_back(side);
		side.to = u;
		node[v].push_back(side);
	}
	int low = 0, high = 1000000;
	while (low + 1 < high)
	{
		int mid = (low + high) / 2;
		if (bfs(1, mid))
			high = mid;
		else
			low = mid;
	}
	//cout << high << endl;
	printf("%d\n", high);
	return 0;
}
int bfs(int root, int value)
{
	//pair.first 保存结点信息，pair.second保存层信息.
	queue<pair<int,int>> que;
	int color[N] = { 0 };
	que.push(make_pair(root,0));
	color[root] = 1;
	while (!que.empty())
	{
		pair<int,int> p = que.front(); 
		que.pop();
		if (p.first == t)
			return 1;
		if (p.second >= k)
			continue;
		for (auto mem : node[p.first])
		{
			if (mem.weight <= value&&color[mem.to] == 0)
			{
				que.push(make_pair(mem.to, p.second + 1));
				color[mem.to] = 1;
			}
		}
	}
	return 0;
}