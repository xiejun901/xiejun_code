#pragma once
//https://leetcode.com/problems/valid-palindrome/
#include"leetcode.h"
class Solution {
public:
	bool isPalindrome(string s) {
		const int diff = 'a' - 'A';
		int i = 0;
		int j = s.size() - 1;
		while (i < j)
		{
			while (i<j && !(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'))
				i++;
			while (i<j && !(s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z' || s[j] >= '0' && s[j] <= '9'))
				j--;
			if (s[i] >= 'a')
				s[i] -= diff;
			if (s[j] >= 'a')
				s[j] -= diff;
			if (s[i] == s[j])
			{
				i++;
				j--;
			}
			else
				return false;
		}
		return true;
	}
};