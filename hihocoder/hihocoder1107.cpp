#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;
typedef struct tnode
{
	struct tnode * son[26];
	int num;
}trieNode;
typedef trieNode *triePtr;

void trieInsert(triePtr root, char * s);
int trieDfs(triePtr root);
int main()
{
	int n;
	int temp;
	char s[20] ;
	triePtr root;
	root = (triePtr)malloc(sizeof(trieNode));
	memset(root, 0, sizeof(trieNode));
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		trieInsert(root, s);
	}
	temp = trieDfs(root);
	printf("%d", temp);
	return 0;

}

void trieInsert(triePtr root, char * s)
{
	triePtr node,newnode;
	node = root;
	while (*s)
	{
		if (node->son[*s - 'a'] == NULL)
		{
			newnode = (triePtr)malloc(sizeof(trieNode));
			memset(newnode, 0, sizeof(trieNode));
			node->son[*s - 'a'] = newnode;
		}
		node = node->son[*s - 'a'];
		node->num++;
		s++;
	}
}

int trieDfs(triePtr root)
{
	int i,count=0;
	triePtr node = root;
	stack<triePtr> stk;
	stk.push(node);
	while (!stk.empty())
	{
		node = stk.top();
		stk.pop();
		for (i = 25; i >= 0; i--)
		{
			if (node->son[i] != NULL)
			{
				if (node->son[i]->num <= 5)
					count++;
				else
					stk.push(node->son[i]);
			}
		}
	}
	return count;
}