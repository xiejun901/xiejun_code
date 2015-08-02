#pragma once
//https://leetcode.com/problems/reverse-words-in-a-string/   Reverse Words in a String
#include"leetcode.h"

class Solution {
public:
	void reverseWords(string &s) {
		auto new_last = unique(s.begin(), s.end(), [](char a, char b) {return a == b && a == ' '; });
		s.erase(new_last, s.end());
		if (!s.empty() && s.front() == ' ')
			s.erase(s.begin());
		if (!s.empty() && s.back() == ' ')
			s.erase(s.end() - 1);
		reverse(s.begin(), s.end());
		string::iterator iter1 = s.begin();
		string::iterator iter2;
		while ((iter2 = find(iter1, s.end(), ' ')) != s.end())
		{
			reverse(iter1, iter2);
			iter1 = iter2 + 1;
		}
		reverse(iter1, iter2);
	}
};