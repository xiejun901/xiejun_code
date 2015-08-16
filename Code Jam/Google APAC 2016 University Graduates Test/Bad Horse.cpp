#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool check(const vector<vector<int>> &graph, int totalVertex)
{
	vector<int> color(totalVertex + 1, 0);
	vector<int> isVisit(totalVertex + 1, 0);
	stack<int> st;
	int i = 1;
	color[i] = 1;
	isVisit[i] = 1;
	st.push(i);
	while (!st.empty())
	{
		int p = st.top();
		st.pop();
		for (auto j : graph[p])
		{
			if (isVisit[j] && color[p] + color[j] != 0)
			{
				return false;
			}
			else
			{
				if (isVisit[j] == 0)
				{
					color[j] = 0 - color[p];
					isVisit[j] = 1;
					st.push(j);
				}
			}
		}
	}
	return true;
}


int main()
{
	int testNum;
	ifstream cin("A-small-2-attempt0.in");
	ofstream cout("A-small-2-attempt0.out");
	cin >> testNum;
	for (int t = 1; t <= testNum; ++t)
	{
		int m;
		int index = 1;
		cin >> m;
		map<string, int> nameMap;
		vector<vector<int>> graph(101,vector<int>());
		while (m--)
		{
			string name1, name2;
			cin >> name1 >> name2;
			if (nameMap.find(name1) == nameMap.end())
				nameMap[name1] = index++;
			int n1 = nameMap[name1];
			if (nameMap.find(name2) == nameMap.end())
				nameMap[name2] = index++;
			int n2 = nameMap[name2];
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}
		int totalVertex = index - 1;
		if (check(graph, totalVertex))
			cout << "Case #" << t << ": Yes" << endl;
		else
			cout << "Case #" << t << ": No" << endl;
	}
	return 0;
}

