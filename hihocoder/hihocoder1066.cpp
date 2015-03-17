#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#define NHASH 100003
#define N NHASH
using namespace std;
map<string, int> map1;
int c=0;
int hasht(const string &str);
int reprent[N];
int findReprent(int i);
int hashtt(const string &str);
struct Hashnode{
	int index;
	string str;
	Hashnode *next;
};
Hashnode *node[N];
int main()
{
	int n;
	for (int i = 0; i < N; i++)
		reprent[i] = i;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int op;
		string s1, s2;
//		int hs1, hs2;
		cin >> op >> s1 >> s2;
		int hs1 = hasht(s1);
		int hs2 = hasht(s2);
		if (op == 0)
		{
			reprent[findReprent(hs1)] = findReprent(hs2);
		}
		else
		{
			if (findReprent(hs1) == findReprent(hs2))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}
int hasht(const string &str)
{
	int h = 0;
	for (auto ch : str)
	{
		h = h * 31 + ch;
	}
	h = h & 0x7fffffff;
	h=h%NHASH;
	Hashnode *newnode = node[h];
	while (newnode != nullptr)
	{
		if (str == newnode->str)
			return newnode->index;
		else
			newnode = newnode->next;
	}
	newnode = new Hashnode;
	newnode->index = ++c;
	newnode->next = node[h];
	newnode->str = str;
	node[h] = newnode;
	return c;
}
int hashtt(const string &str)
{
	if (map1[str] == 0)
		map1[str] = ++c;
	return map1[str];
}
int findReprent(int i)
{
	if (reprent[i] != i)
		reprent[i] = findReprent(reprent[i]);
	return reprent[i];	
}