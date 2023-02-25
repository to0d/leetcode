#!/usr/bin/python

class Solution(object):

    int_max = 2147483647
    int_min = -2147483648
    
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        isPositive, isOverflow, start, end, result = True, False, 0, len(s), 0

        while start < end and s[start] == ' ' : #Skip head blanks
            start += 1

        if start < end :                        #Check sign
            if s[start] == '-' :
                isPositive = False
                start += 1
            elif s[start] == '+' :
                start += 1
           
        while start < end :
            c = s[start]
            if not c.isdigit() :                #Invalid character
                break
            # print (c, '=', int(c))
            result *= 10
            result += int(c)
            
            if ((result > self.int_max) and isPositive) or ((result > (self.int_max+1)) and not isPositive):
                isOverflow = True
                break
                
            start += 1
        
        if isOverflow :
            if isPositive :
                return self.int_max
            else:
                return self.int_min
        
        if (not isPositive) :
            result = -result;

        return result


n = "1234567"
print "input:", n,
r = Solution().myAtoi(n)
print "; output:", r

# Result 
#
# 2023-02-09: Runtime 26ms 57.38% Memory 13.6MB 55.13%, https://leetcode.com/problems/string-to-integer-atoi/submissions/894766554/

