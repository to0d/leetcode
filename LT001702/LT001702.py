#!/usr/bin/python

class Solution(object):
    cmap = {2:"abc", 3:"def", 4:"ghi", 5:"jkl", 6:"mno", 7:"pqrs", 8:"tuv", 9: "wxyz"}
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        rst, dlen = [], len(digits)
        
        if dlen > 0 :
            tmp = [""] * (dlen+1)
            for d in digits :
                if not self.cmap.has_key(int(d)) :
                    return rst
            self.letterCombinations2(digits, rst, dlen, tmp, 0)

        return rst
        
    def letterCombinations2(self, digits, rst, dlen, tmp, pos):

        if pos == dlen :
            rst.append(tmp[pos]) 
        else :                
            for dc in self.cmap[int(digits[pos])] :
                tmp[pos+1] = tmp[pos] + dc
                self.letterCombinations2(digits, rst, dlen, tmp, pos+1)


digits = "23"
print "input:", digits,
output = Solution().letterCombinations(digits)
print "; output:", output

# Result 
#
# 2022-11-03: Runtime 23ms 36.90% Memory 13.7MB 6.24%, https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/836079709/