#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> graphV(n+1,vector<int>());
		vector<int> deg(n + 1,0);
		for (int i = 1;i <= m;++i)
		{
			int a, b;
			cin >> a >> b;
			graphV[a].push_back(b);
		}
		for (int i = 1;i <= n;++i)
		{
			for (auto s : graphV[i])
			{
				deg[s]++;
			}
		}
		queue<int> q;
		for (int i = 1;i <= n;++i)
		{
			if (deg[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int k = q.front();
			q.pop();
			for (auto s : graphV[k])
			{
				if (deg[s] == 0)
					continue;
				if (--deg[s] == 0)
					q.push(s);
			}
		}
		bool flag=true;
		for (int i = 1;i <= n;++i)
		{
			if (deg[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Correct" << endl;
		else
			cout << "Wrong" << endl;
	}
	return 0;
}