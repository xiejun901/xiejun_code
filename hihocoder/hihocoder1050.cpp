#include<cstdio>
using namespace std;
#define N 100000+1
struct TreeSide{
	int to;
	int next;
};
TreeSide side[N];
int header[N];
int n,maxlength;
int dfs(int i);
int main()
{
	scanf("%d", &n);
	int from, to;
	for (int i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &from, &to);
		side[i].to = to;
		side[i].next = header[from];
		header[from] = i;
	}
	dfs(1);
	printf("%d\n",maxlength);
	return 0;

}

int dfs(int i)
{
	int first=0, second=0,length=0;
	int p = header[i];
	while (p != 0)
	{
		length=dfs(side[p].to)+1;
		if (length > first)
		{
			second = first;
			first = length;
		}
		else if (length > second)
		{
			second = length;
		}
		p = side[p].next;
	}
	if (maxlength < first + second)
		maxlength = first + second;
	return first;
	
}