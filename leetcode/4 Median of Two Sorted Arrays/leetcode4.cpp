#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n)
		{
			nums1.swap(nums2);
			swap(n, m);
		}
		int imin = 0;
		int imax = m;
		int half_len = (m + n + 1) / 2;
		while (imin <= imax)
		{
			int i = (imin + imax) / 2;
			int j = half_len - i;
			if (j > 0 && i<m && nums2[j - 1]>nums1[i])
				imin = i + 1;
			else if (i > 0 && j<n && nums1[i - 1]>nums2[j])
				imax = i - 1;
			else
			{
				int temp1, temp2;
				if (i == 0)
					temp1 = nums2[j - 1];
				else if (j == 0)
					temp1 = nums1[i - 1];
				else
					temp1 = max(nums1[i - 1], nums2[j - 1]);
				if ((m + n) % 2 == 1)
					return temp1;
				if (i == m)
					temp2 = nums2[j];
				else if (j == n)
					temp2 = nums1[i];
				else
					temp2 = min(nums1[i], nums2[j]);
				return static_cast<double>(temp1 + temp2) / 2;
			}
		}
	}
};
int main()
{
	Solution s;
	vector<int> nums1;
	vector<int> nums2{ 1 };
	auto result=s.findMedianSortedArrays(nums1, nums2);
	return 0;
}