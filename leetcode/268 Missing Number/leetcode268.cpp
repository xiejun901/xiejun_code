class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int sum=0;
        for(auto i:nums)
            sum+=i;
        return (n+1)*n/2-sum;
    }
};