#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#define red   0
#define black 1
using namespace std;
typedef struct tnode{
	struct tnode *left;
	struct tnode *right;
	struct tnode *p;
	int color;
	int key;
} treeNode;
typedef treeNode *treePtr;
typedef struct rbtree{
	treePtr root;
	treePtr NIL;
} tree;
tree leftRotation(tree t, treePtr x);
tree rightRotation(tree t, treePtr x);
tree treeInsert(tree t, treePtr z);
void rbInsertFix(tree t, treePtr z);
tree treeInitial(tree t1);
void treeBfs(tree t);
void treePtrPrint(treePtr node);
treePtr treeMinimum(tree t ,treePtr);
int main()
{
	tree t1;
	int a[20] = { 26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39, 3 };
	treePtr node[20];
	int i;
	t1.NIL = (treePtr)malloc(sizeof(treeNode));
	memset(t1.NIL, 0, sizeof(treeNode));
	t1.root = t1.NIL;
	t1.NIL->color = black;
	//////////////
	for (i = 0; i < 20; i++)
	{
		node[i] = (treePtr)malloc(sizeof(treeNode));
		memset(node[i], 0, sizeof(treeNode));
		node[i]->key = a[i];
		t1 = treeInsert(t1, node[i]);
	}
	////////////////////
	treePtrPrint(treeMinimum(t1,t1.root));
	treeBfs(t1);
	return 0;
}

tree treeInitial(tree t1)
{
	int a[20] = { 26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39,3 };
	treePtr node[20];
	int i;
	for (i = 0; i < 20; i++)
	{
		node[i] = (treePtr)malloc(sizeof(treeNode));
		memset(node[i], 0, sizeof(treeNode));
		node[i]->key = a[i];
		t1 = treeInsert(t1, node[i]);
	}
	return t1;
}

tree leftRotation(tree t, treePtr x)
{
	treePtr y = x->right;
	x->right = y->left;
	y->left->p = x;
	y->p = x->p;
	if (x->p == t.NIL)
		t.root = y;
	else
	{
		if (x == x->p->right)
			x->p->right=y;
		else
			x->p->left=y;
	}
	x->p = y;
	y->left = x;
	return t;
}

tree rightRotation(tree t, treePtr x)
{
	treePtr y = x->left;
	x->left = y->right;
	y->right->p = x;
	y->p = x->p;
	if (x->p == t.NIL)
		t.root = y;
	else
	{
		if (x == x->p->left)
			x->p->left = y;
		else
			x->p->right = y;

	}
	x->p = y;
	y->right = x;
	return t;
}

tree treeInsert(tree t, treePtr z)
{
	treePtr newnode=t.NIL;
	treePtr node = t.root;
	while (node != t.NIL)
	{
		newnode = node;
		if (z->key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	if (newnode == t.NIL)
		t.root = z;
	else
	{
		if (z->key < newnode->key)
			newnode->left = z;
		else
			newnode->right = z;
	}
	z->p = newnode;
	z->left = t.NIL;
	z->right = t.NIL;
	z->color = red;
	rbInsertFix(t, z);
	return t;
}

void rbInsertFix(tree t, treePtr z)
{
	while (z->p->color == red)
	{
		if (z->p == z->p->p->left)
		{
			if (z->p->p->right->color == red)
			{
				z->p->color = black;
				z->p->p->right->color = black;
				z->p->p->color = red;
				z = z->p->p;
			}
			else
			{
				if (z == z->p->right)
				{
					z = z->p;
					leftRotation(t, z);
				}
				z->p->color = black;
				z->p->p->color = red;
				rightRotation(t, z->p->p);
			}
		}
		else
		{
			if (z->p->p->left->color == red)
			{
				z->p->color = black;
				z->p->p->left->color = black;
				z->p->p->color = red;
				z = z->p->p;
			}
			else
			{
				if(z = z->p->left)
				{
					z = z->p;
					rightRotation(t, z);
				}
				z->p->color = black;
				z->p->p->color = red;
				leftRotation(t, z);
			}
		}
	}
	t.root->color = black;
}

void treeBfs(tree t)
{
	queue<treePtr> q1;
	treePtr node = t.root;
	q1.push(node);
	while (!q1.empty())
	{
		node = q1.front();
		q1.pop();
		if (node->left != t.NIL)
			q1.push(node->left);
		if (node->right != t.NIL)
			q1.push(node->right);
		printf("%p,%4d,%4d,\n", node, node->key, node->color);
	}
}

void treePtrPrint(treePtr node)
{
	printf("pointer:%p,parent:%p,left son:%p,right son:%p,key:%3d,color:%2d\n:", node, node->p, node->left, node->right, node->key, node->color);
}
treePtr treeSuccessor(tree t, treePtr z)
{
	if (z->right != t.NIL)
		return treeMinimum(t, z->right);
	return 0;
}

treePtr treeMinimum(tree t,treePtr node)
{
	while (node->left != t.NIL)
		node = node->left;
	return node;
}

