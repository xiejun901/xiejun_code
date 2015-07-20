class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		for (auto i : nums)
			strs.push_back(to_string(i));
		sort(strs.begin(), strs.end(), [](const string &s1, const string &s2) {return s1+s2 < s2+s1;});
		string result;
		for (auto iter = strs.rbegin();iter != strs.rend();++iter)
		{
			result = result + *iter;
		}
		while (result[0] == '0' && result.length()>1)
			result.erase(0, 1);
		return result;
	}
};