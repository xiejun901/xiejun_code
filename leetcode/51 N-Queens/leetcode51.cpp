#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		if (n == 1)
			return(vector<vector<string>>(1, vector<string>(1, "Q")));
		vector<vector<string>> ret;
		vector<int> row(n,0);
		for (int i = 0;i < n;++i)
		{
			row[0] = i;
			gotRow(1,row,ret);
		}
		return ret;
	}
	void gotRow(int k, vector<int> &row, vector<vector<string>> &ret)
	{
		for (int i = 0;i < row.size();++i)
		{
			if (isValid(k, i,row))
			{
				row[k] = i;
				if (k == row.size() - 1)
				{
					vector<string> temp(row.size(), string(row.size(), '.'));
					for (int mm = 0;mm < row.size();++mm)
					{
						temp[mm][row[mm]] = 'Q';
					}
					ret.push_back(temp);
				}
				else
				{
					gotRow(k + 1,row,ret);
				}
			}
		}
	}
	bool isValid(int row_, int col_,const vector<int>& row)
	{
		for (int i = 0;i < row_;++i)
		{
			if (row[i] == col_ || (abs(row_ - i) == abs(col_ - row[i])))
				return false;
		}
		return true;
	}
};
int main()
{
	Solution s;
	auto ans = s.solveNQueens(4);
	return 0;
}