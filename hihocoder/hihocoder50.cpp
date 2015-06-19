#include<iostream>
#include<vector>
using namespace std;
struct Side {
	Side():v1(0),v2(0),is_connect(true){}
	void set_vertex(int i, int j) { v1 = i;v2 = j;is_connect = true; }
	int get_other_vertex(int i){
		if (i == v1)
			return v2;
		else
			return v1;
	}
	int v1, v2;
	bool is_connect;
};
void dfs(int i,const vector<vector<Side*>> &gra, vector<int> &ret);
int main() 
{
	int n, m;
	cin >> n >> m;
	vector<vector<Side *>> gra(n+1);
	vector<int> degree(n+1,0);
	vector<Side> sides(m);//×Ü¹²mÌõ±ß
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		sides[m].set_vertex(u, v);
		gra[u].push_back(&sides[m]);
		gra[v].push_back(&sides[m]);
		degree[u]++;
		degree[v]++;
	}
	int i;
	for (i = 1;i < n;++i)
	{
		if (degree[i] % 2)
			break;
	}
	vector<int> ret;
	dfs(i, gra, ret);
	for (auto i : ret)
		cout << i << ' ';
	cout << endl;
	return 0;
}
void dfs(int i, const vector<vector<Side*>> &gra, vector<int> &ret)
{
	for (auto g_side : gra[i])
	{
		if (g_side->is_connect)
		{
			g_side->is_connect = false;
			dfs(g_side->get_other_vertex(i), gra, ret);
		}
	}
	ret.push_back(i);
}