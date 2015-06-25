#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct Side {
	Side():from(0),to(0),isConnect(true){}
	int from;
	int to;
	bool isConnect;
};

void dfs(int i, vector<vector<Side*>> &vertesSide, vector<int> &ret)
{
	for (auto side : vertesSide[i])
	{
		if (side->isConnect)
		{
			side->isConnect = false;
			dfs(side->to, vertesSide,ret);
		}
	}
	ret.push_back(i);
}
int main()
{
	int n;
	scanf("%d", &n);
	int numVertex = pow(2, n - 1);//定点数量
	int numSide = pow(2, n);//边的数量
	vector<vector<Side*>> vertesSide(numVertex, vector<Side*>());
	vector<Side> sides(numSide,Side());
	for (int i = 0;i < numSide;++i)
	{
		sides[i].from = i / 2;
		sides[i].to = i&(~(1 << (n - 1)));
		vertesSide[sides[i].from].push_back(&sides[i]);
	}
	vector<int> ret;
	dfs(0, vertesSide, ret);
	ret.pop_back();
	for (auto iter = ret.rbegin();iter != ret.rend();++iter)
	{
		printf("%d", (*iter)&1);
	}
	printf("\n");
}