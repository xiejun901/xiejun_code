class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==1)
            return vector<vector<int>>(1,vector<int>(1,1));
        int total_nums=n*n;
        vector<vector<int>> result(n,vector<int>(n));
        int i=0,j=0;
        int loop=0;
        int count=0;
        while(count < total_nums)
        {
            while(j < n-loop)
                result[i][j++] = ++count;
            j--;
            i++;
            while(i < n-loop)
                result[i++][j] = ++count;
            i--;
            j--;
            while(j>=loop)
                result[i][j--] = ++count;
            j++;
            i--;
            while(i>loop)
                result[i--][j] = ++count;
            i++;
            j++;
            loop++;
        }
        return result;
    }
};