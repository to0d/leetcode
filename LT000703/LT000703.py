#!/usr/bin/python

class Solution(object):
    max_int = 2**31-1
    
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign, y = 1, 0
        if x < 0:
            x, sign = -x, -1  
        s = `x`[::-1]

        for c in s:
            n = int(c)
            y = int(10*y+n)
            if y > self.max_int:
                return 0
        
        return y*sign


n = 123
print "input:", n,
r = Solution().reverse(n)
print "; output:", r

# Result 
#
# 2023-02-09: Runtime 15ms 91.70% Memory 13.3MB 69.56%, https://leetcode.com/problems/reverse-integer/submissions/894755028/
