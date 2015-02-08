#include<stdio.h>
#include<stdlib.h>
typedef struct tnode{
	int key;
	struct tnode *p;
	struct tnode *left;
	struct tnode *right;
} treeNode;
typedef treeNode *treePtr;
treePtr treeAdd(treePtr node,int key);
treePtr treeAddIteration(treePtr root,int key);
void inorder_tree_walk(treePtr node);
treePtr tree_search(treePtr node,int key);
void tree_print(treePtr node);
treePtr tree_minimum(treePtr node);
treePtr tree_minimumIteration(treePtr node);
treePtr tree_maxmum(treePtr node);
treePtr tree_maxmumIteration(treePtr node);
treePtr tree_successor(treePtr node);
treePtr tree_predecessor(treePtr node);
void tree_delete(treePtr root,treePtr node);
int main()
{
	int n;
	int i;
	int key;
	treePtr root=NULL;
	treePtr node=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		root=treeAddIteration(root,key);
	}
	inorder_tree_walk(root);
	printf("\ninput the searched key:");
	scanf("%d",&key);
	tree_print(node=tree_search(root,key));
	printf("递归方式的求最小值输出：");
	tree_print(tree_minimum(root));
	printf("迭代方式的求最小值输出：");
	tree_print(tree_minimumIteration(root));
	printf("递归方式的求最大值输出：");
	tree_print(tree_maxmum(root));
	printf("迭代方式的求最大值输出：");
	tree_print(tree_maxmumIteration(root));
	printf("successor:");
	tree_print(tree_successor(tree_search(root,key)));
	printf("predecessor:");
	tree_print(tree_predecessor(tree_search(root,key)));
	tree_delete(root,node);
	inorder_tree_walk(root);

}

treePtr treeAdd(treePtr node,int key)
{
	if(node==NULL)
	{
		node=(treePtr)malloc(sizeof(treeNode));
		node->key=key;
		node->left=NULL;
		node->right=NULL;
		node->p=NULL;
	}
	else if(key<node->key)
	{
		node->left=treeAdd(node->left,key);
		node->left->p=node;
	}
	else
	{
		node->right=treeAdd(node->right,key);
		node->right->p=node;
	}
	return node;
}

treePtr treeAddIteration(treePtr root,int key)
{
	treePtr y=NULL;
	treePtr x=root;
	while(x!=NULL)
	{
		y=x;
		if(key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	x=(treePtr)malloc(sizeof(treeNode));
	x->key=key;
	x->left=NULL;
	x->right=NULL;
	x->p=y;
	if(y==NULL)
	{
		root=x;
	}
	else
	{
		if(key<y->key)
			y->left=x;
		else
			y->right=x;
	}
	return root;
}

void inorder_tree_walk(treePtr node)
{
	if(node!=NULL)
	{
		inorder_tree_walk(node->left);
		//printf("%d,",node->key);
		tree_print(node);
		inorder_tree_walk(node->right);
	}
}

treePtr tree_search(treePtr node,int key)
{
	if(node==NULL || node->key==key)
		return node;
	else if(key<node->key)
		return tree_search(node->left,key);
	else
		return tree_search(node->right,key);
}

void tree_print(treePtr node)
{
	//printf("the key of the node is:%d\n",node->key);
	//printf("the parrent of the node is:%p\n",node->p);
	//printf("the left son of the node is:%p\n",node->left);
	//printf("the right son of the node is:%p\n",node->right);
	printf("%5d",node->key);
	printf("%12p",node);
	printf("%12p",node->p);
	printf("%12p",node->left);
	printf("%12p\n",node->right);

}
treePtr tree_minimum(treePtr node)
{
	if(node->left!=NULL)
		return tree_minimum(node->left);
	else
		return node;
}
treePtr tree_minimumIteration(treePtr node)
{
	while(node->left!=NULL)
		node=node->left;
	return node;
}
treePtr tree_maxmum(treePtr node)
{
	if(node->right!=NULL)
		return tree_maxmum(node->right);
	else
		return node;
}
treePtr tree_maxmumIteration(treePtr node)
{
	while(node->right!=NULL)
		node=node->right;
	return node;
}

treePtr tree_successor(treePtr node)
{
	if(node->right!=NULL)
		return tree_minimum(node->right);
	else
	{
		while(node->p->p!=NULL && node->p->right==node)
			node=node->p;
		return node->p;
	}
}

treePtr tree_predecessor(treePtr node)
{
	if(node->left!=NULL)
		return tree_maxmum(node->left);
	else
	{
		while(node->p!=NULL && node->p->left==node)
			node=node->p;
		return node->p;
	}
}

void tree_delete(treePtr root,treePtr node)
{
	treePtr y=NULL;
	treePtr x=NULL;
	if(node->left == NULL || node->right ==NULL)
		y=node;
	else
		y=tree_successor(node);
	if(y->left!=NULL)
		x=y->left;
	else
		x=y->right;
	if(x!=NULL)
		x->p=y->p;
	if(y->p==NULL)
	{
		root=x;
	}
	else
	{
		if(y==y->p->left)
			y->p->left=x;
		else
			y->p->right=x;
	}
	if(y!=node)
		node->key=y->key;
	free(y);
	
}
