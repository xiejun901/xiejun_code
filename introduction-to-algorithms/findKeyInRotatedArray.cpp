#include<vector>
#include<iostream>
using namespace std;
bool binarySearch(const vector<int> nums, int low, int high, int target){
    while(low<high){
        int mid=low+(high-low)/2;
        if(target>nums[mid])
            low=mid+1;
        else
            high=mid;
    }
    if(nums[low] == target)
        return true;
    return false;
}
int binarySearchRotated(vector<int> &nums) {
    int low=0;
    int high=nums.size()-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid] > nums[high])
            low=mid+1;
        else
            high = mid;
    }
    return low;
}
bool search(vector<int>& nums, int target) {
    int minLow = binarySearchRotated(nums);
    int low=0;
    int high=nums.size()-1;
    if(target>nums[high])
        return binarySearch(nums,low,minLow-1,target);
    else
        return binarySearch(nums,minLow,high,target);
}
int main()
{
    vector<int> nums{1,1,3,1};
    cout<<binarySearchRotated(nums)<<endl;
    return 0;
}