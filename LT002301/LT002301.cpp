#include <lt_help/lt.h>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while( lists.size() >= 2 )
            for(int i = 0, j = lists.size() - 1; i < j; ++i, --j)
            {   lists[i] = mergeTwoLists( lists[i], lists[j] );
                lists.pop_back();
            }

        return lists.size() == 0 ? NULL : lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // LT002101.cpp
        ListNode tmp(0);
        ListNode* l3 = &tmp;
        while( l1 != NULL && l2 != NULL )
        {   ListNode** pmin = (l1->val < l2->val) ? &l1 : &l2;
            l3->next = *pmin;
            l3       = l3->next;
            *pmin    =(*pmin)->next;
        }
        l3->next= (l1==NULL)? l2 : l1;
        return tmp.next;
    }
};



void test(vector<ListNode*> lists)
{
    cout << "input: ";
    outputList(lists);
    ListNode* r = Solution().mergeKLists(lists);
    cout << "; output: ";
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
    test({makeList(3,1,4,5), makeList(3,1,3,4), makeList(2,2,6)});
}

// Result 
//
// 2022-11-07: Runtime 30ms 53.56% Memory 12.9MB 95.29%, https://leetcode.com/problems/merge-k-sorted-lists/submissions/838723307/
// 2023-02-16: Runtime 16ms 97.81% Memory 13MB 95.29%, https://leetcode.com/problems/merge-k-sorted-lists/submissions/899177077/
// 2023-03-08: Runtime 18ms 95.34% Memory 13MB 86.81%, https://leetcode.com/problems/merge-k-sorted-lists/submissions/910933318/
// 2023-03-14: Runtime 24ms 74.41% Memory 13MB 86.57%, https://leetcode.com/problems/merge-k-sorted-lists/submissions/914464261/



