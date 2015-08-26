class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> sum;
        string result;
        auto itera=a.rbegin();
        auto iterb=b.rbegin();
        while(itera!=a.rend()&&iterb!=b.rend())
        {
            sum.push_back(*itera+*iterb-'0'-'0');
            ++itera;
            ++iterb;
        }
        while(itera!=a.rend())
        {
            sum.push_back(*itera-'0');
            ++itera;
        }
        while(iterb!=b.rend())
        {
            sum.push_back(*iterb-'0');
            ++iterb;
        }
        int c=0;
        for(auto i : sum)
        {
            result.push_back(((i+c)%2)+'0');
            c=(i+c)/2;
        }
        if(c)
            result.push_back('1');
        reverse(result.begin(),result.end());
        return result;
    }
};