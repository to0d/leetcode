#!/usr/bin/python

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """        
        
        points, size = [], len(height)
        for idx in range(size):
            points.append((idx, height[idx]))

        points = sorted(points, key=lambda p:p[1])
        
        pos, left_idx, right_idx, max_area = size-2, points[size-1][0], points[size-1][0], 0
        
        while pos >= 0 :
            cur_idx = points[pos][0]
            if cur_idx < left_idx :
                cur_max_area = (right_idx-cur_idx) * points[pos][1]
                left_idx     = cur_idx
            elif cur_idx > right_idx :
                cur_max_area = (cur_idx-left_idx) * points[pos][1]
                right_idx    = cur_idx
            else :
                cur_max_area = max((right_idx-cur_idx),(cur_idx-left_idx)) * points[pos][1]
           
            if cur_max_area > max_area :
                max_area = cur_max_area
            pos -= 1
            
        return max_area


height = [1,1]
print "input:", height,
output = Solution().maxArea(height)
print "; output:", output

# Result 
#
# 2022-11-02: Runtime 2771ms 5% Memory 35.9MB 8.46%, https://leetcode.com/problems/container-with-most-water/submissions/835428797/
