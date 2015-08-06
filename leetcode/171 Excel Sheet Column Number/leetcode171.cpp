class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n>0)
        {
            n=n-1;
            result.push_back(static_cast<char>(n%26+'A'));
            n/=26;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};