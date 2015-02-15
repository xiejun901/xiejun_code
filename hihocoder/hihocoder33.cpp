#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;
#define N 40010
#define black 1
#define white -1
#define gray 0
typedef struct graphvertex{
	int color;
	int var;
	struct graphvertex *next;
}vertex;
typedef vertex *vertexPtr;
void insertSide(vertexPtr v, vertexPtr s);
int graphBfs(vertexPtr ver[N], int k);
int main()
{
	vertexPtr ver[N];
	vertexPtr s;
	int task;
	int n, m;
	int i;
	int c, v;
	int temp;
	scanf("%d", &task);
	while (task--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= m; i++)
		{
			ver[i] = (vertexPtr)malloc(sizeof(vertex));
			ver[i]->color = gray;
			ver[i]->next = NULL;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &c, &v);
			s = (vertexPtr)malloc(sizeof(vertex));
			s->var = v;
			s->next = NULL;
			insertSide(ver[c], s);
			s = (vertexPtr)malloc(sizeof(vertex));
			s->var = c;
			s->next = NULL;
			insertSide(ver[v], s);
		}
		temp = 1;
		for (i = 1; i <= m; i++)
		{

			if (ver[i]->color == gray)
				temp = temp*graphBfs(ver, i);
		}
		if (temp)
			printf("Correct\n");
		else
			printf("Wrong\n");
	}


	return 0;
}

void insertSide(vertexPtr v, vertexPtr s)
{
	while (v->next != NULL)
		v = v->next;
	v->next = s;
}
int graphBfs(vertexPtr ver[N], int k)
{
	queue<int> q;
	int order = k;
	vertexPtr v;
	q.push(order);
	while ((!q.empty()))
	{
		order = q.front();
		q.pop();
		if (ver[order]->color == gray)
			ver[order]->color = black;
		v = ver[order]->next;
		while (v != NULL)
		{
			if (ver[v->var]->color == gray)
			{
				ver[v->var]->color = 0 - ver[order]->color;
				q.push(v->var);
			}
			else
			{
				if (ver[v->var]->color + ver[order]->color != 0)
					return 0;
			}
			v = v->next;
		}
	}
	return 1;
}