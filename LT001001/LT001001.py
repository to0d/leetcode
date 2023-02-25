#!/usr/bin/python

class Solution(object):

    slen, mlen = 0, 0
    
    def isMatch(self, s, m):
        """
        :type s: str
        :type m: str
        :rtype: bool
        """
        self.slen, self.mlen = len(s), len(m)
        return self.tryMatch(s, m, 0, 0)

    def tryMatch(self, s, m, spos, mpos):
    
        # print(s, m, spos, mpos)
        
        if mpos == self.mlen :
            return spos == self.slen
        
        c     = m[mpos]
        mpos += 1
        
        if c == '*' :
            return False
        
        if mpos < self.mlen and m[mpos] == '*' : 
            mpos += 1
            
            if mpos == self.mlen :
                if c == '.':
                    return True            
            
            while spos <= self.slen :
                if self.tryMatch(s, m, spos, mpos) :
                    return True
                if spos < self.slen and c != '.' and s[spos] != c  :
                    break
                spos += 1

            return False
        else :
            return spos < self.slen and ( c == '.' or c == s[spos]) and self.tryMatch(s, m, spos+1, mpos)

s = "ab"
p = ".*"
print "input:", s, p,
output = Solution().isMatch(s, p)
print "; output:", output

# Result 
#
# 2022-11-02: Runtime 1314ms 7.31% Memory 13.4MB 94.29%, https://leetcode.com/problems/regular-expression-matching/submissions/835424172/

