#include<stdio.h>
#include<stdlib.h>
typedef struct tnode{
	int isTerminal;
	int num;
	struct tnode *p;
	struct tnode * son[26];
} trieNode;
typedef trieNode *triePtr;
triePtr trieInsert(triePtr node, char * s);
int prefixCount(triePtr node, char *s);

int main()
{
	int m;
	char s[12];
	triePtr root = NULL;
	root = (triePtr)malloc(sizeof(trieNode));
	memset(root, 0, sizeof(trieNode));
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", s);
		trieInsert(root, s);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", s);
		printf("%d\n", prefixCount(root, s));
	}
	
	return 0;
}

triePtr trieInsert(triePtr node, char * s)
{
	triePtr newNode;
	int i;
	while (*s)
	{
		if (node->son[*s - 'a'] == NULL)
		{
			newNode = (triePtr)malloc(sizeof(trieNode));
			memset(newNode, 0, sizeof(trieNode));
			newNode->p = node;
			node->son[*s - 'a'] = newNode;
		}
		node = node->son[*s - 'a'];
		node->num++;
		s++;
	}
	node->isTerminal = 1;
}
int prefixCount(triePtr node, char *s)
{
	while (*s)
	{
		if (node->son[*s - 'a'] == NULL)
			return 0;
		node = node->son[*s - 'a'];
		s++;
	}
	return node->num;
}