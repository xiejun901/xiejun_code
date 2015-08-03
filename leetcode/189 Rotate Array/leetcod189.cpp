class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        k=(n-1-k);
        reverse(nums,0,k);
        reverse(nums,k+1,n-1);
        reverse(nums,0,n-1);
    }
    void reverse(vector<int>& nums, int start, int end)
    {
        while(start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
};