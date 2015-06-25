#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0;i != nums.size();++i)
		{
			int low = i + 1;
			int high = n - 1;
			int target = 0 - nums[i];
			while (low < high)
			{
				if (nums[low] + nums[high] < target)
				{
					low++;
					continue;
				}
				if (nums[low] + nums[high] > target)
				{
					high--;
					continue;
				}
				ret.push_back(vector<int>());
				ret.back().push_back(nums[i]);
				ret.back().push_back(nums[low]);
				ret.back().push_back(nums[high]);
				while (nums[low + 1] == nums[low] && low < high)
					low++;
				low++;
				while (nums[high - 1] == nums[high] && high > low)
					high--;
				high--;
			}
			while (i+1<n&&nums[i + 1] == nums[i])
				i++;
		}
		return ret;
	}
};
int main()
{
	Solution s;
	auto t=s.threeSum(vector<int>{-1,0,1,2,-1,-4});
	return 0;
}