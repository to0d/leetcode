#!/usr/bin/python

class Solution(object):
    max_int = 2**31-1

    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 :
            return False

        return x == self.reverse(x)

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


x=121
print "input:", x,
output = Solution().isPalindrome(x)
print "; output:", output

# Result 
#
# 2023-02-09: Runtime 83ms 26.91% Memory 13.6MB 15.22%, https://leetcode.com/problems/palindrome-number/submissions/894774814/ 

