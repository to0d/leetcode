#!/usr/bin/python
#coding=UTF-8

import sys
sys.path.append('/mnt/c/data/project/ctl/include/lt_help/py')

from list import *

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        phead = None
        pnode = None
        val = 0
        
        while (l1 != None) or (l2 != None ) or (val > 0) :
            if l1 != None :
                val = val + l1.val
                l1 = l1.next
            if l2 != None :
                val = val + l2.val
                l2 = l2.next
            if pnode == None :
                pnode = ListNode(val % 10)
                phead = pnode
            else :
                pnode.next = ListNode(val % 10)
                pnode = pnode.next
            val = val / 10

        return phead        


l1 = makeList(2, 4, 3)
l2 = makeList(5, 6, 4)
r = Solution().addTwoNumbers(l1,l2)

print "input: l1=",
outputList(l1)
print ", l2=",
outputList(l2)
print "; output: ",
outputList(r)

# Result 
#
# 2023-02-06: Runtime 63 ms 41.9% Memory 13.5 49.75%, https://leetcode.com/problems/add-two-numbers/submissions/892674641/

