#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int n;
	map<string, string> map1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		map1[str2] = str1;
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		map<string, int> map2;
		string str1, str2;
		cin >> str1 >> str2;
		map2[str1] = 1;
		while (map1[str1]!="")
		{
			str1 = map1[str1];
			map2[str1] = 1;
		}
		while (map2[str2] == 0 && map1[str2] != "")
		{
			str2 = map1[str2];
		}
		if (map2[str2] == 1)
			cout << str2 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
		
}
	