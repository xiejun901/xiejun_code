class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return findKth(nums,0,n-1,k-1);
    }
    
    int findKth(vector<int>& nums,int low,int high,int k){
        if(low<high){
            int i=low;
            for(int j=low;j<high;++j){
                if(nums[j]>nums[high]){
                    exchange(nums[i],nums[j]);
                    ++i;
                }
            }
            exchange(nums[i],nums[high]);
            if(i==k)
                return nums[i];
            else if(i<k)
                return findKth(nums,i+1,high,k);
            else
                return findKth(nums,low,i-1,k);
        }
        else
            return nums[low];
    }
    void exchange(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
};