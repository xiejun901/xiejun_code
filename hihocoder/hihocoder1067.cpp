#include<iostream>
#include<string>
#include<vector>
#define N 100007
#define gray 1
#define black -1
#define white 0
using namespace std;
const int hashn = 100003;
class HashNode{
public:
	HashNode():next(0){}
	int key;
	string str;
	HashNode *next;
	static int c;
};
int HashNode::c = 0;
HashNode *node[N];
struct TreeNode{
	int from;
	int color;
	int theLastSide;
};
struct TreeSide{
	int to;
	int next;
};
TreeNode treenode[N];
TreeSide treeside[N];
int queryTable1[N];
int queryTable2[N];
int reprent[N];
string hashToStringTable[N];
vector<int> queryTable[N];//queryTable[i]={j1,j2j3,j4}结点i相关的请求包括queryList[j1],queryList[j2],queryList[j3],queryList[j4]中;
pair<int, int> ask[N];//ask[i]表示第i个询问，存储是询问的两个结点。
int answer[N];
int hashget(string str);
int findReprent(int i);
void query(int i);
void dfs(int i);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int hs1, hs2;
		hs1 = hashget(str1);
		hs2 = hashget(str2);
		treeside[i].to = hs2;
		treeside[i].next = treenode[hs1].theLastSide;
		treenode[hs1].theLastSide = i;
		treenode[hs2].from = hs1;
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int hs1, hs2;
		hs1 = hashget(str1);
		hs2 = hashget(str2);
		ask[i]=make_pair(hs1, hs2);
		queryTable[hs1].push_back(i);
		queryTable[hs2].push_back(i);		
	}
	dfs(1);
	for (int i = 1; i <= m; i++)
		cout << hashToStringTable[answer[i]] << endl;
	return 0;
}

int hashget(string str)
{
	int h = 0;
	for (const auto &c : str)
	{
		h = h * 31 + c;
	}
	h &= 0x7fffffff;
	h = h%hashn;
	HashNode *newnode = node[h];
	while (newnode != nullptr)
	{
		if (newnode->str == str)
			break;
		else
			newnode = newnode->next;
	}
	if (newnode == nullptr)
	{
		newnode = new HashNode;
		newnode->key = ++(HashNode::c);
		newnode->next = node[h];
		newnode->str = str;
		node[h] = newnode;
		hashToStringTable[newnode->key] = str;
	}
//	delete newnode;
	return newnode->key;
}

void dfs(int i)
{
	//cout << i << endl;
	reprent[i] = i;
	treenode[i].color = gray;
	if (treenode[i].theLastSide)
	{
		int p = treenode[i].theLastSide;
		while (p != 0)
		{
			dfs(treeside[p].to);
			p = treeside[p].next;
		}
		//query(i);
		//cout << i << endl;
	}
	query(i);
	reprent[i] = treenode[i].from;
	treenode[i].color = black;
//	else
//	{
//		cout << i << endl;
//	}
	//treenode[i].color = black;
}


void query(int i)
{
	for (auto j : queryTable[i])
	{
		int theother = (i == ask[j].first ? ask[j].second : ask[j].first);
		if (treenode[theother].color == gray)
			answer[j] = theother;
		else if (treenode[theother].color == black)
			answer[j] = findReprent(theother);
	}
}
int findReprent(int i)
{
	if (i != reprent[i])
		reprent[i] = findReprent(reprent[i]);
	return reprent[i];
}