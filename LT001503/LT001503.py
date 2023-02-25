#!/usr/bin/python

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result, nmap, nlen, i= [], {}, len(nums), 0
        if nlen < 3 :
            return result
            
        nums.sort()                                                  # optimize#1

        for idx in range(nlen) :
            v = nums[idx]
            nmap[nums[idx]] = idx

        ax = nums[0]-1
        while i < nlen - 2 :
            a, j, bx = nums[i], i+1, (nums[i]-1)
            if a > 0 :  
                break;                                               # optimize#2
            if ax != a :
                while j < nlen - 1 :
                    b = nums[j]
                    if (a+b+b) > 0 :                                 # b<c, 0<a+b+b<a+b+c 
                        break                                        # optimize#3
                    c = -a - b
                    if bx != b and nmap.has_key(c) and nmap[c] > j : # no triple found
                        t = [a, b, c]
                        result.append(t)
                    j += 1
                    bx = b
            i += 1
            ax = a 
        return result

nums = [-1,0,1,2,-1,-4]
result = Solution().threeSum(nums)
print "input:", nums,
print "; output:", result

# Result 
#
# 2022-11-03: Runtime 909ms 62.39% Memory 17.1MB 26.84%, https://leetcode.com/problems/3sum/submissions/836066237/


