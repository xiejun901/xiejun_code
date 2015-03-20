#include<iostream>
#include<string>
#define N 5+1
#define HASHN 100003
using namespace std;

struct TreeNode{
	int layer;
	int theLastSide;
};
struct TreeSide{
	int to;
	int nextSide;
};
struct HashNode{
	string str;
	static int c;
	int key;
	HashNode *next;
};
int HashNode::c = 0;
HashNode *hashnode[HASHN];
TreeSide side[N];//保存父子关系的树的边
TreeNode node[N];//保存父子关系的树的结点
int treeToArray[2 * N];//保存树转化成的数组，数组中的内容为层数；
int treeNodeToArray[N];//保存结点最后一次出现对应到数组中的序列，treeNodeToArray[3]=7表示结点3最后一次出现在数组的第七个位置。
int treeToArrayIndex = 0;
int arrayLength;
int segTreeNode[6 * N];
string hashKeyToString[N];
void dfs(int root);
void buildSegTree(int root, int start, int end);
int querySegTree(int root, int start, int end, int qstart, int qend);
int queryCommonAncestor(int root, int start, int end, int node1, int node2);
int hashget(string str);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int from = hashget(str1);
		int to = hashget(str2);
		//cin >> from >> to;
		side[i].to = to;
		side[i].nextSide = node[from].theLastSide;
		node[from].theLastSide = i;
		node[to].layer = node[from].layer + 1;
	}
	dfs(1);
	arrayLength = treeToArrayIndex;
	buildSegTree(1, 1, arrayLength);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int hashStr1 = hashget(str1);
		int hashStr2 = hashget(str2);
		int ancestor=queryCommonAncestor(1, 1, arrayLength, hashStr1, hashStr2);
		cout << hashKeyToString[ancestor]<<endl;
	}
	return 0;
}
void dfs(int root)
{
	if (node[root].theLastSide)
	{
		treeToArray[++treeToArrayIndex] = root;
		int p = node[root].theLastSide;
		while (p)
		{
			dfs(side[p].to);
			p = side[p].nextSide;
			treeToArray[++treeToArrayIndex] = root;
			treeNodeToArray[root] = treeToArrayIndex;
		}
		
	}
	else
	{
		treeToArray[++treeToArrayIndex] = root;
		treeNodeToArray[root] = treeToArrayIndex;
	}
}

void buildSegTree(int root, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		buildSegTree(2 * root, start, mid);
		buildSegTree(2 * root + 1, mid + 1, end);
		if (node[segTreeNode[2 * root]].layer < node[segTreeNode[2 * root + 1]].layer)
			segTreeNode[root] = segTreeNode[2 * root];
		else
			segTreeNode[root] = segTreeNode[2 * root+1];
	}
	else
	{
		segTreeNode[root] = treeToArray[start];
	}
}
int querySegTree(int root, int start, int end, int qstart, int qend)
{
	if (qstart == start&&qend == end)
		return segTreeNode[root];
	int mid = (start + end) / 2;
	if (qend <= mid)
		return querySegTree(root * 2, start, mid, qstart, qend);
	else if (qstart > mid)
		return querySegTree(root * 2 + 1, mid + 1, end, qstart, qend);
	else
	{
		int leftreturn = querySegTree(root * 2, start, mid, qstart, mid);
		int rightreturn = querySegTree(root * 2+1,mid+1,end, mid+1,qend);
		if (node[leftreturn].layer < node[rightreturn].layer)
			return leftreturn;
		else
			return rightreturn;
	}
	//感觉好像没考虑下面两段结点层数都一样的情况
}

int queryCommonAncestor(int root,int start,int end, int node1, int node2)
{
	int qstart = treeNodeToArray[node1] < treeNodeToArray[node2] ? treeNodeToArray[node1] : treeNodeToArray[node2];
	int qend   = treeNodeToArray[node1] > treeNodeToArray[node2] ? treeNodeToArray[node1] : treeNodeToArray[node2];
	return querySegTree(root, start, end, qstart, qend);
}

int hashget(string str)
{
	int h = 0;
	for (auto ch : str)
	{
		h = h * 1331 + ch;
	}
	h = h & 0x7fffffff;
	h = h%HASHN;
	HashNode *newhashnode;
	newhashnode = hashnode[h];
	while (newhashnode != nullptr)
	{
		if (newhashnode->str == str)
			break;
		else
			newhashnode = newhashnode->next;
	}
	if (newhashnode == nullptr)
	{
		newhashnode = new HashNode;
		newhashnode->key = ++(HashNode::c);
		newhashnode->next = hashnode[h];
		newhashnode->str = str;
		hashnode[h] = newhashnode;
		hashKeyToString[HashNode::c] = str;
	}
	return newhashnode->key;
}


//难得的一起提交就accept啊~~ 点个赞~