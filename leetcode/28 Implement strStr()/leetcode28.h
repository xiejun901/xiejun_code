#pragma once
#include"leetcode.h"

class Solution {
public:
    int strStr(const string &haystack, const string &needle) {
        if (needle == string())
            return  0;
        auto next = computePrefix(needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i)
        {
            while (j > 0 && needle[j] != haystack[i])
                j = next[j - 1];
            if (haystack[i] == needle[j])
            {
                if (j == needle.size() - 1)
                {
                    return i - j;
                }
                else
                    j++;
            }
        }
        return -1;
    }
    vector<int> computePrefix(const string &str)
    {
        int m = str.size();
        vector<int> next(m, 0);
        int j = 0;
        for (int p = 1; p < m; p++)
        {
            while (j > 0 && str[p] != str[j])
            {
                j = next[j - 1];
            }
            if (str[p] == str[j])
                j = j + 1;
            next[p] = j;
        }
        return next;
    }
};