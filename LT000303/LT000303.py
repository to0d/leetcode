#!/usr/bin/python
#coding=UTF-8

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        loc_map = {}
        max_len = 0
        sub_len = 0 
        for idx in range(len(s)):
            c = s[idx]
            if( loc_map.has_key(c) and ((idx-loc_map[c]) <= sub_len)):
                sub_len = idx-loc_map[c]
            else:
                sub_len += 1
                if sub_len > max_len :
                    max_len = sub_len
            loc_map[c] = idx
        return max_len

s = "abcabcbb"
l = Solution().lengthOfLongestSubstring(s)
print "input: ", s, "; output: ", l

# Result 
#
# 2022-11-20: Runtime 66 ms 52.9% Memory 14.3 33.61%, https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/846969428/
