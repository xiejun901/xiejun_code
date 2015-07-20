class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> result(n);
        for(int i=1,j=n-2;i<n&&j>=0;i++,j--)
        {
            left[i]=left[i-1]*nums[i-1];
            right[j] = right[j+1]*nums[j+1];
        }
        for(int i=0;i<n;i++)
           result[i]=left[i]*right[i];
        return result;
    }
};