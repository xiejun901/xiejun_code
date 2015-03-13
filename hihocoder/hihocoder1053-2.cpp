#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100002
pair<long long, long long> p1[N], p2[N];
int n;
long long r;
int check(int key);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> r;
		for (int i = 1; i <= n; i++)
			cin >> p1[i].first >> p1[i].second;
		sort(p1 + 1, p1 + n + 1);
		int low = 0;
		int high = 1000000000;
		int mid = (low + high) / 2;
		while (low < high)
		{
			int temp = check(mid);
			if (temp)
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
			mid = (low + high) / 2;
		}
		cout << low << endl;
	}
	return 0;
}

int check(int key)
{
	queue<pair<int, int>> excess, less;
	for (int i = 1; i <= n; i++)
	{
		p2[i] = p1[i];
	}
	for (int i = 1; i <= n; i++)
	{
		while ((!less.empty()) && ((p2[i].first - less.front().first) > r))
			less.pop();
		//while ((!excess.empty()) && (excess.front().second == 0))
			//excess.pop();
		while ((!excess.empty()) && ((p2[i].first - excess.front().first) > r))
			return 0;
		long long total = 0;//������Ҫת�Ƶ�i����ܹ������������ֵ��ת��key����Ϊʲô�أ���Ϊ�������key������i��λ�õľ����������ˣ�����ζ�ų������ǲ����Ժ�Ҫ��i���λ�ü��������ߣ���ô�����е�һЩ���ߵ�·�̾ͻᳬ��r
		while ((!excess.empty()) && total < key)
		{
			if (total + excess.front().second <= key)
			{
				total += excess.front().second;
				excess.pop();
			}
			else
			{
				excess.front().second = excess.front().second - (key - total);
				total = key;
				break;
			}
		}
		while ((!less.empty()) && p2[i].second)
		{
			if (p2[i].second >= less.front().second)
			{
				p2[i].second -= less.front().second;
				less.pop();
			}
			else
			{
				less.front().second = less.front().second - p2[i].second;
				p2[i].second = 0;
				break;
			}
		}
		//���iλ�õ�����������Ҫת�Ƶ�iλ�õ������պ�Ϊkey��������ж���һ����
		if (total + p2[i].second == key)
			continue;
		else if (total + p2[i].second < key)
		{
			//ǰ�滹�й����ģ����ҵ�ǰλ�ü���ת�ƹ����Ĳ��ᳬ��key
			while ((!excess.empty()) && (total + p2[i].second < key))
			{
				if (excess.front().second + total + p2[i].second>key)
				{
					excess.front().second = excess.front().second - (key - total - p2[i].second);
					p2[i].second = key;
					break;
				}
				else
				{
					p2[i].second = p2[i].second + excess.front().second;
					excess.pop();
				}
			}
			if (p2[i].second < key)
				less.push(make_pair(p2[i].first, key - p2[i].second - total));
		}
		else
		{
			excess.push(make_pair(p2[i].first, p2[i].second + total - key));
		}
	}
	if (!excess.empty())
		return 0;
	else
		return 1;
}