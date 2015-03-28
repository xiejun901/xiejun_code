#include<iostream>
#include<vector>
#define N 1000+1
#define INF 0x7fffffff
using namespace std;
struct GraphSide{
	GraphSide(int t, int w) :to(t), weight(w){};
	int to;
	int weight;
};
struct GraphVertex{
	int color;
	int index;
	int shortestPath;
};
int main()
{
	vector<GraphSide> side[N];
	GraphVertex vertex[N];
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, length;
		cin >> u >> v >> length;
		side[u].push_back(GraphSide(v, length));
		side[v].push_back(GraphSide(u, length));
	}
	for (int i = 1; i <= n; i++)
	{
		vertex[i].shortestPath = INF;
		vertex[i].index = i;
		vertex[i].color = 0;
	}
	vertex[s].shortestPath = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = 1;
		int min = INF;
		int u;
		while (j<=n)
		{
			if (vertex[j].color == 0)
			{
				if (vertex[j].shortestPath < min)
				{
					u = j;
					min = vertex[j].shortestPath;
				}
			}
			j++;
		}
		for (auto v : side[u])
		{
			if (v.weight + vertex[u].shortestPath < vertex[v.to].shortestPath)
				vertex[v.to].shortestPath = v.weight + vertex[u].shortestPath;
		}
		vertex[u].color = 1;
	}
	int temp = vertex[t].shortestPath;
	cout << temp << endl;
	return 0;
}