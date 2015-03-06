#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void postOrder(const string &str1, const string &str2);
int main()
{
	string str1, str2;
	//str1 = "ABDEGHCFIJ";
	//str2 = "DBGEHACIJF";

	cin >> str1 >> str2;
	postOrder(str1, str2);
	cout << endl;
	return 0;
}

void postOrder(const string &str1, const string &str2)
{
	if (str1.length()>1)
	{
		string str1L, str1R, str2L, str2R;
		int location = str2.find(str1[0]);
		str1L.assign(str1, 1, location);
		str1R.assign(str1, location + 1, str1.length() - 1);
		str2L.assign(str2, 0, location);
		str2R.assign(str2, location + 1, str2.length() - 1);
		postOrder(str1L, str2L);
		postOrder(str1R, str2R);
		cout << str1[0];
	}
	else if (str1.length()>0)
	{
		cout << str1[0];
	}
}
