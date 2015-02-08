#include <iostream>
#include <string>
using namespace std;
void getnext(string s, int * next);
int main()
{
	string s;
	string p;
	int n;
	int i, j, count;
	cin>>n;
	while (n--)
	{
		cin >> p >> s;
		int * next = new int[p.length()];
		getnext(p, next);
		i = 0;
		j = 0;
		count = 0;
		while (i < s.length())
		{
			while (j != 0 && s[i] != p[j])
			{
				j = next[j - 1];
			}
			if (s[i] == p[j])
			{
				if (j == p.length() - 1)
				{
					j = next[j]; 
					count++;
				}
				else
					j++;
			}
			i++;
		}
		cout << count << endl;


	}
	return 0;


}
void getnext(string s, int * next)
{

	next[0] = 0;
	int i = 1;
	int j = 0;
	while (i < s.length())
	{
		while ((j != 0) && (s[i] != s[j]))
			j = next[j-1];
		if (s[i] == s[j])
			j++;
		next[i] = j;
		i++;
	}

}