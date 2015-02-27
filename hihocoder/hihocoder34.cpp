#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define N 10+1
#define M 10+1
#define gray 0
#define black 1
#define white 0
using namespace std;
int vertex[N] = { 0 };
int match[N] = { 0 };
int visit[N] = { 0 };
vector<int> adjList[N];
int n, m;
void insertSide(int u, int v);
void drawColor();
int findPath(int u);
int main()
{
	cin >> n>>m;
	int u, v;
	int count=0;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		insertSide(u, v);
	}
	drawColor();
	for (int i = 1; i <= n; i++)
	{
		if (vertex[i] == black)
		{
			memset(visit, 0, sizeof(visit));
			count += findPath(i);

		}
	}
	cout << count << endl;
	return 0;

}

void insertSide(int u, int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
void drawColor()
{
	memset(vertex, 0, sizeof(vertex));
	for (int i = 1; i <= n; i++)
	{
		if (vertex[i] == gray)
		{
			vertex[i] = black;
			queue<int> q;
			q.push(i);
			while (!q.empty())
			{
				int index = q.front();
				q.pop();
				for (vector<int>::iterator iter = adjList[index].begin(); iter != adjList[index].end(); ++iter)
				{
					if (vertex[*iter] == gray)
					{
						q.push(*iter);
						vertex[*iter] = 0 - vertex[index];
					}
				}
			}			
		}
	}
}
int findPath(int u)
{
	for (vector<int>::iterator iter = adjList[u].begin(); iter != adjList[u].end(); ++iter)
	{
		if (!visit[*iter])
		{
			visit[*iter] = 1;
			if (findPath(match[*iter])||match[*iter] == 0)
			{
				match[u] = *iter;
				match[*iter] = u;
				return 1;
			}
		}
	}
	return 0;
}