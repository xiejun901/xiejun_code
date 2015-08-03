#pragma once
//https://leetcode.com/problems/multiply-strings/
#include"leetcode.h"
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> n1;
		vector<int> n2;
		for (auto iter = num1.rbegin(); iter != num1.rend(); ++iter)
			n1.push_back(*iter - '0');
		for (auto iter = num2.rbegin(); iter != num2.rend(); ++iter)
			n2.push_back(*iter - '0');
		vector<int> sum(n1.size() + n2.size(), 0);
		for (int i = 0; i<n2.size(); ++i)
		{
			for (int j = 0; j<n1.size(); ++j)
			{
				sum[i + j] += n2[i] * n1[j];
			}
		}
		int i = 0;
		for (i = 0; i<sum.size()-1; ++i)
		{
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
		string result;
		while (i > 0 && sum[i] == 0) --i;
		while (i >= 0)
		{
			result.push_back(static_cast<char>(sum[i] + '0'));
			--i;
		}
		return result;
	}
};