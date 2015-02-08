#include<stdio.h>
#include<stdlib.h>
#define N 26
typedef struct tnode{
	int isTerminal;
	struct tnode *p;
	struct tnode * son[N];
	struct tnode *next;
} trieNode;
typedef trieNode *triePtr;
typedef struct qnode{
	triePtr key;
	struct qnode * next;
} qNode;
typedef qNode *qPtr;
typedef struct qlist{
	qPtr front, back;
} qList;
typedef qList *qListPtr;
triePtr trieInsert(triePtr node, char * s);
void queuePushback(qListPtr q, triePtr key);
triePtr queuePopfront(qListPtr q);
void trieSolveNext(triePtr root);
int searchTrie(triePtr node, char *s);
int main()
{
	int m;
	char s[1000000];
	int temp;
	triePtr root = NULL;
	root = (triePtr)malloc(sizeof(trieNode));
	memset(root, 0, sizeof(trieNode));
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", s);
		trieInsert(root, s);
	}
	scanf("%s", s);
	trieSolveNext(root);
	temp = searchTrie(root, s);
	if (temp == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}

triePtr trieInsert(triePtr node, char * s)
{
	triePtr newNode;
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
		s++;
	}
	node->isTerminal = 1;
	return node;
}


void queuePushback(qListPtr q, triePtr key)
{
	qPtr newPtr;
	newPtr = (qPtr)malloc(sizeof(qNode));
	newPtr->key = key;
	newPtr->next = NULL;
	if ((*q).front == NULL)
	{
		(*q).front = (*q).back = newPtr;
	}
	else
	{
		(*q).back->next = newPtr;
		(*q).back = newPtr;
	}
}

triePtr queuePopfront(qListPtr q)
{
	triePtr newPtr;
	qPtr tempPtr;
	newPtr = (*q).front->key;
	tempPtr = (*q).front;
	(*q).front = tempPtr->next;
	free(tempPtr);
	return newPtr;
}


void trieSolveNext(triePtr root)
{
	int i;
	qList queue1;
	triePtr node;
	memset(&queue1, 0, sizeof(queue1));
	node = root;
	queuePushback(&queue1, node);
	node->next = node;
	while (queue1.front != NULL)
	{
		node = queuePopfront(&queue1);
		if (node->next->isTerminal == 1)
			node->isTerminal = 1;
		for (i = 0; i < N; i++)
		{
			if (node->son[i] != NULL)
			{
				queuePushback(&queue1, node->son[i]);
				if (node == root)
					node->son[i]->next = node;
				else
					node->son[i]->next = node->next->son[i];
			}
			else
			{
				if (node == root)
					node->son[i] = node;
				else
					node->son[i] = node->next->son[i];
			}
		}
	}
}

int searchTrie(triePtr node, char *s)
{
	while (*s)
	{
		if (node->isTerminal == 1)
			return 1;
		node = node->son[*s - 'a'];
		s++;
	}
	if (node->isTerminal == 1)
		return 1;
	else
		return 0;
}
