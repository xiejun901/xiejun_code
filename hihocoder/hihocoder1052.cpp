#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int sum = 0;
		string str1;
		int k;
		cin >> str1;
		cin >> k;
		int length = str1.length();
		int dist = length - k;
		for (int j = 0; j < dist&&j<k; j++)
		{
			unordered_map<char, int> map1;
			for (int i = j; i<length;i+=dist)
				map1[str1[i]] ++;
			int temp = 0;
			for (unordered_map<char, int>::iterator iter = map1.begin(); iter != map1.end(); ++iter)
			{
				if (iter->second>temp)
					temp = iter->second;
				sum += iter->second;
			}
			sum -= temp;
		}
		cout << sum << endl;
	}
	return 0;
}