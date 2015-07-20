class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> index_pair;
        int n=matrix.size();
        if(n==0)
            return;
        int m=matrix.back().size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==0)
                    index_pair.push_back(make_pair(i,j));
            }
        }
        for(auto p :index_pair)
        {
            setZero(p.first,p.second,matrix);
        }
    }
    void setZero(int i, int j, vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix.back().size();
        for(int ii=0;ii<n;++ii)
            matrix[ii][j]=0;
        for(int jj=0;jj<m;++jj)
            matrix[i][jj]=0;
    }
};