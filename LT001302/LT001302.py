#!/usr/bin/python

class Solution(object):
    roman_map = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, idx, size = 0, 0, len(s)
        
        if size == 0 :
            raise ValueError
            
        while idx < size :
            c = s[idx]
            if (idx+1) < size and self.roman_map[c] < self.roman_map[s[idx+1]] :
                n -= self.roman_map[c]
            else:
                n += self.roman_map[c]
            idx += 1
        
        return n

s="MCMXCIV"
print "input:", s,
output = Solution().romanToInt(s)
print "; output:", output

# Result 
#
# 2022-11-02: Runtime 84ms 13.39% Memory 13.5MB 63.99%, https://leetcode.com/problems/roman-to-integer/submissions/835440517/
