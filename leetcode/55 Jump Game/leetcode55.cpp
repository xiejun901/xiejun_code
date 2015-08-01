class Solution {
public:
    bool canJump(vector<int>& nums) {
        int longDistance=0;
        int i=0;
        while(i<nums.size() && i<=longDistance)
        {
            if(nums[i]+i > longDistance)
                longDistance = nums[i]+i;
            ++i;
        }
        return longDistance>=nums.size()-1;
    }
};