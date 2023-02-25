#!/usr/bin/python

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nlen = len(nums);
        if nlen < 3:
            return 0

        nums.sort()

        best = nums[0] + nums[1] + nums[2]
        i = 0
        while i < nlen - 2:
            j, k = i + 1, nlen-1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]

                if abs(sum-target) < abs(best-target):
                    best = sum

                if sum < target:
                    j += 1
                elif sum > target:
                    k -= 1
                else:
                    return target;
            i += 1

        return best

nums = [-1, 2, 1, -4]
target = 1
print "input:", nums, ",", target,
output = Solution().threeSumClosest(nums, target)
print "; output:", output

# Result 
#
# 2022-11-03: Runtime 754ms 34.73% Memory 13.5MB 67.41%, https://leetcode.com/problems/3sum-closest/submissions/836071713/

