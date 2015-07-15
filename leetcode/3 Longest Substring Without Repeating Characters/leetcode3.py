class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        n=len(s)
        if n == 0:
            return 0
        start=0
        m={}
        maxlength=1
        m[s[0]]=0
        for i in range(1,n):
            if s[i] in m and m[s[i]] >= m[s[start]]:
                if i-start > maxlength:
                    maxlength=i-start
                start=m[s[i]]+1
                m[s[i]]=i
            else:
                m[s[i]]=i
        if n-start > maxlength:
            maxlength = n - start
        return maxlength


s=Solution()
print(s.lengthOfLongestSubstring("abba"))