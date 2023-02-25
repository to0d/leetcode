#!/usr/bin/python

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        pos, n, prefix = 0, len(strs), ""
        
        if n > 0 :        
            while True :
                if pos >= len(strs[0]) :
                    return prefix                
                c, idx = strs[0][pos], 1
                while idx < n :
                    if pos >= len(strs[idx]) or c != strs[idx][pos] : 
                        return prefix
                    idx += 1
                pos += 1
                prefix += c
                
        return prefix

strs = ["flower","flow","flight"]
print "input:", strs,
output = Solution().longestCommonPrefix(strs)
print "; output:", output

# Result 
#
# 2022-11-03: Runtime 54ms 6.48% Memory 13.5MB 88.80%, https://leetcode.com/problems/longest-common-prefix/submissions/836055945/
