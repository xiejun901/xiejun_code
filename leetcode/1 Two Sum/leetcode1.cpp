class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int i=0;
        int j=temp.size()-1;
        vector<int> ret;
        while(i<j)
        {
            if(temp[i]+temp[j]==target)
                break;
            if(temp[i]+temp[j]<target)
                i++;
            else
                j--;
        }
        for(int k=0;k<nums.size();++k)
        {
            if(nums[k]==temp[i]||nums[k]==temp[j])
                ret.push_back(k+1);
        }
        return ret;
    }
};