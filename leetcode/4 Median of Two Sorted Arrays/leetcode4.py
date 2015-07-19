class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        i_min = 0
        i_max = m
        half_len = (m+n+1)//2
        while i_min <= i_max:
            i = (i_min + i_max)//2
            j = half_len - i
            if j > 0 and i < m and nums2[j-1] > nums1[i]:
                i_min = i + 1
            elif i > 0 and j < n and nums1[i-1] > nums2[j]:
                i_max = i -1
            else:
                if i == 0:
                    num1 = nums2[j-1]
                elif j == 0:
                    num1 = nums1[i-1]
                else:
                    num1 = max(nums1[i-1], nums2[j-1])

                if (m+n) % 2 == 1:
                    return num1
                if i==m:
                    num2 = nums2[j]
                elif j == n:
                    num2 = nums1[i]
                else:
                    num2 = min(nums1[i], nums2[j])
                return (num1+num2) / 2.0

s = Solution()
print(s.findMedianSortedArrays([1,3,5,6,7],[2,5,6,7,8,9,11]))