#include <lt_help/lt.h>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size;
        while( (size = lists.size()) >= 2 )
        {   for(int i = 0, j = size - 1; i < j; ++i, --j)
            {   lists[i] = mergeTwoLists( lists[i], lists[j] );
                lists.pop_back();
            }
        }
        return size == 0 ? NULL : lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tmp(0);
        ListNode* pnode = &tmp;

        while( l1 != NULL && l2 != NULL )
        {   ListNode** pmin = (l1->val < l2->val) ? &l1 : &l2;
            pnode->next = *pmin;
            pnode       = pnode->next;
            *pmin       =(*pmin)->next;
        }

        if( l1 != NULL )
            pnode->next = l1;

        if( l2 != NULL )
            pnode->next = l2;

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


