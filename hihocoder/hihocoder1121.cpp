#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define M 40000
#define N 10000
#define gray 0
#define black 1
#define white -1
int bfsGraph(int(&vertex)[N + 1], std::vector<int>(&vec)[N + 1], int k);
int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n, m;
		int u, v;
		int flag = 1;
		std::vector<int> vec[N + 1];
		int vertex[N + 1];
		std::memset(vertex, 0, sizeof(vertex));
		std::cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			std::cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (vertex[i] == gray)
			{
				if (!bfsGraph(vertex, vec, i))
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			std::cout << "Correct" << std::endl;
		else
			std::cout << "Wrong" << std::endl;
	}
	return 0;
}
int bfsGraph(int(&vertex)[N + 1], std::vector<int>(&vec)[N + 1], int k)
{
	std::queue<int> q;
	int index = k;
	vertex[index] = black;
	q.push(k);
	while (!q.empty())
	{
		index = q.front();
		q.pop();
		for (std::vector<int>::iterator iter = vec[index].begin(); iter != vec[index].end(); ++iter)
		{
			if (vertex[*iter] == gray)
			{
				vertex[*iter] = 0 - vertex[index];
				q.push(*iter);
			}
			else
			{
				if (vertex[*iter] + vertex[index] != 0)
					return 0;
			}
		}
	}
	return 1;
}