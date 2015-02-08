#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000100
using namespace std;
int Min(int a, int b);
int main()
{
	int n;
	int len;
	int maxl;
	//string s1;
	char s1[MAXN];
	char s[2 * MAXN];
	int i, j, id, maxid;
	int p[2 * MAXN];
	scanf("%d", &n);
	while (n--)
	{
		//p[0] = 1;
		//		cin >> s1;
		maxl = 0;
		scanf("%s", s1);
		//		length=s1.length();
		len = strlen(s1);
		s[0] = '$';
		for (i = 0; i < len; i++)
		{
			s[(i << 1) + 1] = '#';
			s[(i << 1) + 2] = s1[i];
		}
		s[2 * i + 1] = '#';
		s[2 * i + 2] = 0;
		len = 2 * len + 2;
		id = 0;
		maxid = 0;
		for (i = 1; i < len; i++)
		{
			if (maxid>i)
				j = Min(maxid - i, p[(id << 1) - i]);
			else
				j = 1;
			while (s[i - j] == s[i + j])
				j++;
			if (i + j >= maxid)//是记录maxid扩展到右边最远处而不是记录P[i]最大的ID和maxid。 随然都能算，但是因为效率不同啊！！！
			{
				maxid = i + j;
				id = i;
			}
			p[i] = j;
			if (p[i]>maxl)
				maxl = p[i];

		}
		//	cout << maxid-id-1<< endl;
		printf("%d\n", maxl - 1);

	}
	return 0;

}

int Min(int a, int b)
{
	return a < b ? a : b;
}