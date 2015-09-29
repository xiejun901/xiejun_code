class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minmum=INT_MAX;
        int profile = 0;
        for(int i=0;i<prices.size();++i)
        {
            minmum=min(minmum,prices[i]);
            profile = max(profile,prices[i]-minmum);
        }
        return profile;
    }
};