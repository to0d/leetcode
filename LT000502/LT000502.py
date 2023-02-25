#!/usr/bin/python

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_width, begin, pos, size = 0, 0, 0, len(s)
        if size <= 0 :
            return ""
        
        while (pos+(max_width+1)/2) < size:
            for odd in range(2) :
                start = int (pos - (max_width+1)/2 + odd)
                end   = int (pos + (max_width+1)/2 ) 
                if start < 0 or end >= size :
                    continue
                i, j = start, end
                while i < j and s[i] == s[j]:
                    i, j = i+1, j-1
                if i < j :
                    continue;
                while start >= 0 and end < size and s[start] == s[end]:
                    max_width = end - start + 1
                    begin     = start
                    start, end = start-1, end+1
            pos = pos+1
         
        return s[begin : begin+max_width]


input = "babad"
solution = Solution()
output = solution.longestPalindrome(input)
print "input:", input,
print "; output:", output

# Result 
#
# 2023-02-08: Runtime 203ms 93.30% Memory 13.6MB 52.76%, https://leetcode.com/problems/longest-palindromic-substring/submissions/894127050/
