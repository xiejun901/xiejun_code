#pragma once
//https://leetcode.com/problems/compare-version-numbers/   compare-version-numbers
#include"leetcode.h"
class Solution {
public:
	int compareVersion(string version1, string version2) {
		auto vec1 = split(version1, [](char ch) {return ch == '.'; });
		auto vec2 = split(version2, [](char ch) {return ch == '.'; });
		auto iter1 = vec1.begin();
		auto iter2 = vec2.begin();
		while (iter1 != vec1.end() && iter2 != vec2.end())
		{
			if (stoi(*iter1) > stoi(*iter2))
				return 1;
			else if (stoi(*iter1) < stoi(*iter2))
				return -1;
			++iter1;
			++iter2;
		}
		while (iter1 != vec1.end())
		{
			if (stoi(*iter1) != 0)
				return 1;
			++iter1;
		}
		while (iter2 !=vec2.end())
		{
			if (stoi(*iter2) != 0)
				return -1;
			++iter2;
		}
		return 0;
	}
	template<typename Fun>
	vector<string> split(const string &str, Fun f)
	{
		vector<string> result;
		auto iter1 = str.begin();
		auto iter2 = iter1;
		while (iter2 != str.end())
		{
			if (f(*iter2))
			{
				if (iter1 == iter2)
				{
					++iter1;
					++iter2;
				}
				else
				{
					result.push_back(string(iter1, iter2));
					iter1 = ++iter2;
				}
			}
			else
				++iter2;

		}
		if (iter1 != iter2)
			result.push_back(string(iter1, iter2));
		return result;
	}
};