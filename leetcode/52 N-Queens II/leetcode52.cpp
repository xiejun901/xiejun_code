class Solution {
public:
    int totalNQueens(int n) {
        if (n == 1)
			return 1;
		int ret;
		vector<int> row(n,0);
		for (int i = 0;i < n;++i)
		{
			row[0] = i;
			gotRow(1,row,ret);
		}
		return ret;
	}
	void gotRow(int k, vector<int> &row, int &ret)
	{
		for (int i = 0;i < row.size();++i)
		{
			if (isValid(k, i,row))
			{
				row[k] = i;
				if (k == row.size() - 1)
				{
					ret++;
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