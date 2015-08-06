class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result;
        int total_interval = 2*(numRows-1);
        for(int i=0;i<numRows;++i)
        {
            int current_interval = total_interval - 2 * i;
            if(current_interval == 0)
                current_interval = total_interval;
            int j=i;
            while(j<s.size())
            {
                result.push_back(s[j]);
                j += current_interval;
                if(current_interval != total_interval)
                    current_interval = total_interval - current_interval;
            }
        }
        return result;
    }
};