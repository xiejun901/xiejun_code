class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>::iterator iter;
            if((iter=m.find(nums[i]))!=m.end())
            {
                if(i-iter->second <=k)
                    return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }
	//using unordered_set
	bool containsNearbyDuplicate_set(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();++i)
        {
            if(i>k)
                s.erase(nums[i-k-1]);
            if(s.find(nums[i])!=s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};