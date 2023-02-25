#!/usr/bin/python

class Solution(object):
   
   ToArray = [{0:"", 1:"I", 2:"II", 3:"III", 4:"IV", 5:"V", 6:"VI", 7:"VII", 8:"VIII", 9:"IX",},    
              {0:"", 1:"X", 2:"XX", 3:"XXX", 4:"XL", 5:"L", 6:"LX", 7:"LXX", 8:"LXXX", 9:"XC",},
              {0:"", 1:"C", 2:"CC", 3:"CCC", 4:"CD", 5:"D", 6:"DC", 7:"DCC", 8:"DCCC", 9:"CM",},
              {0:"", 1:"M", 2:"MM", 3:"MMM"}]
   
   def intToRoman(self, num):
       """
       :type num: int
       :rtype: str
       """
       
       if num > 3999 or num < 0 :
           raise ValueError
       
       rst, pos = "", 0
       
       while num > 0 :
           idx = num % 10
           rst = self.ToArray[pos][idx] + rst
           pos += 1
           num /= 10
       
       return rst

num=1994
print "input:", num,
output = Solution().intToRoman(num)
print "; output:", output

# Result 
#
# 2022-11-02: Runtime 67ms 21.4% Memory 13.5MB 44.69%, https://leetcode.com/problems/integer-to-roman/submissions/835434548/