#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream cin("C-small-2-attempt0.in");
	ofstream cout("C-small-2-attempt0.out");
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; ++t)
	{
		int n;
		cin >> n;
		string maximum;
		int result = 0;
		cin.get();
		for (int i = 0; i < n; ++i)
		{
			string name;
			getline(cin, name);
			if (name < maximum)
				result++;
			else
				maximum = name;
		}
		cout << "Case #" << t << ": "<<result << endl;
	}
	return 0;
}