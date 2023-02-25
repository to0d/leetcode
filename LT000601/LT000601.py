#!/usr/bin/python

class Solution(object):
    def convert(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        if n <= 1:
            return s
        
        tmp = []
        
        for i in range(n):
            tmp.append('')
            
        pos, size, m = 0, len(s), int(2*n - 2)
            
        while pos < size:
            for i in range(n):
                if (pos+i) < size:
                    tmp[i] += s[pos+i]
                if i != 0 and i != (n-1) and (pos+m-i) < size:
                    tmp[i] += s[pos+m-i]            
            pos += m

        out = ''
        for i in range(n):
            out += tmp[i]
        
        return out


s = "PAYPALISHIRING"
n = 3
print "input:", s, n, 
r = Solution().convert(s, n)
print "; output:", r

# Result 
#
# 2023-02-09: Runtime 49ms 60.51% Memory 13.7MB 37.66%, https://leetcode.com/problems/zigzag-conversion/submissions/894135244/

