#!/usr/bin/python
#coding=UTF-8

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        index_map = {}
        rtype = []
        for idx in range(len(nums)):
            num = nums[idx]
            if index_map.has_key(num):
                rtype.append(index_map[num])
                rtype.append(idx)
                return rtype
            index_map[target-num]=idx
        return rtype


input = [2, 7, 11, 15]
solution = Solution()
output = solution.twoSum(input, 9)

print "input:", input, "; output:", output

# Result 
#
# 2023-02-06: Runtime 34 ms 98.30% Memory 14.3 75.38%, https://leetcode.com/problems/two-sum/submissions/892661721/